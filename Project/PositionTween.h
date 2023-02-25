// @PositionTween.h
// @brief
// @author ICE
// @date 2023/02/23
//
// @details

#pragma once
#include "Tween.h"

namespace ma_tween {

class PositionTween {
 public:
  static TweenDriver<base_engine::Vector2>& Tween(base_engine::Actor* actor,
                                                  base_engine::Vector2 to,
                                                  float duration);
};
}  // namespace ma_tween
