// @SpriteAlphaTween.h
// @brief
// @author 
// @date 2023/01/03
// 
// @details

#pragma once
#include "Tween.h"

namespace ma_tween {

class SpriteAlphaTween {
 public:
  static TweenDriver<int>& Tween(base_engine::Actor* actor, int to,
                                           float duration);
};
}  // namespace ma_tween
