#pragma once
#include "Actor.h"
#include "Component.h"
#include "LoadObjectParameter.h"

class DataChipActor final : public base_engine::Actor {
 public:
  explicit DataChipActor(base_engine::Game* game) : Actor(game) {}

  void Create(const LoadObject& object);
  void Start() override;
  void Input() override;
  void Update() override;
};
class DataChipComponent final : public base_engine::Component {
 public:
  DataChipComponent(base_engine::Actor* owner) : Component(owner) {}
  void Start() override;
  void OnCollision(const base_engine::SendManifold& manifold) override;
};
