#pragma once

#include "2DShapes.h"

namespace base_engine::Geometry2D {
[[nodiscard]] bool Intersect(const Mof::CVector2& a,
                                    const Mof::CVector2& b) noexcept;

[[nodiscard]] bool Intersect(const Mof::CVector2& a,
                                    const Mof::CRectangle& b) noexcept;

[[nodiscard]] bool Intersect(const Mof::CVector2& a,
                                    const Mof::CCircle& b) noexcept;

[[nodiscard]] bool Intersect(const Mof::CRectangle& a,
                                    const Mof::CVector2& b) noexcept;

[[nodiscard]] bool Intersect(const Mof::CRectangle& a,
                                    const Mof::CRectangle& b) noexcept;

[[nodiscard]] bool Intersect(const Mof::CRectangle& a,
                                    const Mof::CCircle& b) noexcept;

[[nodiscard]] bool Intersect(const Mof::CCircle& a,
                                    const Mof::CVector2& b) noexcept;

[[nodiscard]] bool Intersect(const Mof::CCircle& a,
                                    const Mof::CRectangle& b) noexcept;

[[nodiscard]] bool Intersect(const Mof::CCircle& a,
                                    const Mof::CCircle& b) noexcept;


}  // namespace base_engine::Geometry2D
#include "Geometry2D.ipp"