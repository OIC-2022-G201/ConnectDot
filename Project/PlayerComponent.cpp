#include "PlayerComponent.h"

#include <string_view>
#include <type_traits>

#include "Actor.h"
#include "CollisionComponent.h"
#include "IShape.h"
#include "Player.h"
#include "SendManifold.h"
using namespace std::string_view_literals;

namespace player {

PlayerComponent::PlayerComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order) {}

void PlayerComponent::Start()
{
    owner_->GetGame()->debug_render_.emplace_back([this]() {
        Mof::CGraphicsUtilities::RenderString(0, 60, "State:%d",
                                              machine_.current_state());

    Mof::CGraphicsUtilities::RenderString(0, 120, "force:x:%f,y:%f",
                                          physics_body_->GetForce().x,
                                          physics_body_->GetForce().y);
    });
    collision_ = owner_->GetComponent<base_engine::CollisionComponent>();
    physics_body_ = owner_->GetComponent<base_engine::PhysicsBodyComponent>();
    machine_.TransitionTo<PlayerIdle>();
}

void PlayerComponent::Update()
{
  physics_body_->AddForce({0,kGravity});
  machine_.Update();
}

void PlayerComponent::OnCollision(const base_engine::SendManifold& manifold) {
  machine_.OnEvent(manifold.collision_b);
  auto const tag = manifold.collision_b->GetActor()->GetTag();
  if (manifold.collision_b->GetActor()->GetTag() == "Field") {

    /*
    auto block_right = collision->AABB().Right;
    auto p_left = collision_->AABB().Left;
    auto diffX = p_left - block_right;
    auto block_top = collision->AABB().Top;
    auto p_bottom = collision_->AABB().Bottom;
    auto diffY = block_top - p_bottom;
    if (diffY > 0 &&diffX <= 0)
    {
      SetVelocityX(0);
      owner_->Translation({0, diffX });
      collision_->Update();
        
    }

    if (diffY < 0)
    {
      SetVelocityY(0);
      owner_->Translation({0, diffY});
      collision_->Update();
    }
    */
  }
}
}  // namespace player