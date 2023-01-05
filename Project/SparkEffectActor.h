// @SparkEffectActor.h
// @brief
// @author
// @date 2023/01/05
//
// @details

#pragma once
#include "Actor.h"
#include "ISpriteAnimationComponent.h"
#include "SpriteComponent.h"
#include "VectorUtilities.h"

class SparkEffectActor final : public base_engine::Actor {
 public:
  explicit SparkEffectActor(base_engine::Game* game);
  void Start() override;
  void Update() override;
  void Show() const;
  void Hide() const;

  void Play();

  void Create(const base_engine::Vector2& pos, std::string_view name);

private:
  base_engine::SpriteComponent* sprite_ = nullptr;
  base_engine::ISpriteAnimationComponent* motion_ = nullptr;
};