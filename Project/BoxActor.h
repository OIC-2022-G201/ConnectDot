#pragma once
#include "Actor.h"
#include "LoadObjectParameter.h"
#include "PhysicsBodyComponent.h"

class BoxActor final : public base_engine::Actor {
 public:
  explicit BoxActor(base_engine::Game* game) : Actor(game) {}
  void Start() override;
  void Input() override;
  void Update() override;
  void Create(const LoadObject& object);
private:
  base_engine::PhysicsBodyComponent* body_;
};

class BoxComponent final : public base_engine::Component {
 public:
  explicit BoxComponent(base_engine::Actor* owner,
                                     const int update_order = 100)
      : Component(owner, update_order) {}

private:
  bool electric_power_ = false;
};