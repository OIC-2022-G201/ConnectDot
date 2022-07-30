#include "ShapeRenderComponent.h"

#include <Utilities/GraphicsUtilities.h>

#include "Circle.h"
#include "IShape.h"
#include "Point.h"
#include "Rect.h"
namespace base_engine {
ShapeRenderComponent::ShapeRenderComponent(Actor* owner, int draw_order)
    : RenderComponent(owner, draw_order) {}

ShapeRenderComponent& ShapeRenderComponent::SetColor(const COLOR color) {
  color_ = color;
  return *this;
}

ShapeRenderComponent& ShapeRenderComponent::SetFillMode(const FillMode mode) {
  fill_mode_ = mode;
  return *this;
}

void ShapeRenderComponent::Draw() { shape_->Draw(*this); }
void ShapeRenderComponent::SetShape(const std::shared_ptr<IShape>& shape) {
  shape_ = shape;
}
void ShapeRenderComponent::Draw(const Rect& rect) const {
  Vector2 p = owner_->GetPosition();
  if (fill_mode_) {
    Mof::CGraphicsUtilities::RenderFillRect(rect + p, color_);
  } else {
    Mof::CGraphicsUtilities::RenderRect(rect + p, color_);
  }
}
void ShapeRenderComponent::Draw(const Circle& circle) const {
  Vector2 p = owner_->GetPosition();
  if (fill_mode_) {
    Mof::CGraphicsUtilities::RenderFillCircle(circle + p, color_);
  } else {
    Mof::CGraphicsUtilities::RenderCircle(circle + p, color_);
  }
}
void ShapeRenderComponent::Draw(const Point& point) const {
  Vector2 p = owner_->GetPosition();
  Mof::CGraphicsUtilities::RenderLine(point + p, point + p, color_);
}

}  // namespace base_engine