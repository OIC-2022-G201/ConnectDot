#pragma once
#include <vector>

#include "PhysicsVector2.h"

namespace base_engine {
namespace physics {
class PhysicsRayCastCallback;
struct PhysicsAABB;
class PhysicsQueryCallback;
}  // namespace physics

class Game;

class IBaseEngineCollider {
 protected:
  std::vector<class CollisionComponent*> body_list_;

 public:
  static IBaseEngineCollider* Create();
  virtual ~IBaseEngineCollider();
  virtual void Collide() = 0;
  virtual void Register(class CollisionComponent* collision) = 0;
  virtual void Remove(class CollisionComponent* collision) = 0;
  virtual void SendComponentsMessage(class Component* component,
                                     const class SendManifold& manifold);

  virtual void SetCallBack(Game* game) {}

  virtual void QueryAABB(physics::PhysicsQueryCallback* callback,
                         const physics::PhysicsAABB& aabb) = 0;
  virtual void RayCast(physics::PhysicsRayCastCallback* callback,
               const physics::PVec2& point1, const physics::PVec2& point2) const = 0;
};
}  // namespace base_engine