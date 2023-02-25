#include "PositionTween.h"
namespace ma_tween {
namespace {
using TweenValueType = base_engine::Vector2;
using TweenBase = Tween<base_engine::Vector2, base_engine::Actor>;

class Driver : public TweenBase {
 public:
  explicit Driver(base_engine::Actor* owner) : TweenBase(owner) {}

  base_engine::Vector2 localPosition;

  bool OnInitialize() override {
    component_weak_ = this->GetOwner();
    return true;
  }
  TweenValueType OnGetFrom() override {
    return this->component_weak_.lock()->GetPosition();
  }

  void OnUpdate(const float eased_time) override {
    this->localPosition = this->component_weak_.lock()->GetPosition();

  	this->value_current_.x = this->InterpolateValue(
        this->value_from_.x, this->value_to_.x, eased_time);

    this->value_current_.y = this->InterpolateValue(
        this->value_from_.y, this->value_to_.y, eased_time);

    this->localPosition = this->value_current_;
    this->component_weak_.lock()->SetPosition(this->localPosition);
  }
};
}  // namespace

TweenDriver<TweenValueType>& PositionTween::Tween(base_engine::Actor* actor,
                                                  const TweenValueType to,
                                                  const float duration) {
  return TweenDriver<TweenValueType>::Add<Driver>(actor).Finalize(to, duration);
}

}  // namespace ma_tween