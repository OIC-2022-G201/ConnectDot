// @ClipSizeXTween.h
// @brief
// @author ICE
// @date 2022/12/30
// 
// @details

#pragma once
#include "Tween.h"
#include "ISpriteAnimatable.h"

namespace ma_tween {

class ClipSizeXTween {
 public:
  static TweenDriver<float>& TweenClipSizeX(base_engine::Actor* actor,
                                                 float to, float duration);
  
  static TweenDriver<float>& TweenClipSizeX(base_engine::Actor* actor, const std::weak_ptr<ISpriteAnimatable>& component, float to,
                                            float duration);
};
}  // namespace ma_tween