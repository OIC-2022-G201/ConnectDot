#include "Button.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "GridPosition.h"
#include "IBaseEngineTexture.h"
#include "IBaseEngineRender.h"
#include "TexturePaths.h"
#include "GameWindow.h"
using namespace base_engine;
using namespace draw_order;
Button::Button(base_engine::Game* game) : Actor(game) {}

void Button::Start() {
	{
		button_sprite_ = new SpriteComponent(this, kButtonDrawOrder);
	}
	{
		auto v = BASE_ENGINE(Render)->GetCameraPosition();
		camera_pos = Vector2{
	  window::kWidth / static_cast<float>(2) - v.x,
	  window::kHeight / static_cast<float>(2) - v.y };
		SetPosition(Vector2{ 0,0 } - camera_pos);
	}
}

void Button::SetButtonSprite(base_engine::TexturePtr texture) {
	button_texture_ = texture;
	if (button_sprite_) {
		button_sprite_->SetImage(button_texture_);
	}
	SetName("Button");
}

void Button::SetChangeButtonSprite(base_engine::TexturePtr texture)
{
	changebutton_texture_ = texture;
}

void Button::SetEvent(std::function<void()> event)
{
	event_ = event;
}

void Button::Update() {

	auto v = BASE_ENGINE(Render)->GetCameraPosition();
	if (auto pos = Vector2{ v.x,v.y };
		camera_pos != pos) {
		SetPosition(Vector2{ 0,0 } - Vector2{
			window::kWidth / static_cast<float>(2) - v.x,
				window::kHeight / static_cast<float>(2) - v.y });
		camera_pos = pos;
	}
}

void Button::OnPress() {
	event_();
}