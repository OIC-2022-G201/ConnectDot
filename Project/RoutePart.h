// @RoutePart.h
// @brief
// @author ICE
// @date 2023/02/21
//
// @details

#pragma once
#include <vector>

#include "Frozen.h"
#include "VectorFrozen.h"

namespace stage::part {
enum class RouteType {
  kRoundTrip,  //往復
  kLoop,       //ループ
  kOneWay      //片道
};
class RoutePart {
  std::vector<int> routes_;
  int type_int_;

 public:
  [[nodiscard]] std::vector<base_engine::Vector2> Route() const {
    std::vector<base_engine::Vector2> result;
    for (int i = 0; i < routes_.size() - 1; i += 2) {
      base_engine::Vector2 pos;

      pos.x = routes_[i];
      pos.y = routes_[i + 1];
      result.emplace_back(pos);
    }
    return result;
  }

  RouteType RouteType() const {
    return static_cast<part::RouteType>(type_int_);
  }
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(routes_);
    type_int_ = routes_.back();
  }
};
}  // namespace stage::part