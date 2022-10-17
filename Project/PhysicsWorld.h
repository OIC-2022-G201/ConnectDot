// @PhysicsWorld.h
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#pragma once
#include "PhysicsBlockAllocator.h"
#include "PhysicsVector2.h"
#include "PhysicsContactManager.h"

namespace base_engine::physics {
struct BodyDef;
class PhysicsBody;

class PhysicsWorld {
 public:
  /// Construct a world object.
  /// @param gravity the world gravity vector.
  PhysicsWorld(const PVec2& gravity);

  /// Destruct the world. All physics entities are destroyed and all heap memory
  /// is released.
  ~PhysicsWorld();

  /// Create a rigid body given a definition. No reference to the definition
  /// is retained.
  /// @warning This function is locked during callbacks.
  PhysicsBody* CreateBody(const BodyDef* def);

  /// Destroy a rigid body given a definition. No reference to the definition
  /// is retained. This function is locked during callbacks.
  /// @warning This automatically deletes all associated shapes and joints.
  /// @warning This function is locked during callbacks.
  void DestroyBody(PhysicsBody* body);

  /// Is the world locked (in the middle of a time step).
  [[nodiscard]] bool IsLocked() const noexcept { return m_locked; }

    void Step(float timeStep);

private:

friend class PhysicsBody;
  PhysicsBlockAllocator m_blockAllocator;
  PhysicsContactManager m_contactManager;
  PhysicsBody* m_bodyList = nullptr;
  int32_t m_bodyCount = 0;

  PVec2 m_gravity{};

  bool m_locked;
  bool m_newContacts;
};
}  // namespace base_engine::physics
