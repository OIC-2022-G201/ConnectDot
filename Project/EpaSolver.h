// @file EpaSolver.h
// @brief EAPアルゴリズムを用いて衝突深度を求める
// @author ICE
// @date 2022/08/17
//
// @details

#pragma once
#include "ExpandingSimplex.h"
#include "Manifold.h"
#include "MinkowskiSum.h"

namespace base_engine::physics::detector {
constexpr size_t kMaxIterations = 100;
class EpaSolver {
 public:
  static Manifold FindManifold(const std::vector<Vector2>& simplex,
                               const MinkowskiSum& support) {
    Manifold result;
    ExpandingSimplex expandingSimplex(simplex);
    std::shared_ptr<ExpandingSimplexEdge> edge;
    Vector2 point;

    for (int i = 0; i < kMaxIterations; i++) {
      edge = expandingSimplex.findClosestEdge();
      point = support.GetSupportPoint(edge->GetNormal());

      const float projection = VectorUtilities::Dot(point, edge->GetNormal());
      if ((projection - edge->GetDistance()) <
          std::numeric_limits<float>::epsilon()) {
        return Manifold(edge->GetPoint1(), edge->GetPoint2(), edge->GetNormal(),
                        projection);
      }

      expandingSimplex.expand(point);
    }

    return Manifold(edge->GetPoint1(), edge->GetPoint2(), edge->GetNormal(),
                    VectorUtilities::Dot(point, edge->GetNormal()));
  }
};
}  // namespace base_engine::physics::detector