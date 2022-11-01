// @PhysicsFixture.h
// @brief
// @author かき氷氷味
// @date 2022/10/13
//
// @details

#pragma once
#include "BroadPhase.h"
#include "PhysicsBody2D.h"
#include "PhysicsCollision.h"
#include "PhysicsComponentData.h"
#include "PhysicsShapes.h"

namespace base_engine::physics {
class b2Shape;
class b2ContactEdge;
using int32 = int32_t;
struct b2Filter {
  b2Filter() {
    categoryBits = 0x0001u;
    maskTargetBits = 0xFFFFu;
    maskObjectBits = 0xFFFFu;
    groupIndex = 0u;
  }

  /// The collision category bits. Normally you would just set one bit.
  uint32_t categoryBits;

  /// The collision mask bits. This states the categories that this
  /// shape would accept for collision.
  uint32_t maskTargetBits;
  uint32_t maskObjectBits;

  /// Collision groups allow a certain group of objects to never collide
  /// (negative) or always collide (positive). Zero means no collision group.
  /// Non-zero group filtering always wins against the mask bits.
  int16_t groupIndex;
};
struct PhysicsFixtureDef {
  /// The constructor sets the default fixture definition values.
  PhysicsFixtureDef() {
    shape = nullptr;
    friction = 0.2f;
    restitution = 0.0f;
    restitutionThreshold = 1.0f * kLengthUnitsPerMeter;
    density = 0.0f;
    isSensor = false;
  }

  /// The shape, this must be set. The shape will be cloned, so you
  /// can create the shape on the stack.
  const b2Shape* shape;

  //TODO CollisionComponentへの依存をなくす
  class CollisionComponent* collision = nullptr;
  /// Use this to store application specific fixture data.
  FixtureUserComponentData userData;

  /// The friction coefficient, usually in the range [0,1].
  float friction;

  /// The restitution (elasticity) usually in the range [0,1].
  float restitution;

  /// Restitution velocity threshold, usually in m/s. Collisions above this
  /// speed have restitution applied (will bounce).
  float restitutionThreshold;

  /// The density, usually in kg/m^2.
  float density;

  /// A sensor shape collects contact information but never generates a
  /// collision response.
  bool isSensor;

  /// Contact filtering data.
  b2Filter filter;
};

class PhysicsFixture;
struct PhysicsFixtureProxy {
  PhysicsAABB aabb;
  PhysicsFixture* fixture;
  int32_t childIndex;
  int32_t proxyId;
};
class PhysicsFixture {

public:
  [[nodiscard]] b2Shape::Type GetType() const noexcept {
    return m_shape->GetType();
  }

  b2Shape* GetShape() { return m_shape; }
  [[nodiscard]] const b2Shape* GetShape() const noexcept { return m_shape; }

  void SetSensor(bool sensor) noexcept { m_isSensor = sensor; }

  [[nodiscard]] bool IsSensor() const noexcept { return m_isSensor; }

  void SetFilterData(const b2Filter& filter) {
    m_filter = filter;

    ReFilter();
  }

  [[nodiscard]] const b2Filter& GetFilterData() const { return m_filter; }

  void ReFilter() {

    if (m_body == nullptr) {
      return;
    }
    /*
    // Flag associated contacts for filtering.
    b2ContactEdge* edge = m_body->GetContactList();
    while (edge) {
      PhysicsContact* contact = edge->contact;
      PhysicsFixture* fixtureA = contact->GetFixtureA();
      PhysicsFixture* fixtureB = contact->GetFixtureB();
      if (fixtureA == this || fixtureB == this) {
        contact->FlagForFiltering();
      }

      edge = edge->next;
    }

    PhysicsWorld* world = m_body->GetWorld();
    if (world == nullptr) {
      return;
    }

    // Touch each proxy so that new pairs may be created
    bp::BroadPhase* broadPhase = &world->m_contactManager.m_broadPhase;
    for (int32_t i = 0; i < m_proxyCount; ++i) {
      broadPhase->TouchProxy(m_proxies[i].proxyId);
    }
    */
    

  }

  PhysicsBody* GetBody() { return m_body; }
  [[nodiscard]] const PhysicsBody* GetBody() const { return m_body; }

  PhysicsFixture* GetNext() { return m_next; }
  [[nodiscard]] const PhysicsFixture* GetNext() const { return m_next; }

  FixtureUserComponentData& GetUserData() { return m_userData; }
  [[nodiscard]] const FixtureUserComponentData& GetUserData() const {
    return m_userData;
  }

  [[nodiscard]] bool TestPoint(const PVec2& p) const {
    return m_shape->TestPoint(m_body->GetTransform(), p);
  }

  bool RayCast(PhysicsRayCastOutput* output, const PhysicsRayCastInput& input,
               int32_t childIndex) const {
    return m_shape->RayCast(output, input, m_body->GetTransform(), childIndex);
  }

  void GetMassData(PhysicsMassData* massData) const noexcept {
    m_shape->ComputeMass(massData, m_density);
  }

  [[nodiscard]] const PhysicsAABB& GetAABB(int32_t childIndex) const {
    return m_proxies[childIndex].aabb;
  }

 protected:
  friend class PhysicsBody;
  friend class PhysicsWorld;
  friend class PhysicsContact;
  friend class PhysicsContactManager;

  PhysicsFixture() {
    m_body = nullptr;
    m_next = nullptr;
    m_proxies = nullptr;
    m_proxyCount = 0;
    m_shape = nullptr;
    m_density = 0.0f;
  }

  // We need separation create/destroy functions from the constructor/destructor
  // because the destructor cannot access the allocator (no destructor arguments
  // allowed by C++).
  void Create(PhysicsBlockAllocator* allocator, PhysicsBody* body,
              const PhysicsFixtureDef* def);
  void Destroy(PhysicsBlockAllocator* allocator);

  // These support body activation/deactivation.
  void CreateProxies(bp::BroadPhase* broadPhase, const b2Transform& xf);
  void DestroyProxies(bp::BroadPhase* broadPhase);

  void Synchronize(bp::BroadPhase* broadPhase, const b2Transform& xf1,
                   const b2Transform& xf2) const;

  float m_density;

  PhysicsFixture* m_next;
  PhysicsBody* m_body;

  b2Shape* m_shape;

  float m_friction;
  float m_restitution;
  float m_restitutionThreshold;

  PhysicsFixtureProxy* m_proxies;
  int32_t m_proxyCount;

  b2Filter m_filter;

  bool m_isSensor;

  FixtureUserComponentData m_userData;

public:
  // TODO CollisionComponentへの依存をなくす

  class CollisionComponent* collision_ = nullptr;
};

}  // namespace base_engine::physics