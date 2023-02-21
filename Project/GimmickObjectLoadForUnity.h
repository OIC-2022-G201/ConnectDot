// @GimmickObjectLoadForUnity.h
// @brief
// @author ICE
// @date 2023/02/22
//
// @details

#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include <variant>

#include "Actor.h"
#include "Frozen.h"
#include "Part.h"
struct GimmickObjectParameter {
  std::string name;
  int x;
  int y;
  int part_count;
  int color_type;
  std::vector<stage::part::PartVariant> parts;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(name, x, y, part_count, color_type);
  }
};
class GimmickObjectLoadForUnity {
 public:
  GimmickObjectParameter object_;
  void SetPart(base_engine::Actor* actor, std::filesystem::path path);
  GimmickObjectParameter GenerateObject(std::filesystem::path path);
};
