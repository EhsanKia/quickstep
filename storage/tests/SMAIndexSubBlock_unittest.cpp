/**
 *   Copyright 2016 Pivotal Software, Inc.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "glog/logging.h"

#include "catalog/CatalogAttribute.hpp"
#include "catalog/CatalogRelation.hpp"
#include "catalog/CatalogTypedefs.hpp"
#include "expressions/predicate/ComparisonPredicate.hpp"
#include "expressions/predicate/TrivialPredicates.hpp"
#include "expressions/scalar/Scalar.hpp"
#include "expressions/scalar/ScalarAttribute.hpp"
#include "expressions/scalar/ScalarLiteral.hpp"
#include "storage/CompressedPackedRowStoreTupleStorageSubBlock.hpp"
#include "storage/CompressedTupleStorageSubBlock.hpp"
#include "storage/SMAIndexSubBlock.hpp"
#include "storage/StorageBlockLayout.pb.h"
#include "storage/StorageErrors.hpp"
#include "storage/TupleIdSequence.hpp"
#include "storage/tests/MockTupleStorageSubBlock.hpp"
#include "types/CharType.hpp"
#include "types/DoubleType.hpp"
#include "types/FloatType.hpp"
#include "types/LongType.hpp"
#include "types/Type.hpp"
#include "types/TypeFactory.hpp"
#include "types/TypedValue.hpp"
#include "types/TypeID.hpp"
#include "types/VarCharType.hpp"
#include "types/containers/Tuple.hpp"
#include "types/operations/comparisons/Comparison.hpp"
#include "types/operations/comparisons/ComparisonFactory.hpp"
#include "types/operations/comparisons/ComparisonID.hpp"
#include "types/operations/comparisons/ComparisonUtil.hpp"
#include "utility/ScopedBuffer.hpp"

using std::binary_search;
using std::int64_t;
using std::numeric_limits;
using std::ostringstream;
using std::set;
using std::size_t;
using std::string;
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::vector;

namespace quickstep {

typedef sma_internal::EntryReference EntryReference;
typedef sma_internal::SMAEntry SMAEntry;
// typedef sma_internal::SMAPredicate SMAPredicate;

namespace sma_test {
  // Handy comparison functions.
  bool longs_equal(TypedValue left, TypedValue right) {
    return ComparisonFactory::GetComparison(ComparisonID::kEqual)
        .compareTypedValuesChecked(left, LongType::InstanceNonNullable(),
                                   right, LongType::InstanceNonNullable());
  }

  bool floats_equal(TypedValue left, TypedValue right) {
    return ComparisonFactory::GetComparison(ComparisonID::kEqual)
        .compareTypedValuesChecked(left, FloatType::InstanceNonNullable(),
                                   right, FloatType::InstanceNonNullable());
  }

  bool doubles_equal(TypedValue left, TypedValue right) {
    return ComparisonFactory::GetComparison(ComparisonID::kEqual)
        .compareTypedValuesChecked(left, DoubleType::InstanceNonNullable(),
                                   right, DoubleType::InstanceNonNullable());
  }

  bool chars_equal(TypedValue left, TypedValue right) {
    return ComparisonFactory::GetComparison(ComparisonID::kEqual)
        .compareTypedValuesChecked(left, CharType::Instance(80, false),
                                   right, CharType::Instance(80, false));
  }
}  // namespace sma_test

class SMAIndexSubBlockTest : public ::testing::Test {
 protected:
  static const size_t kIndexSubBlockSize = 0x100000;  // 1 MB
  // Hack: replace long_attr values equal to this with NULL.
  static const int64_t kLongAttrNullValue = -55555;
  static const char kCharAttrNullValue[];

  virtual void SetUp() {
    // Create a sample relation with a variety of attribute types.
    relation_.reset(new CatalogRelation(NULL, "TestRelation"));

    CatalogAttribute *long_attr = new CatalogAttribute(relation_.get(),
                                                       "long_attr",
                                                       TypeFactory::GetType(kLong, false));
    ASSERT_EQ(0, relation_->addAttribute(long_attr));

    CatalogAttribute *nullable_long_attr = new CatalogAttribute(relation_.get(),
                                                                "nullable_long_attr",
                                                                TypeFactory::GetType(kLong, true));
    ASSERT_EQ(1, relation_->addAttribute(nullable_long_attr));

    CatalogAttribute *float_attr = new CatalogAttribute(relation_.get(),
                                                        "float_attr",
                                                        TypeFactory::GetType(kFloat, false));
    ASSERT_EQ(2, relation_->addAttribute(float_attr));

    CatalogAttribute *char_attr = new CatalogAttribute(relation_.get(),
                                                       "char_attr",
                                                       TypeFactory::GetType(kChar, 4, false));
    ASSERT_EQ(3, relation_->addAttribute(char_attr));

    CatalogAttribute *nullable_char_attr = new CatalogAttribute(relation_.get(),
                                                                "nullable_char_attr",
                                                                TypeFactory::GetType(kChar, 4, true));
    ASSERT_EQ(4, relation_->addAttribute(nullable_char_attr));

    CatalogAttribute *big_char_attr = new CatalogAttribute(relation_.get(),
                                                           "big_char_attr",
                                                           TypeFactory::GetType(kChar, 80, false));
    ASSERT_EQ(5, relation_->addAttribute(big_char_attr));

    CatalogAttribute *varchar_attr = new CatalogAttribute(relation_.get(),
                                                          "varchar_attr",
                                                          TypeFactory::GetType(kVarChar, 8, false));
    ASSERT_EQ(6, relation_->addAttribute(varchar_attr));

    // Create a MockTupleStorageSubBlock to hold tuples for testing.
    tuple_store_.reset(new MockTupleStorageSubBlock(*relation_));

    // Don't initialize the SMAIndexSubBlock yet. Different tests will
    // index on different attributes.
    index_memory_.reset();
    index_description_.reset();
    index_.reset();
  }

  void createIndex(const vector<attribute_id> &indexed_attrs, const size_t index_memory_size){
    // Make the IndexSubBlockDescription.
    index_description_.reset(new IndexSubBlockDescription());
    index_description_->set_sub_block_type(IndexSubBlockDescription::SMA);
    for (int i = 0; i < indexed_attrs.size(); ++i) {
      index_description_->AddExtension(SMAIndexSubBlockDescription::indexed_attribute_id,
                                       indexed_attrs[i]);
    }
    index_memory_.reset(index_memory_size);
    index_.reset(new SMAIndexSubBlock(*tuple_store_,
                                      *index_description_,
                                      true,
                                      index_memory_.get(),
                                      index_memory_size));
  }

  // Insert a tuple with the specified attribute values into tuple_store_.
  tuple_id insertTupleInTupleStore(const int64_t long_val,
                                   const int64_t nullable_long_val,
                                   const float float_val,
                                   const string &char_val,
                                   const string &nullable_char_val,
                                   const string &big_char_val,
                                   const string &varchar_val) {
    std::vector<TypedValue> attrs;

    attrs.emplace_back(LongType::InstanceNonNullable().makeValue(&long_val));

    if (nullable_long_val == kLongAttrNullValue) {
      attrs.emplace_back(LongType::InstanceNullable().makeNullValue());
    } else {
      attrs.emplace_back(LongType::InstanceNullable().makeValue(&nullable_long_val));
    }

    attrs.emplace_back(FloatType::InstanceNonNullable().makeValue(&float_val));

    attrs.emplace_back(CharType::InstanceNonNullable(4).makeValue(
        char_val.c_str(),
        char_val.size() >= 4 ? 4 : char_val.size() + 1).ensureNotReference());

    if (nullable_char_val == kCharAttrNullValue) {
      attrs.emplace_back(CharType::InstanceNullable(4).makeNullValue());
    } else {
      attrs.emplace_back(CharType::InstanceNonNullable(4).makeValue(
          nullable_char_val.c_str(),
          nullable_char_val.size() >= 4 ? 4 : nullable_char_val.size() + 1).ensureNotReference());
    }

    attrs.emplace_back(CharType::InstanceNonNullable(80).makeValue(
        big_char_val.c_str(),
        big_char_val.size() >= 80 ? 80 : big_char_val.size() + 1).ensureNotReference());

    TypedValue varchar_typed_value
        = VarCharType::InstanceNonNullable(varchar_val.size()).makeValue(
            varchar_val.c_str(),
            varchar_val.size() + 1);
    // Test strings are sometimes longer than 8 characters, so truncate if
    // needed.
    varchar_typed_value = VarCharType::InstanceNonNullable(8).coerceValue(
        varchar_typed_value,
        VarCharType::InstanceNonNullable(varchar_val.size()));
    varchar_typed_value.ensureNotReference();
    attrs.emplace_back(std::move(varchar_typed_value));

    // MockTupleStorageSubBlock takes ownership of new tuple passed in with
    // addTupleMock() method.
    return tuple_store_->addTupleMock(new Tuple(std::move(attrs)));
  }

  // Generate a sample tuple based on 'base_value' and insert in into
  // tuple_store_. The sample tuple will have long_attr equal to 'base_value',
  // float_attr equal to 0.25 * base_value, and each of char_attr,
  // big_char_attr, and varchar_attr equal to the string representation of
  // 'base_value' with 'string_suffix' appended on to it. If 'generate_nulls'
  // is true, then both nullable_long_attr and nullable_char_attr will be NULL,
  // otherwise nullable_long_attr will be equal to 'base_value' and
  // nullable_char_attr will be equal to the other string values. Returns the
  // tuple_id of the inserted tuple.
  tuple_id generateAndInsertTuple(const int64_t base_value,
                                  const bool generate_nulls,
                                  const string &string_suffix) {
    ostringstream string_value_buffer;
    string_value_buffer << base_value << string_suffix;
    if (generate_nulls) {
      return insertTupleInTupleStore(base_value,
                                     kLongAttrNullValue,
                                     0.25 * base_value,
                                     string_value_buffer.str(),
                                     kCharAttrNullValue,
                                     string_value_buffer.str(),
                                     string_value_buffer.str());
    } else {
      return insertTupleInTupleStore(base_value,
                                     base_value,
                                     0.25 * base_value,
                                     string_value_buffer.str(),
                                     string_value_buffer.str(),
                                     string_value_buffer.str(),
                                     string_value_buffer.str());
    }
  }

  // Create a ComparisonPredicate of the form "attribute comp literal".
  template <typename AttributeType>
  ComparisonPredicate* generateNumericComparisonPredicate(
      const ComparisonID comp,
      const attribute_id attribute,
      const typename AttributeType::cpptype literal) {
    ScalarAttribute *scalar_attribute = new ScalarAttribute(*relation_->getAttributeById(attribute));
    ScalarLiteral *scalar_literal
        = new ScalarLiteral(AttributeType::InstanceNonNullable().makeValue(&literal),
                            AttributeType::InstanceNonNullable());
    return new ComparisonPredicate(ComparisonFactory::GetComparison(comp), scalar_attribute, scalar_literal);
  }

  // Retrieves the SMAEntry from the test SMAIndex instance.
  SMAEntry* getEntryForAttribute(attribute_id attribute) {
    return const_cast<SMAEntry*>(index_->getEntryChecked(attribute));
  }

  std::unique_ptr<CatalogRelation> relation_;
  std::unique_ptr<MockTupleStorageSubBlock> tuple_store_;
  ScopedBuffer index_memory_;
  std::unique_ptr<IndexSubBlockDescription> index_description_;
  std::unique_ptr<SMAIndexSubBlock> index_;

};

const char SMAIndexSubBlockTest::kCharAttrNullValue[] = "_NULLSTRING";

TEST_F(SMAIndexSubBlockTest, DescriptionIsValidTest) {
  std::unique_ptr<IndexSubBlockDescription> index_description_;
  vector<attribute_id> valid_attrs({0, 1, 2});
  // Only descriptions with non-Null, non-variable length attributes should be valid.
  for (const CatalogAttribute &attr : *relation_) {
    index_description_.reset(
        new IndexSubBlockDescription());
    index_description_->set_sub_block_type(
        IndexSubBlockDescription::SMA);
    index_description_->AddExtension(
        SMAIndexSubBlockDescription::indexed_attribute_id,
        attr.getID());
    if (std::find(valid_attrs.begin(), valid_attrs.end(), attr.getID()) != valid_attrs.end()) {
      EXPECT_TRUE(SMAIndexSubBlock::DescriptionIsValid(
          *relation_,
          *index_description_)) 
               << "Expected attribute " << attr.getID() << " to be valid.";
    } else {
      EXPECT_FALSE(SMAIndexSubBlock::DescriptionIsValid(
          *relation_,
          *index_description_))
              << "Expected attribute " << attr.getID() << " to be invalid.";
    }    
  }
}

TEST_F(SMAIndexSubBlockTest, TestConstructor) {
  createIndex({0, 1, 2}, kIndexSubBlockSize); // Creates proper description.
  memset(index_memory_.get(),0,kIndexSubBlockSize);
  index_.reset(new SMAIndexSubBlock(*tuple_store_,
                                    *index_description_,
                                    true,
                                    index_memory_.get(),
                                    kIndexSubBlockSize));
  EXPECT_TRUE(index_->requiresRebuild());
  EXPECT_TRUE(index_->rebuild());
  index_.reset(new SMAIndexSubBlock(*tuple_store_,
                                    *index_description_,
                                    false,
                                    index_memory_.get(),
                                    kIndexSubBlockSize));
  EXPECT_FALSE(index_->requiresRebuild());
}

TEST_F(SMAIndexSubBlockTest, TestRebuild) {
  createIndex({0, 2}, kIndexSubBlockSize);  // Index long, float type, bigChar type.
  int min = 0, max = 9010, step = 10;
  std::int64_t sum_0 = 0;
  double sum_2 = 0;
  for (unsigned i = min; i <= max; i+=step) {
    generateAndInsertTuple(i, false, "suffix");
    sum_0 += i;
    sum_2 += (i * 0.25);
  }
  index_->rebuild();
  SMAEntry* entry0 = getEntryForAttribute(0);
  SMAEntry* entry2 = getEntryForAttribute(2);
  
  // Check min ids and values.
  EXPECT_EQ(0, entry0->min_entry_.tuple_);
  EXPECT_EQ(0, entry2->min_entry_.tuple_);
  EXPECT_TRUE(sma_test::longs_equal(entry0->min_entry_.value_,
                                    tuple_store_->getAttributeValueTyped(0, 0)));

  EXPECT_TRUE(sma_test::floats_equal(entry2->min_entry_.value_,
                                     tuple_store_->getAttributeValueTyped(0, 2)));

  // Check max ids and values.
  tuple_id max_id = (max - min)/step;
  EXPECT_EQ(max_id, entry0->max_entry_.tuple_);
  EXPECT_EQ(max_id, entry2->max_entry_.tuple_);
  EXPECT_TRUE(sma_test::longs_equal(entry0->max_entry_.value_,
                                    tuple_store_->getAttributeValueTyped(max_id, 0)));
  EXPECT_TRUE(sma_test::floats_equal(entry2->max_entry_.value_,
                                     tuple_store_->getAttributeValueTyped(max_id, 2)));

  // Check sums.
  EXPECT_TRUE(sma_test::longs_equal(entry0->sum_, TypedValue(sum_0)));
  EXPECT_TRUE(sma_test::doubles_equal(entry2->sum_, TypedValue(sum_2)));

  // Check count.
  EXPECT_EQ(max_id + 1, index_->getCount());
}

TEST_F(SMAIndexSubBlockTest, TestRebuildWithNulls) {
  createIndex({0, 1, 2}, kIndexSubBlockSize);
  int min = 0, max = 9010, step = 10;
  std::int64_t sum_1 = 0;  // Attribute 1 will contain some nulls.
  for (unsigned i = min; i <= max; i+=step) {
    bool insertNull = (i % 4) == 0;
    generateAndInsertTuple(i, insertNull, "suffix");
    sum_1 += insertNull ? 0 : i;
  }
  index_->rebuild();
  SMAEntry* entry1 = getEntryForAttribute(1);

  // Check min ids and values.
  tuple_id min_tuple = 1;
  EXPECT_EQ(min_tuple, entry1->min_entry_.tuple_);
  EXPECT_TRUE(sma_test::longs_equal(entry1->min_entry_.value_,
                                    tuple_store_->getAttributeValueTyped(min_tuple, 1)));

  // Check max ids and values.
  int num_tuples = (max - min)/step + 1;
  tuple_id max_tuple = ((num_tuples - 1) % 4) == 0 ? num_tuples - 2 : num_tuples - 1;
  EXPECT_EQ(max_tuple, entry1->max_entry_.tuple_);
  EXPECT_TRUE(sma_test::longs_equal(entry1->max_entry_.value_,
                                    tuple_store_->getAttributeValueTyped(max_tuple, 1)));

  // Check sums.
  EXPECT_TRUE(sma_test::longs_equal(entry1->sum_, TypedValue(sum_1)));

  // Check count.
  EXPECT_EQ(num_tuples, index_->getCount());
}

}  // namespace quickstep