// @Easer.h
// @brief
// @author ICE
// @date 2022/12/12
//
// @details イージング用メソッドをまとめたクラス

#pragma once

enum class EaseType;

namespace ma_tween {
class Easer {
 public:
  static float Apply(const EaseType& ease, float time);
};
}  // namespace ma_tween