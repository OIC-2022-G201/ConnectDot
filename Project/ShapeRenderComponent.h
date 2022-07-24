#pragma once
#include <memory>

#include "RenderComponent.h"
#include "YesNo.h"

namespace base_engine {
using COLOR = MofU32;
using FillMode = YesNo<struct Fill_mode>;

class ShapeRenderComponent : RenderComponent {
  std::unique_ptr<class IShape> shape_;

  FillMode fill_mode_ = FillMode::No;
  COLOR color_ = MOF_COLOR_WHITE;

 public:
  ShapeRenderComponent(Actor* owner, int draw_order);
  ShapeRenderComponent& SetColor(const COLOR color);

  ShapeRenderComponent& SetFillMode(const FillMode mode);
  void CreateRect(float left, float top, float right, float bottom);
  void CreateRect(const Mof::CRectangle& rect);
  void Draw() override;
  void Draw(const class Rect& rect) const;
};
}  // namespace base_engine