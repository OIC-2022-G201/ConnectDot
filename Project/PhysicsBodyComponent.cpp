#include "PhysicsBodyComponent.h"

#include "CollisionComponent.h"
#include "SendManifold.h"

base_engine::PhysicsBodyComponent::PhysicsBodyComponent(Actor* owner,
                                                        int update_order)
    : Component(owner, update_order) {}

void base_engine::PhysicsBodyComponent::Start() {
  const auto collider = owner_->GetComponent<CollisionComponent>();
  if (collider == nullptr) return;
  collider->SetPhysicsBody(this);
}
using enum base_engine::physics::BodyMotionType;
void base_engine::PhysicsBodyComponent::OnCollision(
    const SendManifold& manifold) {
  const auto this_collision = manifold.collision_a;
  const auto target_collision = manifold.collision_b;
  if (this_collision->GetTrigger() || target_collision->GetTrigger()) return;

  const auto collision_depth = manifold.manifold;
  const auto target_body = target_collision->GetPhysicsBody();

  Solver(collision_depth, target_body);
  AddForce(-GetForce() * collision_depth.normal);
}

void base_engine::PhysicsBodyComponent::Solver(
    const physics::Manifold& manifold,
    const PhysicsBodyComponent* target_body) const
{
  if (target_body == nullptr) {
    owner_->Translation({manifold.normal * -manifold.depth});
    return;
  }

  const auto target_type = target_body->motion_type_;
  if (motion_type_ == kDynamic && target_type == kDynamic) {
    owner_->Translation({manifold.normal * -manifold.depth * 0.5f});
    return;
  }

  if (motion_type_ == kDynamic && target_type != kDynamic) {
    owner_->Translation({manifold.normal * -manifold.depth});
    return;
  }

  if (motion_type_ == kKinematic && motion_type_ == kKinematic) {
    owner_->Translation({manifold.normal * -manifold.depth * 0.5});
    return;
  }
}
