#include "PlayerComponent.h"

#include <string_view>
#include <type_traits>

#include "Actor.h"
#include "CollisionComponent.h"
#include "IShape.h"
#include "Player.h"
using namespace std::string_view_literals;

namespace player {

PlayerComponent::PlayerComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order) {}

void PlayerComponent::Start()
{
    owner_->GetGame()->debug_render_.emplace_back([this]() {
        Mof::CGraphicsUtilities::RenderString(0, 60, "State:%d",
                                              machine_.current_state());
    });
    collision_ = owner_->GetComponent<base_engine::CollisionComponent>();
}

void PlayerComponent::Update()
{
  machine_.Update();
  AddVelocityY(kGravity);
  owner_->AddPosition(GetVelocity());
}

void PlayerComponent::OnCollision(base_engine::CollisionComponent* collision) {
  machine_.OnEvent(collision);
  auto const tag = collision->GetActor()->GetTag();
  if (collision->GetActor()->GetTag() == "Field") {
    auto block_right = collision->AABB().Right;
    auto p_left = collision_->AABB().Left;
    auto diffX = p_left - block_right;
    auto block_top = collision->AABB().Top;
    auto p_bottom = collision_->AABB().Bottom;
    auto diffY = block_top - p_bottom;
    if (diffY > 0 &&diffX <= 0)
    {
      SetVelocityX(0);
      owner_->AddPosition({0, diffX });
      collision_->Update();
        
    }

    if (diffY < 0)
    {
      SetVelocityY(0);
      owner_->AddPosition({0, diffY});
      collision_->Update();
    }
  }
}
}  // namespace player