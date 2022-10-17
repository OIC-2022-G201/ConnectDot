#include "PhysicsContact.h"

#include "PhysicsFixture.h"

namespace base_engine::physics {

b2ContactRegister
    PhysicsContact::s_registers[ee::ElementCount<b2Shape::Type>()]
                               [ee::ElementCount<b2Shape::Type>()];

bool PhysicsContact::s_initialized = false;

void PhysicsContact::AddType(b2ContactCreateFcn* createFcn,
                             b2ContactDestroyFcn* destroyFcn,
                             b2Shape::Type typeA, b2Shape::Type typeB) {
  int type1 = static_cast<int>(typeA);
  int type2 = static_cast<int>(typeB);
  s_registers[type1][type2].createFcn = createFcn;
  s_registers[type1][type2].destroyFcn = destroyFcn;
  s_registers[type1][type2].primary = true;

  if (type1 != type2) {
    s_registers[type2][type1].createFcn = createFcn;
    s_registers[type2][type1].destroyFcn = destroyFcn;
    s_registers[type2][type1].primary = false;
  }
}

void PhysicsContact::InitializeRegisters() {}

PhysicsContact* PhysicsContact::Create(PhysicsFixture* fixtureA, int32_t indexA,
                                       PhysicsFixture* fixtureB, int32_t indexB,
                                       PhysicsBlockAllocator* allocator) {
  if (s_initialized == false) {
    InitializeRegisters();
    s_initialized = true;
  }

  b2Shape::Type type1 = fixtureA->GetType();
  b2Shape::Type type2 = fixtureB->GetType();

  b2ContactCreateFcn* createFcn =
      s_registers[static_cast<int>(type1)][static_cast<int>(type2)].createFcn;
  if (createFcn) {
    if (s_registers[static_cast<int>(type1)][static_cast<int>(type2)].primary) {
      return createFcn(fixtureA, indexA, fixtureB, indexB, allocator);
    } else {
      return createFcn(fixtureB, indexB, fixtureA, indexA, allocator);
    }
  } else {
    return nullptr;
  }
}
}  // namespace base_engine::physics