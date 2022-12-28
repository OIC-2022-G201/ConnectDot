#include "SpriteComponent.h"

#include <Utilities/GraphicsUtilities.h>

#include "Actor.h"
#include "Game.h"
#include "IBaseEngineRender.h"

using namespace ee;
namespace base_engine {
SpriteComponent::SpriteComponent(Actor* owner, int draw_order)
    : RenderComponent(owner, draw_order),
      texture_(nullptr),
      color_(MOF_XRGB(255, 255, 255)),
      mFlashTime(0.0f) {}

SpriteComponent::~SpriteComponent() {}

SpriteComponent& SpriteComponent::SetImage(Mof::LPTexture img) {
  texture_ = img;
  if (clip_rect_ == Mof::CRectangle{}) {
    FitClipRect();
  }
  return *this;
}

void SpriteComponent::FitClipRect() {
  clip_rect_ = Mof::CRectangle{0, 0, static_cast<float>(texture_->GetWidth()),
                               static_cast<float>(texture_->GetHeight())};
}

void SpriteComponent::StartFlash(float time, const COLOR& color) {
  mFlashTime = time;
  color_ = color;
}

void SpriteComponent::Update() { }

void SpriteComponent::Draw() {
  Vector2 p = owner_->GetPosition() + offset_;

  float a = owner_->GetRotation();
  const float s = owner_->GetScale();
  const Mof::Vector3 pos = {p.x, p.y, 0};
  sprite_.m_Position = pos;
  auto rect = clip_rect_;
  if (ee::has<Flip::kHorizontal>(flip_)) {
    std::swap(rect.Right, rect.Left);
  }
  if (ee::has<Flip::kVertical>(flip_)) {
    std::swap(rect.Top, rect.Bottom);
  }
  BASE_ENGINE(Render)->AddTexture(texture_, p, {s, s}, angle_, rect, color_,
                                  alignment_);
}
}  // namespace base_engine