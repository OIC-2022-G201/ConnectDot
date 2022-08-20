#include "IBaseEngineCollider.h"

#include "BaseEngineCollision.h"

namespace base_engine {
IBaseEngineCollider* IBaseEngineCollider::Create() {
  return new BaseEngineCollision;
}

IBaseEngineCollider::~IBaseEngineCollider() = default;

void IBaseEngineCollider::SendComponentsMessage(Component* component,
                                                const SendManifold& manifold) {}
}  // namespace base_engine