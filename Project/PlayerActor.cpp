#include "PlayerActor.h"

#include <Utilities/InputUtilities.h>

#include "BeaconActor.h"
#include "InputManager.h"
#include "Player.h"
#include "PlayerComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
namespace player {
PlayerActor::PlayerActor(base_engine::Game* game)
    : Actor(game), input_manager_(nullptr) {}

PlayerActor::~PlayerActor() {}
void PlayerActor::Start() {
  player_component_ = new PlayerComponent(this, 100);

  player_component_->SetInput(input_manager_);
}

void PlayerActor::SetInput(InputManager* input_manager) {
  input_manager_ = input_manager;
}

void PlayerActor::Input() {
  // const float horizontal = input_manager_->MoveHorizontal();
  // move_vector_.x = horizontal * 3;
  if (input_manager_->PlaceBeaconFire()) {
    auto beacon = new BeaconActor(GetGame());
    beacon->SetPosition(GetPosition());
  }
}
void PlayerActor::Update() {
  player_component_->AddVelocityY(kGravity);
  position_ += player_component_->GetVelocity();
  float bottom =
      Mof::CGraphicsUtilities::GetGraphics()->GetTargetHeight() - 230;
  if (position_.y>bottom)
  {
    position_.y = bottom;
  }
}
}  // namespace player