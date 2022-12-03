// @ContactRayCastCallBack.h
// @brief
// @author ICE
// @date 2022/12/02
//
// @details

#pragma once
#include <optional>

#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "PhysicsFixture.h"
#include "PhysicsWorldCallBack.h"

namespace base_engine::physics {
class RayCastAnyCallback final
    : public base_engine::physics::PhysicsRayCastCallback {
 public:
  RayCastAnyCallback(const std::bitset<kCollisionFilterSize>& layer =
                         CollisionLayer::Layer::kNone)
      : hit_(false), point_(), normal_(), target_layer_(layer) {}

  float ReportFixture(PhysicsFixture* fixture, const PVec2& point,
                      const PVec2& normal, float fraction) override {
    if ((target_layer_ & fixture->collision_->GetObjectFilter()) != 0) {
      hit_ = true;
      point_ = point;
      normal_ = normal;
      fixture_ = fixture;
      return 0.0f;
    }
    return fraction;
  }
  PhysicsFixture* fixture_ = nullptr;
  bool hit_;
  PVec2 point_;
  PVec2 normal_;
  std::bitset<kCollisionFilterSize> target_layer_;
};
}  // namespace base_engine::physics