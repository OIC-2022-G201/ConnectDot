// @PhysicsAABB.h
// @brief
// @author かき氷氷味
// @date 2022/10/13
//
// @details

#pragma once
#include "PhysicsMathUtility.h"
#include "PhysicsVector2.h"
#undef max
#undef min
namespace base_engine::physics {
/// Ray-cast input data. The ray extends from p1 to p1 + maxFraction * (p2 -
/// p1).
struct PhysicsRayCastInput {
  PVec2 p1, p2;
  float maxFraction;
};

/// Ray-cast output data. The ray hits at p1 + fraction * (p2 - p1), where p1
/// and p2 come from b2RayCastInput.
struct PhysicsRayCastOutput {
  PVec2 normal;
  float fraction;
};
struct PhysicsAABB {
  /// Verify that the bounds are sorted.
  [[nodiscard]] bool IsValid() const {
    const PVec2 d = upperBound - lowerBound;
    bool valid = d.x >= 0.0f && d.y >= 0.0f;
    valid = valid && lowerBound.IsValid() && upperBound.IsValid();
    return valid;
  };

  /// Get the center of the AABB.
  [[nodiscard]] PVec2 GetCenter() const {
    return 0.5f * (lowerBound + upperBound);
  }

  /// Get the extents of the AABB (half-widths).
  [[nodiscard]] PVec2 GetExtents() const {
    return 0.5f * (upperBound - lowerBound);
  }

  /// Get the perimeter length
  [[nodiscard]] float GetPerimeter() const {
    float wx = upperBound.x - lowerBound.x;
    float wy = upperBound.y - lowerBound.y;
    return 2.0f * (wx + wy);
  }

  /// Combine an AABB into this one.
  void Combine(const PhysicsAABB& aabb) {
    lowerBound = PhysicsMin(lowerBound, aabb.lowerBound);
    upperBound = PhysicsMax(upperBound, aabb.upperBound);
  }

  /// Combine two AABBs into this one.
  void Combine(const PhysicsAABB& aabb1, const PhysicsAABB& aabb2) {
    lowerBound = PhysicsMin(aabb1.lowerBound, aabb2.lowerBound);
    upperBound = PhysicsMax(aabb1.upperBound, aabb2.upperBound);
  }

  /// Does this aabb contain the provided AABB.
  [[nodiscard]] bool Contains(const PhysicsAABB& aabb) const {
    bool result = true;
    result = result && lowerBound.x <= aabb.lowerBound.x;
    result = result && lowerBound.y <= aabb.lowerBound.y;
    result = result && aabb.upperBound.x <= upperBound.x;
    result = result && aabb.upperBound.y <= upperBound.y;
    return result;
  }

  bool RayCast(PhysicsRayCastOutput* output,
               const PhysicsRayCastInput& input) const {
    float tmin = std::numeric_limits<float>::min();
    float tmax = std::numeric_limits<float>::max();

    PVec2 p = input.p1;
    PVec2 d = input.p2 - input.p1;
    PVec2 absD = PhysicsAbs(d);

    PVec2 normal;

    for (size_t i = 0; i < 2; ++i) {
      if (absD(i) < std::numeric_limits<float>::epsilon()) {
        // Parallel.
        if (p(i) < lowerBound(i) || upperBound(i) < p(i)) {
          return false;
        }
      } else {
        const float inv_d = 1.0f / d(i);
        float t1 = (lowerBound(i) - p(i)) * inv_d;
        float t2 = (upperBound(i) - p(i)) * inv_d;

        // Sign of the normal vector.
        float s = -1.0f;

        if (t1 > t2) {
          std::swap(t1, t2);
          s = 1.0f;
        }

        // Push the min up
        if (t1 > tmin) {
          normal.SetZero();
          normal(i) = s;
          tmin = t1;
        }

        // Pull the max down
        tmax = PhysicsMin(tmax, t2);

        if (tmin > tmax) {
          return false;
        }
      }
    }

    // Does the ray start inside the box?
    // Does the ray intersect beyond the max fraction?
    if (tmin < 0.0f || input.maxFraction < tmin) {
      return false;
    }

    // Intersection.
    output->fraction = tmin;
    output->normal = normal;
    return true;
  }

  PVec2 lowerBound;  ///< the lower vertex
  PVec2 upperBound;  ///< the upper vertex
};

constexpr bool b2TestOverlap(const PhysicsAABB& a, const PhysicsAABB& b) {
  const PVec2 d1 = b.lowerBound - a.upperBound;
  const PVec2 d2 = a.lowerBound - b.upperBound;

  if (d1.x > 0.0f || d1.y > 0.0f) return false;

  if (d2.x > 0.0f || d2.y > 0.0f) return false;

  return true;
}
}  // namespace base_engine::physics