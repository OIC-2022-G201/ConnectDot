// @PhysicsContact.h
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#pragma once
#include <cstdint>

#include "EnumExtension.h"
#include "PhysicsManifold.h"
#include "PhysicsShapes.h"
#include "PhysicsTransform.h"

namespace base_engine {
namespace physics {
class IPhysicsContactListener;
class PhysicsFixture;
struct b2Manifold;
class PhysicsBody;
class PhysicsContact;

struct b2ContactEdge {
  PhysicsBody* other;  ///< provides quick access to the other body attached.
  PhysicsContact* contact;  ///< the contact
  b2ContactEdge*
      prev;  ///< the previous contact edge in the body's contact list
  b2ContactEdge* next;  ///< the next contact edge in the body's contact list
};
typedef PhysicsContact* b2ContactCreateFcn(PhysicsFixture* fixtureA,
                                           int32_t indexA,
                                           PhysicsFixture* fixtureB,
                                           int32_t indexB,
                                           PhysicsBlockAllocator* allocator);
typedef void b2ContactDestroyFcn(PhysicsContact* contact,
                                 PhysicsBlockAllocator* allocator);

struct b2ContactRegister {
  b2ContactCreateFcn* createFcn;
  b2ContactDestroyFcn* destroyFcn;
  bool primary;
};
class PhysicsContact {
 public:
  /// Get the contact manifold. Do not modify the manifold unless you understand
  /// the internals of Box2D.
  b2Manifold* GetManifold();
  const b2Manifold* GetManifold() const;

  /// Get the world manifold.
  // void GetWorldManifold(b2WorldManifold* worldManifold) const;

  /// Is this contact touching?
  bool IsTouching() const {
    return (m_flags & e_touchingFlag) == e_touchingFlag;
  }

  /// Enable/disable this contact. This can be used inside the pre-solve
  /// contact listener. The contact is only disabled for the current
  /// time step (or sub-step in continuous collisions).
  void SetEnabled(bool flag);

  /// Has this contact been disabled?
  bool IsEnabled() const;

  /// Get the next contact in the world's contact list.
  PhysicsContact* GetNext() { return m_next; }
  const PhysicsContact* GetNext() const { return m_next; }

  /// Get fixture A in this contact.
  PhysicsFixture* GetFixtureA() { return m_fixtureA; }
  const PhysicsFixture* GetFixtureA() const { return m_fixtureA; }

  /// Get the child primitive index for fixture A.
  int32_t GetChildIndexA() const { return m_indexA; }

  /// Get fixture B in this contact.
  PhysicsFixture* GetFixtureB() { return m_fixtureB; }
  const PhysicsFixture* GetFixtureB() const { return m_fixtureB; }

  /// Get the child primitive index for fixture B.
  int32_t GetChildIndexB() const { return m_indexB; }

  /// Override the default friction mixture. You can call this in
  /// b2ContactListener::PreSolve. This value persists until set or reset.
  void SetFriction(float friction);

  /// Get the friction.
  float GetFriction() const;

  /// Reset the friction mixture to the default value.
  void ResetFriction();

  /// Override the default restitution mixture. You can call this in
  /// b2ContactListener::PreSolve. The value persists until you set or reset.
  void SetRestitution(float restitution);

  /// Get the restitution.
  float GetRestitution() const;

  /// Reset the restitution to the default value.
  void ResetRestitution();

  /// Override the default restitution velocity threshold mixture. You can call
  /// this in b2ContactListener::PreSolve. The value persists until you set or
  /// reset.
  void SetRestitutionThreshold(float threshold);

  /// Get the restitution threshold.
  float GetRestitutionThreshold() const;

  /// Reset the restitution threshold to the default value.
  void ResetRestitutionThreshold();

  /// Set the desired tangent speed for a conveyor belt behavior. In meters per
  /// second.
  void SetTangentSpeed(float speed);

  /// Get the desired tangent speed. In meters per second.
  float GetTangentSpeed() const;

  /// Evaluate this contact with your own manifold and transforms.
  virtual void Evaluate(b2Manifold* manifold, const b2Transform& xfA,
                        const b2Transform& xfB) = 0;

 protected:
  friend class PhysicsContactManager;
  friend class PhysicsWorld;
  friend class b2ContactSolver;
  friend class PhysicsBody;
  friend class PhysicsFixture;

  // Flags stored in m_flags
  enum {
    // Used when crawling contact graph when forming islands.
    e_islandFlag = 0x0001,

    // Set when the shapes are touching.
    e_touchingFlag = 0x0002,

    // This contact can be disabled (by user)
    e_enabledFlag = 0x0004,

    // This contact needs filtering because a fixture filter was changed.
    e_filterFlag = 0x0008,

    // This bullet contact had a TOI event
    e_bulletHitFlag = 0x0010,

    // This contact has a valid TOI in m_toi
    e_toiFlag = 0x0020
  };

  /// Flag this contact for filtering. Filtering will occur the next time step.
  void FlagForFiltering();

  static void AddType(b2ContactCreateFcn* createFcn,
                      b2ContactDestroyFcn* destroyFcn, b2Shape::Type typeA,
                      b2Shape::Type typeB);
  static void InitializeRegisters();
  static PhysicsContact* Create(PhysicsFixture* fixtureA, int32_t indexA,
                                PhysicsFixture* fixtureB, int32_t indexB,
                                PhysicsBlockAllocator* allocator);
  static void Destroy(PhysicsContact* contact, b2Shape::Type typeA,
                      b2Shape::Type typeB, PhysicsBlockAllocator* allocator);
  static void Destroy(PhysicsContact* contact,
                      PhysicsBlockAllocator* allocator);

  PhysicsContact() : m_fixtureA(nullptr), m_fixtureB(nullptr) {}
  PhysicsContact(PhysicsFixture* fA, int32_t indexA, PhysicsFixture* fB,
                 int32_t indexB) {
    m_flags = e_enabledFlag;

    m_fixtureA = fA;
    m_fixtureB = fB;

    m_indexA = indexA;
    m_indexB = indexB;

    m_manifold.pointCount = 0;

    m_prev = nullptr;
    m_next = nullptr;

    m_nodeA.contact = nullptr;
    m_nodeA.prev = nullptr;
    m_nodeA.next = nullptr;
    m_nodeA.other = nullptr;

    m_nodeB.contact = nullptr;
    m_nodeB.prev = nullptr;
    m_nodeB.next = nullptr;
    m_nodeB.other = nullptr;

    m_toiCount = 0;

    m_tangentSpeed = 0.0f;
  }
  virtual ~PhysicsContact() {}

  void Update(IPhysicsContactListener* listener);

  static b2ContactRegister s_registers[ee::ElementCount<b2Shape::Type>()]
                                      [ee::ElementCount<b2Shape::Type>()];
  static bool s_initialized;

  uint32_t m_flags;

 public:
  // World pool and list pointers.
  PhysicsContact* m_prev;
  PhysicsContact* m_next;

  // Nodes for connecting bodies.
  b2ContactEdge m_nodeA;
  b2ContactEdge m_nodeB;

  PhysicsFixture* m_fixtureA;
  PhysicsFixture* m_fixtureB;

  int32_t m_indexA;
  int32_t m_indexB;

  b2Manifold m_manifold;

  int32_t m_toiCount;
  float m_toi;

  float m_friction;
  float m_restitution;
  float m_restitutionThreshold;

  float m_tangentSpeed;
};
}  // namespace physics
}  // namespace base_engine
