// @file SendManifold.h
// @brief
// @author ICE
// @date 2022/08/20
//
// @details

#pragma once
#include "Manifold.h"
namespace base_engine {

struct SendManifold {
  SendManifold(class CollisionComponent* collision_a,
               class CollisionComponent* collision_b,
               const physics::Manifold& manifold)
      : collision_a(collision_a),
        collision_b(collision_b),
        manifold(manifold) {}

  CollisionComponent* collision_a;
  CollisionComponent* collision_b;
  const physics::Manifold& manifold;
};
}  // namespace base_engine