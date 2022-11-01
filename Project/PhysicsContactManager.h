// @PhysicsContactManager.h
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#pragma once
#include <cstdint>

#include "BroadPhase.h"

namespace base_engine::physics {
class PhysicsContact;

class PhysicsContact;
class IPhysicsContactFilter;
class IPhysicsContactListener;
class PhysicsBlockAllocator;

class PhysicsContactManager {
 public:
  PhysicsContactManager();

  // Broad-phase callback.
  void AddPair(void* proxyUserDataA, void* proxyUserDataB);

  void FindNewContacts();

  void Destroy(PhysicsContact* c);

  void Collide();

  bp::BroadPhase m_broadPhase;
  PhysicsContact* m_contactList{};
  int32_t m_contactCount{};
  IPhysicsContactFilter* m_contactFilter{};
  IPhysicsContactListener* m_contactListener{};
  PhysicsBlockAllocator* m_allocator{};
};
}  // namespace base_engine::physics
