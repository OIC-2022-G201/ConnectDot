#include "PhysicsFixture.h"

#include "BroadPhase.h"
#include "PhysicsBlockAllocator.h"
#include "PhysicsCircleShape.h"
#include "PhysicsContact.h"
#include "PhysicsPolygonShape.h"
// @PhysicsFixture.cpp
// @brief
// @author かき氷氷味
// @date 2022/10/17
//
// @details


namespace base_engine::physics {
	void PhysicsFixture::ReFilter()
	{

		if (m_body == nullptr) {
			return;
		}
		
    // Flag associated contacts for filtering.
    PhysicsContactEdge* edge = m_body->GetContactList();
    while (edge) {
      PhysicsContact* contact = edge->contact;
      PhysicsFixture* fixtureA = contact->GetFixtureA();
      PhysicsFixture* fixtureB = contact->GetFixtureB();
      if (fixtureA == this || fixtureB == this) {
        contact->FlagForFiltering();
      }

      edge = edge->next;
    }
    

	}

void PhysicsFixture::Create(PhysicsBlockAllocator* allocator, PhysicsBody* body,
	                            const PhysicsFixtureDef* def) {
  m_userData = def->userData;
  m_friction = def->friction;
  m_restitution = def->restitution;
  m_restitutionThreshold = def->restitutionThreshold;

  m_body = body;
  collision_ = def->collision;
  m_next = nullptr;

  m_filter = def->filter;

  m_isSensor = def->isSensor;

  m_shape = def->shape->Clone(allocator);

  // Reserve proxy space
  int32 childCount = m_shape->GetChildCount();
  m_proxies = static_cast<PhysicsFixtureProxy*>(
      allocator->Allocate(childCount * sizeof(PhysicsFixtureProxy)));
  for (int32 i = 0; i < childCount; ++i) {
    m_proxies[i].fixture = nullptr;
    m_proxies[i].proxyId = bp::kNullProxy;
  }
  m_proxyCount = 0;

  m_density = def->density;
}

void PhysicsFixture::Destroy(PhysicsBlockAllocator* allocator) {
  // Free the proxy array.
  int32 childCount = m_shape->GetChildCount();
  allocator->Free(m_proxies, childCount * sizeof(PhysicsFixtureProxy));
  m_proxies = nullptr;

  // Free the child shape.
  switch (m_shape->m_type) {
    case PhysicsShape::Type::kCircle: {
      PhysicsCircleShape* s = (PhysicsCircleShape*)m_shape;
      s->~PhysicsCircleShape();
      allocator->Free(s, sizeof(PhysicsCircleShape));
    } break;

    case PhysicsShape::Type::kEdge: {
      // PhysicsEdgeShape* s = (PhysicsEdgeShape*)m_shape;
      // s->~PhysicsEdgeShape();
      // allocator->Free(s, sizeof(PhysicsEdgeShape));
    } break;

    case PhysicsShape::Type::kPolygon: {
      auto s = static_cast<PhysicsPolygonShape*>(m_shape);
      s->~PhysicsPolygonShape();
      allocator->Free(s, sizeof(PhysicsPolygonShape));

    } break;

    case PhysicsShape::Type::kChain: {
      // PhysicsChainShape* s = (PhysicsChainShape*)m_shape;
      // s->~PhysicsChainShape();
      // allocator->Free(s, sizeof(PhysicsChainShape));
    } break;

    default:
      break;
  }

  m_shape = nullptr;
}

void PhysicsFixture::CreateProxies(bp::BroadPhase* broadPhase,
                                   const PhysicsTransform& xf) {
  m_proxyCount = m_shape->GetChildCount();

  for (int32 i = 0; i < m_proxyCount; ++i) {
    PhysicsFixtureProxy* proxy = m_proxies + i;
    m_shape->ComputeAABB(&proxy->aabb, xf, i);
    proxy->proxyId = broadPhase->CreateProxy(proxy->aabb, proxy);
    proxy->fixture = this;
    proxy->childIndex = i;
  }
}

void PhysicsFixture::DestroyProxies(bp::BroadPhase* broadPhase) {
  // Destroy proxies in the broad-phase.
  for (int32 i = 0; i < m_proxyCount; ++i) {
    PhysicsFixtureProxy* proxy = m_proxies + i;
    broadPhase->DestroyProxy(proxy->proxyId);
    proxy->proxyId = bp::kNullProxy;
  }

  m_proxyCount = 0;
}

void PhysicsFixture::Synchronize(bp::BroadPhase* broadPhase,
                                 const PhysicsTransform& xf1,
                                 const PhysicsTransform& xf2) const {
  if (m_proxyCount == 0) {
    return;
  }

  for (int32 i = 0; i < m_proxyCount; ++i) {
    PhysicsFixtureProxy* proxy = m_proxies + i;

    // Compute an AABB that covers the swept shape (may miss some rotation
    // effect).
    PhysicsAABB aabb1, aabPhysics;
    m_shape->ComputeAABB(&aabb1, xf1, proxy->childIndex);
    m_shape->ComputeAABB(&aabPhysics, xf2, proxy->childIndex);

    proxy->aabb.Combine(aabb1, aabPhysics);

    PVec2 displacement = aabPhysics.GetCenter() - aabb1.GetCenter();

    broadPhase->MoveProxy(proxy->proxyId, proxy->aabb, displacement);
  }
}
}  // namespace base_engine::physics