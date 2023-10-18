// @PhysicsVector2.h
// @brief
// @author ICE
// @date 2022/10/13
//
// @details

#pragma once
#include <cmath>
#include <cstdint>

namespace base_engine::physics {
template <class _Floating>
struct PhysicsVector2 {
 public:
  constexpr PhysicsVector2() = default;
  constexpr PhysicsVector2(_Floating x, _Floating y) : x(x), y(y) {}

  constexpr void SetZero() {
    x = static_cast<_Floating>(0);
    y = static_cast<_Floating>(0);
  }
  constexpr void Set(_Floating x_in, _Floating y_in) {
    x = x_in;
    y = y_in;
  }

  PhysicsVector2 operator-() const { return {-x, -y}; }

  float operator()(uint_fast32_t i) const { return (&x)[i]; }

  float& operator()(uint_fast32_t i) { return (&x)[i]; }

  void operator+=(const PhysicsVector2& v) {
    x += v.x;
    y += v.y;
  }

  void operator-=(const PhysicsVector2& v) {
    x -= v.x;
    y -= v.y;
  }

  void operator*=(float a) {
    x *= a;
    y *= a;
  }

  [[nodiscard]] constexpr _Floating Length() const {
    return std::sqrt(x * x + y * y);
  }

  [[nodiscard]] constexpr _Floating LengthSquared() const {
    return x * x + y * y;
  }

  constexpr _Floating Normalize() {
    float length = Length();
    if (length < std::numeric_limits<_Floating>::epsilon()) {
      return 0.0f;
    }
    float inv_length = 1.0f / length;
    x *= inv_length;
    y *= inv_length;

    return length;
  }

  [[nodiscard]] bool IsValid() const { return isfinite(x) && isfinite(y); }

  [[nodiscard]] constexpr PhysicsVector2 Skew() const { return PhysicsVector2(-y, x); }
  _Floating x, y;
};

using PVec2 = PhysicsVector2<float>;

constexpr float PhysicsDot(const PVec2& a, const PVec2& b) {
  return a.x * b.x + a.y * b.y;
}

constexpr float PhysicsCross(const PVec2& a, const PVec2& b) {
  return a.x * b.y - a.y * b.x;
}

constexpr PVec2 PhysicsCross(const PVec2& a, float s) {
  return {s * a.y, -s * a.x};
}

constexpr PVec2 PhysicsCross(float s, const PVec2& a) {
  return {-s * a.y, s * a.x};
}

constexpr PVec2 operator+(const PVec2& a, const PVec2& b) {
  return {a.x + b.x, a.y + b.y};
}

constexpr PVec2 operator-(const PVec2& a, const PVec2& b) {
  return {a.x - b.x, a.y - b.y};
}

constexpr PVec2 operator*(float s, const PVec2& a) {
  return {s * a.x, s * a.y};
}

constexpr bool operator==(const PVec2& a, const PVec2& b) {
  return a.x == b.x && a.y == b.y;
}

constexpr bool operator!=(const PVec2& a, const PVec2& b) {
  return a.x != b.x || a.y != b.y;
}

constexpr float PhysicsDistance(const PVec2& a, const PVec2& b) {
  PVec2 c = a - b;
  return c.Length();
}

constexpr float PhysicsDistanceSquared(const PVec2& a, const PVec2& b) {
  PVec2 c = a - b;
  return PhysicsDot(c, c);
}
}  // namespace base_engine::physics