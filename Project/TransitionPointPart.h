// @TransitionPointPart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"
#include "GridPosition.h"

namespace stage::part {
class TransitionPointPart {
  int point_x_;
  int point_y_;

 public:
  GridPosition GetPos() const { return {point_x_, point_y_}; }
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    int k = 2;
    archive(k,point_x_, point_y_);
  }
};
}  // namespace stage::part
