#include "CollisionComponent.h"

#include <utility>

#include "Actor.h"
#include "BaseEngineCore.h"
#include "GJK.h"
#include "IShape.h"
#include "PhysicsBody2D.h"
#include "PhysicsBodyComponent.h"
#include "PhysicsFixture.h"

namespace base_engine {
CollisionComponent::CollisionComponent(Actor* owner, int update_order)
    : Component(owner, update_order),
      target_layer_(kCollisionFilterAllMask),
      object_layer_(kCollisionFilterAllMask) {}

IShape* CollisionComponent::GetShape() const { return shape_.get(); }

void CollisionComponent::SetShape(const std::shared_ptr<IShape> shape) {
  shape_ = shape;
  if (is_start_) {
    Sync();
  }
}

void CollisionComponent::Sync() {
  BASE_ENGINE(Collider)->Remove(this);
  BASE_ENGINE(Collider)->Register(this);
}

physics::Manifold CollisionComponent::Collision(
    const CollisionComponent* target) const {
  if (GetShape()==nullptr || target->GetShape() == nullptr) return physics::Manifold{};
  return physics::detector::Gjk::Detect(
      *GetShape(), GetPosition(), *target->GetShape(), target->GetPosition());
}

void CollisionComponent::SetTargetFilter(
    const std::bitset<kCollisionFilterSize>& layer) {
  target_layer_ = layer;
  if (physics_body_) {
    if (!physics_body_->GetFixtureList()) return;

    auto filter = physics_body_->GetFixtureList()->GetFilterData();
    filter.maskTargetBits = target_layer_.to_ulong();
    physics_body_->GetFixtureList()->SetFilterData(filter);
  }
}

const std::bitset<kCollisionFilterSize>& CollisionComponent::GetTargetFilter()
    const {
  return target_layer_;
}

void CollisionComponent::SetObjectFilter(
    const std::bitset<kCollisionFilterSize>& layer) {
  object_layer_ = layer;
  if (physics_body_) {
    if (!physics_body_->GetFixtureList()) return;
    auto filter = physics_body_->GetFixtureList()->GetFilterData();
    filter.maskObjectBits = object_layer_.to_ulong();
    physics_body_->GetFixtureList()->SetFilterData(filter);
  }
}

const std::bitset<kCollisionFilterSize>& CollisionComponent::GetObjectFilter()
    const {
  return object_layer_;
}

void CollisionComponent::CollisionSender(const SendManifold& manifold) {
  owner_->SendCallbackMessage(BASE_ENGINE(Collider), manifold);
}

CollisionComponent::~CollisionComponent() {
  BASE_ENGINE(Collider)->Remove(this);
}

void CollisionComponent::Update() {}

void CollisionComponent::Start()
{
  is_start_ = true;
	BASE_ENGINE(Collider)->Register(this);
}

PhysicsBodyComponent* CollisionComponent::GetPhysicsBody() {
  if (!body_) {
    body_ = owner_->GetComponent<PhysicsBodyComponent>().lock().get();
  }
  return body_;
}

void CollisionComponent::SyncPosition() {
  auto p = GetPosition();

  physics_body_->SetTransform({p.x, p.y}, 0);
}

void CollisionComponent::SetEnabled(const bool enable) const
{ physics_body_->SetEnabled(enable);
}
}  // namespace base_engine
