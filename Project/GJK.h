// @file GJK.h
// @brief GJKアルゴリズムによる当たり判定
// @author ICE
// @date 2022/08/17
//
// @details GJKによる当たり判定とEPAによる衝突深度を求める

#pragma once

#include <vector>

#include "EpaSolver.h"
#include "Manifold.h"
#include "MinkowskiSum.h"


namespace base_engine::physics::detector {
using Simplex = std::vector<Vector2>;
class Gjk {
 public:
  static Manifold Detect(const IShape& shape1, InVector2 transform1,
                         const IShape& shape2, InVector2 transform2) {
    if (shape1.GetType() == ShapeType::kCircle &&
        shape2.GetType() == ShapeType::kCircle) {
      return DetectCircle(shape1, transform1,
                          shape2, transform2);
    }
    Simplex simplex;
    const MinkowskiSum minkowski_sum(shape1, transform1, shape2, transform2);

    if (Vector2 direction =
            CalcInitialDirection(shape1, transform1, shape2, transform2);
        Detect(minkowski_sum, simplex, direction)) {
      return EpaSolver::FindManifold(simplex, minkowski_sum);
    }

    return Manifold();
  }

  static Vector2 CalcInitialDirection(const IShape& shape1,
                                      InVector2 transform1,
                                      const IShape& shape2,
                                      InVector2 transform2) {
    Vector2 c1 = transform1 + (shape1.AABB().GetCenter());
    Vector2 c2 = transform2 + (shape2.AABB().GetCenter());

    return c2 - c1;
  }
  static bool Detect(const MinkowskiSum& minkowski_sum, Simplex& simplex,
                     Vector2& direction) {
    if (VectorUtilities::IsZero(direction)) {
      direction = Vector2(1.0, 0.0);
    }

    simplex.push_back(minkowski_sum.GetSupportPoint(direction));

    if (VectorUtilities::Dot(simplex[0], direction) <= 0.0) {
      return false;
    }

    direction *= -1.0;

    while (true) {
      simplex.push_back(minkowski_sum.GetSupportPoint(direction));
      if (simplex.size() > 4) return false;  //@bug 無限ループを強制終了
      Vector2 lastPoint = simplex.back();
      if (VectorUtilities::Dot(lastPoint, direction) <= 0.0) {
        return false;
      } else {
        if (NextSimplex(simplex, direction)) {
          return true;
        }
      }
    }
  }

  static Manifold DetectCircle(const base_engine::IShape& shape1, InVector2 transform1,
                               const base_engine::IShape& shape2,
                               InVector2 transform2);
  /**
   * \brief
   * \param simplex
   * \param direction
   * \return
   * @todo バグの原因を探す
   * @bug 無限ループの原因
   */
  bool static NextSimplex(std::vector<Vector2> simplex, Vector2& direction) {
    Vector2 a = simplex.back();

    Vector2 ao = -a;

    if (simplex.size() == 3) {
      Vector2 b = simplex[1];
      Vector2 c = simplex[0];

      Vector2 ab = b - a;
      Vector2 ac = c - a;

      Vector2 ab_perpendicular = VectorUtilities::TripleProduct(ac, ab, ab);
      Vector2 ac_perpendicular = VectorUtilities::TripleProduct(ab, ac, ac);

      float acLocation = VectorUtilities::Dot(ac_perpendicular, ao);

      if (acLocation >= 0.0) {
        simplex.erase(simplex.begin() + 1);

        direction = ac_perpendicular;
      } else {
        float abLocation = VectorUtilities::Dot(ab_perpendicular, ao);

        if (abLocation < 0.0) {
          return true;
        } else {
          direction = ab_perpendicular;
        }
      }
    } else {
      Vector2 b = simplex[0];
      Vector2 ab = b - a;

      direction = VectorUtilities::TripleProduct(ab, ao, ab);

      if (VectorUtilities::MagnitudeSquared(direction) <= 0.1f) {
        direction = VectorUtilities::Left(ab);
      }
    }

    return false;
  }
};

}  // namespace base_engine::physics::detector