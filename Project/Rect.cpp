#include "Rect.h"
#include "ShapeRenderComponent.h"

base_engine::Rect::Rect(float left, float top, float right, float bottom): Mof::CRectangle(left,top,right,bottom)
{
      
}

void base_engine::Rect::Draw(const ShapeRenderComponent& drawable)
{
    drawable.Draw(*this);
}
