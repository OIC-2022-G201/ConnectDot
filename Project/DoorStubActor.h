// @file DoorStubActor.h
// @brief
// @author ICE
// @date 2022/11/20
//
// @details

#pragma once
#include "Actor.h"
#include "LoadObjectParameter.h"

class DoorStubActor final : public base_engine::Actor {
 public:
  explicit DoorStubActor(base_engine::Game* game);

  void Create(const LoadObject& object);
};
