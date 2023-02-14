#include "PlayerActor.h"

#include <Utilities/InputUtilities.h>

#include "BeaconActor.h"
#include "CameraComponent.h"
#include "CameraCustomComponent.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "DrawOrder.h"
#include "DummyEmptyBeaconActor.h"
//#include "FollowComponent.h"
#include "GameWindow.h"
#include "IBaseEngineTexture.h"
#include "InputManager.h"
#include "MofSpriteAnimationComponent.h"
#include "PlayerComponent.h"
#include "Rect.h"
#include "ReleaseInfo.h"
#include "ResourceContainer.h"
#include "ShaderBase.h"
#include "Material.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
#include "TileMapComponent.h"
using namespace base_engine;
namespace player {
PlayerActor::PlayerActor(base_engine::Game* game)
    : Actor(game), input_manager_(nullptr) {}

PlayerActor::~PlayerActor() = default;

void PlayerActor::Start() {
  {
    player_component_ = new PlayerComponent(this, 100);

    player_component_->SetInput(input_manager_);
    player_component_->SetMap(map_);
  }
  {
    const auto collision = new CollisionComponent(this);
    const auto shape_player = std::make_shared<Rect>(90, 100, 256 -90, 256);
    collision->SetShape(shape_player);
    collision->SetObjectFilter(kPlayerObjectFilter);
    collision->SetTargetFilter(kPlayerTargetFilter);
    if (kIsCollisionRenderMode) {
      const auto debug_collision_render = new ShapeRenderComponent(this, 500);
      debug_collision_render->SetShape(shape_player);
      debug_collision_render->SetColor(MOF_COLOR_GREEN);
    }
  }
  {
    const auto player_sprite =
        new SpriteComponent(this, draw_order::kPlayerDrawOrder);
    const auto player_animation = new MofSpriteAnimationComponent(this);
    player_animation->Load(player_sprite, "Player_Animation.aei");
    player_sprite->SetImage(
        BASE_ENGINE(Texture)->Get(texture::kPlayerTextureKey));
    using RC = ResourceContainer;
    const auto material = RC::GetResource<RC::MaterialResourcePack, Material>("TestShader");
    struct {
      Vector2 Screen;
      int nCount;
    } sb;
    sb.Screen.x = 1920;
    sb.Screen.y = 1080;
    sb.nCount = 5;
    material->SetParameter({"cb",0,PropertyType::kBuffer,&sb});
//    player_sprite->SetMaterial(material);
  }
  auto body = new PhysicsBodyComponent(this);
  SetName("Player");
}

void PlayerActor::SetInput(InputManager* input_manager) {
  input_manager_ = input_manager;
}

void PlayerActor::Create(const LoadObject& object) {
  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[1]).value;
    SetPosition(GridPosition::GridTo({pos.x, pos.y}));
  }
  SetInput(InputManager::Instance());
  SetMap(ComponentServiceLocator::Instance()
             .Resolve<tile_map::TileMapComponent>());
  CameraComponent::GetMainCamera()
      .lock()
      ->GetOwner()
      .lock()
      ->GetComponent<CameraCustomComponent>()
      .lock()
      ->BindTarget(GetGame()->GetActor(GetId()));
}

void PlayerActor::Input() {}
void PlayerActor::Update() {}
}  // namespace player