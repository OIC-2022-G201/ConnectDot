#pragma once
#include "Tween.h"

namespace ma_tween {

class ImageAlphaTween {
 public:
  static TweenDriver<int>& TweenImageAlpha(base_engine::Actor* actor,
                                                 int to, float duration);
};
}  // namespace ma_tween