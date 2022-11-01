#include "ButtonSelecter.h"

#include <Utilities/InputUtilities.h>

#include "Button.h"
#include "InputManager.h"

ButtonSelecter::ButtonSelecter(base_engine::Game* game) : Actor(game), input_manager_(nullptr){}


void ButtonSelecter::Start() {

}

void ButtonSelecter::SetInput(InputManager* input_manager) {
	input_manager_ = input_manager;
}

void ButtonSelecter::Update() {
	size_t horiizontal = input_manager_->ButtonHorizontal();
	size_t vertical = input_manager_->ButtonVertical();
	now_select_x += horiizontal;
	if (now_select_x >= buttongroupe.size())
	{
		now_select_x = buttongroupe.size();
	}
	if (now_select_x <= 0)
	{
		now_select_x = 0;
	}
	now_select_y += vertical;
	if (now_select_y >= buttongroupe.size())
	{
		now_select_y = buttongroupe.size();
	}
	if (now_select_y <= 0)
	{
		now_select_y = 0;
	}

	if (input_manager_->JumpFire())
	{
		ButtonSelect();
	}
}

void ButtonSelecter::ButtonSelect() {
	buttongroupe[now_select_y][now_select_x]->OnPress();
}
