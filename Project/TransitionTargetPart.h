// @TransitionTargetPart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"

namespace stage::part {

class TransitionTargetPart {
  std::string right_;
  std::string left_;
 public:
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(right_, left_);
  }
};
}  // namespace stage::part