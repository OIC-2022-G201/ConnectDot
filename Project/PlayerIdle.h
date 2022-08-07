// @file PlayerIdle.h
// @brief プレイヤー停止のステート
// @author ICE
// @date 2022/08/07
//
// @details
#pragma once
#include "InputManager.h"

namespace player {
class PlayerJump;

class PlayerIdle {
  class PlayerComponent* player_;
  bool is_jump_ = false;
 public:
  explicit PlayerIdle(PlayerComponent* player);
  void Start();
  void Update();
  void ProcessInput();
  void End();

  template <typename Machine>
  void Transition(Machine& machine) const;
};
template <typename Machine>
void PlayerIdle::Transition(Machine& machine) const {
  if (is_jump_)
    machine.template TransitionTo<PlayerJump>();
}

}  // namespace player
