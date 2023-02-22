#pragma once
#include "Actor.h"
#include "LoadObjectParameter.h"

class DataChipActor final : public base_engine::Actor {
 public:
  explicit DataChipActor(base_engine::Game* game) : Actor(game) {}

  void Create(const LoadObject& object);
  void Start() override;
  void Input() override;
  void Update() override;
};
