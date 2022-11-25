#include "PlayerActor.h"

#include <Utilities/InputUtilities.h>

#include "BeaconActor.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "GameWindow.h"
#include "IBaseEngineTexture.h"
#include "InputManager.h"
#include "MofSpriteAnimationComponent.h"
#include "PlayerComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
using namespace base_engine;
namespace player {
PlayerActor::PlayerActor(base_engine::Game* game)
    : Actor(game), input_manager_(nullptr) {}

PlayerActor::~PlayerActor() = default;

void PlayerActor::Start() {
  {
    player_component_ = new PlayerComponent(this, 100);

    player_component_->SetInput(input_manager_);
    SetPosition({300, window::kHeight - 930});
  }
  {
    const auto collision = new CollisionComponent(this);
    const auto shape_player = std::make_shared<Rect>(70, 70, 256 - 70, 256);
    collision->SetShape(shape_player);
    collision->SetObjectFilter(kPlayerObjectFilter);
    collision->SetTargetFilter(kPlayerTargetFilter);

    const auto debug_collision_render = new ShapeRenderComponent(this, 500);
    debug_collision_render->SetShape(shape_player);
    debug_collision_render->SetColor(MOF_COLOR_GREEN);
  }
  {
    const auto player_sprite =
        new SpriteComponent(this, draw_order::kPlayerDrawOrder);
    const auto player_animation = new MofSpriteAnimationComponent(this);
    player_animation->Load(player_sprite, "Player_Animation.aei");
    player_sprite->SetImage(
        BASE_ENGINE(Texture)->Get(texture::kPlayerTextureKey));
  }

  auto body = new PhysicsBodyComponent(this);
  SetName("Player");
}

void PlayerActor::SetInput(InputManager* input_manager) {
  input_manager_ = input_manager;
}

void PlayerActor::Input() {}
void PlayerActor::Update() { camera_->SetPosition(GetPosition()); }
}  // namespace player