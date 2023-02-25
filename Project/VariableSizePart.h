// @VariableSizePart.h
// @brief
// @author ICE
// @date 2023/02/24
//
// @details

#pragma once
#include "Frozen.h"
namespace stage::part {
enum class VariableSizeType { kMiddle, kLeft, kRight };
class VariableSizePart {
  int type;

 public:
  VariableSizeType GetType() const {
    return static_cast<VariableSizeType>(type);
  }

  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    int k = 2;
    archive(k, type);
  }
};
}  // namespace stage::part