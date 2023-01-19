#include "ButtonSelecter.h"

#include "Button.h"
#include "InputManager.h"

ButtonSelecter::ButtonSelecter(base_engine::Game* game)
    : Actor(game), input_manager_(nullptr) {}

void ButtonSelecter::ArrowSync()
{
  if (cursor_.expired()) return;

	const auto& current_button = buttongroupe_[now_select_y_][now_select_x_];
  if (!current_button) return;
  const auto pos = current_button->GetPosition();
	cursor_.lock()->GetOwner().lock()->SetPosition(pos);
}

ButtonSelecter::~ButtonSelecter() = default;

void ButtonSelecter::ButtonRegister(size_t x_, size_t y_, Button* button)
{
	buttongroupe_[y_][x_] = button;
}

void ButtonSelecter::OnEnable()
{
	if (on_enable_action_) {
		on_enable_action_();
		return;
	}
	enable_ = true;
	if(!cursor_.expired())
	{
		cursor_.lock()->SetEnabled(true);
	}
}

void ButtonSelecter::OnDisable()
{
	if (on_disable_action_)
	{
		on_disable_action_();
		return;
	}
	enable_ = false;
	if (!cursor_.expired()) {
		cursor_.lock()->SetEnabled(false);
	}
}

void ButtonSelecter::Start() {
  buttongroupe_[now_select_y_][now_select_x_]->OnHover();
  ArrowSync();
}

void ButtonSelecter::SetInput(InputManager* input_manager) {
  input_manager_ = input_manager;
}

void ButtonSelecter::SetSelect(size_t now_select_x, size_t now_select_y) {
  prev_x_ = now_select_x_;
  prev_y_ = now_select_y_;

  now_select_x_ = now_select_x;
  now_select_y_ = now_select_y;
  ChangeHover();
}

void ButtonSelecter::ChangeHover() {
  if (!buttongroupe_[now_select_y_][now_select_x_]) return;
  if (!buttongroupe_[prev_y_][prev_x_]) return;
  if (now_select_x_ == prev_x_ && now_select_y_ == prev_y_) return;
  const auto& current_button = buttongroupe_[now_select_y_][now_select_x_];
  ArrowSync();
  current_button->OnHover();
  buttongroupe_[prev_y_][prev_x_]->OutHover();
}

void ButtonSelecter::CreateCursor(base_engine::TexturePtr image, size_t order,
                                  const base_engine::Vector2& offset) {
  if (!cursor_.expired()) return;
  const auto child = new Actor(GetGame());
  const auto cursor =
      new base_engine::ImageComponent(child, order);
  cursor->SetImage(image);
  cursor->SetOffset(offset);
  cursor_ = child->GetComponent<base_engine::ImageComponent>();
  ArrowSync();
}

void ButtonSelecter::Update() {
  if (!enable_) return;
  SelectorMove();
  if (input_manager_->ButtonDecision()) {
    ButtonSelect();
  }
}

void ButtonSelecter::SelectorMove() {
  int horiizontal = input_manager_->ButtonHorizontal();
  int vertical = input_manager_->ButtonVertical();
  if (horiizontal == 0 && vertical == 0) return;
  int tmp_prev_x = now_select_x_;
  int tmp_prev_y = now_select_y_;
  if (horiizontal != 0) {
    now_select_x_ += horiizontal;
    if (now_select_x_ >= static_cast<int>(buttongroupe_.size())) {
      now_select_x_ = buttongroupe_.size();
    }
    if (now_select_x_ <= 0) {
      now_select_x_ = 0;
    }
  }

  if (vertical != 0) {
    now_select_y_ += vertical;
    if (now_select_y_ >= static_cast<int>(buttongroupe_.size())) {
      now_select_y_ = buttongroupe_.size();
    }
    if (now_select_y_ <= 0) {
      now_select_y_ = 0;
    }
  }
  if (!buttongroupe_[now_select_y_][now_select_x_]) {
    now_select_x_ = tmp_prev_x;
    now_select_y_ = tmp_prev_y;
  }
  if (tmp_prev_x != now_select_x_) prev_x_ = tmp_prev_x;
  if (tmp_prev_y != now_select_y_) prev_y_ = tmp_prev_y;

  ChangeHover();
}

void ButtonSelecter::ButtonSelect() {
  buttongroupe_[now_select_y_][now_select_x_]->OnPress();
}
