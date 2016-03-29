/**
 *   Copyright 2016, Quickstep Research Group, Computer Sciences Department,
 *     University of Wisconsin—Madison.
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

#include "catalog/IndexScheme.hpp"

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "catalog/Catalog.pb.h"
#include "storage/IndexSubBlockDescriptionFactory.hpp"
#include "storage/StorageBlockLayout.pb.h"

#include "glog/logging.h"

namespace quickstep {

bool IndexScheme::ProtoIsValid(const serialization::IndexScheme &proto) {
  // Check that proto is fully initialized.
  if (!proto.IsInitialized()) {
    return false;
  }

  // Check that each index entry contains initialized valid index descriptions.
  for (int i = 0; i < proto.index_entries_size(); ++i) {
    const serialization::IndexScheme_IndexEntry &index_entry = proto.index_entries(i);
    for (int j = 0; j < index_entry.index_description_size(); ++j) {
      const IndexSubBlockDescription &index_description = index_entry.index_description(j);
      if (!IndexSubBlockDescriptionFactory::ProtoIsValid(index_description)) {
        return false;
      }
    }
  }
  return true;
}

IndexScheme* IndexScheme::ReconstructFromProto(const serialization::IndexScheme &proto) {
  DCHECK(ProtoIsValid(proto))
    << "Attempted to create IndexScheme from an invalid proto description:\n"
    << proto.DebugString();

  std::unique_ptr<IndexScheme> index_scheme(new IndexScheme());

  for (int index_num = 0; index_num < proto.index_entries_size(); ++index_num) {
    const serialization::IndexScheme_IndexEntry &index_entry = proto.index_entries(index_num);
    std::vector<IndexSubBlockDescription> index_descriptions;
    for (int i = 0; i < index_entry.index_description_size(); ++i) {
      index_descriptions.emplace_back(index_entry.index_description(i));
    }
    // Make sure that index with same name does not already exist.
    DCHECK(index_scheme->index_map_.find(index_entry.index_name())
           == index_scheme->index_map_.end())
        << "Attempted to create IndexScheme from proto with duplicate index names.";
    // Store the index_name and corresponding list of index descriptions in map.
    index_scheme->index_map_.emplace(index_entry.index_name(), std::move(index_descriptions));
  }
  return index_scheme.release();
}

serialization::IndexScheme IndexScheme::getProto() const {
  serialization::IndexScheme proto;
  // Set the entries of the index scheme.
  for (auto cit = index_map_.cbegin(); cit != index_map_.cend(); ++cit) {
    // Create an index entry.
    serialization::IndexScheme_IndexEntry *index_entry = proto.add_index_entries();

    // Populate the details of the index entry.
    index_entry->set_index_name(cit->first);
    const std::vector<IndexSubBlockDescription> &index_descriptions = cit->second;
    for (auto index_description_it = index_descriptions.begin();
         index_description_it != index_descriptions.end();
         ++index_description_it) {
      // Add each index description to the index entry.
      index_entry->add_index_description()->MergeFrom(*index_description_it);
    }
  }
  return proto;
}

}  // namespace quickstep
