#include "PlayerActor.h"

#include <Utilities/InputUtilities.h>

#include "BeaconActor.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "GameWindow.h"
#include "InputManager.h"
#include "Player.h"
#include "PlayerComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"

#include "IBaseEngineTexture.h"
#include "TexturePaths.h"
using namespace base_engine;
namespace player {
PlayerActor::PlayerActor(base_engine::Game* game)
    : Actor(game), input_manager_(nullptr) {}

PlayerActor::~PlayerActor() {}
void PlayerActor::Start() {
  player_component_ = new PlayerComponent(this, 100);

  player_component_->SetInput(input_manager_);
  SetPosition({300, window::kHeight - 730});
  auto collision = new CollisionComponent(this);
  const auto shape_player = std::make_shared<Rect>(0, 0, 100, 200);
  collision->SetShape(shape_player);
  collision->SetObjectFilter(kPlayerObjectFilter);
  collision->SetTargetFilter(kPlayerTargetFilter);
  auto debugCollisionRender = new ShapeRenderComponent(this, 500);
  debugCollisionRender->SetShape(shape_player);
  debugCollisionRender->SetColor(MOF_COLOR_GREEN);
  auto playerSprite = new SpriteComponent(this, 100);
  playerSprite->SetImage(BASE_ENGINE(Texture)->Get(texture::kPlayerTextureKey));

    auto body = new PhysicsBodyComponent(this);
    SetName("Player");
}

void PlayerActor::SetInput(InputManager* input_manager) {
  input_manager_ = input_manager;
}

void PlayerActor::Input() {
  // const float horizontal = input_manager_->MoveHorizontal();
  // move_vector_.x = horizontal * 3;
  if (input_manager_->PlaceBeaconFire() && have_beacon_count_ > 0) {
    --have_beacon_count_;
    auto beacon = new BeaconActor(GetGame());
    beacon->SetPosition(GetPosition());
    beacon->SetSequential(MaxBeacon() - have_beacon_count_);
  }
}
void PlayerActor::Update() {
  float bottom = window::kHeight - 230;
  if (position_.y>bottom)
  {
    //position_.y = bottom;
  }
}
}  // namespace player