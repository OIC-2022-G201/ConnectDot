// @ITransitionFadeSystem.h
// @brief
// @author ICE
// @date 2023/01/16
//
// @details

#pragma once
#include "Tween.h"
struct TransitionFadeInfo {
  float duration;
  EaseType ease;
};
constexpr TransitionFadeInfo kTransitionFadeDefault{2.0, EaseType::kInoutsine};
__interface ITransitionFadeSystem {
	ma_tween::TweenDriver<float>& FadeOut(float duration);
  ma_tween::TweenDriver<float>& FadeIn(float duration);
  void SceneTransition(
      std::string_view scene_name,
      TransitionFadeInfo in_duration = kTransitionFadeDefault,
      TransitionFadeInfo out_duration = kTransitionFadeDefault);
};
