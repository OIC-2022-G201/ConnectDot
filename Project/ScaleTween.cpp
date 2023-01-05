#include "ScaleTween.h"
namespace ma_tween {
namespace {
class Driver : public Tween<float, base_engine::Actor> {
 public:
  explicit Driver(base_engine::Actor* owner)
      : Tween<float, base_engine::Actor>(owner) {}

  float local_scale_ = 0;

  bool OnInitialize() override {
    component_weak_ = this->GetOwner();
    return true;
  }
  float OnGetFrom() override {
    return this->component_weak_.lock()->GetScale();
  }

  void OnUpdate(const float eased_time) override {
    this->local_scale_ = this->component_weak_.lock()->GetScale();
    this->value_current_ =
        this->InterpolateValue(this->value_from_, this->value_to_, eased_time);
    this->local_scale_ = this->value_current_;
    this->component_weak_.lock()->SetScale(this->local_scale_);
  }
};
}  // namespace
TweenDriver<float>& ScaleTween::Tween(base_engine::Actor* actor, const float to, const float duration)
{
  return TweenDriver<float>::Add<Driver>(actor).Finalize(to, duration);
}
}  // namespace ma_tween