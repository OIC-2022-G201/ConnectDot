#pragma once

#include "Button.h"
#include "Component.h"
#include "ImageAlphaTween.h"

class GameOverComponent final:public base_engine::Component
{
	base_engine::Actor* logo_;
	std::vector<Button*> buttons_;
	auto& ButtonsAnimation()
	{
		float duration = 0.5f;
		ma_tween::ImageAlphaTween::TweenImageAlpha(buttons_[0], 255, duration);
		return ma_tween::ImageAlphaTween::TweenImageAlpha(buttons_[1], 255, duration);
	}

public:
	GameOverComponent(base_engine::Actor* owner) :Component(owner) {};
	void Start() override;
	void SetLogo(base_engine::Actor* logo) { logo_ = logo; }
	void SetButton(Button* button) { buttons_.emplace_back(button); }
};

