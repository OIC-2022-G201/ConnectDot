// @PlayerFall.h
// @brief
// @author ICE
// @date 2022/11/26
//
// @details

#pragma once
#include "PhysicsBodyComponent.h"
#include "PlayerState.h"

namespace player {

class PlayerFall {
  int frame_ = 0;
  class PlayerComponent* player_;
  base_engine::PhysicsBodyComponent* body_ = nullptr;
  bool is_ground_ = false;
  bool is_sneak_ = false;

 public:
  explicit PlayerFall(PlayerComponent* player);
  void Start();

  void Update();

  void ProcessInput();
  void End();

  template <typename Machine>
  void Transition(Machine& machine) const {
    if (is_sneak_ && is_ground_) {
      machine.template TransitionTo<PlayerSneak>();
    } else if (is_ground_) {
      machine.template TransitionTo<PlayerIdle>();
    }
  }

private:
  void Acceleration() const;
};
}  // namespace player