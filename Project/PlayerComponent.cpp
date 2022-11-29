#include "PlayerComponent.h"

#include <Mof.h>

#include <string_view>
#include <type_traits>

#include "Actor.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "IMachineActionable.h"
#include "PhysicsFixture.h"
#include "PhysicsWorldCallBack.h"
#include "Player.h"
#include "SendManifold.h"
#include "SpriteComponent.h"
#include "TileMapComponent.h"
using namespace std::string_view_literals;
using namespace base_engine;
namespace player {
class HitGroundCallback final : public physics::PhysicsRayCastCallback {
 public:
  HitGroundCallback() {}

  float ReportFixture(physics::PhysicsFixture* fixture,
                      const physics::PVec2& point, const physics::PVec2& normal,
                      float fraction) override {
    if (fixture->collision_->GetObjectFilter() == kFieldObjectFilter) {
      ground_fixture_ = fixture;
      return 0;
    }
    return fraction;
  }
  physics::PhysicsFixture* ground_fixture_ = nullptr;
};
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
  sprite_ = owner_->GetComponent<SpriteComponent>();
  dir_.Subscribe([this](const Dir dir) {
    switch (dir) {
      case Dir::kLeft:
        sprite_.lock()->SetFlip(Flip::kHorizontal);
        break;
      case Dir::kRight:
        sprite_.lock()->SetFlip(Flip::kNone);
        break;
    }
  });
  collision_ = owner_->GetComponent<CollisionComponent>();
  physics_body_ = owner_->GetComponent<PhysicsBodyComponent>();
  animator_ = owner_->GetComponent<ISpriteAnimationComponent>();
  machine_.TransitionTo<PlayerIdle>();
}

void PlayerComponent::Update() {
  physics_body_.lock()->AddForce({0, kGravity});
  machine_.Update();

  CheckGround();
}

void PlayerComponent::OnCollision(const base_engine::SendManifold& manifold) {
  machine_.OnEvent(manifold.collision_b);
  if (input_manager_->ActionFire()) {
    if (const auto actionable = manifold.collision_b->GetActor()
                                    ->GetComponent<IMachineActionable>();
        !actionable.expired()) {
      actionable.lock()->Action(owner_);
    }
  }
}

bool PlayerComponent::CanPlace(const GridPosition& pos) const {
  const auto map = map_.lock();
  const bool space = map->GetCell(pos) == tile_map::kEmptyCell;
  const bool ground =
      map->GetCell(pos + GridPosition{0, 1}) != tile_map::kEmptyCell;
  return space && ground;
}

int PlayerComponent::MaxBeacon() const { return 90; }

void PlayerComponent::MovedLookAt() {
  if (GetHorizontal() > 0)
    LookAtRight();
  else if (GetHorizontal() < 0)
    LookAtLeft();
}

void PlayerComponent::CheckGround() {
  HitGroundCallback callback;
  const auto rect = sprite_.lock()->GetClipRect();

  physics::PVec2 p1 = {owner_->GetPosition().x + 80, owner_->GetPosition().y};
  p1.y += rect.GetHeight() - 2;
  physics::PVec2 p2 = p1;
  p2.y += 2;
  BASE_ENGINE(Collider)->RayCast(&callback, p1, p2);
  if (!callback.ground_fixture_) {
    p1.x += 96;
    p2.x += 96;
    BASE_ENGINE(Collider)->RayCast(&callback, p1, p2);
  }
  if (callback.ground_fixture_) {
    if (g_pInput->IsKeyHold(MOFKEY_Q)) {
      int n = 3;
    }
    SetGround(true);
  } else {
    SetGround(false);
  }
}
}  // namespace player