#include "PlayerComponent.h"

#include <Mof.h>

#include <string_view>
#include <type_traits>

#include "Actor.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "EventBus.h"
#include "EventHandler.h"
#include "GameOverSceneFactory.h"
#include "GoalEffectActor.h"
#include "GoalEvent.h"
#include "IMachineActionable.h"
#include "ObjectTileMapComponent.h"
#include "PhysicsFixture.h"
#include "PhysicsWorldCallBack.h"
#include "Player.h"
#include "SceneManager.h"
#include "SendManifold.h"
#include "ServiceLocator.h"
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

class PlayerComponent::PlayerListener final : public EventHandler<GoalEvent> {
  PlayerComponent& player_;

 public:
  explicit PlayerListener(PlayerComponent& player) : player_(player){};
  void OnEvent(GoalEvent& e) override {
    player_.can_control_ = false;
    player_.goal_event_ = true;
    new GoalEffectActor(player_.GetGame());
  }
};

PlayerComponent::~PlayerComponent() {}

PlayerComponent::PlayerComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order) {}

void PlayerComponent::Start() {
  listener_ = std::make_unique<PlayerListener>(*this);
  event_handler_ = EventBus::AddHandler(*listener_);

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
  sound_effect_ = new SoundEffectActor(owner_->GetGame());

  collision_ = owner_->GetComponent<CollisionComponent>();
  physics_body_ = owner_->GetComponent<PhysicsBodyComponent>();
  animator_ = owner_->GetComponent<ISpriteAnimationComponent>();



  machine_.TransitionTo<PlayerIdle>();
}

void PlayerComponent::ProcessInput() { machine_.ProcessInput(); }

void PlayerComponent::SetInput(const InputManager* input_manager) {
  input_manager_ = input_manager;
}

bool PlayerComponent::IsJumpKey() const { return input_manager_->JumpFire(); }

float PlayerComponent::GetHorizontal() const {
  float result = 0;
  if (can_control_) {
    result = input_manager_->MoveHorizontal();
  } else if (goal_event_) {
    result = 1;
  }

  return result;
}

bool PlayerComponent::IsSneakKey() const { return input_manager_->SneakFire(); }

bool PlayerComponent::IsPlaceBeaconKey() const {
  return input_manager_->PlaceBeaconFire();
}

bool PlayerComponent::IsCollectBeaconKey() const {
  return input_manager_->CollectBeaconFire();
}

bool PlayerComponent::IsActionKey() const {
  return input_manager_->ActionFire();
}

base_engine::CollisionComponent* PlayerComponent::GetCollision() const {
  return collision_.lock().get();
}

base_engine::ISpriteAnimationComponent* PlayerComponent::GetAnimator() const {
  return animator_.lock().get();
}

base_engine::PhysicsBodyComponent* PlayerComponent::PhysicsBody() const {
  return physics_body_.lock().get();
}

int PlayerComponent::GetBeacon() const { return have_beacon_count_; }

void PlayerComponent::SetBeacon(const int num) { have_beacon_count_ = num; }

void PlayerComponent::LookAtRight() { dir_ = Dir::kRight; }

void PlayerComponent::LookAtLeft() { dir_ = Dir::kLeft; }

bool PlayerComponent::IsRight() const {
  return static_cast<Dir>(dir_) == Dir::kRight;
}

bool PlayerComponent::IsGround() const { return is_ground_; }

void PlayerComponent::SetGround(const bool ground) { is_ground_ = ground; }

base_engine::Game* PlayerComponent::GetGame() const {
  return owner_->GetGame();
}

base_engine::Actor* PlayerComponent::GetOwner() const { return owner_; }

void PlayerComponent::SetMap(const TileMapWeak& map) { map_ = map; }

void PlayerComponent::PlaySoundEffect() const { sound_effect_->Play(300); }

void PlayerComponent::StopSoundEffect() const { sound_effect_->Stop(); }

void PlayerComponent::Update() {
  const auto aabb = collision_.lock()->AABB();
  sound_effect_->SetPosition({aabb.GetCenter().x,aabb.Bottom});
  physics_body_.lock()->AddForce({0, kGravity});
  machine_.Update();

  CheckGround();
  if (g_pInput->IsKeyPush(MOFKEY_L)) {
    auto a = std::any{1};
    GoalEvent goal{a};
    EventBus::FireEvent(goal);
  }
}

void PlayerComponent::OnCollision(const base_engine::SendManifold& manifold) {
  const auto actor = manifold.collision_b->GetActor();
  if (actor->GetTag() == "Enemy")
  {
    scene::LoadScene(kGameOver);
    return;
  }
	machine_.OnEvent(manifold.collision_b);
  if (input_manager_->ActionFire()) {
    if (const auto actionable = manifold.collision_b->GetActor()
                                    ->GetComponent<IMachineActionable>();
        !actionable.expired()) {
      actionable.lock()->Action(owner_);
    }
  }

}

void PlayerComponent::VentEnter(VentComponent* vent) {
  machine_.TransitionTo<PlayerVentAction>();
  machine_.OnEvent(vent);
}

bool PlayerComponent::CanPlace(const GridPosition& pos) const {
  const auto map = map_.lock();
  const bool space = map->GetCell(pos) == tile_map::kEmptyCell;
  const bool ground =
      map->GetCell(pos + GridPosition{0, 1}) != tile_map::kEmptyCell;
  const auto is_empty = ServiceLocator::Instance()
                            .Resolve<tile_map::ObjectTileMapComponent>()
                            ->GetCell(pos.x, pos.y) == tile_map::kEmptyCell;
  return space && ground && is_empty;
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
  p1.y += rect.GetHeight() - 4;
  physics::PVec2 p2 = p1;
  p2.y += 5;
  BASE_ENGINE(Collider)->RayCast(&callback, p1, p2);
  if (!callback.ground_fixture_) {
    p1.x += 96;
    p2.x += 96;
    BASE_ENGINE(Collider)->RayCast(&callback, p1, p2);
  }
  if (callback.ground_fixture_) {
    SetGround(true);
  } else {
    SetGround(false);
  }
}
}  // namespace player