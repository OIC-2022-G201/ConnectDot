#include "ShapeRenderComponent.h"

#include <Utilities/GraphicsUtilities.h>

#include "IShape.h"
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

void ShapeRenderComponent::CreateRect(float left, float top, float right,
                                      float bottom) {
  shape_ = std::make_unique<Rect>(left, top, right, bottom);
}
void ShapeRenderComponent::CreateRect(const Mof::CRectangle& rect) {
  shape_ = std::make_unique<Rect>(rect);
}

void ShapeRenderComponent::Draw() { shape_->Draw(*this); }

void ShapeRenderComponent::Draw(const Rect& rect) const {
  Vector2 p = owner_->GetPosition();
  if (fill_mode_) {
    Mof::CGraphicsUtilities::RenderFillRect(rect + p, color_);
  } else {
    Mof::CGraphicsUtilities::RenderRect(rect + p, color_);
  }
}

}  // namespace base_engine