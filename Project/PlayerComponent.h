// @file PlayerComponent.h
// @brief プレイヤーを管理するクラス
// @author ICE
// @date 2022/08/07
//
// @details
#pragma once
#include <Math/Vector2.h>
#include <Utilities/GraphicsUtilities.h>

#include "Component.h"
#include "Game.h"
#include "GridPosition.h"
#include "HandlerRegistration.h"
#include "ISpriteAnimationComponent.h"
#include "InputManager.h"
#include "PhysicsBodyComponent.h"
#include "PlayerFall.h"
#include "PlayerIdle.h"
#include "PlayerJump.h"
#include "PlayerMove.h"
#include "PlayerSneak.h"
#include "PlayerSneakMove.h"
#include "PlayerVentAction.h"
#include "ReactiveProperty.h"
#include "StateMachine.h"


class VentComponent;

namespace tile_map {
class TileMapComponent;
}

namespace player {
enum class Dir { kLeft, kRight };
class PlayerComponent final : public base_engine::Component {
  using Vector2 = Mof::CVector2;
  using TileMapWeak =
      base_engine::ComponentDerivedWeakPtr<tile_map::TileMapComponent>;
 public:
  class PlayerListener;
  ~PlayerComponent() override;
  PlayerComponent(base_engine::Actor* owner, int update_order);
  void Start() override;
  void ProcessInput() override { machine_.ProcessInput(); }
  void Update() override;
  void OnCollision(const base_engine::SendManifold& manifold) override;
  void VentEnter(VentComponent* vent);

  void SetInput(const InputManager* input_manager) {
    input_manager_ = input_manager;
  }
  bool CanPlace(const GridPosition& pos) const;
  [[nodiscard]] bool IsJumpKey() const { return input_manager_->JumpFire(); }
  [[nodiscard]] float GetHorizontal() const {
    return input_manager_->MoveHorizontal();
  }
  [[nodiscard]] bool IsSneakKey() const { return input_manager_->SneakFire(); }
  [[nodiscard]] bool IsPlaceBeaconKey() const {
    return input_manager_->PlaceBeaconFire();
  }
  [[nodiscard]] bool IsCollectBeaconKey() const {
    return input_manager_->CollectBeaconFire();
  }

  [[nodiscard]] bool IsActionKey() const {
    return input_manager_->ActionFire();
  }
  [[nodiscard]] base_engine::CollisionComponent* GetCollision() const {
    return collision_.lock().get();
  }
  [[nodiscard]] base_engine::ISpriteAnimationComponent* GetAnimator() const {
    return animator_.lock().get();
  }
  [[nodiscard]] base_engine::PhysicsBodyComponent* PhysicsBody() const {
    return physics_body_.lock().get();
  }
  [[nodiscard]] int MaxBeacon() const;
  [[nodiscard]] int GetBeacon() const { return have_beacon_count_; }
  void SetBeacon(const int num) { have_beacon_count_ = num; }

  void LookAtRight() { dir_ = Dir::kRight; }
  void LookAtLeft() { dir_ = Dir::kLeft; }
  bool IsRight() const { return static_cast<Dir>(dir_) == Dir::kRight; }
  void MovedLookAt();

  bool IsGround() const { return is_ground_; }
  void SetGround(const bool ground) { is_ground_ = ground; }
  [[nodiscard]] base_engine::Game* GetGame() const { return owner_->GetGame(); }
  [[nodiscard]] base_engine::Actor* GetOwner() const { return owner_; }

  void SetMap(const TileMapWeak& map) { map_ = map; }

 private:
  int have_beacon_count_ = MaxBeacon();

  const InputManager* input_manager_ = nullptr;
  TileMapWeak map_;

  til::Machine<PlayerIdle, PlayerMove, PlayerSneak, PlayerSneakMove, PlayerJump,
               PlayerFall, PlayerVentAction>
      machine_ = til::Machine{PlayerIdle{this},  PlayerMove{this},
                              PlayerSneak{this}, PlayerSneakMove{this},
                              PlayerJump{this},  PlayerFall{this},
                              PlayerVentAction{this}};

  std::weak_ptr<base_engine::CollisionComponent> collision_;
  std::weak_ptr<base_engine::PhysicsBodyComponent> physics_body_;
  std::weak_ptr<base_engine::ISpriteAnimationComponent> animator_;
  std::weak_ptr<base_engine::SpriteComponent> sprite_;
  std::unique_ptr<PlayerListener> listener_;
  std::shared_ptr<HandlerRegistration> event_handler_;
  observable::ReactiveProperty<Dir> dir_ = Dir::kRight;
  bool is_ground_ = false;

 private:
  void CheckGround();
};
}  // namespace player