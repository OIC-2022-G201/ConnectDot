// @PhysicsBody2D.cpp
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#include "PhysicsBody2D.h"

#include "PhysicsContact.h"
#include "PhysicsFixture.h"
#include "PhysicsWorld.h"

namespace base_engine::physics {
PhysicsFixture* PhysicsBody::CreateFixture(const PhysicsFixtureDef* def) {
  if (m_world->IsLocked() == true) {
    return nullptr;
  }

  PhysicsBlockAllocator* allocator = &m_world->m_blockAllocator;

  void* memory = allocator->Allocate(sizeof(PhysicsFixture));
  auto* fixture = new (memory) PhysicsFixture;
  fixture->Create(allocator, this, def);

  if (m_flags & e_enabledFlag) {
    bp::BroadPhase* broadPhase = &m_world->m_contactManager.m_broadPhase;
    fixture->CreateProxies(broadPhase, m_xf);
  }

  fixture->m_next = m_fixtureList;
  m_fixtureList = fixture;
  ++m_fixtureCount;

  fixture->m_body = this;

  // Adjust mass properties if needed.
  if (fixture->m_density > 0.0f) {
    ResetMassData();
  }

  // Let the world know we have a new fixture. This will cause new contacts
  // to be created at the beginning of the next time step.
  m_world->m_newContacts = true;

  return fixture;
}

PhysicsFixture* PhysicsBody::CreateFixture(const b2Shape* shape,
                                           float density) {
  PhysicsFixtureDef def;
  def.shape = shape;
  def.density = density;

  return CreateFixture(&def);
}

void PhysicsBody::DestroyFixture(PhysicsFixture* fixture) {
  if (fixture == NULL) {
    return;
  }

  if (m_world->IsLocked() == true) {
    return;
  }

  // Remove the fixture from this body's singly linked list.
  PhysicsFixture** node = &m_fixtureList;
  bool found = false;
  while (*node != nullptr) {
    if (*node == fixture) {
      *node = fixture->m_next;
      found = true;
      break;
    }

    node = &(*node)->m_next;
  }

  const float density = fixture->m_density;

  // Destroy any contacts associated with the fixture.
  b2ContactEdge* edge = m_contactList;
  while (edge) {
    PhysicsContact* c = edge->contact;
    edge = edge->next;

    PhysicsFixture* fixtureA = c->GetFixtureA();
    PhysicsFixture* fixtureB = c->GetFixtureB();

    if (fixture == fixtureA || fixture == fixtureB) {
      // This destroys the contact and removes it from
      // this body's contact list.
      m_world->m_contactManager.Destroy(c);
    }
  }

  PhysicsBlockAllocator* allocator = &m_world->m_blockAllocator;

  if (m_flags & e_enabledFlag) {
    bp::BroadPhase* broadPhase = &m_world->m_contactManager.m_broadPhase;
    fixture->DestroyProxies(broadPhase);
  }

  fixture->m_body = nullptr;
  fixture->m_next = nullptr;
  fixture->Destroy(allocator);
  fixture->~PhysicsFixture();
  allocator->Free(fixture, sizeof(PhysicsFixture));

  --m_fixtureCount;

  // Reset the mass data
  if (density > 0.0f) {
    ResetMassData();
  }
}

void PhysicsBody::SetTransform(const PVec2& position, float angle)
{
  if (m_world->IsLocked() == true) {
    return;
  }
  if (m_xf.p == position) {
    return;
  }
  m_xf.q.Set(angle);
  m_xf.p = position;

  m_sweep.c = PhysicsMul(m_xf, m_sweep.localCenter);
  m_sweep.a = angle;

  m_sweep.c0 = m_sweep.c;
  m_sweep.a0 = angle;

  bp::BroadPhase* broadPhase = &m_world->m_contactManager.m_broadPhase;
  for (PhysicsFixture* f = m_fixtureList; f; f = f->m_next) {
    f->Synchronize(broadPhase, m_xf, m_xf);
  }

  // Check for new contacts the next step
  m_world->m_newContacts = true;
}

bool PhysicsBody::ShouldCollide(const PhysicsBody* other) const
{
  if (m_type != PhysicsBodyType::kDynamicBody &&
      other->m_type != PhysicsBodyType::kDynamicBody) {
    return true;
  }
    return true;
}

PhysicsBody::PhysicsBody(const BodyDef* bd, PhysicsWorld* physics_world)
    : m_xf(),
      m_world(physics_world),
      m_prev(nullptr),
      m_next(nullptr),
      m_fixtureList(nullptr),
      m_fixtureCount(0) {
  m_xf.p = bd->position;
  m_xf.q.Set(bd->angle);

	m_flags = 0;

  if (bd->bullet) {
    m_flags |= e_bulletFlag;
  }
  if (bd->fixedRotation) {
    m_flags |= e_fixedRotationFlag;
  }
  if (bd->allowSleep) {
    m_flags |= e_autoSleepFlag;
  }
  if (bd->awake && bd->type != PhysicsBodyType::kStaticBody) {
    m_flags |= e_awakeFlag;
  }
  if (bd->enabled) {
    m_flags |= e_enabledFlag;
  }
  m_sweep.localCenter.SetZero();
  m_sweep.c0 = m_xf.p;
  m_sweep.c = m_xf.p;
  m_sweep.a0 = bd->angle;
  m_sweep.a = bd->angle;
  m_sweep.alpha0 = 0.0f;

  m_prev = nullptr;
  m_next = nullptr;

  m_linearVelocity = bd->linearVelocity;
  m_angularVelocity = bd->angularVelocity;

  m_linearDamping = bd->linearDamping;
  m_angularDamping = bd->angularDamping;
  m_gravityScale = bd->gravityScale;

  m_force.SetZero();
  m_torque = 0.0f;

  m_sleepTime = 0.0f;

  m_type = bd->type;

  m_mass = 0.0f;
  m_invMass = 0.0f;

  m_I = 0.0f;
  m_invI = 0.0f;

  m_userData = bd->userData;

  m_fixtureList = nullptr;
  m_fixtureCount = 0;
}
}  // namespace base_engine::physics