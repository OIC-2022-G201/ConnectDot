// @PhysicsManifold.h
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#pragma once
#include <cstdint>

#include "PhysicsCommon.h"
#include "PhysicsVector2.h"

namespace base_engine::physics {
class PhysicsShape;
class PhysicsCircleShape;


constexpr uint8_t Physics_nullFeature = UCHAR_MAX;

/// The features that intersect to form the contact point
/// This must be 4 bytes or less.
struct PhysicsContactFeature {
  enum Type { e_vertex = 0, e_face = 1 };

  uint8_t indexA;  ///< Feature index on shapeA
  uint8_t indexB;  ///< Feature index on shapeB
  uint8_t typeA;   ///< The feature type on shapeA
  uint8_t typeB;   ///< The feature type on shapeB
};

/// Contact ids to facilitate warm starting.
union PhysicsContactID {
  PhysicsContactFeature cf;
  uint32_t key;  ///< Used to quickly compare contact ids.
};

/// A manifold point is a contact point belonging to a contact
/// manifold. It holds details related to the geometry and dynamics
/// of the contact points.
/// The local point usage depends on the manifold type:
/// -e_circles: the local center of circleB
/// -e_faceA: the local center of cirlceB or the clip point of polygonB
/// -e_faceB: the clip point of polygonA
/// This structure is stored across time steps, so we keep it small.
/// Note: the impulses are used for internal caching and may not
/// provide reliable contact forces, especially for high speed collisions.
struct PhysicsManifoldPoint {
  PVec2 localPoint;     ///< usage depends on manifold type
  float normalImpulse;   ///< the non-penetration impulse
  float tangentImpulse;  ///< the friction impulse
  PhysicsContactID id;  ///< uniquely identifies a contact point between two shapes
};

struct PhysicsManifold {
  enum class Type { e_circles, e_faceA, e_faceB };

  PhysicsManifoldPoint points[Physics_maxManifoldPoints];  ///< the points of contact
  PVec2 localNormal;                             ///< not use for Type::e_points
  PVec2 localPoint;  ///< usage depends on manifold type
  Type type;
  int32_t pointCount;  ///< the number of manifold points
};
}  // namespace base_engine::physics