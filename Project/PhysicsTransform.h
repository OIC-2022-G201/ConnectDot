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
struct b2Transform {
  /// The default constructor does nothing.
  b2Transform() = default;

  /// Initialize using a position vector and a rotation.
  b2Transform(const PVec2& position, const PRot& rotation)
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
