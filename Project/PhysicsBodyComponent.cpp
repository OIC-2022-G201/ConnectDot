#include "PhysicsBodyComponent.h"

#include <Mof.h>

#include "CollisionComponent.h"
#include "SendManifold.h"

base_engine::PhysicsBodyComponent::PhysicsBodyComponent(Actor* owner,
                                                        int update_order)
    : Component(owner, update_order) {}

void base_engine::PhysicsBodyComponent::Start() {
  const auto collider = owner_->GetComponent<CollisionComponent>();
  if (collider.expired()) return;
  collider.lock()->SetPhysicsBody(this);
}
using enum base_engine::physics::BodyMotionType;
void base_engine::PhysicsBodyComponent::OnCollision(
    const SendManifold& manifold) {
  const auto this_collision = manifold.collision_a;
  const auto target_collision = manifold.collision_b;
  if (this_collision->GetTrigger() || target_collision->GetTrigger()) return;

  auto collision_depth = manifold.manifold;
  const auto target_body = target_collision->GetPhysicsBody();
  // Solver(collision_depth, target_body);
  Vector2 normal = collision_depth.normal;
  normal.x = std::abs(normal.x);
  normal.y = std::abs(normal.y);
  auto power = -GetForce() * normal;
  if (power.y < -10) {
    int n = 3;
  }
  auto power_abs = VectorUtilities::Abs(power);
  if (collision_depth.depth < 1.1f &&
      abs((GetForce() + power).y) < std::numeric_limits<float>::epsilon() &&
      g_pInput->IsKeyHold(MOFKEY_N)) {
    this_collision->SyncPosition();
    return;
  }
  AddForce(power);

  this_collision->SyncPosition();
}

void base_engine::PhysicsBodyComponent::Solver(
    physics::Manifold& manifold, const PhysicsBodyComponent* target_body) {
  if (target_body == nullptr) {
    auto v = manifold.normal * -manifold.depth;
    auto abs_v = v;
    abs_v.x = std::abs(abs_v.x);
    abs_v.y = std::abs(abs_v.y);

    auto froce = VectorUtilities::Abs(GetForce());

    if (g_pInput->IsKeyHold(MOFKEY_N) &&
        (manifold.normal.y == 1 || manifold.normal.y == -1)) {
      int n = 3;
    }

    if (0 < abs_v.x && 0 < froce.x && abs_v.y == 0) {
//      v.x *= 1.1f;
//      v.x = floor(v.x);
      owner_->Translation(v);
      manifold.normal.y = 0;
      return;
    }
    if (abs_v.y < abs_v.x && froce.x < froce.y && abs(froce.y - froce.x) > 13) {
      v.x = floor(-GetForce().x * 1.2f);
      v.y = -GetForce().y;
      AddForce({0, v.y});
    }
    owner_->Translation(v);
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

  if (motion_type_ == kKinematic && target_type == kKinematic) {
    owner_->Translation({manifold.normal * -manifold.depth * 0.5});
    return;
  }
}
