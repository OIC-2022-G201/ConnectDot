// @file PlayerMove.h
// @brief プレイヤー移動のステート
// @author ICE
// @date 2022/08/07
//
// @details

#pragma once
#include <Math/Vector2.h>

#include "PlayerState.h"

namespace player {
class PlayerMove {
  using Vector2 = Mof::CVector2;
  class PlayerComponent* player_;
  bool is_idle_ = false;
  bool is_sneak_ = false;
  bool is_jump_ = false;
 public:
  explicit PlayerMove(PlayerComponent* player);
  void Start();
  void Update();
  void ProcessInput();
  void End();

  template <typename Machine>
  void Transition(Machine& machine) const;
};
template <typename Machine>
void player::PlayerMove::Transition(Machine& machine) const {
  if (is_idle_) machine.template TransitionTo<PlayerIdle>();
  if (is_sneak_) machine.template TransitionTo<PlayerSneak>();
  if (is_jump_) machine.template TransitionTo<PlayerJump>();
}
}  // namespace player