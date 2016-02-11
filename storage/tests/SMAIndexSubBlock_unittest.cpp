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
#include <cstring>
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
#include "storage/CompressedColumnStoreTupleStorageSubBlock.hpp"
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
typedef sma_internal::SMAPredicate SMAPredicate;
typedef sma_internal::Selectivity Selectivity;

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

  bool varchars_equal(TypedValue left, TypedValue right) {
    return ComparisonFactory::GetComparison(ComparisonID::kEqual)
        .compareTypedValuesChecked(left, TypeFactory::GetType(kVarChar, 8, false),
                                   right, TypeFactory::GetType(kVarChar, 8, false));
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

  ComparisonPredicate* generateStringComparisonPredicate(
      const ComparisonID comp,
      const attribute_id attribute,
      const string &literal) {
    ScalarAttribute *scalar_attribute = new ScalarAttribute(*relation_->getAttributeById(attribute));
    ScalarLiteral *scalar_literal = new ScalarLiteral(
        VarCharType::InstanceNonNullable(literal.size()).makeValue(
            literal.c_str(),
            literal.size() + 1).ensureNotReference(),
        VarCharType::InstanceNonNullable(literal.size()));
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
  vector<attribute_id> valid_attrs({0, 1, 2, 3, 4, 5, 6});
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
  EXPECT_FALSE(index_->requiresRebuild());

  // Reset will cause the Index to go through its delete routine.
  // Creating a block on the same memory should cause the index to retrieve
  // the previously written values.
  index_.reset(new SMAIndexSubBlock(*tuple_store_,
                                    *index_description_,
                                    false,
                                    index_memory_.get(),
                                    kIndexSubBlockSize));
  EXPECT_FALSE(index_->requiresRebuild());
}

TEST_F(SMAIndexSubBlockTest, TestRebuild) {
  createIndex({0, 2}, kIndexSubBlockSize);  // Index long, float type.
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
  // Entries should and must exist.
  ASSERT_TRUE(entry0 != nullptr && entry2 != nullptr);

  // Check entry validity.
  EXPECT_TRUE(entry0->min_entry.valid);
  EXPECT_TRUE(entry2->min_entry.valid);
  EXPECT_TRUE(entry0->max_entry.valid);
  EXPECT_TRUE(entry2->max_entry.valid);

  // Check min ids and values.
  EXPECT_EQ(0, entry0->min_entry.tuple);
  EXPECT_EQ(0, entry2->min_entry.tuple);
  EXPECT_TRUE(sma_test::longs_equal(entry0->min_entry.value,
                                    tuple_store_->getAttributeValueTyped(0, 0)));

  EXPECT_TRUE(sma_test::floats_equal(entry2->min_entry.value,
                                     tuple_store_->getAttributeValueTyped(0, 2)));

  // Check max ids and values.
  tuple_id max_id = (max - min)/step;
  EXPECT_EQ(max_id, entry0->max_entry.tuple);
  EXPECT_EQ(max_id, entry2->max_entry.tuple);
  EXPECT_TRUE(sma_test::longs_equal(entry0->max_entry.value,
                                    tuple_store_->getAttributeValueTyped(max_id, 0)));
  EXPECT_TRUE(sma_test::floats_equal(entry2->max_entry.value,
                                     tuple_store_->getAttributeValueTyped(max_id, 2)));

  // Check sums.
  EXPECT_TRUE(sma_test::longs_equal(entry0->sum, TypedValue(sum_0)));
  EXPECT_TRUE(sma_test::doubles_equal(entry2->sum, TypedValue(sum_2)));

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
  bool rebuild_status = index_->rebuild();
  ASSERT_TRUE(rebuild_status);

  SMAEntry* entry1 = getEntryForAttribute(1);
  EXPECT_TRUE(entry1->min_entry.valid);

  // Check min ids and values.
  tuple_id min_tuple = 1;
  EXPECT_EQ(min_tuple, entry1->min_entry.tuple);
  EXPECT_TRUE(sma_test::longs_equal(entry1->min_entry.value,
                                    tuple_store_->getAttributeValueTyped(min_tuple, 1)));

  // Check max ids and values.
  int num_tuples = (max - min)/step + 1;
  // The math figures out what the max tuple id is (sometimes the expected max will be null).
  tuple_id max_tuple = ((num_tuples - 1) % 4) == 0 ? num_tuples - 2 : num_tuples - 1;
  EXPECT_EQ(max_tuple, entry1->max_entry.tuple);
  EXPECT_TRUE(sma_test::longs_equal(entry1->max_entry.value,
                                    tuple_store_->getAttributeValueTyped(max_tuple, 1)));

  // Check sums.
  EXPECT_TRUE(sma_test::longs_equal(entry1->sum, TypedValue(sum_1)));

  // Check count.
  EXPECT_EQ(num_tuples, index_->getCount());
}

TEST_F(SMAIndexSubBlockTest, TestWithVariableLengthAttrs) {
  createIndex({4, 5, 6}, kIndexSubBlockSize);  // Nullable char, BigChar, VarChar.
  int min = 0, max = 1001;
  tuple_id max_id, min_id;

  std::string suffix("suffix");
  std::string max_str("");
  std::string min_str("Z");
  for (unsigned i = min; i < max; ++i) {
    tuple_id id = generateAndInsertTuple(i, false, suffix);

    // Keep track of the min/max strings entered.
    ostringstream string_value_buffer;
    string_value_buffer << i << suffix;
    if (string_value_buffer.str() < min_str) {
      min_str = string_value_buffer.str();
      min_id = id;
    }
    if (string_value_buffer.str() > max_str) {
      max_str = string_value_buffer.str();
      max_id = id;
    }
  }

  EXPECT_TRUE(index_->hasEntryForAttribute(4));
  EXPECT_TRUE(index_->hasEntryForAttribute(5));
  EXPECT_TRUE(index_->hasEntryForAttribute(6));
  EXPECT_TRUE(index_->rebuild());

  // Test attribute 4, a nullable 4 character char.
  SMAEntry* entry4 = getEntryForAttribute(4);
  EXPECT_EQ(kChar, entry4->type);
  EXPECT_EQ(4, entry4->attribute);

  // Min and Max values should be valid at this point.
  EXPECT_TRUE(entry4->max_entry.valid);
  EXPECT_TRUE(entry4->min_entry.valid);

  // Check min ids and values.
  EXPECT_EQ(min_id, entry4->min_entry.tuple);
  EXPECT_EQ(max_id, entry4->max_entry.tuple);
  EXPECT_TRUE(sma_test::chars_equal(
      entry4->min_entry.value,
      tuple_store_->getAttributeValueTyped(entry4->min_entry.tuple, 4)));

  EXPECT_TRUE(sma_test::chars_equal(
      entry4->max_entry.value,
      tuple_store_->getAttributeValueTyped(entry4->max_entry.tuple, 4)));

  // Test attribute 5, an 80 character char.
  SMAEntry* entry5 = getEntryForAttribute(5);
  EXPECT_EQ(kChar, entry5->type);
  EXPECT_EQ(5, entry5->attribute);

  // Min and Max values should be valid at this point.
  EXPECT_TRUE(entry5->max_entry.valid);
  EXPECT_TRUE(entry5->min_entry.valid);

  // Check min ids and values.
  EXPECT_EQ(min_id, entry5->min_entry.tuple);
  EXPECT_EQ(max_id, entry5->max_entry.tuple);
  EXPECT_TRUE(sma_test::chars_equal(
      entry5->min_entry.value,
      tuple_store_->getAttributeValueTyped(entry5->min_entry.tuple, 5)));

  EXPECT_TRUE(sma_test::chars_equal(
      entry5->max_entry.value,
      tuple_store_->getAttributeValueTyped(entry5->max_entry.tuple, 5)));

  // Test attribute 6, an 8 character varchar.
  SMAEntry* entry6 = getEntryForAttribute(6);
  EXPECT_EQ(kVarChar, entry6->type);
  EXPECT_EQ(6, entry6->attribute);

  // Min and Max values should be valid at this point.
  EXPECT_TRUE(entry6->max_entry.valid);
  EXPECT_TRUE(entry6->min_entry.valid);

  // Check min ids and values.
  EXPECT_EQ(min_id, entry6->min_entry.tuple);
  EXPECT_EQ(max_id, entry6->max_entry.tuple);
  EXPECT_TRUE(sma_test::varchars_equal(
      entry6->min_entry.value,
      tuple_store_->getAttributeValueTyped(entry6->min_entry.tuple, 6)));

  EXPECT_TRUE(sma_test::varchars_equal(
      entry6->max_entry.value,
      tuple_store_->getAttributeValueTyped(entry6->max_entry.tuple, 6)));

  // Try kicking the index out of memory and then getting the variable length
  // attributes back.
  index_.reset(new SMAIndexSubBlock(*tuple_store_,
                                    *index_description_,
                                    false,
                                    index_memory_.get(),
                                    kIndexSubBlockSize));
  ASSERT_FALSE(index_->requiresRebuild());

  // Ensure that the attributes are as they were before the rebuild process.
  SMAEntry* nentry6 = getEntryForAttribute(6);
  EXPECT_EQ(kVarChar, nentry6->type);
  EXPECT_EQ(6, nentry6->attribute);
  EXPECT_EQ(min_id, nentry6->min_entry.tuple);
  EXPECT_EQ(max_id, nentry6->max_entry.tuple);
  ASSERT_EQ(kVarChar, nentry6->max_entry.value.getTypeID());
  ASSERT_EQ(kVarChar, nentry6->min_entry.value.getTypeID());
  EXPECT_TRUE(sma_test::varchars_equal(
      nentry6->min_entry.value,
      tuple_store_->getAttributeValueTyped(nentry6->min_entry.tuple, 6)));
  EXPECT_TRUE(sma_test::varchars_equal(
      nentry6->max_entry.value,
      tuple_store_->getAttributeValueTyped(nentry6->max_entry.tuple, 6)));

  // Check count.
  EXPECT_EQ(max, index_->getCount());
}

// TODO(marc): finish this test. I've neglected it for now because the process of creating a compressed
// block is tedious.
TEST_F(SMAIndexSubBlockTest, TestWithCompressedColumnStore) {
  // Create a relation with just a single attribute, which will be compressed.
  relation_.reset(new CatalogRelation(NULL, "TestRelation"));
  CatalogAttribute *truncated_long_attr = new CatalogAttribute(relation_.get(),
                                                               "truncated_long_attr",
                                                               TypeFactory::GetType(kLong, false));
  ASSERT_EQ(0, relation_->addAttribute(truncated_long_attr));

  CatalogAttribute *compessed_string_attr = new CatalogAttribute(relation_.get(),
                                                                 "compressed_string_attr",
                                                                 TypeFactory::GetType(kVarChar, 80, false));
  ASSERT_EQ(1, relation_->addAttribute(compessed_string_attr));

  // Create a CompressedPackedRowStoreTupleStorageSubBlock.
  TupleStorageSubBlockDescription *tuple_store_description = new TupleStorageSubBlockDescription();
  tuple_store_description->set_sub_block_type(TupleStorageSubBlockDescription::COMPRESSED_COLUMN_STORE);
  tuple_store_description->SetExtension(
      CompressedColumnStoreTupleStorageSubBlockDescription::sort_attribute_id,
      0);
  for (attribute_id attr_id = 0; attr_id < 2; ++attr_id) {
    tuple_store_description->AddExtension(
        CompressedColumnStoreTupleStorageSubBlockDescription::compressed_attribute_id,
        attr_id);
  }

  ScopedBuffer compressed_tuple_store_memory(kIndexSubBlockSize);
  std::unique_ptr<CompressedColumnStoreTupleStorageSubBlock> compressed_tuple_store(
      new CompressedColumnStoreTupleStorageSubBlock(
          *relation_,
          *tuple_store_description,
          true,
          compressed_tuple_store_memory.get(),
          kIndexSubBlockSize));

  // Create an index on the compressed tuple store.
  IndexSubBlockDescription compressed_index_description;
  compressed_index_description.set_sub_block_type(IndexSubBlockDescription::SMA);
  compressed_index_description.AddExtension(SMAIndexSubBlockDescription::indexed_attribute_id, 0);
  compressed_index_description.AddExtension(SMAIndexSubBlockDescription::indexed_attribute_id, 1);

  index_memory_.reset(kIndexSubBlockSize);
  index_.reset(new SMAIndexSubBlock(*compressed_tuple_store,
                                    compressed_index_description,
                                    true,
                                    index_memory_.get(),
                                    kIndexSubBlockSize));
}

TEST_F(SMAIndexSubBlockTest, TestExtractComparison) {
  const attribute_id indexed_attr = 0;
  const int comparison_lit = 123;
  std::unique_ptr<ComparisonPredicate> predicate(
      generateNumericComparisonPredicate<LongType>(ComparisonID::kEqual, indexed_attr, comparison_lit));
  std::unique_ptr<SMAPredicate> smapredicate(SMAPredicate::ExtractSMAPredicate(*predicate));

  EXPECT_EQ(indexed_attr, smapredicate->attribute);
  EXPECT_EQ(ComparisonID::kEqual, smapredicate->comparison);
  EXPECT_EQ(comparison_lit, smapredicate->literal.getLiteral<std::int64_t>());

  // Test against a comparison which it might flip (less->greater).
  predicate.reset(generateNumericComparisonPredicate<LongType>(ComparisonID::kLess, indexed_attr, comparison_lit));
  smapredicate.reset(SMAPredicate::ExtractSMAPredicate(*predicate));

  EXPECT_EQ(indexed_attr, smapredicate->attribute);
  EXPECT_EQ(ComparisonID::kLess, smapredicate->comparison);
  EXPECT_EQ(comparison_lit, smapredicate->literal.getLiteral<std::int64_t>());

  // Make a comparison which it must flip.
  ScalarAttribute *scalar_attribute = new ScalarAttribute(*relation_->getAttributeById(indexed_attr));
  ScalarLiteral *scalar_literal
      = new ScalarLiteral(LongType::InstanceNonNullable().makeValue(&comparison_lit),
                          LongType::InstanceNonNullable());
  predicate.reset(new ComparisonPredicate(ComparisonFactory::GetComparison(ComparisonID::kGreater), scalar_literal, scalar_attribute));
  smapredicate.reset(SMAPredicate::ExtractSMAPredicate(*predicate));

  EXPECT_EQ(indexed_attr, smapredicate->attribute);
  EXPECT_EQ(ComparisonID::kLess, smapredicate->comparison);
  EXPECT_EQ(comparison_lit, smapredicate->literal.getLiteral<std::int64_t>());
}

TEST_F(SMAIndexSubBlockTest, TestGetSelectivity) {
  // Test with an inline type.
  long lsmallest = 0, lsmall = 100, lmedium = 1000, llarge = 10000, llargest = 100000;
  const TypedValue long_smallest = LongType::InstanceNonNullable().makeValue(&lsmallest);
  const TypedValue long_small = LongType::InstanceNonNullable().makeValue(&lsmall);
  const TypedValue long_medium = LongType::InstanceNonNullable().makeValue(&lmedium);
  const TypedValue long_large = LongType::InstanceNonNullable().makeValue(&llarge);
  const TypedValue long_largest = LongType::InstanceNonNullable().makeValue(&llargest);
  std::unique_ptr<UncheckedComparator> longs_equal(
      ComparisonFactory::GetComparison(ComparisonID::kEqual)
          .makeUncheckedComparatorForTypes(LongType::InstanceNonNullable(), LongType::InstanceNonNullable()));
  std::unique_ptr<UncheckedComparator> longs_less(
      ComparisonFactory::GetComparison(ComparisonID::kLess)
          .makeUncheckedComparatorForTypes(LongType::InstanceNonNullable(), LongType::InstanceNonNullable()));

  // Test with equals.
  EXPECT_EQ(Selectivity::kNone,
            sma_internal::getSelectivity(long_smallest, ComparisonID::kEqual,
                                         long_small, long_large,
                                         longs_equal.get(), longs_less.get()));
  EXPECT_EQ(Selectivity::kNone,
            sma_internal::getSelectivity(long_largest, ComparisonID::kEqual,
                                         long_small, long_large,
                                         longs_equal.get(), longs_less.get()));
  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_medium, ComparisonID::kEqual,
                                         long_small, long_large,
                                         longs_equal.get(), longs_less.get()));

  // Test with not equals.
  EXPECT_EQ(Selectivity::kUnknown,
            sma_internal::getSelectivity(long_smallest, ComparisonID::kNotEqual,
                                         long_small, long_large,
                                         longs_equal.get(), longs_less.get()));

  // Test with less.
  EXPECT_EQ(Selectivity::kAll,
            sma_internal::getSelectivity(long_large, ComparisonID::kLess,
                                         long_smallest, long_medium,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_large, ComparisonID::kLess,
                                         long_smallest, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_largest, ComparisonID::kLess,
                                         long_smallest, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kNone,
            sma_internal::getSelectivity(long_medium, ComparisonID::kLess,
                                         long_medium, long_largest,
                                         longs_equal.get(), longs_less.get()));

  // Test with less equals.
  EXPECT_EQ(Selectivity::kAll,
            sma_internal::getSelectivity(long_largest, ComparisonID::kLessOrEqual,
                                         long_smallest, long_large,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kAll,
            sma_internal::getSelectivity(long_largest, ComparisonID::kLessOrEqual,
                                         long_medium, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_large, ComparisonID::kLessOrEqual,
                                         long_smallest, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_medium, ComparisonID::kLessOrEqual,
                                         long_medium, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kNone,
            sma_internal::getSelectivity(long_small, ComparisonID::kLessOrEqual,
                                         long_medium, long_largest,
                                         longs_equal.get(), longs_less.get()));

  // Test with greater.
  EXPECT_EQ(Selectivity::kAll,
            sma_internal::getSelectivity(long_smallest, ComparisonID::kGreater,
                                         long_small, long_large,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_large, ComparisonID::kGreater,
                                         long_smallest, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_smallest, ComparisonID::kGreater,
                                         long_smallest, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kNone,
            sma_internal::getSelectivity(long_medium, ComparisonID::kGreater,
                                         long_smallest, long_medium,
                                         longs_equal.get(), longs_less.get()));

  // Test with greater or equals.
  EXPECT_EQ(Selectivity::kAll,
            sma_internal::getSelectivity(long_smallest, ComparisonID::kGreaterOrEqual,
                                         long_small, long_large,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kAll,
            sma_internal::getSelectivity(long_medium, ComparisonID::kGreaterOrEqual,
                                         long_medium, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_large, ComparisonID::kGreaterOrEqual,
                                         long_smallest, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(long_largest, ComparisonID::kGreaterOrEqual,
                                         long_medium, long_largest,
                                         longs_equal.get(), longs_less.get()));

  EXPECT_EQ(Selectivity::kNone,
            sma_internal::getSelectivity(long_largest, ComparisonID::kGreaterOrEqual,
                                         long_small, long_large,
                                         longs_equal.get(), longs_less.get()));

  // Now test with variable length attributes.
  vector<string> str_vals({"avocado", "cruciferous", "fructose", "sauerkraut", "zeppelini"});
  vector<TypedValue> str_tvals;
  for (string &str : str_vals) {
    str_tvals.push_back(
        VarCharType::InstanceNonNullable(str.size()).makeValue(
            str.c_str(),
            str.size() + 1));
    str_tvals.back().ensureNotReference();
  }
  std::unique_ptr<UncheckedComparator> str_equals(
      ComparisonFactory::GetComparison(ComparisonID::kEqual)
          .makeUncheckedComparatorForTypes(VarCharType::InstanceNonNullable(16), VarCharType::InstanceNonNullable(16)));
  std::unique_ptr<UncheckedComparator> str_less(
      ComparisonFactory::GetComparison(ComparisonID::kLess)
          .makeUncheckedComparatorForTypes(VarCharType::InstanceNonNullable(16), VarCharType::InstanceNonNullable(16)));

  // Test with equals.
  EXPECT_EQ(Selectivity::kNone,
            sma_internal::getSelectivity(str_tvals[4], ComparisonID::kEqual,
                                         str_tvals[0], str_tvals[3],
                                         str_equals.get(), str_less.get()));
  EXPECT_EQ(Selectivity::kNone,
            sma_internal::getSelectivity(str_tvals[0], ComparisonID::kEqual,
                                         str_tvals[1], str_tvals[3],
                                         str_equals.get(), str_less.get()));
  EXPECT_EQ(Selectivity::kSome,
            sma_internal::getSelectivity(str_tvals[1], ComparisonID::kEqual,
                                         str_tvals[0], str_tvals[2],
                                         str_equals.get(), str_less.get()));

}

TEST_F(SMAIndexSubBlockTest, TestEvaluatePredicateCost) {
  // Create the index on all the attributes.
  createIndex({0, 1, 2, 3, 4, 5}, kIndexSubBlockSize);
  const int min = 250, max = 500;
  for (unsigned i = min; i <= max; ++i) {
    if (i % 10 == 0) {
      generateAndInsertTuple(i, true, "suffix");
    } else {
      generateAndInsertTuple(i, false, "suffix");
    }    
  }
  index_->rebuild();

  // Test with inline values, returning both possible value types.
  std::unique_ptr<ComparisonPredicate> predicate(
      generateNumericComparisonPredicate<LongType>(ComparisonID::kLess, 0, min));
  predicate_cost_t eval_cost = index_->estimatePredicateEvaluationCost(*predicate);
  EXPECT_EQ(predicate_cost::kConstantTime, eval_cost);

  predicate.reset(
      generateNumericComparisonPredicate<LongType>(ComparisonID::kLess, 0, max + 1));
  eval_cost = index_->estimatePredicateEvaluationCost(*predicate);
  EXPECT_EQ(predicate_cost::kConstantTime, eval_cost);

  predicate.reset(
      generateNumericComparisonPredicate<LongType>(ComparisonID::kLess, 0, ((max - min)/2) + min));
  eval_cost = index_->estimatePredicateEvaluationCost(*predicate);
  EXPECT_EQ(predicate_cost::kInfinite, eval_cost);

  // Test with out of line values.
  predicate.reset(
      generateStringComparisonPredicate(ComparisonID::kLess, 5, " "));
  eval_cost = index_->estimatePredicateEvaluationCost(*predicate);
  EXPECT_EQ(predicate_cost::kConstantTime, eval_cost);

  predicate.reset(
      generateStringComparisonPredicate(ComparisonID::kGreater, 5, " "));
  eval_cost = index_->estimatePredicateEvaluationCost(*predicate);
  EXPECT_EQ(predicate_cost::kConstantTime, eval_cost);

  predicate.reset(
      generateStringComparisonPredicate(ComparisonID::kEqual, 5, "100suffix"));
  eval_cost = index_->estimatePredicateEvaluationCost(*predicate);
  EXPECT_EQ(predicate_cost::kInfinite, eval_cost);

  // Test with an inconsistent index.
  tuple_id new_tuple = generateAndInsertTuple(0x1337, false, "suffix");
  predicate.reset(generateNumericComparisonPredicate<LongType>(ComparisonID::kLess, 0, min));
  EXPECT_TRUE(index_->addEntry(new_tuple));
  EXPECT_TRUE(index_->requiresRebuild());
  EXPECT_EQ(predicate_cost::kInfinite, index_->estimatePredicateEvaluationCost(*predicate));
}

TEST_F(SMAIndexSubBlockTest, TestGetMatchesForPredicate) {
  // Create the index on all the attributes.
  createIndex({0, 1, 2, 3, 4, 5}, kIndexSubBlockSize);
  const int min = 250, max = 500;
  for (unsigned i = min; i <= max; ++i) {
    if (i % 10 == 0) {
      generateAndInsertTuple(i, true, "suffix");
    } else {
      generateAndInsertTuple(i, false, "suffix");
    }    
  }
  index_->rebuild();

  // Test with inline values.
  // Check that no tuples have been returned.
  std::unique_ptr<ComparisonPredicate> predicate(
      generateNumericComparisonPredicate<LongType>(ComparisonID::kLess, 0, min));
  std::unique_ptr<TupleIdSequence> result(index_->getMatchesForPredicate(*predicate, nullptr));
  EXPECT_EQ(tuple_store_->getMaxTupleID() + 1, result->length());
  EXPECT_EQ(0, result->numTuples());  

  // // Check that all tuples have been returned.
  // TODO: fix bug which causes this to crash.
  // predicate.reset(
  //     generateNumericComparisonPredicate<LongType>(ComparisonID::kLess, 0, max + 1));
  // result.reset(index_->getMatchesForPredicate(*predicate, nullptr));
  // EXPECT_EQ(tuple_store_->getMaxTupleID() + 1, result->length());
  // EXPECT_EQ(tuple_store_->getMaxTupleID() + 1, result->numTuples());

  predicate.reset(
      generateNumericComparisonPredicate<LongType>(ComparisonID::kLess, 0, ((max - min)/2) + min));
  // SMA should not be used in this case, it cannot answer this query.
  EXPECT_DEATH(index_->getMatchesForPredicate(*predicate, nullptr), "SMAIndex failed to evaluate predicate");

  // Test with out of line values.

}


}  // namespace quickstep