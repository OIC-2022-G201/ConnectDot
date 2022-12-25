// @SoundEffectActor.h
// @brief
// @author ICE
// @date 2022/12/26
//
// @details

#pragma once
#include "Actor.h"
#include "ISpriteAnimationComponent.h"
#include "SpriteComponent.h"

class SoundEffectActor final : public base_engine::Actor {
  base_engine::SpriteComponent* sprite_ = nullptr;
  base_engine::ISpriteAnimationComponent* motion_ = nullptr;

 public:
  explicit SoundEffectActor(base_engine::Game* game) : Actor(game) {}
  void Play();
  void Stop();
};
