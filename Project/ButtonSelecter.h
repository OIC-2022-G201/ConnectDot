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
	/// �L�[����ł̐��l�ύX
	/// </summary>
	void Update() override;
	
	/// <summary>
	/// �I�𒆂̃{�^���̎��s
	/// </summary>
	void ButtonSelect();


private:
	std::vector<std::vector<Button*>> buttongroupe;
	size_t now_select_x;
	size_t now_select_y;
	InputManager* input_manager_;
};

