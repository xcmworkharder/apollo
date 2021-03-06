/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 * @brief Define the trajectory_imitation_inference class
 */

#pragma once

#include <string>

#include "modules/planning/learning_based/model_inference/model_inference.h"
#include "torch/extension.h"
#include "torch/script.h"

namespace apollo {
namespace planning {

class TrajectoryConvRnnInference : public ModelInference {
 public:
  /**
   * @brief Constructor
   */
  explicit TrajectoryConvRnnInference(
      const LearningModelInferenceTaskConfig& config);

  /**
   * @brief Destructor
   */
  virtual ~TrajectoryConvRnnInference() = default;

  /**
   * @brief Get the name of model inference
   */
  std::string GetName() override { return "TRAJECTORY_CONV_RNN_INFERENCE"; };

  /**
   * @brief load a learned model
   */
  bool LoadModel(const LearningModelInferenceTaskConfig& config) override;

  /**
   * @brief inference a learned model
   * @param learning_data_frame input and output intermediate for inference
   */
  bool Inference(LearningDataFrame* learning_data_frame) override;

 private:
  torch::jit::script::Module model_;
  torch::Device device_;
};

}  // namespace planning
}  // namespace apollo
