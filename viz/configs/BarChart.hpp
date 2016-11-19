/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 **/

#ifndef QUICKSTEP_VIZ_CONFIGS_BAR_CHART_HPP_
#define QUICKSTEP_VIZ_CONFIGS_BAR_CHART_HPP_

#include "catalog/CatalogTypedefs.hpp"
#include "utility/Macros.hpp"
#include "viz/configs/VizConfig.hpp"
#include "viz/VizContext.hpp"

#include "json.hpp"

namespace quickstep {

class CatalogRelation;
class StorageManager;

namespace viz {

/** \addtogroup Viz
 *  @{
 */

class BarChart : public VizConfig {
 public:
  BarChart(const attribute_id dimension_attr_id,
           const attribute_id measure_attr_id,
           const VizContextPtr &context)
      : VizConfig(context),
        dimension_attr_id_(dimension_attr_id),
        measure_attr_id_(measure_attr_id) {}

  ~BarChart() override {}

  nlohmann::json toJSON() override {
    nlohmann::json data = nlohmann::json::array();
    data.push_back(copyColumn(dimension_attr_id_));
    data.push_back(copyColumn(measure_attr_id_));

    nlohmann::json ret;
    ret["type"] = "BarChart";
    ret["trace"] = copyTrace();
    ret["schema"] = copySchema({dimension_attr_id_, measure_attr_id_});
    ret["data"] = data;

    return ret;
  }

 private:
  const attribute_id dimension_attr_id_;
  const attribute_id measure_attr_id_;

  DISALLOW_COPY_AND_ASSIGN(BarChart);
 };

/** @} */

}  // namespace viz
}  // namespace quickstep

#endif  // QUICKSTEP_VIZ_CONFIGS_BAR_CHART_HPP_
