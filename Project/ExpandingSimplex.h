// @file ExpandingSimplex.h
// @brief
// @author ICE
// @date 2022/08/17
//
// @details

#pragma once
#include <memory>
#include <queue>

#include "ExpandingSimplexEdge.h"

namespace base_engine::physics::detector {

class ExpandingSimplex {
 public:
    explicit ExpandingSimplex(const std::vector<Vector2>& simplex) {
    this->winding_ = calcWinding(simplex);

    size_t size = simplex.size();
    for (uint32_t i = 0; i < size; i++) {
      int j = i + 1 == size ? 0 : i + 1;

      // create the edge
      Vector2 a = simplex[i];
      Vector2 b = simplex[j];
      edge_queue_.push(std::shared_ptr<ExpandingSimplexEdge>(
          new ExpandingSimplexEdge(a, b, this->winding_)));
    }
  }

  std::shared_ptr<ExpandingSimplexEdge> findClosestEdge() {
    return edge_queue_.top();
  }
  void expand(Vector2 point) {
    std::shared_ptr<ExpandingSimplexEdge> edge = edge_queue_.top();
    edge_queue_.pop();

    std::shared_ptr<ExpandingSimplexEdge> edge1(
        new ExpandingSimplexEdge(edge->GetPoint1(), point, winding_));
    edge_queue_.push(edge1);

    std::shared_ptr<ExpandingSimplexEdge> edge2(
        new ExpandingSimplexEdge(point, edge->GetPoint2(), winding_));
    edge_queue_.push(edge2);
  }

 private:
  int32_t calcWinding(const std::vector<Vector2>& simplex) {
    size_t size = simplex.size();
    for (uint32_t i = 0; i < size; i++) {
      int j = i + 1 == size ? 0 : i + 1;

      Vector2 a = simplex[i];
      Vector2 b = simplex[j];

      float aCrossB = VectorUtilities::Cross(a, b);
      if (aCrossB > 0) {
        return 1;
      } else if (aCrossB < 0) {
        return -1;
      }
    }

    return 0;
  }

 private:
  int32_t winding_;

  std::priority_queue<std::shared_ptr<ExpandingSimplexEdge>,
                      std::vector<std::shared_ptr<ExpandingSimplexEdge>>,
                      DistancePredicate>
      edge_queue_;
};
}  // namespace base_engine::physics::detector
