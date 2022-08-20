// @file MinkowskiSum.h
// @brief ミンコフスキー和を計算する
// @author ICE
// @date 2022/08/17
// 
// @details 

#pragma once
#include "IShape.h"
#include "Vector.h"


namespace base_engine {
class MinkowskiSum {
 public:
  MinkowskiSum(const IShape& convex1, InVector2 transform1,
               const IShape& convex2, InVector2 transform2)
      : convex1(convex1),
        transform1(transform1),
        convex2(convex2),
        transform2(transform2) {}

  [[nodiscard]] Vector2 GetSupportPoint(Vector2 direction) const {
    // get the farthest point in the given direction in convex1
    Vector2 point1 = convex1.GetFarthestPoint(transform1,direction );

    // get the farthest point in the opposite direction in convex2
    direction *= -1;
    Vector2 point2 = convex2.GetFarthestPoint(transform2,direction);

    // return the Minkowski sum point
    return point1 - point2;
  }
 private:
  const IShape& convex1;
  InVector2 transform1;

  const IShape& convex2;
  InVector2 transform2;
};
}  // namespace base_engine
