// @GimmickTargetPart.h
// @brief
// @author ICE
// @date 2023/02/21
// 
// @details

#pragma once
#include <vector>
#include "StringFrozen.h"
#include "Frozen.h"

namespace stage::part {
class GimmickTargetPart {
  std::vector<std::string> targets_;
 public:
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(targets_);
  }
};
}  // namespace stage::part