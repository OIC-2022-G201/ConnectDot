#include "CollisionComponent.h"

#include <utility>

#include "Actor.h"
#include "BaseEngineCore.h"
#include "IShape.h"

namespace base_engine {
CollisionComponent::CollisionComponent(Actor* owner, int update_order)
    : Component(owner, update_order),
      target_layer_(kCollisionFilterAllMask),
      object_layer_(kCollisionFilterAllMask) {
}

IShape* CollisionComponent::GetShape() const
{
    return shape_.get();
}

void CollisionComponent::SetShape(const std::shared_ptr<IShape>& shape) {
  shape_ = shape;
}
bool CollisionComponent::Collision(const CollisionComponent* target) const {
    return GetShape()->Collision(target->GetShape());
}

void CollisionComponent::SetTargetFilter(
    const std::bitset<kCollisionFilterSize>& layer) {
  target_layer_ = layer;
}

const std::bitset<kCollisionFilterSize>& CollisionComponent::GetTargetFilter() const
{
    return target_layer_;
}

void CollisionComponent::SetObjectFilter(
    const std::bitset<kCollisionFilterSize>& layer) {
  object_layer_ = layer;
}

const std::bitset<kCollisionFilterSize>& CollisionComponent::GetObjectFilter() const
{
    return object_layer_;
}



void CollisionComponent::CollisionSender(CollisionComponent* target) {
  owner_->SendCallbackMessage(BASE_ENGINE(Collider), target);
}

CollisionComponent::~CollisionComponent() {
  BASE_ENGINE(Collider)->Remove(this);
}

void CollisionComponent::Update() { shape_->SetOffset(owner_->GetPosition()); }

void CollisionComponent::Start()
{ BASE_ENGINE(Collider)->Register(this); }
}  // namespace base_engine
