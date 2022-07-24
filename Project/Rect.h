#pragma once
#include <Collision/Rectangle.h>

#include "IShape.h"

namespace base_engine
{
    
class Rect final : public Mof::CRectangle,public IShape {
 public:
    explicit Rect(const CRectangle& pObj)
        : CRectangle(pObj)
    {
    }

    Rect(float left,float top,float right,float bottom);
    void Draw(const ShapeRenderComponent& drawable) override;
};
}  // namespace base_engine
