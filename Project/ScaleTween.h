// @ScaleTween.h
// @brief
// @author 
// @date 2023/01/03
// 
// @details

#pragma once
#include "Tween.h"

namespace ma_tween {
class ScaleTween {
 public:
  static TweenDriver<float>& Tween(base_engine::Actor* actor, float to,
                                   float duration);;
};
}  // namespace ma_tween