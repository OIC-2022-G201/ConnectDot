#include "PositionYTween.h"
namespace ma_tween {
namespace {
class Driver : public Tween<float, base_engine::Actor> {
 public:
  explicit Driver(base_engine::Actor* owner)
      : Tween<float, base_engine::Actor>(owner) {}

  base_engine::Vector2 localPosition;

  bool OnInitialize() override {
    component_weak_ = this->GetOwner();
    return true;
  }
  float OnGetFrom() override {
    return this->component_weak_.lock()->GetPosition().y;
  }

  void OnUpdate(const float eased_time) override {
    this->localPosition = this->component_weak_.lock()->GetPosition();
    this->value_current_ =
        this->InterpolateValue(this->value_from_, this->value_to_, eased_time);
    this->localPosition.y = this->value_current_;
    this->component_weak_.lock()->SetPosition(this->localPosition);
  }
};
}  // namespace
TweenDriver<float>& PositionYTween::TweenLocalPositionY(
    base_engine::Actor* actor, float to, float duration) {
  return TweenDriver<float>::Add<Driver>(actor).Finalize(to, duration);
}
}  // namespace ma_tween