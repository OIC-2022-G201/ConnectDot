// @PositionYTween.h
// @brief
// @author ICE
// @date 2022/12/28
// 
// @details

#pragma once
#include "Tween.h"

namespace ma_tween {

class PositionYTween {
 public:
  static TweenDriver<float>& Tween(base_engine::Actor* actor,
                                                 float to, float duration);
};
}  // namespace ma_tween