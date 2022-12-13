// @PositionXTween.h
// @brief
// @author ICE
// @date 2022/12/13
//
// @details

#pragma once
#include "Tween.h"

namespace ma_tween {

class PositionXTween{
 public:

  static TweenDriver<float>& TweenLocalPositionX(base_engine::Actor* actor, float to, float duration);
};
}  // namespace ma_tween