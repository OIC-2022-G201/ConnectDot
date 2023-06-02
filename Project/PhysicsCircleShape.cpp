#include "PhysicsCircleShape.h"

base_engine::physics::PhysicsCircleShape::PhysicsCircleShape()
{
    m_type = Type::kCircle;
    m_radius = 0.0f;
    m_p.SetZero();
}

base_engine::physics::PhysicsShape* base_engine::physics::PhysicsCircleShape::Clone(PhysicsBlockAllocator* allocator) const
{
    void* mem = allocator->Allocate(sizeof(PhysicsCircleShape));
    const auto clone = new (mem) PhysicsCircleShape;
    *clone = *this;
    return clone;
}

base_engine::physics::int32 base_engine::physics::PhysicsCircleShape::GetChildCount() const
{ return 1; }

bool base_engine::physics::PhysicsCircleShape::TestPoint(const PhysicsTransform& transform, const PVec2& p) const
{
    PVec2 center = transform.p + PhysicsMul(transform.q, m_p);
    PVec2 d = p - center;
    return PhysicsDot(d, d) <= m_radius * m_radius;
}

bool base_engine::physics::PhysicsCircleShape::RayCast(PhysicsRayCastOutput* output, const PhysicsRayCastInput& input,
    const PhysicsTransform& transform, int32 childIndex) const
{
    PVec2 position = transform.p + PhysicsMul(transform.q, m_p);
    PVec2 s = input.p1 - position;
    float b = PhysicsDot(s, s) - m_radius * m_radius;

    // Solve quadratic equation.
    PVec2 r = input.p2 - input.p1;
    float c = PhysicsDot(s, r);
    float rr = PhysicsDot(r, r);
    float sigma = c * c - rr * b;

    // Check for negative discriminant and short segment.
    if (sigma < 0.0f || rr < std::numeric_limits<float>::max()) {
        return false;
    }

    // Find the point of intersection of the line with the circle.
    float a = -(c + std::sqrt(sigma));

    // Is the intersection point on the segment?
    if (0.0f <= a && a <= input.maxFraction * rr) {
        a /= rr;
        output->fraction = a;
        output->normal = s + a * r;
        output->normal.Normalize();
        return true;
    }

    return false;
}

void base_engine::physics::PhysicsCircleShape::ComputeAABB(PhysicsAABB* aabb, const PhysicsTransform& transform,
    int32 childIndex) const
{
    PVec2 p = transform.p + PhysicsMul(transform.q, m_p);
    aabb->lowerBound.Set(p.x - m_radius, p.y - m_radius);
    aabb->upperBound.Set(p.x + m_radius, p.y + m_radius);
}

void base_engine::physics::PhysicsCircleShape::ComputeMass(PhysicsMassData* massData, float density) const
{
    massData->mass = density * std::numbers::pi_v<float> * m_radius * m_radius;
    massData->center = m_p;

    // inertia about the local origin
    massData->I =
        massData->mass * (0.5f * m_radius * m_radius + PhysicsDot(m_p, m_p));
}
