#include "PhysicsFixture.h"

#include "BroadPhase.h"
#include "PhysicsBlockAllocator.h"
#include "PhysicsCircleShape.h"
// @PhysicsFixture.cpp
// @brief
// @author かき氷氷味
// @date 2022/10/17
//
// @details
namespace base_engine::physics {
void PhysicsFixture::Create(PhysicsBlockAllocator* allocator, PhysicsBody* body,
                            const PhysicsFixtureDef* def) {
  m_userData = def->userData;
  m_friction = def->friction;
  m_restitution = def->restitution;
  m_restitutionThreshold = def->restitutionThreshold;

  m_body = body;
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

void PhysicsFixture::Destroy(PhysicsBlockAllocator* allocator)
{
    // Free the proxy array.
    int32 childCount = m_shape->GetChildCount();
    allocator->Free(m_proxies, childCount * sizeof(PhysicsFixtureProxy));
    m_proxies = nullptr;

    // Free the child shape.
    switch (m_shape->m_type) {
    case b2Shape::Type::kCircle:
    {
        b2CircleShape* s = (b2CircleShape*)m_shape;
        s->~b2CircleShape();
        allocator->Free(s, sizeof(b2CircleShape));
    } break;

    case b2Shape::Type::kEdge: {
        //b2EdgeShape* s = (b2EdgeShape*)m_shape;
        //s->~b2EdgeShape();
        //allocator->Free(s, sizeof(b2EdgeShape));
    } break;

    case b2Shape::Type::kPolygon: {
        //b2PolygonShape* s = (b2PolygonShape*)m_shape;
        //s->~b2PolygonShape();
        //allocator->Free(s, sizeof(b2PolygonShape));
    } break;

    case b2Shape::Type::kChain: {
        //b2ChainShape* s = (b2ChainShape*)m_shape;
        //s->~b2ChainShape();
        //allocator->Free(s, sizeof(b2ChainShape));
    } break;

    default:
        break;
    }

    m_shape = nullptr;
}

void PhysicsFixture::CreateProxies(bp::BroadPhase* broadPhase, const b2Transform& xf)
{
    m_proxyCount = m_shape->GetChildCount();

    for (int32 i = 0; i < m_proxyCount; ++i) {
        PhysicsFixtureProxy* proxy = m_proxies + i;
        m_shape->ComputeAABB(&proxy->aabb, xf, i);
        proxy->proxyId = broadPhase->CreateProxy(proxy->aabb, proxy);
        proxy->fixture = this;
        proxy->childIndex = i;
    }
}

void PhysicsFixture::DestroyProxies(bp::BroadPhase* broadPhase)
{
    // Destroy proxies in the broad-phase.
    for (int32 i = 0; i < m_proxyCount; ++i) {
        PhysicsFixtureProxy* proxy = m_proxies + i;
        broadPhase->DestroyProxy(proxy->proxyId);
        proxy->proxyId = bp::kNullProxy;
    }

    m_proxyCount = 0;
}

void PhysicsFixture::Synchronize(bp::BroadPhase* broadPhase, const b2Transform& xf1, const b2Transform& xf2) const
{
    if (m_proxyCount == 0) {
        return;
    }

    for (int32 i = 0; i < m_proxyCount; ++i) {
        PhysicsFixtureProxy* proxy = m_proxies + i;

        // Compute an AABB that covers the swept shape (may miss some rotation
        // effect).
        PhysicsAABB aabb1, aabb2;
        m_shape->ComputeAABB(&aabb1, xf1, proxy->childIndex);
        m_shape->ComputeAABB(&aabb2, xf2, proxy->childIndex);

        proxy->aabb.Combine(aabb1, aabb2);

        PVec2 displacement = aabb2.GetCenter() - aabb1.GetCenter();

        broadPhase->MoveProxy(proxy->proxyId, proxy->aabb, displacement);
    }
}
}  // namespace base_engine::physics