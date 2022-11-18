#include "PlayerComponent.h"

#include <string_view>
#include <type_traits>

#include "Actor.h"
#include "CollisionComponent.h"
#include "IPlayerAction.h"
#include "IShape.h"
#include "Player.h"
#include "SendManifold.h"
using namespace std::string_view_literals;

namespace player {

PlayerComponent::PlayerComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order) {}

void PlayerComponent::Start() {
  owner_->GetGame()->debug_render_.emplace_back([this]() {
    Mof::CGraphicsUtilities::RenderString(0, 60, "State:%d",
                                          machine_.current_state());

    Mof::CGraphicsUtilities::RenderString(0, 120, "force:x:%f,y:%f",
                                          physics_body_.lock()->GetForce().x,
                                          physics_body_.lock()->GetForce().y);
  });
  collision_ = owner_->GetComponent<base_engine::CollisionComponent>();
  physics_body_ = owner_->GetComponent<base_engine::PhysicsBodyComponent>();
  machine_.TransitionTo<PlayerIdle>();
}

void PlayerComponent::Update() {
  physics_body_.lock()->AddForce({0, kGravity});
  machine_.Update();
}

void PlayerComponent::OnCollision(const base_engine::SendManifold& manifold) {
  machine_.OnEvent(manifold.collision_b);
  auto const tag = manifold.collision_b->GetActor()->GetTag();
  if (const auto target = manifold.collision_b->GetActor();
      target->GetTag() == "Lever") {
    const auto get1 = target->GetComponent<IPlayerAction>();
    get1.lock()->Action();

    int n = 2;
  }
}

}  // namespace player