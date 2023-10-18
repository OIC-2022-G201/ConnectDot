// @PhysicsCircleShape.h
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#pragma once
#include <numbers>

#include "PhysicsBlockAllocator.h"
#include "PhysicsShapes.h"

namespace base_engine::physics {
using int32 = int32_t;
class PhysicsCircleShape : public PhysicsShape {
 public:
  PhysicsCircleShape();

  /// Implement PhysicsShape.
  PhysicsShape* Clone(PhysicsBlockAllocator* allocator) const override;

  /// @see PhysicsShape::GetChildCount
  int32 GetChildCount() const override;

  /// Implement PhysicsShape.
  bool TestPoint(const PhysicsTransform& transform, const PVec2& p) const override;

  /// Implement PhysicsShape.
  /// @note because the circle is solid, rays that start inside do not hit
  /// because the normal is not defined.
  bool RayCast(PhysicsRayCastOutput* output, const PhysicsRayCastInput& input,
               const PhysicsTransform& transform, int32 childIndex) const override;

  /// @see PhysicsShape::ComputeAABB
  void ComputeAABB(PhysicsAABB* aabb, const PhysicsTransform& transform,
                   int32 childIndex) const override;

  /// @see PhysicsShape::ComputeMass
  void ComputeMass(PhysicsMassData* massData, float density) const override;

  /// Position
  PVec2 m_p;
};
}  // namespace base_engine::physics
