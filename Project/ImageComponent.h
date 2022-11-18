// @ImageComponent.h
// @brief
// @author ICE
// @date 2022/11/01
//
// @details

#pragma once
#include "RenderComponent.h"

namespace base_engine {
class ImageComponent : public RenderComponent {
 public:
  using COLOR = uint32_t;

 public:
  ImageComponent(class Actor* owner, int draw_order = 100);
  ~ImageComponent() override = default;

  void Update() override {}
  void Draw() override;

  ImageComponent& SetImage(Mof::LPTexture img) {
    texture_ = img;
    if (clip_rect_ == Mof::CRectangle{}) {
      clip_rect_ = Mof::CRectangle{0, 0, static_cast<float>(img->GetWidth()),
                                   static_cast<float>(img->GetHeight())};
    }
    return *this;
  }
  Mof::CRectangle GetClipRect() const { return clip_rect_; }
  void SetClipRect(Mof::CRectangle rect) { clip_rect_ = rect; }
  ImageComponent& SetColor(const COLOR& color) {
    color_ = color;
    return *this;
  }
  ImageComponent& SetOffset(InVector2 offset) {
    offset_ = offset;
    return *this;
  }
  ImageComponent& SetAngle(MofFloat angle) {
    angle_ = angle;
    return *this;
  }

  ImageComponent& SetAlignment(Mof::TextureAlignment alignment) {
    alignment_ = alignment;
    return *this;
  }
  MofFloat GetAngle() const { return angle_; }

 private:
  int draw_order_;
  Mof::LPTexture texture_;
  COLOR color_;
  Vector2 offset_;
  MofFloat angle_ = 0;
  Mof::CRectangle clip_rect_{};
  Mof::TextureAlignment alignment_ = Mof::TextureAlignment::TEXALIGN_TOPLEFT;

 public:
  void StartFlash(float time, const COLOR& color);

 private:
  float mFlashTime;
};
}  // namespace base_engine
