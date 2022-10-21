// @PhysicsPolygonShape.h
// @brief
// @author ICE
// @date 2022/10/18
//
// @details

#pragma once
#include "PhysicsComponentData.h"
#include "PhysicsShapes.h"
#include "PhysicsVector2.h"

namespace base_engine::physics {
class b2PolygonShape : public b2Shape {
 public:
  b2PolygonShape();

  /// Implement b2Shape.
  b2Shape* Clone(PhysicsBlockAllocator* allocator) const override;

  /// @see b2Shape::GetChildCount
  [[nodiscard]] int32_t GetChildCount() const override;

  /// Create a convex hull from the given array of local points.
  /// The count must be in the range [3, b2_maxPolygonVertices].
  /// @warning the points may be re-ordered, even if they form a convex polygon
  /// @warning collinear points are handled but not removed. Collinear points
  /// may lead to poor stacking behavior.
  void Set(const PVec2* points, uint8_t count);

  /// Build vertices to represent an axis-aligned box centered on the local
  /// origin.
  /// @param hx the half-width.
  /// @param hy the half-height.
  void SetAsBox(float hx, float hy) {
    m_count = 4;
    m_vertices[0].Set(0, 0);
    m_vertices[1].Set(hx, 0);
    m_vertices[2].Set(hx, hy);
    m_vertices[3].Set(0, hy);
    m_normals[0].Set(0.0f, -1.0f);
    m_normals[1].Set(1.0f, 0.0f);
    m_normals[2].Set(0.0f, 1.0f);
    m_normals[3].Set(-1.0f, 0.0f);
    m_centroid.SetZero();
  }
  /// @see b2Shape::TestPoint
  bool TestPoint(const b2Transform& transform, const PVec2& p) const override;

  /// Implement b2Shape.
  /// @note because the polygon is solid, rays that start inside do not hit
  /// because the normal is not defined.
  bool RayCast(PhysicsRayCastOutput* output, const PhysicsRayCastInput& input,
               const b2Transform& transform, int32_t childIndex) const override;

  /// @see b2Shape::ComputeAABB
  void ComputeAABB(PhysicsAABB* aabb, const b2Transform& transform,
                   int32_t childIndex) const override;

  /// @see b2Shape::ComputeMass
  void ComputeMass(PhysicsMassData* massData, float density) const override
  {
      
  }

  /// Validate convexity. This is a very time consuming operation.
  /// @returns true if valid
  bool Validate() const;

  PVec2 m_centroid{};
  PVec2 m_vertices[kMaxPolygonVertices]{};
  PVec2 m_normals[kMaxPolygonVertices]{};
  int32_t m_count;
};
}  // namespace base_engine::physics
