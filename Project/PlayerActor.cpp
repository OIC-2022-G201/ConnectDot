#include "PlayerActor.h"

#include "InputManager.h"
#include "ShapeRenderComponent.h"

PlayerActor::PlayerActor(base_engine::Game* game)
    : Actor(game), input_manager_(nullptr) {}

PlayerActor::~PlayerActor() {}
void PlayerActor::Start() {
  auto shape = new base_engine::ShapeRenderComponent(this, 110);
  shape->CreateRect(0, 0, 50, 50);
  shape->SetFillMode(base_engine::FillMode::Yes).SetColor(MOF_COLOR_GREEN);
}

void PlayerActor::SetInput(InputManager* input_manager) {
  input_manager_ = input_manager;
}

void PlayerActor::Input() {
  float horizontal = input_manager_->MoveHorizontal();

  move_vector_.x = horizontal * 3;
  position_ = input_manager_->MousePosition();

}

void PlayerActor::Update() {}