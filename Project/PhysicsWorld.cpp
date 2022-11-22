#include "PhysicsWorld.h"

#include "PhysicsBody2D.h"
#include "PhysicsContact.h"
#include "PhysicsFixture.h"
#include "PhysicsWorldCallBack.h"

namespace base_engine::physics {
PhysicsWorld::PhysicsWorld(const PVec2& gravity) {
  m_gravity = gravity;

  m_locked = false;
  m_contactManager.m_allocator = &m_blockAllocator;
}

PhysicsBody* PhysicsWorld::CreateBody(const BodyDef* def) {
  if (IsLocked()) {
    return nullptr;
  }

  void* mem = m_blockAllocator.Allocate(sizeof(PhysicsBody));
  PhysicsBody* b = new (mem) PhysicsBody(def, this);

  // Add to world doubly linked list.
  b->m_prev = nullptr;
  b->m_next = m_bodyList;
  if (m_bodyList) {
    m_bodyList->m_prev = b;
  }
  m_bodyList = b;
  ++m_bodyCount;

  return b;
}

void PhysicsWorld::DestroyBody(PhysicsBody* b) {
  b2ContactEdge* ce = b->m_contactList;
  while (ce) {
    b2ContactEdge* ce0 = ce;
    ce = ce->next;
    m_contactManager.Destroy(ce0->contact);
  }
  b->m_contactList = nullptr;

  PhysicsFixture* f = b->m_fixtureList;
  while (f) {
    PhysicsFixture* f0 = f;
    f = f->m_next;

    f0->DestroyProxies(&m_contactManager.m_broadPhase);
    f0->Destroy(&m_blockAllocator);
    f0->~PhysicsFixture();
    m_blockAllocator.Free(f0, sizeof(PhysicsFixture));

    b->m_fixtureList = f;
    b->m_fixtureCount -= 1;
  }
  b->m_fixtureList = nullptr;
  b->m_fixtureCount = 0;

  // Remove world body list.
  if (b->m_prev) {
    b->m_prev->m_next = b->m_next;
  }

  if (b->m_next) {
    b->m_next->m_prev = b->m_prev;
  }

  if (b == m_bodyList) {
    m_bodyList = b->m_next;
  }

  --m_bodyCount;
  b->~PhysicsBody();
  m_blockAllocator.Free(b, sizeof(PhysicsBody));
}

void PhysicsWorld::Step(float timeStep) {
  if (m_newContacts) {
    m_contactManager.FindNewContacts();
    m_newContacts = false;
  }
  { m_contactManager.Collide(); }
}

struct b2WorldQueryWrapper {
  bool QueryCallback(int32 proxyId) {
    auto proxy =
        static_cast<PhysicsFixtureProxy*>(broadPhase->GetUserData(proxyId));
    return callback->ReportFixture(proxy->fixture);
  }

  const bp::BroadPhase* broadPhase;
  PhysicsQueryCallback* callback;
};

void PhysicsWorld::QueryAABB(PhysicsQueryCallback* callback,
                             const PhysicsAABB& aabb) const {
  b2WorldQueryWrapper wrapper{&m_contactManager.m_broadPhase, callback};
  wrapper.broadPhase = &m_contactManager.m_broadPhase;
  wrapper.callback = callback;
  m_contactManager.m_broadPhase.Query(&wrapper, aabb);
}

struct b2WorldRayCastWrapper {
  [[nodiscard]] float RayCastCallback(const PhysicsRayCastInput& input,
                                      const int32 proxyId) const {
    void* userData = broadPhase->GetUserData(proxyId);
    const auto proxy = static_cast<PhysicsFixtureProxy*>(userData);
    PhysicsFixture* fixture = proxy->fixture;
    const int32 index = proxy->childIndex;
    PhysicsRayCastOutput output{};

    if (fixture->RayCast(&output, input, index)) {
      const float fraction = output.fraction;
      const PVec2 point = (1.0f - fraction) * input.p1 + fraction * input.p2;
      return callback->ReportFixture(fixture, point, output.normal, fraction);
    }

    return input.maxFraction;
  }

  const bp::BroadPhase* broadPhase;
  PhysicsRayCastCallback* callback;
};

void PhysicsWorld::RayCast(PhysicsRayCastCallback* callback, const PVec2& point1,
                           const PVec2& point2) const
{
  b2WorldRayCastWrapper wrapper{&m_contactManager.m_broadPhase, callback};
  const PhysicsRayCastInput input{point1, point2,1.0f};
  m_contactManager.m_broadPhase.RayCast(&wrapper, input);
}

PhysicsWorld::~PhysicsWorld() {
  PhysicsBody* b = m_bodyList;
  while (b) {
    PhysicsBody* bNext = b->m_next;

    auto f = b->m_fixtureList;
    while (f) {
      auto fNext = f->m_next;
      f->m_proxyCount = 0;
      f->Destroy(&m_blockAllocator);
      f = fNext;
    }

    b = bNext;
  }
}
}  // namespace base_engine::physics
