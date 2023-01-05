#include "SpriteAlphaTween.h"

#include "SpriteComponent.h"

namespace ma_tween {
namespace {
class Driver : public Tween<int, base_engine::SpriteComponent> {
 public:
  explicit Driver(base_engine::Actor* owner)
      : Tween<int, base_engine::SpriteComponent>(owner) {}

  base_engine::COLOR color;
  bool OnInitialize() override {
    component_weak_ = owner_->GetComponent<base_engine::SpriteComponent>();
    return !component_weak_.expired();
  }

  uint32_t GetAlpha() const {
    return MOF_GetAlpha(component_weak_.lock()->GetColor());
  }

  int OnGetFrom() override { return GetAlpha(); }

  void OnUpdate(const float eased_time) override {
    this->color = component_weak_.lock()->GetColor();
    this->value_current_ =
        this->InterpolateValue(this->value_from_, this->value_to_, eased_time);
    this->color = MOF_ARGB(this->value_current_, MOF_GetRed(this->color),
                           MOF_GetGreen(this->color), MOF_GetBlue(this->color));
    this->component_weak_.lock()->SetColor(this->color);
  }
};
}  // namespace
ma_tween::TweenDriver<int>& ma_tween::SpriteAlphaTween::Tween(
    base_engine::Actor* actor, int to, float duration) {
  return TweenDriver<int>::Add<Driver>(actor).Finalize(to, duration);
}
}  // namespace ma_tween