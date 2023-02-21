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
  std::string GetRight() const { return right_; }
  std::string GetLeft() const { return left_; }
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    int k = 2;
    archive(k, right_, left_);
  }
};
}  // namespace stage::part