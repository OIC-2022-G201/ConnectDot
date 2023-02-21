// @file PlayerJump.h
// @brief プレイヤージャンプのステート
// @author ICE
// @date 2022/08/07
//
// @details
#pragma once
#include "CollisionComponent.h"
#include "PhysicsBodyComponent.h"
#include "PlayerState.h"
namespace player {
class PlayerJump {
  int frame_ = 0;
  class PlayerComponent* player_;
  base_engine::PhysicsBodyComponent* body_ = nullptr;
  bool is_ground_ = false;
  bool is_sneak_ = false;
  bool is_fall_ = false;
 public:
  explicit PlayerJump(PlayerComponent* player);
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
    } else if (is_fall_)
      machine.template TransitionTo<PlayerFall>();
  }
  
 private:
  void Acceleration() const;
};

}  // namespace player