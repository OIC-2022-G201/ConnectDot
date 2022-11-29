// @PlayerSneakMove.h
// @brief
// @author ICE
// @date 2022/11/26
// 
// @details

#pragma once
#include <Math/Vector2.h>

#include "PhysicsBodyComponent.h"
#include "PlayerState.h"
namespace player {
class PlayerSneakMove {
  using Vector2 = Mof::CVector2;
  class PlayerComponent* player_;
  base_engine::PhysicsBodyComponent* body_;
  bool is_jump_ = false;
  bool is_move_ = false;
  bool is_idle_ = false;

 public:
  explicit PlayerSneakMove(PlayerComponent* player);

  void Start();

  void Update();

  void ProcessInput();

  void End();

  template <typename Machine>
  void Transition(Machine& machine) const {
    if (is_jump_) {
      machine.template TransitionTo<PlayerJump>();
    }
    if (is_idle_) {
      machine.template TransitionTo<PlayerIdle>();
    }
    if (!is_move_) {
      machine.template TransitionTo<PlayerSneak>();
    }
  }
};
}  // namespace player