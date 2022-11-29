// @PlayerVentAction.h
// @brief
// @author ICE
// @date 2022/11/29
//
// @details

#pragma once
#include "CollisionComponent.h"

class PlayerVentAction {
  class PlayerComponent* player_;
  base_engine::CollisionComponent* collider_ = nullptr;

 public:
  explicit PlayerVentAction(PlayerComponent* player);

  void Start();

  void Update();

  void ProcessInput();
  void End();

  template <typename Machine>
  void Transition(Machine& machine) const;
};
