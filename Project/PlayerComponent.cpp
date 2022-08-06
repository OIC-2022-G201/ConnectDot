#include "PlayerComponent.h"

#include <string_view>
#include <type_traits>

#include "Actor.h"
#include "CollisionComponent.h"
using namespace std::string_view_literals;

namespace player {

PlayerComponent::PlayerComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order) {}

void PlayerComponent::OnCollision(base_engine::CollisionComponent* collision) {
  auto const tag = collision->GetActor()->GetTag();
  if (collision->GetActor()->GetTag() == "Block") {
    int n = 1;
  }
}
}  // namespace player