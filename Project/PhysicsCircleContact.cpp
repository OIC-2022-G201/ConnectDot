#include "PhysicsCircleContact.h"

#include "PhysicsBlockAllocator.h"

base_engine::physics::PhysicsContact*
base_engine::physics::PhysicsCircleContact::Create(
    PhysicsFixture* fixtureA, int32_t indexA, PhysicsFixture* fixtureB,
    int32_t indexB, PhysicsBlockAllocator* allocator) {
  void* mem = allocator->Allocate(sizeof(PhysicsCircleContact));
  return new (mem) PhysicsCircleContact(fixtureA, fixtureB);
}

void base_engine::physics::PhysicsCircleContact::Destroy(
    PhysicsContact* contact, PhysicsBlockAllocator* allocator) {
  ((PhysicsCircleContact*)contact)->~PhysicsCircleContact();
  allocator->Free(contact, sizeof(PhysicsCircleContact));
}

base_engine::physics::PhysicsCircleContact::PhysicsCircleContact(
    PhysicsFixture* fixtureA, PhysicsFixture* fixtureB)
    : PhysicsContact(fixtureA, 0, fixtureB, 0) {
    
}

base_engine::physics::PhysicsCircleContact::~PhysicsCircleContact() {}

void base_engine::physics::PhysicsCircleContact::Evaluate(
    b2Manifold* manifold, const b2Transform& xfA, const b2Transform& xfB)
{

}
