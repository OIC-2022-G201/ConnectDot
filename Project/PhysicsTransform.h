// @PhysicsTransform.h
// @brief
// @author かき氷氷味
// @date 2022/10/16
//
// @details

#pragma once
#include "PhysicsRotate.h"
#include "PhysicsVector2.h"

namespace base_engine::physics {
struct PhysicsTransform {
  /// The default constructor does nothing.
  PhysicsTransform() = default;

  /// Initialize using a position vector and a rotation.
  PhysicsTransform(const PVec2& position, const PRot& rotation)
      : p(position), q(rotation) {}

  /// Set this to the identity transform.
  void SetIdentity() {
    p.SetZero();
    q.SetIdentity();
  }

  /// Set this based on the position and angle.
  void Set(const PVec2& position, float angle) {
    p = position;
    q.Set(angle);
  }

  PVec2 p;
  PRot q;
};
}  // namespace base_engine::physics
