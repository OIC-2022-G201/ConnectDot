// @TransitionPointPart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"

namespace stage::part {
class TransitionPointPart {
  int point_x_;
  int point_y_;
 public:
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(point_x_, point_y_);
  }
};
}  // namespace stage::part
