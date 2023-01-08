﻿#include "StageSceneFactory.h"

#include <array>

#include "CameraComponent.h"
#include "ComponentServiceLocator.h"
#include "DebugStage.h"
#include "EnemyActor.h"
#include "EventRegister.h"
#include "FollowComponent.h"
#include "ImageComponent.h"
#include "InputActor.h"
#include "InputManager.h"
#include "ObjectLoader.h"
#include "ObjectTileMapComponent.h"
#include "ParallaxCameraFlowLayer.h"
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
    new tile_map::ObjectTileMapComponent(stageActor);
    ComponentServiceLocator::Instance().RegisterInstance(
        stageActor->GetComponent<tile_map::ObjectTileMapComponent>());
    ComponentServiceLocator::Instance().RegisterInstance(
        stageActor->GetComponent<tile_map::TileMapComponent>());
  }

  {
    using CreateInfo = ParallaxCameraFlowLayer::CreateInfo;
    std::array create_def = {CreateInfo{"Back", 1, 0.2f, 10},
                             CreateInfo{"Middle", 0.7, 0, 20},
                             CreateInfo{"Front", -0.2, 0, 300}};
//    ParallaxCameraFlowLayer::Create(game_, stage_def->first.stem().string(),
//                                    create_def);
    ParallaxCameraFlowLayer::Create(game_, "Stage1",
                                    create_def);
  }
  const auto BG = new ImageComponent(new Actor(game_),1);

  BG->SetImage(
      *ResourceContainer::GetResource<ResourceContainer::SpriteResourcePack,
                                      ResourceContainer::Sprite>("BG"));
  new InputManager(new InputActor(game_));
  ObjectLoader object_loader{game_};
  object_loader.Load(stage_def->second.string());

  ResultScoreComponent::Create(game_);
}
