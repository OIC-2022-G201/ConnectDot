#include "PlayerComponent.h"

#include <Mof.h>

#include <fstream>
#include <string_view>
#include <type_traits>

#include "ActionToolTipComponent.h"
#include "Actor.h"
#include "AudioVolume.h"
#include "BeaconPowerUpActionEvent.h"
#include "BeaconPowerUpActor.h"
#include "BinaryArchive.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "DummyEmptyBeaconActor.h"
#include "EventBus.h"
#include "EventHandler.h"
#include "GameOverEvent.h"
#include "GameOverSceneFactory.h"
#include "GoalEffectActor.h"
#include "GoalEvent.h"
#include "IMachineActionable.h"
#include "ObjectTileMapComponent.h"
#include "PauseManager.h"
#include "PhysicsFixture.h"
#include "PhysicsWorldCallBack.h"
#include "Player.h"
#include "ResourceContainer.h"
#include "SceneManager.h"
#include "SendManifold.h"
#include "SpriteComponent.h"
#include "TextArchive.h"
#include "TileMapComponent.h"
#include "TransitionParameter.h"

using namespace std::string_view_literals;
using namespace base_engine;
namespace player {
class HitGroundCallback final : public physics::PhysicsRayCastCallback {
 public:
  HitGroundCallback() {}

  float ReportFixture(physics::PhysicsFixture* fixture,
                      const physics::PVec2& point, const physics::PVec2& normal,
                      float fraction) override {
    if (fixture->collision_->GetTrigger()) {
      return fraction;
    }
    if (fixture->collision_->GetObjectFilter() == kFieldObjectFilter) {
      ground_fixture_ = fixture;
      return 0;
    }
    return fraction;
  }
  physics::PhysicsFixture* ground_fixture_ = nullptr;
};

class PlayerComponent::PlayerListener final
    : public EventHandler<GoalEvent>,
      public EventHandler<BeaconPowerUpActionEvent> {
  PlayerComponent& player_;

 public:
  explicit PlayerListener(PlayerComponent& player) : player_(player){};
  void OnEvent(GoalEvent& e) override {
    player_.machine_.TransitionTo<PlayerGoal>();
    player_.goal_event_ = true;
    new GoalEffectActor(player_.GetGame());
  }

  void OnEvent(BeaconPowerUpActionEvent& e) override {
    if (player_.GetCurrentBeaconPowerUp() < player_.GetLimitBeaconPowerUp()) {
      dynamic_cast<std::remove_cv_t<BeaconActor*>>(
          std::any_cast<Actor*>(e.GetSender()))
          ->LevelUp();
      player_.IncrementCurrentBeaconPowerUp();
    }
  }
};

PlayerComponent::~PlayerComponent() {}

PlayerComponent::PlayerComponent(base_engine::Actor* owner, int update_order)
    : Component(owner, update_order) {}

struct JumpParameter {
  float height;
  int time;
  template <class Archive>
  void FROZEN_SERIALIZE_FUNCTION_NAME(Archive& archive) {
    archive(height, time);
  }
};

void PlayerComponent::Start() {
  listener_ = std::make_unique<PlayerListener>(*this);
  event_handlers_.emplace_back(EventBus::AddHandler<GoalEvent>(*listener_));
  event_handlers_.emplace_back(
      EventBus::AddHandler<BeaconPowerUpActionEvent>(*listener_));
  ServiceLocator::Instance().Resolve<PauseManager>()->IsOpen().Subscribe(
      [this](bool open) { can_control_ = !open; });

  JumpParameter jump_parameter;
  {
    constexpr std::string_view PlayerJumpParameter =
        "Meta/Player/PlayerJumpParameter.txt";
    if (fs::exists(PlayerJumpParameter)) {
      std::ifstream stream;
      stream.open(PlayerJumpParameter);
      {
        frozen::TextInputArchive archive{stream};
        archive(jump_parameter);
      }
    } else {
      std::ofstream stream;
      stream.open(PlayerJumpParameter);
      {
        jump_parameter.height = 450;
        jump_parameter.time = 120;
        frozen::TextOutputArchive archive{stream};
        archive(jump_parameter);
      }
    }
    jump_height_ = jump_parameter.height;
    jump_time_ = jump_parameter.time;
  }

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
  audio_stream_ = new AudioStreamComponent(owner_);
  audio_stream_->AssetLoad("PlayerRundingSE");
  audio_stream_->SetLoop(true);
  audio_stream_->SetVolume(
      ServiceLocator::Instance().Resolve<AudioVolume>()->SEVolume());
  sound_effect_ = new SoundEffectActor(owner_->GetGame());

  const auto beacon_dummy = new DummyEmptyBeaconActor(owner_->GetGame());
  beacon_dummy->SetPlayer(this);
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
  return can_control_ && input_manager_->ActionFire();
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

void PlayerComponent::PlayRunAudio() const {
  audio_stream_->SetLoop(false);
  if (audio_stream_->IsPlay()) return;
  audio_stream_->Play();
}

void PlayerComponent::StopRunAudio() const { audio_stream_->SetLoop(false); }

void PlayerComponent::ActionKey(const CollisionComponent* collision) {
  if (!IsGround()) return;
  if ((collision->GetObjectFilter().to_ulong() &
       CollisionLayer::Layer{CollisionLayer::kActionable}) == 0)
    return;
  const auto machine_actor = collision->GetActor();
  const auto machine_component =
      machine_actor->GetComponent<IMachineActionable>();
  if (machine_component.expired() ||
      !machine_component.lock()->CanInteractive(owner_))
    return;
  action_machine_buffer_.emplace_back(machine_actor);
}

void PlayerComponent::MachineActionExecute() {
  if (action_machine_buffer_.empty()) return;

  const auto pos = owner_->GetPosition() + Vector2{64, 0};

  std::ranges::sort(
      action_machine_buffer_, [&pos](const Actor* rth, const Actor* lth) {
        return VectorUtilities::Length(
                   VectorUtilities::Abs(rth->GetPosition() - pos)) <
               VectorUtilities::Length(
                   VectorUtilities::Abs(lth->GetPosition() - pos));
      });
  for (const auto& machine : action_machine_buffer_) {
    const auto actionable = machine->GetComponent<IMachineActionable>();
    if (actionable.expired()) continue;
    ActionToolTipComponent::Create(machine, actionable).lock()->Show();
    if (!IsActionKey()) break;
    actionable.lock()->Action(owner_);
    break;
  }
  action_machine_buffer_.clear();
}

void PlayerComponent::Update() {
  const auto aabb = collision_.lock()->AABB();
  sound_effect_->SetPosition({aabb.GetCenter().x, aabb.Bottom});
  physics_body_.lock()->AddForce({0, kGravity});

  if (!can_control_) {
    machine_.TransitionTo<PlayerIdle>();
    return;
  }
  machine_.Update();

  CheckGround();
  MachineActionExecute();

  if (g_pInput->IsKeyPush(MOFKEY_L)) {
    auto a = std::any{1};
    GoalEvent goal{a};
    EventBus::FireEvent(goal);
  }
}

void PlayerComponent::OnCollision(const base_engine::SendManifold& manifold) {
  const auto actor = manifold.collision_b->GetActor();
  if (actor->GetTag() == "Enemy") {
    std::any sender = this;
    GameOverEvent game_over_event{sender};
    EventBus::FireEvent(game_over_event);
    scene::LoadScene(kGameOver);
    return;
  }
  if (!can_control_) return;
  machine_.OnEvent(manifold.collision_b);
  ActionKey(manifold.collision_b);
}

void PlayerComponent::VentEnter(VentComponent* vent) {
  machine_.TransitionTo<PlayerVentAction>();
  machine_.OnEvent(vent);
}

bool PlayerComponent::CanPlace(const GridPosition& pos) const {
  const auto map = map_.lock();
  const auto object_map = ComponentServiceLocator::Instance()
                              .Resolve<tile_map::ObjectTileMapComponent>();
  const bool space = map->GetCell(pos) == tile_map::kEmptyCell &&
                     object_map->GetCell(pos) == tile_map::kEmptyCell;
  const auto bottom_pos = pos + GridPosition{0, 1};
  const bool ground =
      (map->GetCell(bottom_pos) != tile_map::kEmptyCell ||
       object_map->GetCell(bottom_pos) == tile_map::kCanOnPlace ||
       object_map->GetCell(bottom_pos) == tile_map::kCanOnPlace + 1) &&
      object_map->GetCell(bottom_pos) != tile_map::kNotPutCell;
  return space && ground;
}

std::optional<GridPosition> PlayerComponent::SearchPlacePosition() const {
  std::optional<GridPosition> result;

  auto pos = GridPosition::VectorTo(owner_->GetPosition());
  pos.x += IsRight() ? 1 : 0;
  pos.y += 1;

  if (CanPlace(pos)) {
    result = pos;
    return result;
  }
  pos.x -= IsRight() ? 1 : -1;
  if (CanPlace(pos)) {
    result = pos;
    return result;
  }

  return std::nullopt;
}

int PlayerComponent::MaxBeacon() const { return 900; }

void PlayerComponent::MovedLookAt() {
  if (GetHorizontal() > 0)
    LookAtRight();
  else if (GetHorizontal() < 0)
    LookAtLeft();
}

void PlayerComponent::CheckGround() {
  HitGroundCallback callback;
  const auto rect = sprite_.lock()->GetClipRect();

  physics::PVec2 p1 = {owner_->GetPosition().x + 100, owner_->GetPosition().y};
  p1.y += rect.GetHeight() - 4;
  physics::PVec2 p2 = p1;
  p2.y += 5;
  BASE_ENGINE(Collider)->RayCast(&callback, p1, p2);
  if (!callback.ground_fixture_) {
    p1.x += 40;
    p2.x += 40;
    BASE_ENGINE(Collider)->RayCast(&callback, p1, p2);
  }
  if (callback.ground_fixture_) {
    SetGround(true);
  } else {
    SetGround(false);
  }
}
}  // namespace player