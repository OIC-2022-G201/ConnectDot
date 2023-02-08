#include "Button.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "IBaseEngineRender.h"
#include "IBaseEngineTexture.h"
#include "ImageComponent.h"
#include "TexturePaths.h"
using namespace base_engine;
using namespace draw_order;
Button::Button(base_engine::Game* game, int draw_order) : Actor(game) {
  {
    button_sprite_ = new ImageComponent(this, draw_order);
    if (button_texture_) button_sprite_->SetImage(button_texture_);
  }
}

void Button::Start() {}

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

void Button::SetEvent(const std::function<void()>& event) {
  event_.emplace_back(event);
}

void Button::SetHoverEvent(const std::function<void()>& event) {
  hover_event_.emplace_back(event);
}

void Button::Update() {}

void Button::OnPress() {
  if (event_.empty()) return;
  for (const auto& event : event_) {
    event();
  }
}

void Button::OnHover() {
  if (!changebutton_texture_) return;
  for (const auto& event : hover_event_) {
    event();
  }
  button_sprite_->SetImage(changebutton_texture_);
}

void Button::OutHover() {
  if (!button_texture_) return;
  button_sprite_->SetImage((button_texture_));
}

void Button::SetHover(const bool flg) const {
  if (flg) {
    if (!changebutton_texture_) return;
    button_sprite_->SetImage(changebutton_texture_);
  } else {
    if (!button_texture_) return;
    button_sprite_->SetImage((button_texture_));
  }
}
