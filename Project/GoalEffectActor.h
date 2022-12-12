// @GoalEffectActor.h
// @brief
// @author ICE
// @date 2022/12/12
//
// @details

#pragma once
#include "Actor.h"
#include "Component.h"


class GoalEffectActor final : base_engine::Actor {
  class GoalEffectComponent;
 public:
  explicit GoalEffectActor(base_engine::Game* game);

  void Start() override;
};
