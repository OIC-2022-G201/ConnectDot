#include "IBaseEngineCollider.h"

#include "BaseEngineCollision.h"

namespace base_engine {
IBaseEngineCollider* IBaseEngineCollider::Create() {
  return new BaseEngineCollision;
}

IBaseEngineCollider::~IBaseEngineCollider() = default;

void IBaseEngineCollider::SendComponentsMessage(Component* component,
                                                CollisionComponent* collision) {}
}  // namespace base_engine