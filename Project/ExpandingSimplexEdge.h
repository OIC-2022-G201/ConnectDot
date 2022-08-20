// @file ExpandingSimplexEdge.h
// @brief 
// @author ICE
// @date 2022/08/17
// 
// @details

#pragma once
#include <memory>

#include "Vector.h"
#include "VectorUtilities.h"

namespace base_engine::physics::detector {
class ExpandingSimplexEdge {
 public:
  ExpandingSimplexEdge(InVector2 point1, InVector2 point2,
                       const int32_t winding) {
    this->normal_ = Vector2(point2.x - point1.x, point2.y - point1.y);

    if (winding < 0) {
      this->normal_ = VectorUtilities::Right(normal_);
    } else {
      this->normal_ = VectorUtilities::Left(normal_);
    }

    this->normal_ = VectorUtilities::Normalize(normal_);
    
    this->distance_ = abs(point1.x * normal_.x + point1.y * normal_.y);
    this->point1_ = point1;
    this->point2_ = point2;
  }

  Vector2 GetPoint1() const { return point1_; }

  Vector2 GetPoint2() const { return point2_; }

  float GetDistance() const { return distance_; }

  Vector2 GetNormal() const { return normal_; }
  


 private:
  //!
  Vector2 point1_;

  //!
  Vector2 point2_;

  //!
  Vector2 normal_;

  //!
  float distance_;
};

struct DistancePredicate {
  bool operator()(const std::shared_ptr<ExpandingSimplexEdge>& lhs,
                  const std::shared_ptr<ExpandingSimplexEdge>& rhs) const {
    return lhs->GetDistance() > rhs->GetDistance();
  }
};
}  // namespace base_engine::physics::detector