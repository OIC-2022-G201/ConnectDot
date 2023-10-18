#include "PhysicsPolygonContact.h"

#include "PhysicsBlockAllocator.h"
namespace base_engine::physics {
PhysicsContact* PhysicsPolygonContact::Create(
    PhysicsFixture* fixtureA, int32 indexA, PhysicsFixture* fixtureB,
    int32 indexB, PhysicsBlockAllocator* allocator) {
  void* mem = allocator->Allocate(sizeof(PhysicsPolygonContact));
  return new (mem) PhysicsPolygonContact(fixtureA, fixtureB);
}

void PhysicsPolygonContact::Destroy(PhysicsContact* contact,
                                    PhysicsBlockAllocator* allocator) {
  ((PhysicsPolygonContact*)contact)->~PhysicsPolygonContact();
  allocator->Free(contact, sizeof(PhysicsPolygonContact));
}

PhysicsPolygonContact::PhysicsPolygonContact(PhysicsFixture* fixtureA,
                                             PhysicsFixture* fixtureB)
    : PhysicsContact(fixtureA, 0, fixtureB, 0) {}

void PhysicsPolygonContact::Evaluate(
    PhysicsManifold* manifold, const PhysicsTransform& xfA, const PhysicsTransform& xfB) {}
}  // namespace base_engine::physics
