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
struct PhysicsManifold;
class PhysicsBody;
class PhysicsContact;

struct PhysicsContactEdge {
  PhysicsBody* other;
  PhysicsContact* contact;
  PhysicsContactEdge* prev;
  PhysicsContactEdge* next;
};
typedef PhysicsContact* PhysicsContactCreateFcn(
    PhysicsFixture* fixtureA, int32_t indexA, PhysicsFixture* fixtureB,
    int32_t indexB, PhysicsBlockAllocator* allocator);
typedef void PhysicsContactDestroyFcn(PhysicsContact* contact,
                                      PhysicsBlockAllocator* allocator);

struct PhysicsContactRegister {
  PhysicsContactCreateFcn* createFcn;
  PhysicsContactDestroyFcn* destroyFcn;
  bool primary;
};
class PhysicsContact {
 public:
  bool IsTouching() const {
    return (m_flags & e_touchingFlag) == e_touchingFlag;
  }

  PhysicsContact* GetNext() { return m_next; }
  const PhysicsContact* GetNext() const { return m_next; }

  PhysicsFixture* GetFixtureA() { return m_fixtureA; }
  const PhysicsFixture* GetFixtureA() const { return m_fixtureA; }

  int32_t GetChildIndexA() const { return m_indexA; }

  PhysicsFixture* GetFixtureB() { return m_fixtureB; }
  const PhysicsFixture* GetFixtureB() const { return m_fixtureB; }

  int32_t GetChildIndexB() const { return m_indexB; }

  virtual void Evaluate(PhysicsManifold* manifold, const PhysicsTransform& xfA,
                        const PhysicsTransform& xfB) = 0;

 protected:
  friend class PhysicsContactManager;
  friend class PhysicsWorld;
  friend class PhysicsContactSolver;
  friend class PhysicsBody;
  friend class PhysicsFixture;

  // Flags stored in m_flags
  enum {
    e_islandFlag = 0x0001,

    e_touchingFlag = 0x0002,

    e_enabledFlag = 0x0004,
  };

  void FlagForFiltering();

  static void AddType(PhysicsContactCreateFcn* createFcn,
                      PhysicsContactDestroyFcn* destroyFcn,
                      PhysicsShape::Type typeA, PhysicsShape::Type typeB);
  static void InitializeRegisters();
  static PhysicsContact* Create(PhysicsFixture* fixtureA, int32_t indexA,
                                PhysicsFixture* fixtureB, int32_t indexB,
                                PhysicsBlockAllocator* allocator);
  static void Destroy(PhysicsContact* contact, PhysicsShape::Type typeA,
                      PhysicsShape::Type typeB,
                      PhysicsBlockAllocator* allocator);
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

  static PhysicsContactRegister
      s_registers[ee::ElementCount<PhysicsShape::Type>()]
                 [ee::ElementCount<PhysicsShape::Type>()];
  static bool s_initialized;

  uint32_t m_flags;

 public:
  PhysicsContact* m_prev;
  PhysicsContact* m_next;

  PhysicsContactEdge m_nodeA;
  PhysicsContactEdge m_nodeB;

  PhysicsFixture* m_fixtureA;
  PhysicsFixture* m_fixtureB;

  int32_t m_indexA;
  int32_t m_indexB;

  PhysicsManifold m_manifold;

  int32_t m_toiCount;
  float m_toi;

  float m_friction;
  float m_restitution;
  float m_restitutionThreshold;

  float m_tangentSpeed;
};
}  // namespace physics
}  // namespace base_engine
