#include "ClipSizeYTween.h"

#include "Rect.h"

namespace ma_tween {
namespace {
class Driver : public Tween<float, ISpriteAnimatable> {
 public:
  explicit Driver(base_engine::Actor* owner)
      : Tween<float, ISpriteAnimatable>(owner) {}
  explicit Driver(base_engine::Actor* owner,
                  const std::weak_ptr<ISpriteAnimatable>& animatable)
      : Tween<float, ISpriteAnimatable>(owner, animatable) {}

  Mof::Rectangle clip_rect_{0, 0, 0, 0};

  float OnGetFrom() override {
    return this->component_weak_.lock()->GetClipRect().GetHeight();
  }

  void OnUpdate(const float eased_time) override {
    this->clip_rect_ = static_cast<Mof::Rectangle>(this->component_weak_.lock()->GetClipRect());
    this->value_current_ =
        this->InterpolateValue(this->value_from_, this->value_to_, eased_time);
    this->clip_rect_.Bottom = this->value_current_;
    this->component_weak_.lock()->SetClipRect(this->clip_rect_);
  }
};
}  // namespace
TweenDriver<float>& ClipSizeYTween::TweenClipSizeY(base_engine::Actor* actor,
                                                   float to, float duration) {
  return TweenDriver<float>::Add<Driver>(actor).Finalize(to, duration);
}

TweenDriver<float>& ClipSizeYTween::TweenClipSizeY(
    base_engine::Actor* actor,
    const std::weak_ptr<ISpriteAnimatable>& component, float to,
    float duration) {
  return TweenDriver<float>::Add<Driver>(actor, component)
      .Finalize(to, duration);
}
}  // namespace ma_tween