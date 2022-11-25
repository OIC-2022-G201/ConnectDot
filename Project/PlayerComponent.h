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
#include "ISpriteAnimationComponent.h"
#include "InputManager.h"
#include "PhysicsBodyComponent.h"
#include "PlayerIdle.h"
#include "PlayerJump.h"
#include "PlayerMove.h"
#include "PlayerSneak.h"
#include "StateMachine.h"

namespace player {

class PlayerComponent final : public base_engine::Component {
  using Vector2 = Mof::CVector2;

 public:
  PlayerComponent(base_engine::Actor* owner, int update_order);
  void Start() override;
  void ProcessInput() override { machine_.ProcessInput(); }
  void Update() override;
  void OnCollision(const base_engine::SendManifold& manifold) override;

  void SetInput(const InputManager* input_manager) {
    input_manager_ = input_manager;
  }

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
  [[nodiscard]] base_engine::Game* GetGame() const { return owner_->GetGame(); }
  [[nodiscard]] base_engine::Actor* GetOwner() const { return owner_; }

 private:
  int have_beacon_count_ = MaxBeacon();

  const InputManager* input_manager_ = nullptr;

  til::Machine<PlayerIdle, PlayerMove, PlayerSneak, PlayerJump> machine_ =
      til::Machine{PlayerIdle{this}, PlayerMove{this}, PlayerSneak{this},
                   PlayerJump{this}};
  std::weak_ptr<base_engine::CollisionComponent> collision_;
  std::weak_ptr<base_engine::PhysicsBodyComponent> physics_body_;
  std::weak_ptr<base_engine::ISpriteAnimationComponent> animator_;
};
}  // namespace player