#include "StageSceneFactory.h"

#include "CameraComponent.h"
#include "DebugStage.h"
#include "EnemyActor.h"
#include "EventRegister.h"
#include "FollowComponent.h"
#include "InputActor.h"
#include "InputManager.h"
#include "ObjectLoader.h"
#include "ObjectTileMapComponent.h"
#include "PlayerActor.h"
#include "PylonActor.h"
#include "ServiceLocator.h"
#include "TileMapComponent.h"
using namespace base_engine;
void StageSceneFactory::Factory() {
  auto camera = new Actor(game_);
  auto camera_component = new CameraComponent(camera);
  camera_component->SetMainCamera();
  auto follow = new FollowComponent(camera);
  auto stageActor = new DebugStage(game_);
  {
    stageActor->SetName("Stage");
    new tile_map::TileMapComponent(stageActor, 100);
    new tile_map::ObjectTileMapComponent(stageActor);
    ServiceLocator::Instance().RegisterInstance(
        stageActor->GetComponent<tile_map::ObjectTileMapComponent>()
        );
  }

  new InputManager(new InputActor(game_));
  
  auto player = new player::PlayerActor(game_);
  player->SetInput(InputManager::Instance());
  const auto tilemap = stageActor->GetComponent<tile_map::TileMapComponent>();
  player->SetMap(tilemap);
  follow->BindTarget(game_->GetActor(player->GetId()));
  new enemy::EnemyActor(game_);

  ObjectLoader object_loader{game_};
  object_loader.Load("MapData/Stage1");
}
