// @PhysicsWorldCallBack.h
// @brief
// @author ICE
// @date 2022/11/02
//
// @details

#pragma once
#include "PhysicsVector2.h"

namespace base_engine::physics {
class PhysicsFixture;

/// Callback class for AABB queries.
/// See b2World::Query
class PhysicsQueryCallback {
 public:
  virtual ~PhysicsQueryCallback() {}

  /// Called for each fixture found in the query AABB.
  /// @return false to terminate the query.
  virtual bool ReportFixture(PhysicsFixture* fixture) = 0;
};

/// Callback class for ray casts.
/// See b2World::RayCast
class PhysicsRayCastCallback {
 public:
  virtual ~PhysicsRayCastCallback() {}

  /// Called for each fixture found in the query. You control how the ray cast
  /// proceeds by returning a float:
  /// return -1: ignore this fixture and continue
  /// return 0: terminate the ray cast
  /// return fraction: clip the ray to this point
  /// return 1: don't clip the ray and continue
  /// @param fixture the fixture hit by the ray
  /// @param point the point of initial intersection
  /// @param normal the normal vector at the point of intersection
  /// @param fraction the fraction along the ray at the point of intersection
  /// @return -1 to filter, 0 to terminate, fraction to clip the ray for
  /// closest hit, 1 to continue
  virtual float ReportFixture(PhysicsFixture* fixture, const PVec2& point,
                              const PVec2& normal, float fraction) = 0;
};

}  // namespace base_engine::physics