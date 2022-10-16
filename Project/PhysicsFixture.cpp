#include "PhysicsFixture.h"

#include "BroadPhase.h"
#include "PhysicsBlockAllocator.h"
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
}  // namespace base_engine::physics