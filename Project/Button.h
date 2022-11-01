#pragma once
#include "Actor.h"
#include "IBaseEngineTexture.h"
#include "SpriteComponent.h"

class Button : public base_engine::Actor{
	base_engine::Vector2 camera_pos;
public:
	explicit Button(base_engine::Game* game);

	~Button() override = default;

	void Start() override;

	void SetButtonSprite(base_engine::TexturePtr texture);

	void SetChangeButtonSprite(base_engine::TexturePtr texture);

	void SetEvent(std::function<void()>);

	void Update() override;

	void OnPress();
private:
	std::function<void()> event_;
	base_engine::TexturePtr button_texture_ = nullptr;
	base_engine::TexturePtr changebutton_texture_ = nullptr;
	base_engine::SpriteComponent* button_sprite_ = nullptr;
	base_engine::SpriteComponent* changebutton_sprite_ = nullptr;
};