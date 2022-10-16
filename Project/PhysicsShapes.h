// @PhysicsShapes.h
// @brief
// @author かき氷氷味
// @date 2022/10/16
//
// @details

#pragma once
#include <cstdint>

#include "PhysicsCollision.h"
#include "PhysicsTransform.h"
#include "PhysicsVector2.h"

namespace base_engine::physics {
class PhysicsBlockAllocator;

struct PhysicsMassData {
  float mass;

  PVec2 center;

  float I;
};

class b2Shape {
 public:
  enum class Type { kCircle = 0, kEdge = 1, kPolygon = 2, kChain = 3 };

  virtual ~b2Shape() = default;

  virtual b2Shape* Clone(PhysicsBlockAllocator* allocator) const = 0;

  [[nodiscard]] Type GetType() const { return m_type; }

  [[nodiscard]] virtual int32_t GetChildCount() const = 0;

  [[nodiscard]] virtual bool TestPoint(const b2Transform& xf,
                                       const PVec2& p) const = 0;
  virtual bool RayCast(PhysicsRayCastOutput* output,
                       const PhysicsRayCastInput& input,
                       const b2Transform& transform,
                       int32_t childIndex) const = 0;

  virtual void ComputeAABB(PhysicsAABB* aabb, const b2Transform& xf,
                           int32_t childIndex) const = 0;

  virtual void ComputeMass(PhysicsMassData* massData, float density) const = 0;

  Type m_type;

  float m_radius;
};
}  // namespace base_engine::physics
