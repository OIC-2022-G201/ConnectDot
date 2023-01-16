#include "VirtualTweenFloat.h"

using namespace base_engine;

namespace ma_tween {

namespace {
class Driver : public Tween<float, base_engine::Actor> {
 public:
  explicit Driver(base_engine::Actor* owner) : Tween(owner) {}
  bool OnInitialize() override { return true; }

  float OnGetFrom() override { return value_from_; }

  void OnUpdate(const float eased_time) override {
    this->value_current_ =
        this->InterpolateValue(this->value_from_, this->value_to_, eased_time);
    dummy_ = this->value_current_;
  }
  void OnComplete() override { owner_->GetGame()->RemoveActor(owner_); }

 private:
  float dummy_ = 0;
};
}  // namespace

TweenDriver<float>& VirtualTweenFloat::Tween(
    Game* game, float from, float to, const float duration,
    const std::function<void(float)>& onUpdate) {
  return TweenDriver<float>::Add<Driver>(new Actor(game))
      .Finalize(to, duration)
      .SetOnUpdate(onUpdate)
      .SetFrom(from);
}
}  // namespace ma_tween