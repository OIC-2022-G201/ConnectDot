#include "ButtonSelecter.h"

#include "Button.h"
#include "InputManager.h"

ButtonSelecter::ButtonSelecter(base_engine::Game* game) : Actor(game), input_manager_(nullptr){}


void ButtonSelecter::Start() {

	buttongroupe_[now_select_y_][now_select_x_]->OnHover();
}

void ButtonSelecter::SetInput(InputManager* input_manager) {
	input_manager_ = input_manager;
}

void ButtonSelecter::SetSelect(size_t now_select_x, size_t now_select_y){
	prev_x_ = now_select_x_;
	prev_y_ = now_select_y_;

	now_select_x_ = now_select_x;
	now_select_y_ = now_select_y;
	ChangeHover();
}

void ButtonSelecter::ChangeHover()
{
	if (!buttongroupe_[now_select_y_][now_select_x_])return;
	if (!buttongroupe_[prev_y_][prev_x_])return;
	buttongroupe_[now_select_y_][now_select_x_]->OnHover();
	buttongroupe_[prev_y_][prev_x_]->OutHover();
}

void ButtonSelecter::Update() {

	SelectorMove();
	if (input_manager_->ButtonDecision())
	{
		ButtonSelect();
	}
}

void ButtonSelecter::SelectorMove()
{
	int horiizontal = input_manager_->ButtonHorizontal();
	int vertical = input_manager_->ButtonVertical();
	if (horiizontal==0 && vertical == 0)return;
	int tmp_prev_x = now_select_x_;
	int tmp_prev_y = now_select_y_;
	if(horiizontal!=0)
	{
		now_select_x_ += horiizontal;
		if (now_select_x_ >= static_cast<int>(buttongroupe_.size()))
		{
			now_select_x_= buttongroupe_.size();
		}
		if (now_select_x_ <= 0)
		{
			now_select_x_ = 0;
		}

	}


	if(vertical!=0)
	{
		now_select_y_ += vertical;
		if (now_select_y_ >= static_cast<int>(buttongroupe_.size()))
		{
			now_select_y_ = buttongroupe_.size();
		}
		if (now_select_y_ <= 0)
		{
			now_select_y_ = 0;
		}

	}
	if (!buttongroupe_[now_select_y_][now_select_x_])
	{
		now_select_x_ = tmp_prev_x;
		now_select_y_ = tmp_prev_y;
	}
	if (tmp_prev_x != now_select_x_)prev_x_ = tmp_prev_x;
	if (tmp_prev_y != now_select_y_)prev_y_ = tmp_prev_y;

	ChangeHover();
}

void ButtonSelecter::ButtonSelect() {
	buttongroupe_[now_select_y_][now_select_x_]->OnPress();
}
