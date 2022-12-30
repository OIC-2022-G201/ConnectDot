// @ClipSizeYTween.h
// @brief
// @author ICE
// @date 2022/12/30
//
// @details

#pragma once
#include "ISpriteAnimatable.h"
#include "Tween.h"

namespace ma_tween {

class ClipSizeYTween {
 public:
  static TweenDriver<float>& TweenClipSizeY(base_engine::Actor* actor, float to,
                                            float duration);

  static TweenDriver<float>& TweenClipSizeY(
      base_engine::Actor* actor,
      const std::weak_ptr<ISpriteAnimatable>& component, float to,
      float duration);
};
}  // namespace ma_tween