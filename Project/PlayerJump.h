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
  bool is_idle_ = false;

 public:
  PlayerJump(PlayerComponent* player);
  void Start();

  void Update();

  void ProcessInput();
  void End();

  template <typename Machine>
  void Transition(Machine& machine) const {
    if (is_idle_) machine.template TransitionTo<PlayerIdle>();
  }
  void OnEvent(base_engine::CollisionComponent* collision);

 private:
  void Acceleration() const;
};

}  // namespace player