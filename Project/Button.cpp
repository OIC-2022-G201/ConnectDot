#include "Button.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "IBaseEngineTexture.h"
#include "IBaseEngineRender.h"
#include "ImageComponent.h"
#include "TexturePaths.h"
using namespace base_engine;
using namespace draw_order;
Button::Button(base_engine::Game* game) : Actor(game) {}

void Button::Start() {
	{
		button_sprite_ = new ImageComponent(this, kButtonDrawOrder);

		if(button_texture_)button_sprite_->SetImage(button_texture_);
	}
}

void Button::SetButtonSprite(base_engine::TexturePtr texture) {
	button_texture_ = texture;
	if (button_sprite_) {
		button_sprite_->SetImage(button_texture_);
	}
	SetName("Button");
}

void Button::SetChangeButtonSprite(base_engine::TexturePtr texture) {
	changebutton_texture_ = texture;
}

void Button::SetEvent(std::function<void()> event) {
	event_ = event;
}

void Button::Update() {

}

void Button::OnPress() {
	if(!event_)return;
	event_();
}

void Button::OnHover(){
	if (!changebutton_texture_)return;
	button_sprite_->SetImage(changebutton_texture_);
}

void Button::OutHover(){
	if (!button_texture_)return;;
	button_sprite_->SetImage((button_texture_));
}
