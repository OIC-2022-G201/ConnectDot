#pragma once
#include <array>
#include "Actor.h"
class InputManager;
class Button;

class ButtonSelecter : public base_engine::Actor{
public:
	explicit ButtonSelecter(base_engine::Game* game);

	~ButtonSelecter() override = default;

	void Start() override;

	void SetInput(InputManager* input_manager);

	void SetSelect(size_t now_select_x, size_t now_select_y);

	void ChangeHover();

	void ButtonRegister(size_t x_,size_t y_, Button* button)
	{
		buttongroupe_[y_][x_] = button;
	}

	/// <summary>
	/// キー操作での数値変更
	/// </summary>
	void Update() override;

	void SelectorMove();

	/// <summary>
	/// 選択中のボタンの実行
	/// </summary>
	void ButtonSelect();


private:
	std::array<std::array<Button*,15>,15> buttongroupe_ = std::array<std::array<Button*, 15>, 15>();
	int now_select_x_ = 0;
	int now_select_y_ = 0;
	int prev_x_ = 0;
	int prev_y_ = 0;
	InputManager* input_manager_;
};