#include "PhysicsPolygonShape.h"

#include <array>

#include "PhysicsBlockAllocator.h"

namespace base_engine::physics {

static PVec2 ComputeCentroid(const PVec2* vs, int32_t count) {
  PVec2 c(0.0f, 0.0f);
  float area = 0.0f;

  // Get a reference point for forming triangles.
  // Use the first vertex to reduce round-off errors.
  PVec2 s = vs[0];

  constexpr float inv3 = 1.0f / 3.0f;

  for (int32_t i = 0; i < count; ++i) {
    // Triangle vertices.
    PVec2 p1 = vs[0] - s;
    PVec2 p2 = vs[i] - s;
    PVec2 p3 = i + 1 < count ? vs[i + 1] - s : vs[0] - s;

    PVec2 e1 = p2 - p1;
    PVec2 e2 = p3 - p1;

    float D = PhysicsCross(e1, e2);

    float triangleArea = 0.5f * D;
    area += triangleArea;

    // Area weighted centroid
    c += triangleArea * inv3 * (p1 + p2 + p3);
  }

  // Centroid
  c = (1.0f / area) * c + s;
  return c;
}

b2PolygonShape::b2PolygonShape()
{
    m_type = Type::kPolygon;
    m_radius = 0.001f;
    m_count = 0;
    m_centroid.SetZero();
}

b2Shape* b2PolygonShape::Clone(PhysicsBlockAllocator* allocator) const {
  void* mem = allocator->Allocate(sizeof(b2PolygonShape));
  const auto clone = new (mem) b2PolygonShape;
  *clone = *this;
  return clone;
}

int32_t b2PolygonShape::GetChildCount() const { return 1; }
using int32 = int32_t;
void b2PolygonShape::Set(const PVec2* points, uint8_t count) {
  if (count < 3) {
    SetAsBox(1.0f, 1.0f);
    return;
  }

  int32 n = std::min(count, kMaxPolygonVertices);

  // Perform welding and copy vertices into local buffer.
  std::array<PVec2, kMaxPolygonVertices> ps;
  int32 tempCount = 0;
  for (int32 i = 0; i < n; ++i) {
    PVec2 v = points[i];

    bool unique = true;
    for (int32 j = 0; j < tempCount; ++j) {
      if (PhysicsDistanceSquared(v, ps[j]) <
          ((0.5f * 0.005f) * (0.5f * 0.005f))) {
        unique = false;
        break;
      }
    }

    if (unique) {
      ps[tempCount++] = v;
    }
  }

  n = tempCount;
  if (n < 3) {
    SetAsBox(1.0f, 1.0f);
    return;
  }

  int32 i0 = 0;
  float x0 = ps[0].x;
  for (int32 i = 1; i < n; ++i) {
    float x = ps[i].x;
    if (x > x0 || (x == x0 && ps[i].y < ps[i0].y)) {
      i0 = i;
      x0 = x;
    }
  }

  int32 hull[kMaxPolygonVertices];
  int32 m = 0;
  int32 ih = i0;

  for (;;) {
    hull[m] = ih;

    int32 ie = 0;
    for (int32 j = 1; j < n; ++j) {
      if (ie == ih) {
        ie = j;
        continue;
      }

      PVec2 r = ps[ie] - ps[hull[m]];
      PVec2 v = ps[j] - ps[hull[m]];
      float c = PhysicsCross(r, v);
      if (c < 0.0f) {
        ie = j;
      }

      // Collinearity check
      if (c == 0.0f && v.LengthSquared() > r.LengthSquared()) {
        ie = j;
      }
    }

    ++m;
    ih = ie;

    if (ie == i0) {
      break;
    }
  }

  if (m < 3) {
    SetAsBox(1.0f, 1.0f);
    return;
  }

  m_count = m;

  // Copy vertices.
  for (int32 i = 0; i < m; ++i) {
    m_vertices[i] = ps[hull[i]];
  }

  // Compute normals. Ensure the edges have non-zero length.
  for (int32 i = 0; i < m; ++i) {
    int32 i1 = i;
    int32 i2 = i + 1 < m ? i + 1 : 0;
    PVec2 edge = m_vertices[i2] - m_vertices[i1];
    m_normals[i] = PhysicsCross(edge, 1.0f);
    m_normals[i].Normalize();
  }

  // Compute the polygon centroid.
  m_centroid = ComputeCentroid(m_vertices, m);
}

bool b2PolygonShape::TestPoint(const b2Transform& transform,
                               const PVec2& p) const {
  const PVec2 pLocal = PhysicsMulT(transform.q, p - transform.p);

  for (int32_t i = 0; i < m_count; ++i) {
    if (const float dot = PhysicsDot(m_normals[i], pLocal - m_vertices[i]);
        dot > 0.0f) {
      return false;
    }
  }

  return true;
}

bool b2PolygonShape::RayCast(PhysicsRayCastOutput* output,
                             const PhysicsRayCastInput& input,
                             const b2Transform& transform,
                             int32_t childIndex) const {
  // Put the ray into the polygon's frame of reference.
  PVec2 p1 = PhysicsMulT(transform.q, input.p1 - transform.p);
  PVec2 p2 = PhysicsMulT(transform.q, input.p2 - transform.p);
  PVec2 d = p2 - p1;

  float lower = 0.0f, upper = input.maxFraction;

  int32_t index = -1;

  for (int32_t i = 0; i < m_count; ++i) {
    // p = p1 + a * d
    // dot(normal, p - v) = 0
    // dot(normal, p1 - v) + a * dot(normal, d) = 0
    float numerator = PhysicsDot(m_normals[i], m_vertices[i] - p1);
    float denominator = PhysicsDot(m_normals[i], d);

    if (denominator == 0.0f) {
      if (numerator < 0.0f) {
        return false;
      }
    } else {
      // Note: we want this predicate without division:
      // lower < numerator / denominator, where denominator < 0
      // Since denominator < 0, we have to flip the inequality:
      // lower < numerator / denominator <==> denominator * lower > numerator.
      if (denominator < 0.0f && numerator < lower * denominator) {
        // Increase lower.
        // The segment enters this half-space.
        lower = numerator / denominator;
        index = i;
      } else if (denominator > 0.0f && numerator < upper * denominator) {
        // Decrease upper.
        // The segment exits this half-space.
        upper = numerator / denominator;
      }
    }

    // The use of epsilon here causes the assert on lower to trip
    // in some cases. Apparently the use of epsilon was to make edge
    // shapes work, but now those are handled separately.
    // if (upper < lower - b2_epsilon)
    if (upper < lower) {
      return false;
    }
  }

  if (index >= 0) {
    output->fraction = lower;
    output->normal = PhysicsMul(transform.q, m_normals[index]);
    return true;
  }

  return false;
}

void b2PolygonShape::ComputeAABB(PhysicsAABB* aabb,
                                 const b2Transform& transform,
                                 int32_t childIndex) const {
  PVec2 lower = PhysicsMul(transform, m_vertices[0]);
  PVec2 upper = lower;

  for (int32_t i = 1; i < m_count; ++i) {
    PVec2 v = PhysicsMul(transform, m_vertices[i]);
    lower = PhysicsMin(lower, v);
    upper = PhysicsMax(upper, v);
  }

  PVec2 r(m_radius, m_radius);
  aabb->lowerBound = lower - r;
  aabb->upperBound = upper + r;
}

bool b2PolygonShape::Validate() const {
  for (int32_t i = 0; i < m_count; ++i) {
    int32_t i1 = i;
    int32_t i2 = i < m_count - 1 ? i1 + 1 : 0;
    PVec2 p = m_vertices[i1];
    PVec2 e = m_vertices[i2] - p;

    for (int32_t j = 0; j < m_count; ++j) {
      if (j == i1 || j == i2) {
        continue;
      }

      PVec2 v = m_vertices[j] - p;
      float c = PhysicsCross(e, v);
      if (c < 0.0f) {
        return false;
      }
    }
  }

  return true;
}
}  // namespace base_engine::physics
