#include "GJK.h"

#include "Circle.h"

namespace base_engine::physics::detector {
Manifold Gjk::DetectCircle(const IShape& shape1, InVector2 transform1,
                           const IShape& shape2, InVector2 transform2) {
  const auto circle1 = static_cast<const Circle&>(shape1);
  const auto circle2 = static_cast<const Circle&>(shape2);
  const Vector2 c1 = transform1 + circle1.Position;
  const Vector2 c2 = transform2 + circle2.Position;
  const Vector2 v = c2 - c1;

  if (const float mag = VectorUtilities::Length(v),
      radii = circle1.r + circle2.r;
      mag < radii) {
    return Manifold(c1, c2, VectorUtilities::Normalize(v), radii - mag);
  }
  return Manifold{};
}
}  // namespace base_engine::physics::detector