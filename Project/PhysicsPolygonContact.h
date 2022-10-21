// @PhysicsPolygonContact.h
// @brief
// @author ICE
// @date 2022/10/20
//
// @details

#pragma once
#include "PhysicsContact.h"
#include "PhysicsFixture.h"

namespace base_engine::physics {
class PhysicsPolygonContact : public PhysicsContact {
 public:
  static PhysicsContact* Create(PhysicsFixture* fixtureA, int32 indexA,
                                PhysicsFixture* fixtureB, int32 indexB,
                                PhysicsBlockAllocator* allocator);
  static void Destroy(PhysicsContact* contact,
                      PhysicsBlockAllocator* allocator);

  PhysicsPolygonContact(PhysicsFixture* fixtureA, PhysicsFixture* fixtureB);

  ~PhysicsPolygonContact() {}

  void Evaluate(b2Manifold* manifold, const b2Transform& xfA,
                const b2Transform& xfB) override;
};
}  // namespace base_engine::physics
