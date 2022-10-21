#include "PhysicsContact.h"

#include "PhysicsCircleContact.h"
#include "PhysicsFixture.h"
#include "PhysicsPolygonContact.h"

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

void PhysicsContact::InitializeRegisters() {
  AddType(PhysicsPolygonContact::Create, PhysicsPolygonContact::Destroy,
          b2Shape::Type::kPolygon, b2Shape::Type::kPolygon);

      AddType(PhysicsCircleContact::Create, PhysicsCircleContact::Destroy,
          b2Shape::Type::kCircle, b2Shape::Type::kCircle);
}

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

void PhysicsContact::Destroy(PhysicsContact* contact, PhysicsBlockAllocator* allocator)
{
    PhysicsFixture* fixtureA = contact->m_fixtureA;
    PhysicsFixture* fixtureB = contact->m_fixtureB;

    if (contact->m_manifold.pointCount > 0 && fixtureA->IsSensor() == false &&
        fixtureB->IsSensor() == false) {
        fixtureA->GetBody()->SetAwake(true);
        fixtureB->GetBody()->SetAwake(true);
    }

    const size_t typeA = static_cast<size_t>(fixtureA->GetType());
    const size_t typeB = static_cast<size_t>(fixtureB->GetType());

    b2ContactDestroyFcn* destroyFcn = s_registers[typeA][typeB].destroyFcn;
    destroyFcn(contact, allocator);
}

void PhysicsContact::Update(IPhysicsContactListener* listener)
{
      
}
}  // namespace base_engine::physics