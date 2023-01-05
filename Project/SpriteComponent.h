#pragma once
#include <Graphics/DirectX11/DX11Texture.h>
#include <Graphics/Sprite2D.h>
#include <Graphics/Sprite3D.h>
#include <Math/MathCommon.h>

#include "Actor.h"
#include "EnumFlags.h"
#include "ISpriteAnimatable.h"
#include "RenderComponent.h"

namespace base_engine {
using COLOR = MofU32;
enum class Flip : size_t {
  kNone,
  kHorizontal,
  kVertical,
  kHorizontalAndVertical,
};
ENUM_CLASS_FLAGS(Flip);

class SpriteComponent : public RenderComponent, public ISpriteAnimatable {
 public:
  SpriteComponent(class Actor* owner, int draw_order = 100);
  ~SpriteComponent() override;

  void Update() override;
  void Draw() override;
  SpriteComponent& SetImage(Mof::LPTexture img);
  void SetClipRect(const Mof::CRectangle& rect) override { clip_rect_ = rect; }
  void FitClipRect();
  Mof::CRectangle GetClipRect() const override { return clip_rect_; }
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
  SpriteComponent& SetFlip(Flip flip) {
    flip_ = flip;
    return *this;
  }

  MofFloat GetAngle() const { return angle_; }
  COLOR GetColor() const { return color_; }

 private:
  int draw_order_;
  Mof::LPTexture texture_;
  COLOR color_;
  Vector2 offset_;
  MofFloat angle_ = 0;
  Mof::CRectangle clip_rect_{};
  Mof::TextureAlignment alignment_ = Mof::TextureAlignment::TEXALIGN_TOPLEFT;
  Flip flip_ = Flip::kNone;

 public:
  void StartFlash(float time, const COLOR& color);

 private:
  float mFlashTime;
  Mof::CSprite2D sprite_;
};
}  // namespace base_engine