// @PlayerGoal.h
// @brief
// @author ICE
// @date 2023/01/17
//
// @details

#pragma once
#include "PhysicsBodyComponent.h"
#include "PlayerState.h"

namespace player {

class PlayerGoal {
  class PlayerComponent* player_;
  base_engine::PhysicsBodyComponent* body_;

 public:
  explicit PlayerGoal(PlayerComponent* player);
  void Start();
  void Update();
  void ProcessInput();
  void End();
};
}  // namespace player