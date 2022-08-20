#pragma once
#include <vector>

namespace base_engine
{
    

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
};
}
;
