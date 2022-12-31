#include "Dummytween.h"

namespace ma_tween {

namespace {
class Driver : public Tween<float, base_engine::Actor> {
 public:
  explicit Driver(base_engine::Actor* owner)
      : Tween(owner) {}
  bool OnInitialize() override {
    return true;
  }

  float OnGetFrom() override { return dummy_; }

  void OnUpdate(const float eased_time) override {
    this->value_current_ =
        this->InterpolateValue(this->value_from_, this->value_to_, eased_time);
    dummy_ = this->value_current_; 
  }
private:
  float dummy_ = 0;
};
}  // namespace
TweenDriver<float>& DummyTween::TweenDummy(
    base_engine::Actor* actor,float duration) {
  return TweenDriver<float>::Add<Driver>(actor).Finalize(1, duration);
}
}  // namespace ma_tween