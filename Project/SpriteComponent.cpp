#include "SpriteComponent.h"

#include <Utilities/GraphicsUtilities.h>

#include "Actor.h"
#include "Game.h"
#include "IBaseEngineRender.h"

namespace base_engine {
SpriteComponent::SpriteComponent(Actor* owner, int draw_order)
    : RenderComponent(owner, draw_order),
      texture_(nullptr),
      color_(MOF_XRGB(255, 255, 255)),
      mFlashTime(0.0f) {}

SpriteComponent::~SpriteComponent()
{ if (draw_order_==120)
{
    int n = 3;
  }
}

SpriteComponent& SpriteComponent::SetImage(Mof::LPTexture img) {

  texture_ = img;
  if (clip_rect_ == Mof::CRectangle{})
  {
      clip_rect_ = Mof::CRectangle{0, 0, static_cast<float>(img->GetWidth()),
                                   static_cast<float>(img->GetHeight())};
  }
  return *this;
}

void SpriteComponent::StartFlash(float time, const COLOR& color) {
  mFlashTime = time;
  color_ = color;
}

void SpriteComponent::Update() { color_ = MOF_ARGB(255, 255, 255, 255); }

void SpriteComponent::Draw() {
  Vector2 p = owner_->GetPosition() + offset_;

  float a = owner_->GetRotation();
  float s = owner_->GetScale();
  Mof::Vector3 pos = {p.x, p.y, 0};
  sprite_.m_Position = pos;
  BASE_ENGINE(Render)->AddTexture(texture_, p, {s,s}, angle_, clip_rect_, color_,
                                  alignment_);

}
}  // namespace base_engine