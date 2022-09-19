#pragma once
#include <Graphics/DirectX11/DX11Texture.h>
#include <Graphics/Sprite2D.h>
#include <Graphics/Sprite3D.h>
#include <Math/MathCommon.h>

#include "Actor.h"
#include "RenderComponent.h"

namespace base_engine {
using COLOR = MofU32;
class SpriteComponent : public RenderComponent {
 public:
  SpriteComponent(class Actor* owner, int draw_order = 100);
  ~SpriteComponent() override;

  void Update() override;
  void Draw() override;
  SpriteComponent& SetImage(Mof::LPTexture img);
  void SetClipRect(Mof::CRectangle rect) { clip_rect_ = rect; }
  SpriteComponent& SetColor(const COLOR& color) {
    color_ = color;
    return *this;
  }
  SpriteComponent& SetOffset(InVector2 offset) {
    offset_ = offset;
    return *this;
  }
  SpriteComponent& SetAngle(MofFloat angle) {
    angle_ = angle;
    return *this;
  }

  SpriteComponent& SetAlignment(Mof::TextureAlignment alignment) {
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
  Mof::CSprite2D sprite_;
};
}  // namespace base_engine