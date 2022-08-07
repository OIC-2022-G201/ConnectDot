// @file PlayerComponent.h
// @brief プレイヤーを管理するクラス
// @author ICE
// @date 2022/08/07
//
// @details
#pragma once
#include "Component.h"
#include "PlayerIdle.h"
#include "PlayerJump.h"
#include "StateMachine.h"

class InputManager;
namespace player {

class PlayerComponent final : public base_engine::Component {
  til::Machine<PlayerIdle, PlayerJump> machine_ =
      til::Machine{PlayerIdle{this}, PlayerJump{}};

 public:
  PlayerComponent(base_engine::Actor* owner, int update_order);
  void Start() override
  { 
  }
  void ProcessInput() override { machine_.ProcessInput(); }
  void Update() override { machine_.Update(); }
  void OnCollision(base_engine::CollisionComponent* collision) override;

    void SetInput(const InputManager* input_manager) { input_manager_ = input_manager;
    }
public:
    const InputManager* input_manager_;
};
}  // namespace player