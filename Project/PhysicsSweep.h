// @PhysicsSweep.h
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#pragma once
#include <numbers>

#include "PhysicsMathUtility.h"
#include "PhysicsTransform.h"
#include "PhysicsVector2.h"

namespace base_engine::physics {

struct PhysicsSweep {
  PhysicsSweep() = default;

  /// Get the interpolated transform at a specific time.
  /// @param transform the output transform
  /// @param beta is a factor in [0,1], where 0 indicates alpha0.
  void GetTransform(PhysicsTransform* xf, float beta) const {
    xf->p = (1.0f - beta) * c0 + beta * c;
    float angle = (1.0f - beta) * a0 + beta * a;
    xf->q.Set(angle);

    // Shift to origin
    xf->p -= PhysicsMul(xf->q, localCenter);
  }

  /// Advance the sweep forward, yielding a new initial state.
  /// @param alpha the new initial time.
  void Advance(float alpha) {
    float beta = (alpha - alpha0) / (1.0f - alpha0);
    c0 += beta * (c - c0);
    a0 += beta * (a - a0);
    alpha0 = alpha;
  }

  /// Normalize the angles.
  void Normalize()
  {
    float twoPi = 2.0f * std::numbers::pi_v<float>;
    float d = twoPi * std::floorf(a0 / twoPi);
    a0 -= d;
    a -= d;
  }

  PVec2 localCenter;  ///< local center of mass position
  PVec2 c0, c;        ///< center world positions
  float a0, a;        ///< world angles

  /// Fraction of the current time step in the range [0,1]
  /// c0 and a0 are the positions at alpha0.
  float alpha0;
};
}  // namespace base_engine::physics