// @BeaconStackPart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"
namespace stage::part {

class BeaconStackPart {
  int max_beacon_;
  int strengthen_count_;

 public:
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(max_beacon_, strengthen_count_);
  }
};
}  // namespace stage::part