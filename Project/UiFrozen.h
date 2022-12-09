// @UiFrozen.h
// @brief
// @author ICE
// @date 2022/12/09
//
// @details

#pragma once
#include <string>
#include <variant>

#include "Frozen.h"
#include "StringFrozen.h"
struct ImageFrozenPack {
  float x, y;
  std::string path;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(x, y, path);
  }
};

struct ButtonFrozenPack {
  float x, y;
  std::string path;
  int tx, ty;
  std::string event_name;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(x, y, path, tx, ty, event_name);
  }
};

using PackageVariant = std::variant<ImageFrozenPack, ButtonFrozenPack>;
