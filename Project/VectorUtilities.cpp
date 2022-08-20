#include "VectorUtilities.h"

namespace base_engine {
Floating VectorUtilities::Dot(InVector2 a, InVector2 b) {
  return a.x * b.x + a.y * b.y;
}

Floating VectorUtilities::Cross(InVector2 a, InVector2 b) {
  return a.x * b.y - a.y * b.x;
}

Floating VectorUtilities::Length(InVector2 a)
{ return std::sqrt(Dot(a, a));
}

Vector2 VectorUtilities::Normalize(InVector2 a)
{ return a / Length(a); }

Vector2 VectorUtilities::TripleProduct(InVector2 a, InVector2 b, InVector2 c)
{
    return (b * Dot(a, c)) - (a * Dot(b, c));
}

float VectorUtilities::MagnitudeSquared(const Vector2& v)
{
    return v.x * v.x + v.y * v.y;
}

Vector2 VectorUtilities::Left(InVector2 v)
{ return {v.y, -v.x}; }

Vector2 VectorUtilities::Right(InVector2 v)
{ return {-v.y, v.x}; }

bool VectorUtilities::IsZero(InVector2 v)
{
    return abs(v.x) <= std::numeric_limits<float>::epsilon() &&
        abs(v.y) <= std::numeric_limits<float>::epsilon();
}
}  // namespace base_engine