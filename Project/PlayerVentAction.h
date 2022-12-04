// @PlayerVentAction.h
// @brief
// @author ICE
// @date 2022/11/29
//
// @details

#pragma once
#include "CollisionComponent.h"
#include "PlayerState.h"
#include "VentComponent.h"
class VentComponent;

namespace player {
class PlayerVentAction {
  enum class VentActionType { kNone, kIn, kStay, kOut };

 public:
  explicit PlayerVentAction(class PlayerComponent* player);

  void Start();

  void Update();

  void ProcessInput();
  void End();
  void OnEvent(const VentComponent* const v);

  template <typename Machine>
  void Transition(Machine& machine) const {
    if (end_) machine.template TransitionTo<PlayerIdle>();
  }

 private:
  void InActionUpdate();
  void OutActionUpdate();
  class PlayerComponent* player_;
  base_engine::CollisionComponent* collider_ = nullptr;
  base_engine::PhysicsBodyComponent* physics_body_ = nullptr;

  base_engine::Vector2 target_pos_;
  base_engine::Vector2 start_pos_;
  size_t current_frame_;
  VentActionType action_type_ = VentActionType::kNone;
  bool end_ = false;
};
}  // namespace player
