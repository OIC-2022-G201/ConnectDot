// @LoadObjectParameter.h
// @brief
// @author ICE
// @date 2022/11/18
// 
// @details

#pragma once
#include "Point2dFrozen.h"
#include "StringFrozen.h"
#include "VariantFrozen.h"
#include "VectorFrozen.h"

template <class T, class Ta>
struct TagWrap {
  T value;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(value);
  }
  using TagType = Ta;
  using ValueType = T;
};
struct AssetID {
  std::string uuid;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(uuid);
  }
};

struct LoadObject {
  using ObjectSize = TagWrap<Point2I, struct ObjectSizeTag>;
  using Transform = TagWrap<Point2I, struct TransformTag>;
  using Prefab = TagWrap<AssetID, struct PrefabTag>;
  using VariantT = std::variant<bool, int, float, Point2I, Point2F, std::string,
                                AssetID, Transform, ObjectSize, Prefab>;
  std::vector<VariantT> parameters;
  std::string name;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(name, parameters);
  }
};