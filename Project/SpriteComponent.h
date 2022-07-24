#pragma once
#include <Graphics/Sprite2D.h>
#include <Graphics/Sprite3D.h>
#include <Graphics/DirectX11/DX11Texture.h>
#include <Math/MathCommon.h>

#include "Actor.h"
#include "RenderComponent.h"

namespace base_engine {
    using COLOR = MofU32;
class SpriteComponent : public RenderComponent {
 public:
  SpriteComponent(class Actor* owner, int draw_order = 100);
  ~SpriteComponent();

  void Update() override;
  void Draw() override;
  virtual void SetImage(Mof::LPTexture img);
  
  void SetColor(const COLOR& color) { color_ = color; }

 private:
  int draw_order_;
  Mof::LPTexture texture_;
  COLOR color_;

 public:
  void StartFlash(float time, const COLOR& color);

 private:
  float mFlashTime;
  Mof::CSprite3D sprite_;
};
}  // namespace base_engine