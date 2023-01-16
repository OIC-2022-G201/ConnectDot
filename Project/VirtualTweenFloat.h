// @VirtualTweenFloat.h
// @brief
// @author ICE
// @date 2023/01/16
// 
// @details

#pragma once
#include "Tween.h"

namespace ma_tween {

class VirtualTweenFloat {
 public:
  static TweenDriver<float>& Tween(base_engine::Game* game,float from, float to,
                                   float duration,
                                   const std::function<void(float)>& onUpdate);
};
}  // namespace ma_tween