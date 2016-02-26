/**
 *   Copyright 2011-2015 Quickstep Technologies LLC.
 *   Copyright 2015-2016 Pivotal Software, Inc.
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

#include "relational_operators/SelectOperator.hpp"

#include <vector>

#include "catalog/CatalogDatabase.hpp"
#include "catalog/CatalogRelationSchema.hpp"
#include "query_execution/QueryContext.hpp"
#include "query_execution/WorkOrdersContainer.hpp"
#include "storage/InsertDestination.hpp"
#include "storage/StorageBlock.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "storage/StorageManager.hpp"

#include "glog/logging.h"

#include "tmb/id_typedefs.h"

namespace quickstep {

class Predicate;

bool SelectOperator::getAllWorkOrders(
    WorkOrdersContainer *container,
    const tmb::client_id foreman_client_id,
    tmb::MessageBus *bus) {
  if (input_relation_is_stored_) {
    if (!started_) {
      for (const block_id input_block_id : input_relation_block_ids_) {
        container->addNormalWorkOrder(
            new SelectWorkOrder(input_relation_.getID(),
                                output_destination_index_,
                                predicate_index_,
                                selection_index_,
                                *simple_selection_,
                                simple_projection_,
                                input_block_id),
            op_index_);
      }
      started_ = true;
    }
    return started_;
  } else {
    while (num_workorders_generated_ < input_relation_block_ids_.size()) {
      container->addNormalWorkOrder(
          new SelectWorkOrder(
              input_relation_.getID(),
              output_destination_index_,
              predicate_index_,
              selection_index_,
              *simple_selection_,
              simple_projection_,
              input_relation_block_ids_[num_workorders_generated_]),
          op_index_);
      ++num_workorders_generated_;
    }
    return done_feeding_input_relation_;
  }
}

void SelectWorkOrder::execute(QueryContext *query_context,
                              CatalogDatabase *database,
                              StorageManager *storage_manager) {
  DCHECK(query_context != nullptr);
  DCHECK(database != nullptr);
  DCHECK(storage_manager != nullptr);

  BlockReference block(
      storage_manager->getBlock(input_block_id_,
                                *database->getRelationById(input_relation_id_)));

  InsertDestination *output_destination =
      query_context->getInsertDestination(output_destination_index_);
  DCHECK(output_destination != nullptr);

  const Predicate *predicate = query_context->getPredicate(predicate_index_);

  if (simple_projection_) {
    block->selectSimple(simple_selection_,
                        predicate,
                        output_destination);
  } else {
    block->select(query_context->getScalarGroup(selection_index_),
                  predicate,
                  output_destination);
  }
}

}  // namespace quickstep
