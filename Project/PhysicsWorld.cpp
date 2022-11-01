#include "PhysicsWorld.h"

#include "PhysicsBody2D.h"
#include "PhysicsFixture.h"

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
  {
      m_contactManager.Collide();
  }
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
