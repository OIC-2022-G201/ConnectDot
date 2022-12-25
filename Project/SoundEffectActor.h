// @SoundEffectActor.h
// @brief
// @author ICE
// @date 2022/12/26
//
// @details

#pragma once
#include <array>

#include "Actor.h"
#include "ISpriteAnimationComponent.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"
#include "ShapeRenderComponent.h"
class SoundEffectActor final : public base_engine::Actor {

  using AnimationPair = std::pair<base_engine::SpriteComponent*,
                                  base_engine::ISpriteAnimationComponent*>;
  std::array<AnimationPair, 2> effects_;
  base_engine::CollisionComponent* collision_;
  base_engine::ShapeRenderComponent* debug_shape_;
  float range_ = 0;
 public:
  explicit SoundEffectActor(base_engine::Game* game) : Actor(game) {}

  void Play(const float range);
  void Stop();
  bool is_create_ = false;
};
