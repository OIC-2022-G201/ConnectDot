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
#include "PlayerIdle.h"
#include "PlayerJump.h"
#include "PlayerMove.h"
#include "PlayerSneak.h"
#include "StateMachine.h"

namespace player {

class PlayerComponent final : public base_engine::Component {
  using Vector2 = Mof::CVector2;
  til::Machine<PlayerIdle, PlayerMove, PlayerSneak, PlayerJump> machine_ =
      til::Machine{PlayerIdle{this}, PlayerMove{this}, PlayerSneak{this},
                   PlayerJump{this}};
  Vector2 velocity_;

 public:
  PlayerComponent(base_engine::Actor* owner, int update_order);
  void Start() override {
    owner_->GetGame()->debug_render_.emplace_back([this]()
    {
      Mof::CGraphicsUtilities::RenderString(0, 60, "State:%d",
                                            machine_.current_state());
    }
  );
  }
  void ProcessInput() override { machine_.ProcessInput(); }
  void Update() override {
    machine_.Update();
      
  }
  void OnCollision(base_engine::CollisionComponent* collision) override;

  void SetInput(const InputManager* input_manager) {
    input_manager_ = input_manager;
  }

  inline void AddVelocity(const Vector2& power) { velocity_ += power; }
  inline void AddVelocityX(const float power) { velocity_.x += power; }
  inline void AddVelocityY(const float power) { velocity_.y += power; }
  inline void SetVelocity(const Vector2& power) { velocity_ = power; }
  inline void SetVelocityX(const float power) { velocity_.x = power; }
  inline void SetVelocityY(const float power) { velocity_.y = power; }
  inline Vector2 GetVelocity() { return velocity_; }

  inline bool IsJumpKey() { return input_manager_->JumpFire(); }
  inline float GetHorizontal() { return input_manager_->MoveHorizontal(); }
  inline bool IsSneakKey() { return input_manager_->SneakFire(); }
  inline bool IsPlaceBeaconKey() { return input_manager_->PlaceBeaconFire(); }
  inline bool IsCollectBeaconKey() { return input_manager_->CollectBeaconFire(); }
  inline bool IsActionKey() { return input_manager_->ActionFire(); }

 private:
  const InputManager* input_manager_;
};
}  // namespace player