#include "PlayerActor.h"

#include <Utilities/InputUtilities.h>

#include "InputManager.h"
#include "PlayerComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
namespace player {
PlayerActor::PlayerActor(base_engine::Game* game)
    : Actor(game), input_manager_(nullptr) {}

PlayerActor::~PlayerActor() {}
void PlayerActor::Start() {
  auto shape = new base_engine::ShapeRenderComponent(this, 110);
  shape->SetShape(std::make_shared<base_engine::Rect>(0, 0, 50, 50));
  shape->SetFillMode(base_engine::FillMode::Yes).SetColor(MOF_COLOR_GREEN);
  player_component_ = new PlayerComponent(this, 100);

  player_component_->SetInput(input_manager_);
}

void PlayerActor::SetInput(InputManager* input_manager) {
  input_manager_ = input_manager;
}

void PlayerActor::Input() {
  const float horizontal = input_manager_->MoveHorizontal();

  move_vector_.x = horizontal * 3;
}
void PlayerActor::Update() { position_ += move_vector_; }
}  // namespace player