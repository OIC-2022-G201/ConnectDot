// @EnemyMoveRail.h
// @brief
// @author ICE
// @date 2023/02/23
//
// @details

#pragma once
#include "Component.h"
#include "RoutePart.h"

class EnemyMoveRail final : base_engine::Component {
 public:
  explicit EnemyMoveRail(base_engine::Actor* owner) : Component(owner) {}
  void SetRoute(const std::vector<base_engine::Vector2>& route) {
    route_ = route;
  }
  void SetType(const stage::part::RouteType type);
  void Update() override;
private:
  using RouteVector = std::vector<base_engine::Vector2>;
  std::vector<base_engine::Vector2> route_;
  stage::part::RouteType route_type_ = stage::part::RouteType::kRoundTrip;
  std::function<base_engine::Vector2(const RouteVector&,int*)> current_process_update_;
  int current_process_ = 0;
  bool is_move_ = false;
};
