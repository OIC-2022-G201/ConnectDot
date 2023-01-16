// @TransitionFadeSystem.h
// @brief
// @author ICE
// @date 2023/01/16
//
// @details

#pragma once
#include "Game.h"
#include "ITransitionFadeSystem.h"
#include "Material.h"

class TransitionFadeSystem final : public ITransitionFadeSystem {
  base_engine::Game* game_;
  std::shared_ptr<base_engine::Material> material_;

 public:
  explicit TransitionFadeSystem(base_engine::Game* game);

  void SceneTransition(
      std::string_view scene_name,
      TransitionFadeInfo in_duration = kTransitionFadeDefault,
      TransitionFadeInfo out_duration = kTransitionFadeDefault) override;

  [[nodiscard]] ma_tween::TweenDriver<float>& FadeIn(float duration) override;
  [[nodiscard]] ma_tween::TweenDriver<float>& FadeOut(float duration) override;
};
