#pragma once
#include "InputManager.h"

namespace player {
class Jump;

class Idle {
  class PlayerComponent* player_;
  bool is_jump_ = false;
 public:
  explicit Idle(PlayerComponent* player);
  void Start();
  void Update();
  void ProcessInput();
  void End();

  template <typename Machine>
  void Transition(Machine& machine) const;
};
template <typename Machine>
void Idle::Transition(Machine& machine) const {
  if (is_jump_)
    machine.template TransitionTo<Jump>();
}

}  // namespace player
