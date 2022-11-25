#include "PlayerComponent.h"

#include <string_view>
#include <type_traits>

#include "Actor.h"
#include "CollisionComponent.h"
#include "IShape.h"
#include "LeverStubActor.h"
#include "Player.h"
#include "SendManifold.h"
using namespace std::string_view_literals;
using namespace base_engine;
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
  collision_ = owner_->GetComponent<CollisionComponent>();
  physics_body_ = owner_->GetComponent<PhysicsBodyComponent>();
  animator_ = owner_->GetComponent<ISpriteAnimationComponent>();
  machine_.TransitionTo<PlayerIdle>();
}

void PlayerComponent::Update() {
  physics_body_.lock()->AddForce({0, kGravity});
  machine_.Update();

}

void PlayerComponent::OnCollision(const base_engine::SendManifold& manifold) {
  machine_.OnEvent(manifold.collision_b);
  if (input_manager_->ActionFire())
  {
      if (const auto actionable = manifold.collision_b->GetActor()->GetComponent<IActionable>(); !actionable.expired())
    {
      actionable.lock()->Action();
    }
  }
}

int PlayerComponent::MaxBeacon() const
{ return 90; }
}  // namespace player