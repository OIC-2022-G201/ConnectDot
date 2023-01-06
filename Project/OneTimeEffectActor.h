// @OneTimeEffectActor.h
// @brief
// @author
// @date 2023/01/06
//
// @details

#pragma once
#include "Actor.h"
#include "ISpriteAnimationComponent.h"
#include "SpriteComponent.h"
#include "VectorUtilities.h"

class OneTimeEffectActor final : public base_engine::Actor {
public:
  explicit OneTimeEffectActor(base_engine::Game* game);

    void Start() override;
  void Update() override;
  void Show() const;
  void Hide() const;

  void Play();

  static OneTimeEffectActor* Create(base_engine::Game* game,
                                    const base_engine::Vector2& pos,
                                    std::string_view name,int draw_order);

 private:
  base_engine::SpriteComponent* sprite_ = nullptr;
  base_engine::ISpriteAnimationComponent* motion_ = nullptr;
};