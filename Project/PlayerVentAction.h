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

  enum class VentDir { kNone, kPrev, kNext };

 private:
  void InActionUpdate();
  void OutActionUpdate();
  [[nodiscard]] std::weak_ptr<VentComponent> GetVentMoveTo(VentDir dir) const;
  void VentMove(const std::weak_ptr<VentComponent>& vent);

  class PlayerComponent* player_;
  base_engine::CollisionComponent* collider_ = nullptr;
  base_engine::PhysicsBodyComponent* physics_body_ = nullptr;
  const VentComponent* vent_ = nullptr;
  base_engine::Vector2 target_pos_;
  base_engine::Vector2 start_pos_;
  size_t current_frame_ = 0;
  VentActionType action_type_ = VentActionType::kNone;
  bool end_ = false;
};
}  // namespace player
