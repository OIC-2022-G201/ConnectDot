#include "NinePatchImageComponent.h"

#include "IBaseEngineCanvasRender.h"

base_engine::NinePatchImageComponent::NinePatchImageComponent(Actor* owner,
                                                              int draw_order)
    : RenderComponent(owner, draw_order) {}
void base_engine::NinePatchImageComponent::CalcPoint() {
  const float x0 = 0;
  const float x1 = center_face_.Left;
  const float x2 = center_face_.Right;
  const float x3 = static_cast<MofFloat>(texture_->GetWidth());

  const float y0 = 0;
  const float y1 = center_face_.Top;
  const float y2 = center_face_.Bottom;
  const float y3 = static_cast<MofFloat>(texture_->GetHeight());

  point_[0] = Vector2{x0, y0};
  point_[1] = Vector2{x1, y0};
  point_[2] = Vector2{x2, y0};
  point_[3] = Vector2{x3, y0};

  point_[4] = Vector2{x0, y1};
  point_[5] = Vector2{x1, y1};
  point_[6] = Vector2{x2, y1};
  point_[7] = Vector2{x3, y1};

  point_[8] = Vector2{x0, y2};
  point_[9] = Vector2{x1, y2};
  point_[10] = Vector2{x2, y2};
  point_[11] = Vector2{x3, y2};

  point_[12] = Vector2{x0, y3};
  point_[13] = Vector2{x1, y3};
  point_[14] = Vector2{x2, y3};
  point_[15] = Vector2{x3, y3};
}
void base_engine::NinePatchImageComponent::Draw() {
  Vector2 diff = {clip_rect_.GetWidth() - texture_->GetWidth(),
                  clip_rect_.GetHeight() - texture_->GetHeight()};

  Draw(point_[0], point_[0], point_[5], {});
  Draw(point_[1], point_[1], point_[6], {diff.x, 0});
  Draw(point_[2] + Vector2{diff.x, 0}, point_[2], point_[7], {});

  Draw(point_[4], point_[4], point_[9], {0, diff.y});
  Draw(point_[5], point_[5], point_[10], diff);
  Draw(point_[6] + Vector2{diff.x, 0}, point_[6], point_[11], {0, diff.y});

  Draw(point_[8] + Vector2{0, diff.y}, point_[8], point_[13], {});
  Draw(point_[9] + Vector2{0, diff.y}, point_[9], point_[14], {diff.x, 0});
  Draw(point_[10] + diff, point_[10], point_[15], {});
}

base_engine::NinePatchImageComponent&
base_engine::NinePatchImageComponent::SetImage(const Mof::LPTexture img,
                                               const Vector2& left_top,
                                               const Vector2& right_bottom) {
  texture_ = img;
  if (clip_rect_ == Mof::CRectangle{}) {
    clip_rect_ = Mof::CRectangle{0, 0, static_cast<float>(img->GetWidth()),
                                 static_cast<float>(img->GetHeight())};
  }

  center_face_ = Mof::Rectangle{left_top, right_bottom};
  CalcPoint();
  return *this;
}

void base_engine::NinePatchImageComponent::SetClipRect(
    const Mof::CRectangle rect) {
  clip_rect_ = rect;
}

base_engine::NinePatchImageComponent&
base_engine::NinePatchImageComponent::SetColor(const COLOR& color) {
  color_ = color;
  return *this;
}

base_engine::NinePatchImageComponent::COLOR
base_engine::NinePatchImageComponent::GetColor() const {
  return color_;
}

base_engine::NinePatchImageComponent&
base_engine::NinePatchImageComponent::SetOffset(InVector2 offset) {
  offset_ = offset;
  return *this;
}

base_engine::NinePatchImageComponent&
base_engine::NinePatchImageComponent::SetAngle(const MofFloat angle) {
  angle_ = angle;
  return *this;
}

base_engine::NinePatchImageComponent&
base_engine::NinePatchImageComponent::SetAlignment(
    Mof::TextureAlignment alignment) {
  alignment_ = alignment;
  return *this;
}

MofFloat base_engine::NinePatchImageComponent::GetAngle() const {
  return angle_;
}

void base_engine::NinePatchImageComponent::Draw(const Vector2& offset,
                                                const Vector2& left_top,
                                                const Vector2& right_bottom,
                                                const Vector2& diff) {
  Vector2 p = owner_->GetPosition() + offset_ + offset;

  float a = owner_->GetRotation();
  float s = owner_->GetScale();
  Mof::Vector3 pos = {p.x, p.y, 0};
  Mof::CMatrix44 mat{};
  mat.Translation(pos);
  BASE_ENGINE(CanvasRender)
      ->AddTexture(mat, Mof::Rectangle{left_top, right_bottom},
                   Mof::Vector4{1, 1, 1, 1}, {0, 0, 0}, {diff.x, diff.y, 0},
                   {0, 0}, {1, 1}, 0, texture_);
}
