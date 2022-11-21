// @file PlayerIdle.h
// @brief プレイヤー停止のステート
// @author ICE
// @date 2022/08/07
//
// @details
#pragma once
#include "PhysicsBodyComponent.h"
#include "PlayerState.h"

namespace player {
class PlayerIdle {
  class PlayerComponent* player_;
  base_engine::PhysicsBodyComponent* body_;
  bool is_jump_ = false;
  bool is_move_ = false;
  bool is_sneak_ = false; 
 public:
  explicit PlayerIdle(PlayerComponent* player);
  void Start();
  void Update();
  void ProcessInput();
  void End();

  void OnEvent(base_engine::CollisionComponent* collision)
  {
      
  }
  template <typename Machine>
  void Transition(Machine& machine) const {

    if (is_jump_) {
      machine.template TransitionTo<PlayerJump>();
    }
    if (is_sneak_) {
      machine.template TransitionTo<PlayerSneak>();
    }
    if (is_move_) {
      machine.template TransitionTo<PlayerMove>();
    }
  }
};

}  // namespace player
