#include "CounterComponent.h"

#include "Actor.h"
#include "ResourceContainer.h"
using RC = ResourceContainer;

base_engine::CounterComponent::CounterComponent(Actor* owner)
    : Component(owner) {
  for (int i = 0; i < 10; ++i) {
    auto p =
        RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(std::to_string(i));
    numbers[i] = *p;
  }
  third_digit = new ImageComponent(owner_,2200);
  second_digit = new ImageComponent(owner_, 2200);
  first_digit = new ImageComponent(owner_, 2200);
}

base_engine::CounterComponent::CounterComponent(Actor* owner, const std::string& prefix): Component(owner) {
  for (int i = 0; i < 10;++i) {
    auto p =
      RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(prefix+ std::to_string(i));
    numbers[i] = *p;
  }
  third_digit = new ImageComponent(owner_, 2200);
  second_digit = new ImageComponent(owner_, 2200);
  first_digit = new ImageComponent(owner_, 2200);
}

void base_engine::CounterComponent::Update() {}

void base_engine::CounterComponent::SetNumber(int number) {
  number_ = number;
  int a, b, c;
  a = number_ / 100;
  b = (number_ - (100 * a)) / 10;
  c = number_ - ((100 * a) + (10 * b));

  a > 0 ? m_bThirdShow = true : m_bThirdShow = false;
  a <= 0 && b > 0 ? m_bSecondShow = true : m_bSecondShow = false;

  if (m_bThirdShow) {
    third_digit->SetImage(numbers[a]);
    second_digit->SetImage(numbers[b]);
    first_digit->SetImage(numbers[c]);
    third_digit->SetEnabled(true);
    is_right_ ? SetPosition(): SetPositionLeft();
    return;
  }
  if (m_bSecondShow) {
    third_digit->SetEnabled(false);
    second_digit->SetImage(numbers[b]);
    first_digit->SetImage(numbers[c]);
    is_right_ ? SetPosition() : SetPositionLeft();
    return;
  }
  if (!m_bSecondShow) {
    second_digit->SetImage(numbers[b]);
    first_digit->SetImage(numbers[c]);
  }
  SetPosition();
}


void base_engine::CounterComponent::SetPosition() {
  second_digit->SetOffset({second_digit->GetClipRect().GetWidth(), 0});
  first_digit->SetOffset({ first_digit->GetClipRect().GetWidth() * 2 + space_, 0 });
}

void base_engine::CounterComponent::SetPositionLeft() {
  if (!m_bSecondShow && m_bThirdShow) {
    first_digit->SetOffset({first_digit->GetClipRect().GetWidth(), 0});
  }
}

void base_engine::CounterComponent::SetEnable(const bool enable)
{
	enable_ = enable;
  first_digit->SetEnabled(enable_);
  second_digit->SetEnabled(enable_);
  third_digit->SetEnabled(enable_);
}
