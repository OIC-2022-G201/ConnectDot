// @GoalComponent.h
// @brief
// @author ICE
// @date 2022/12/03
//
// @details

#pragma once
#include "Actor.h"
#include "Component.h"
#include "LoadObjectParameter.h"

class GoalActor final : public base_engine::Actor {
 public:
  explicit GoalActor(base_engine::Game* game) : Actor(game) {}

  void Create(const LoadObject& object);
};
class GoalComponent final : public base_engine::Component {
 public:
  explicit GoalComponent(base_engine::Actor* owner) : Component(owner) {}

  void OnCollision(const base_engine::SendManifold& manifold) override;

  static void Create(base_engine::Actor* owner);

private:
  void GoalAction();
};
