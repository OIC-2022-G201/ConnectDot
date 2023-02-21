// @ChangeImageNamePart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include "Frozen.h"
#include "StringFrozen.h"   
#include <string>

namespace stage::part {
class ChangeImageNamePart {
  std::string image_;
 public:
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    int k = 1;
    archive(k,image_);
  }
};
}  // namespace stage::part