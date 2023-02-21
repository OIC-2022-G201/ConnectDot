// @EmptyPart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"
namespace stage::part {
class EmptyPart {
  int empty;
 public:
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(empty);
  }
};
}  // namespace stage
