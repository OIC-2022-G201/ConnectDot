#pragma once
#include "Actor.h"
class InputManager;
class Button;

class ButtonSelecter : public base_engine::Actor{
public:
	explicit ButtonSelecter(base_engine::Game* game);

	~ButtonSelecter() override = default;

	void Start() override;

	void SetInput(InputManager* input_manager);
	
	/// <summary>
	/// キー操作での数値変更
	/// </summary>
	void Update() override;
	
	/// <summary>
	/// 選択中のボタンの実行
	/// </summary>
	void ButtonSelect();


private:
	std::vector<std::vector<Button*>> buttongroupe;
	size_t now_select_x;
	size_t now_select_y;
	InputManager* input_manager_;
};

