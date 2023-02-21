// @RoutePart.h
// @brief
// @author ICE
// @date 2023/02/21
// 
// @details

#pragma once
#include <vector>
#include "VectorFrozen.h"
#include "Frozen.h"

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
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(routes_, type_int_);
  }
};
}  // namespace stage::part