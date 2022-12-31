#pragma once
#include "Tween.h"

namespace ma_tween {

class DummyTween {
 public:
  static TweenDriver<float>& TweenDummy(base_engine::Actor* actor, float duration);
};
}  // namespace ma_tween