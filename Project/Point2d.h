// @Point2d.h
// @brief
// @author ICE
// @date 2022/11/18
// 
// @details

#pragma once

#pragma once
template <class Floating>
struct Point2d {
  union {
    Floating iv[2];
    struct {
      Floating x, y;
    };
  };

  constexpr Point2d() : x(0), y(0) {}
  constexpr Point2d(Floating vx, Floating vy) : x(vx), y(vy) {}
  explicit operator Floating*() { return iv; }
};

using Point2I = Point2d<int>;
using Point2F = Point2d<float>;
