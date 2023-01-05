// @BeaconPowerUpActor.h
// @brief
// @author
// @date 2023/01/03
//
// @details

#pragma once
#include "Actor.h"

class BeaconPowerUpActor : public base_engine::Actor {
 public:
  explicit BeaconPowerUpActor(base_engine::Game* game);

  void Create(Actor* target);
private:
  class BeaconPowerUpActionComponent;
};
