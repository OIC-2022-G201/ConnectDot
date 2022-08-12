#include "PlayerComponent.h"

#include <string_view>
#include <type_traits>

#include "Actor.h"
#include "CollisionComponent.h"
#include "IShape.h"
using namespace std::string_view_literals;

namespace player {

PlayerComponent::PlayerComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order) {}

void PlayerComponent::OnCollision(base_engine::CollisionComponent* collision) {
  auto const tag = collision->GetActor()->GetTag();
  if (collision->GetActor()->GetTag() == "Field") {
    int n = 1;
    auto block_top = collision->GetActor()->GetPosition().y;
    auto p_bottom = owner_->GetPosition().y + 200;
    auto diff = block_top - p_bottom;
    if (diff<0)
    {
      owner_->AddPosition({0,diff});
    }
  }
}
}  // namespace player