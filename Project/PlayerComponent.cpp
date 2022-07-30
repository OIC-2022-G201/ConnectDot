#include "PlayerComponent.h"

#include "Actor.h"
#include "CollisionComponent.h"
#include <string_view>
#include <type_traits>
using namespace std::string_view_literals;
PlayerComponent::PlayerComponent(base_engine::Actor* owner, int update_order): Component(owner, update_order)
{
}

void PlayerComponent::OnCollision(base_engine::CollisionComponent* collision)
{
  auto const tag = collision->GetActor()->GetTag();
  if (collision->GetActor()->GetTag() == "Block")
  {
    int n = 1;

  }
}
