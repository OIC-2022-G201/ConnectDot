#include "SpriteComponent.h"

#include <Utilities/GraphicsUtilities.h>

#include "Actor.h"
#include "Game.h"
namespace base_engine {
SpriteComponent::SpriteComponent(Actor* owner, int draw_order)
    : RenderComponent(owner, draw_order),
      texture_(nullptr),
      color_(MOF_XRGB(255, 255, 255)),
      mFlashTime(0.0f) {}

SpriteComponent::~SpriteComponent() { sprite_.Release(); }

void SpriteComponent::SetImage(Mof::LPTexture img) {
  sprite_.SetTexture(img);
  texture_ = img;
}

void SpriteComponent::StartFlash(float time, const COLOR& color) {
  mFlashTime = time;
  color_ = color;
}

void SpriteComponent::Update() { color_ = MOF_ARGB(255, 255, 255, 255); }

void SpriteComponent::Draw() {
  Vector2 p = owner_->GetPosition();
  float a = owner_->GetRotation();
  float s = owner_->GetScale();
  Mof::Vector3 pos = {p.x, p.y,0};
  sprite_.m_Position = pos;
  //sprite_.Render();
  //sprite_.UpdateActor();
  Mof::CGraphicsUtilities::RenderTexture(p.x, p.y, color_, texture_);
}
}  // namespace base_engine