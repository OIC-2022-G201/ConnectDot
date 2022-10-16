// @PhysicsRotate.h
// @brief
// @author かき氷氷味
// @date 2022/10/16
//
// @details

#pragma once
#include <cmath>

#include "PhysicsVector2.h"

namespace base_engine::physics {
template <typename _Floating>
struct PhysicsRotate {
  PhysicsRotate() = default;

  /// Initialize from an angle in radians
  explicit constexpr PhysicsRotate(const _Floating angle) { Set(angle); }

  /// Set using an angle in radians.
  constexpr void Set(const _Floating angle) {
    s = std::sin(angle);
    c = std::cos(angle);
  }

  /// Set to the identity rotation
  constexpr void SetIdentity() {
    s = 0.0f;
    c = 1.0f;
  }

  /// Get the angle in radians
  [[nodiscard]] constexpr float GetAngle() const { return std::atan2(s, c); }

  /// Get the x-axis
  [[nodiscard]] constexpr PVec2 GetXAxis() const { return {c, s}; }

  /// Get the y-axis
  [[nodiscard]] constexpr PVec2 GetYAxis() const { return {-s, c}; }

  /// Sine and cosine
  _Floating s, c;
};

using PRot = PhysicsRotate<float>;
}  // namespace base_engine::physics
