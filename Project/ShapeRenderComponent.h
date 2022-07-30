#pragma once
#include <memory>

#include "RenderComponent.h"
#include "YesNo.h"

namespace base_engine {
using COLOR = MofU32;
using FillMode = YesNo<struct Fill_mode>;

class ShapeRenderComponent final : public RenderComponent {
  std::shared_ptr<class IShape> shape_;

  FillMode fill_mode_ = FillMode::No;
  COLOR color_ = MOF_COLOR_WHITE;

 public:
  ShapeRenderComponent(Actor* owner, int draw_order);
  ShapeRenderComponent& SetColor(const COLOR color);

  ShapeRenderComponent& SetFillMode(const FillMode mode);

  void SetShape(const std::shared_ptr<class IShape>& shape);
  void Draw() override;
  void Draw(const class Rect& rect) const;
  void Draw(const class Circle& rect) const;
  void Draw(const class Point& rect) const;
};
}  // namespace base_engine