#include "StageSceneFactory.h"

#include <array>

#include "AudioStreamComponent.h"
#include "AudioVolume.h"
#include "BeaconCounterPresenter.h"
#include "CameraComponent.h"
#include "CameraCustomComponent.h"
#include "ComponentServiceLocator.h"
#include "DebugStage.h"
#include "FollowComponent.h"
#include "ImageComponent.h"
#include "InputActor.h"
#include "InputManager.h"
#include "ObjectLoader.h"
#include "ObjectTileMapComponent.h"
#include "ParallaxCameraFlowLayer.h"
#include "PauseManager.h"
#include "ResourceContainer.h"
#include "ResultScoreComponent.h"
#include "StageContainer.h"
#include "TileMapComponent.h"
#include "TimeCounterPresenter.h"
#include "TimeCounterView.h"
#include "VentGroupLocator.h"
using namespace base_engine;
void StageSceneFactory::Factory() {
  ServiceLocator::Instance().Resolve<VentGroupLocator>()->Clear();
  const auto stage_container =
      ServiceLocator::Instance().Resolve<StageContainer>();
  const auto stage_def = stage_container->GetStage();
  {
    const auto camera = new Actor(game_);
    const auto camera_component = new CameraComponent(camera);
    camera_component->SetMainCamera();
    const auto follow = new FollowComponent(camera);
    //    const auto camera_cutuom = new CameraCustomComponent(camera);
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
      std::unordered_map<std::string, float> offset = {{"Stage1", 9},
                                                       {"Stage2", 19},
                                                       {"Stage3", 9},
                                                       {"Stage4", 9},
                                                       {"Stage5", 9}};
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
          CreateInfo{"BG20", 0.3, 0, 35, false, pos}};
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

  {
    const auto audioBGM = new AudioStreamComponent(new Actor(game_));
    audioBGM->AssetLoad("InGameBGM");
    audioBGM->SetLoop(true);
    audioBGM->SetVolume(
        ServiceLocator::Instance().Resolve<AudioVolume>()->BGMVolume());
    audioBGM->Play();
  }
  {
    ServiceLocator::Instance().RegisterInstance(
        std::make_shared<BeaconCounterPresenter>());
    const auto beaconCounterView = new BeaconCounterView(game_);
    ServiceLocator::Instance()
        .Resolve<BeaconCounterPresenter>()
        ->SetBeaconCounterView(beaconCounterView);
    const auto beaconPowerUpCounterView = new BeaconPowerUpCounterView(game_);
    ServiceLocator::Instance()
        .Resolve<BeaconCounterPresenter>()
        ->SetBeaconPowerUpCounterView(beaconPowerUpCounterView);
  }
  {
    ServiceLocator::Instance().RegisterInstance(
        std::make_shared<TimeCounterPresenter>());
    const auto timeCounterModel = std::make_shared<TimeCounterModel>();
    ServiceLocator::Instance()
        .Resolve<TimeCounterPresenter>()
        ->SetTimeCounterModel(timeCounterModel);
    const auto timeCounterView = new TimeCounterView(game_);
    ServiceLocator::Instance()
        .Resolve<TimeCounterPresenter>()
        ->SetTimeCounterView(timeCounterView);
    ServiceLocator::Instance().Resolve<TimeCounterPresenter>()->Bind();

    std::any sender = this;
    StageEpilogueEvent stage_epilogue{sender};
    EventBus::FireEvent(stage_epilogue);
  }
  ServiceLocator::Instance().RegisterInstance(
      std::make_shared<PauseManager>(game_));
  ResultScoreComponent::Create(game_);
}