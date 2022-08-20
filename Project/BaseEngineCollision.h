#pragma once
#include "IBaseEngineCollider.h"

namespace base_engine {

class BaseEngineCollision final : public IBaseEngineCollider {
 public:
  ~BaseEngineCollision() override;
  void Collide() override;
  void Register(CollisionComponent* component) override;
  void Remove(CollisionComponent* component) override;

  void SendComponentsMessage(Component* component,
                             const SendManifold& manifold) override;
  
};
}  // namespace base_engine
