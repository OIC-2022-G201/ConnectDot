// @ElectricAreaPart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"

namespace stage::part {

class ElectricAreaPart {
  float radius_;

 public:
  float GetRadius() const { return radius_; }
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    int k = 1;
    archive(k, radius_);
  }
};
}  // namespace stage::part