#include "PhysicsContactManager.h"

#include "PhysicsContact.h"
#include "PhysicsContactFilter.h"
#include "PhysicsContactListener.h"
#include "PhysicsFixture.h"

namespace base_engine::physics {
PhysicsContactManager::PhysicsContactManager()
{
  m_contactFilter = new PhysicsContactFilter;
  m_contactListener = new PhysicsContactListener;
}

void PhysicsContactManager::AddPair(void* proxyUserDataA, void* proxyUserDataB)
{
  PhysicsFixtureProxy* proxyA = (PhysicsFixtureProxy*)proxyUserDataA;
  PhysicsFixtureProxy* proxyB = (PhysicsFixtureProxy*)proxyUserDataB;

  PhysicsFixture* fixtureA = proxyA->fixture;
  PhysicsFixture* fixtureB = proxyB->fixture;

  int32 indexA = proxyA->childIndex;
  int32 indexB = proxyB->childIndex;

  PhysicsBody* bodyA = fixtureA->GetBody();
  PhysicsBody* bodyB = fixtureB->GetBody();

  // Are the fixtures on the same body?
  if (bodyA == bodyB) {
    return;
  }

  // TODO_ERIN use a hash table to remove a potential bottleneck when both
  // bodies have a lot of contacts.
  // Does a contact already exist?
  PhysicsContactEdge* edge = bodyB->GetContactList();
  while (edge) {
    if (edge->other == bodyA) {
      PhysicsFixture* fA = edge->contact->GetFixtureA();
      PhysicsFixture* fB = edge->contact->GetFixtureB();
      int32 iA = edge->contact->GetChildIndexA();
      int32 iB = edge->contact->GetChildIndexB();
  
      if (fA == fixtureA && fB == fixtureB && iA == indexA && iB == indexB) {
        // A contact already exists.
        return;
      }
  
      if (fA == fixtureB && fB == fixtureA && iA == indexB && iB == indexA) {
        // A contact already exists.
        return;
      }
    }
  
    edge = edge->next;
  }

  // Does a joint override collision? Is at least one body dynamic?
  if (bodyB->ShouldCollide(bodyA) == false) {
    return;
  }

  // Check user filtering.
  if (m_contactFilter &&
      m_contactFilter->ShouldCollide(fixtureA, fixtureB) == false) {
    return;
  }

  // Call the factory.
  PhysicsContact* c =
      PhysicsContact::Create(fixtureA, indexA, fixtureB, indexB, m_allocator);
  if (c == nullptr) {
    return;
  }

  // Contact creation may swap fixtures.
  fixtureA = c->GetFixtureA();
  fixtureB = c->GetFixtureB();
  indexA = c->GetChildIndexA();
  indexB = c->GetChildIndexB();
  bodyA = fixtureA->GetBody();
  bodyB = fixtureB->GetBody();

  // Insert into the world.
  c->m_prev = nullptr;
  c->m_next = m_contactList;
  if (m_contactList != nullptr) {
    m_contactList->m_prev = c;
  }
  m_contactList = c;

  // Connect to island graph.

  // Connect to body A
  c->m_nodeA.contact = c;
  c->m_nodeA.other = bodyB;

  c->m_nodeA.prev = nullptr;
  c->m_nodeA.next = bodyA->m_contactList;
  if (bodyA->m_contactList != nullptr) {
    bodyA->m_contactList->prev = &c->m_nodeA;
  }
  bodyA->m_contactList = &c->m_nodeA;

  // Connect to body B
  c->m_nodeB.contact = c;
  c->m_nodeB.other = bodyA;

  c->m_nodeB.prev = nullptr;
  c->m_nodeB.next = bodyB->m_contactList;
  if (bodyB->m_contactList != nullptr) {
    bodyB->m_contactList->prev = &c->m_nodeB;
  }
  bodyB->m_contactList = &c->m_nodeB;

  ++m_contactCount;
}

void PhysicsContactManager::FindNewContacts()
{
  m_broadPhase.UpdatePairs(this);
}

void PhysicsContactManager::Destroy(PhysicsContact* c)
{
  PhysicsFixture* fixtureA = c->GetFixtureA();
  PhysicsFixture* fixtureB = c->GetFixtureB();
  PhysicsBody* bodyA = fixtureA->GetBody();
  PhysicsBody* bodyB = fixtureB->GetBody();

  if (m_contactListener && c->IsTouching()) {
    m_contactListener->EndContact(c);
  }

  // Remove from the world.
  if (c->m_prev) {
    c->m_prev->m_next = c->m_next;
  }

  if (c->m_next) {
    c->m_next->m_prev = c->m_prev;
  }

  if (c == m_contactList) {
    m_contactList = c->m_next;
  }

  // Remove from body 1
  if (c->m_nodeA.prev) {
    c->m_nodeA.prev->next = c->m_nodeA.next;
  }

  if (c->m_nodeA.next) {
    c->m_nodeA.next->prev = c->m_nodeA.prev;
  }

  if (&c->m_nodeA == bodyA->m_contactList) {
    bodyA->m_contactList = c->m_nodeA.next;
  }

  // Remove from body 2
  if (c->m_nodeB.prev) {
    c->m_nodeB.prev->next = c->m_nodeB.next;
  }

  if (c->m_nodeB.next) {
    c->m_nodeB.next->prev = c->m_nodeB.prev;
  }

  if (&c->m_nodeB == bodyB->m_contactList) {
    bodyB->m_contactList = c->m_nodeB.next;
  }

  // Call the factory.
  PhysicsContact::Destroy(c, m_allocator);
  --m_contactCount;
}

void PhysicsContactManager::Collide()
{
  PhysicsContact* c = m_contactList;
  while (c) {
    PhysicsFixture* fixtureA = c->GetFixtureA();
    PhysicsFixture* fixtureB = c->GetFixtureB();
    int32 indexA = c->GetChildIndexA();
    int32 indexB = c->GetChildIndexB();
    PhysicsBody* bodyA = fixtureA->GetBody();
    PhysicsBody* bodyB = fixtureB->GetBody();

    // Is this contact flagged for filtering?
    if (c->m_flags & PhysicsContact::e_filterFlag) {
      // Should these bodies collide?
      if (bodyB->ShouldCollide(bodyA) == false) {
        PhysicsContact* cNuke = c;
        c = cNuke->GetNext();
        Destroy(cNuke);
        continue;
      }

      // Check user filtering.
      if (m_contactFilter &&
          m_contactFilter->ShouldCollide(fixtureA, fixtureB) == false) {
        PhysicsContact* cNuke = c;
        c = cNuke->GetNext();
        Destroy(cNuke);
        continue;
      }

      // Clear the filtering flag.
      c->m_flags &= ~PhysicsContact::e_filterFlag;
    }

    bool activeA = bodyA->IsAwake() && bodyA->m_type !=PhysicsBodyType::kStaticBody;
    bool activeB =
        bodyB->IsAwake() && bodyB->m_type != PhysicsBodyType::kStaticBody;

    // At least one body must be awake and it must be dynamic or kinematic.
    if (activeA == false && activeB == false) {
      c = c->GetNext();
      continue;
    }

    int32 proxyIdA = fixtureA->m_proxies[indexA].proxyId;
    int32 proxyIdB = fixtureB->m_proxies[indexB].proxyId;
    bool overlap = m_broadPhase.TestOverlap(proxyIdA, proxyIdB);

    // Here we destroy contacts that cease to overlap in the broad-phase.
    if (overlap == false) {
      PhysicsContact* cNuke = c;
      c = cNuke->GetNext();
      Destroy(cNuke);
      continue;
    }

    // The contact persists.
    c->Update(m_contactListener);
    c = c->GetNext();
  }
}
}  // namespace base_engine::physics
