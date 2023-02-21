// @RectAreaPart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"

namespace stage::part {
class RectAreaPart {
  float x_;
  float y_;
  float width_;
  float height_;

 public:
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    int k = 4;
    archive(k,x_,y_,width_,height_);
  }
};
}  // namespace stage::part
