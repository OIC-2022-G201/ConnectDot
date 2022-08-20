// @file Manifold.h
// @brief 各コリジョンの衝突深度などを求める
// @author ICE
// @date 2022/08/17
//
// @details

#pragma once
#include <array>

#include "Vector.h"
#include "VectorUtilities.h"

namespace base_engine::physics {

constexpr size_t kMaxManifoldPoints = 2;
using CollisionPoints = std::array<Vector2, kMaxManifoldPoints>;
/**
 * \brief 当たり判定情報
 */
struct Manifold {
  /**
   * \brief 接触点
   */
  CollisionPoints points = CollisionPoints();
  /**
   * \brief 接触点1から2への法線
   */
  Vector2 normal = {0, 0};
  /**
   * \brief 距離
   */
  Floating depth = 0;
  bool has_collision = false;

  explicit Manifold() = default;

  explicit Manifold(InVector2 a, InVector2 b)
      : points({a, b}), has_collision(true) {
    Vector2 ba = a - b;
    depth = VectorUtilities::Length(ba);
    if (depth > 0.00001f) {
      normal = Vector2(ba / depth);
    } else {
      normal = Vector2(0, 1);
      depth = 1;
    }
  }
  explicit Manifold(InVector2 a, InVector2 b, InVector2 n, const float d)
      : points({a, b}), normal(n), depth(d), has_collision(true) {}
};

}  // namespace base_engine::physics
