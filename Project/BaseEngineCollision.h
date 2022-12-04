#pragma once
#include "IBaseEngineCollider.h"

namespace base_engine {
    namespace physics
    {
        class PhysicsWorld;
        class PhysicsFixture;
    }

    class BaseEngineCollision final : public IBaseEngineCollider {
 public:
  ~BaseEngineCollision() override;
  BaseEngineCollision();
  void Collide() override;
  void Register(CollisionComponent* component) override;
  void Remove(CollisionComponent* component) override;

  void SendComponentsMessage(Component* component,
                             const SendManifold& manifold) override;
  void SetCallBack(Game* game) override;
  void Render(physics::PhysicsFixture* fixture);
  void QueryAABB(physics::PhysicsQueryCallback* callback, const physics::PhysicsAABB& aabb) override;
  void RayCast(physics::PhysicsRayCastCallback* callback, const physics::PVec2& point1,
      const physics::PVec2& point2) const override;
private:
  physics::PhysicsWorld* world_ = nullptr;
 int connectCount = 0;
    };
}  // namespace base_engine
