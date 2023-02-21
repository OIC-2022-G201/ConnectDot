// @DirPart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"

namespace stage::part {
enum class Dir { kLeft, kRight };
class DirPart {
  int dir_int_;

 public:
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(dir_int_);
  }

  Dir GetDir() { return static_cast<Dir>(dir_int_); }
};
}  // namespace stage::part