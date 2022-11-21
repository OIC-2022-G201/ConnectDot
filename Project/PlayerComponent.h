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

  inline bool IsJumpKey() { return input_manager_->JumpFire(); }
  inline float GetHorizontal() { return input_manager_->MoveHorizontal(); }
  inline bool IsSneakKey() { return input_manager_->SneakFire(); }
  inline bool IsPlaceBeaconKey() { return input_manager_->PlaceBeaconFire(); }
  inline bool IsCollectBeaconKey() {
    return input_manager_->CollectBeaconFire();
  }
  inline bool IsActionKey() { return input_manager_->ActionFire(); }
  base_engine::CollisionComponent* GetCollision() { return collision_.lock().get(); }
  base_engine::PhysicsBodyComponent* PhysicsBody() {
    return physics_body_.lock().get();
  }
  int MaxBeacon() const { return 90; }
  int GetBeacon() const { return have_beacon_count_; }
  void SetBeacon(const int num) { have_beacon_count_ = num; }
  base_engine::Game* GetGame() { return owner_->GetGame(); }
  base_engine::Actor* GetOwner() { return owner_; }
 private:
  int have_beacon_count_ = MaxBeacon();

  const InputManager* input_manager_ = nullptr;

  til::Machine<PlayerIdle, PlayerMove, PlayerSneak, PlayerJump> machine_ =
      til::Machine{
          PlayerIdle{this}, PlayerMove{this},
                   PlayerSneak{this},
                   PlayerJump{this}};
  std::weak_ptr<base_engine::CollisionComponent> collision_;
private:
  std::weak_ptr < base_engine::PhysicsBodyComponent> physics_body_;
};
}  // namespace player