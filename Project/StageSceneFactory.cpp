#include "StageSceneFactory.h"

#include <array>

#include "CameraComponent.h"
#include "ComponentServiceLocator.h"
#include "DebugStage.h"
#include "EnemyActor.h"
#include "EventRegister.h"
#include "FollowComponent.h"
#include "GameWindow.h"
#include "ImageComponent.h"
#include "InputActor.h"
#include "InputManager.h"
#include "ObjectLoader.h"
#include "ObjectTileMapComponent.h"
#include "ParallaxCameraFlowLayer.h"
#include "PauseManager.h"
#include "PlayerActor.h"
#include "PylonActor.h"
#include "ResourceContainer.h"
#include "ResultScoreComponent.h"
#include "StageContainer.h"
#include "TileMapComponent.h"
using namespace base_engine;
void StageSceneFactory::Factory() {
  const auto stage_container =
      ServiceLocator::Instance().Resolve<StageContainer>();
  const auto stage_def = stage_container->GetStage();
  {
    const auto camera = new Actor(game_);
    const auto camera_component = new CameraComponent(camera);
    camera_component->SetMainCamera();
    const auto follow = new FollowComponent(camera);
  }
  const auto stageActor = new DebugStage(game_);
  {
    stageActor->SetName("Stage");
    const auto stage = new tile_map::TileMapComponent(stageActor, 100);
    stage->SetStage(stage_def->first.string());
    stage->Load();
    new tile_map::ObjectTileMapComponent(stageActor);
    ComponentServiceLocator::Instance().RegisterInstance(
        stageActor->GetComponent<tile_map::ObjectTileMapComponent>());
    ComponentServiceLocator::Instance().RegisterInstance(
        stageActor->GetComponent<tile_map::TileMapComponent>());

    {
      std::unordered_map<std::string, float> offset = {
          {"Stage1", 9}, {"Stage2", 22}, {"Stage3", 9}};
      const float height = stage->LeftBottom().y -
                           offset[stage_def->second.filename().string()] + 0.02;
      const auto pos = GridPosition::GridTo({0, 1}) * height;
      const auto camera_pos = CameraComponent::GetMainCamera()
                                  .lock()
                                  ->GetOwner()
                                  .lock()
                                  ->GetPosition() +
                              GridPosition::GridTo({0, 2});
      using CreateInfo = ParallaxCameraFlowLayer::CreateInfo;
      std::array create_def = {
          CreateInfo{"BG70", 1, 0.2f, 5, false, camera_pos},
          CreateInfo{"BG65", 0.7, 1, 10, false, camera_pos},
          CreateInfo{"BG60", 0.7, 0.1, 15, true, camera_pos},
          CreateInfo{"BG50", 0, 1, 20, false, camera_pos},
          CreateInfo{"BG40", 0.5, 0.1, 25, true, camera_pos},
          CreateInfo{"BG30", 0.4, 1, 30, false, camera_pos},
          CreateInfo{"BG20", 0.3, 0, 35, false, pos},
          CreateInfo{"BG10", -0.2, 0, 200, false, pos}};
      //    ParallaxCameraFlowLayer::Create(game_,
      //    stage_def->first.stem().string(),
      //                                    create_def);
      ParallaxCameraFlowLayer::Create(game_, "Stage1", create_def);
    }
  }
  const auto BG = new ImageComponent(new Actor(game_), 1);

  BG->SetImage(
      *ResourceContainer::GetResource<ResourceContainer::SpriteResourcePack,
                                      ResourceContainer::Sprite>("BG"));
  new InputManager(new InputActor(game_));
  ObjectLoader object_loader{game_};
  object_loader.Load(stage_def->second.string());

  ServiceLocator::Instance().RegisterInstance(
      std::make_shared<PauseManager>(game_));
  ResultScoreComponent::Create(game_);
}
