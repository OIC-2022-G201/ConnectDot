#include "CollisionComponent.h"

#include "Actor.h"
#include "BaseEngineCore.h"
#include "IShape.h"

namespace base_engine {
CollisionComponent::CollisionComponent(Actor* owner, int update_order)
    : Component(owner, update_order) {}

IShape* CollisionComponent::GetShape() const { return shape_; }

void CollisionComponent::SetShape(IShape* shape) { shape_ = shape; }

void CollisionComponent::CollisionSender(CollisionComponent* target) {
  owner_->SendCallbackMessage(BASE_ENGINE(Collider), target);
}
}  // namespace base_engine
