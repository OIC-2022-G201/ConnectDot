#pragma once
#include "Actor.h"

class BeaconActor final : public base_engine::Actor{

 public:
  explicit BeaconActor(base_engine::Game* game);
  

  ~BeaconActor() override;

  void Start() override;
  void Input() override;
  void Update() override;

 private:
};
