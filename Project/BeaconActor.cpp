#include "BeaconActor.h"

#include "AudioVolume.h"
#include "BeaconPowerUpActionEvent.h"
#include "BeaconReceiver.h"
#include "BeaconTransmitter.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "DummyTween.h"
#include "ElectronicsPower.h"
#include "EventBus.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "IMachineActionable.h"
#include "MofSpriteAnimationComponent.h"
#include "ObjectTileMapComponent.h"
#include "PositionYTween.h"
#include "ReceiverComponent.h"
#include "Rect.h"
#include "ReleaseInfo.h"
#include "ResourceContainer.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TransmitterComponent.h"
using namespace electronics;
using namespace beacon;
using namespace base_engine;
using RC = ResourceContainer;
constexpr std::string_view kBeaconName = "BeaconAnimation";
constexpr std::string_view kBeaconOffName = "BeaconOff";
constexpr std::string_view kBeaconOnName = "BeaconOn";
constexpr std::string_view kBeaconPowerup = "BeaconPowerup";
constexpr std::string_view kBeaconOutline = "BeaconOutline";
constexpr std::string_view kBeaconPowerUpRange = "BeaconPowerUpRange";
class BeaconDummyComponent : public Component, public IMachineActionable {
 public:
  BeaconDummyComponent(BeaconActor* owner, int update_order = 100)
      : Component(owner, update_order), owner_as_beacon_(owner) {}

  void Action(Actor* actor) override {
    if (const auto transmitter = owner_->GetComponent<TransmitterComponent>();
        transmitter.expired() || transmitter.lock()->Level() != 1) {
      return;
    }
    if (!static_cast<bool>(owner_as_beacon_->ElectricPowerTrigger())) return;
    std::any send = std::make_any<Actor*>(owner_);

    auto event = BeaconPowerUpActionEvent(send, false);
    EventBus::FireEvent(event);
  }

 private:
  BeaconActor* owner_as_beacon_;
};
BeaconActor::BeaconActor(Game* game) : Actor(game) {
  const auto cell_half = stage::kStageCellSizeHalf<Floating>;
  {
    const auto circle =
        std::make_shared<Circle>(cell_half.x, cell_half.y, kPowerRadius);
    if (kIsCollisionRenderMode) {
      const auto shape = new base_engine::ShapeRenderComponent(this, 110);
      shape->SetShape(circle);
      shape->SetFillMode(kElectricAreaFillMode).SetColor(kElectricAreaColor);
      RegistryPart(shape);
    }
    const auto collision = new CollisionComponent(this);
    collision->SetShape(circle);
    collision->SetObjectFilter(kBeaconObjectFilter);
    collision->SetTargetFilter(kBeaconTargetFilter);
    collision->SetTrigger(true);
    new BeaconDummyComponent(this);
    const auto beacon_body = new base_engine::CollisionComponent(this);
    const auto cell = stage::kStageCellSize<base_engine::Floating>;
    const auto rect = std::make_shared<base_engine::Rect>(0, 0, cell.x, cell.y);
    beacon_body->SetShape(rect);
    beacon_body->SetObjectFilter(kBeaconObjectFilter | kLeverObjectFilter);
    beacon_body->SetTargetFilter(kPlayerObjectFilter);
    beacon_body->SetTrigger(true);
  }
  {
    const auto audio_stream = new AudioStreamComponent(this);
    audio_stream->AssetLoad("BeaconConnectSE");
    audio_stream->SetVolume(ServiceLocator::Instance().Resolve<AudioVolume>()->SEVolume());
  }
  {
    sprite_outline_ = new SpriteComponent(this, 131);
    const auto sprite_outline_resource =
        RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
            kBeaconOutline.data());
    sprite_outline_->SetImage(*sprite_outline_resource);
    sprite_outline_->SetEnabled(false);

    sprite_ = new SpriteComponent(this, 130);
    const auto sprite_resource =
        RC::GetResource<RC::AnimationResourcePack, RC::Sprite>(
            kBeaconName.data());
    sprite_->SetImage(*sprite_resource);
    const auto clips =
        RC::GetResource<RC::AnimationResourcePack, RC::AnimationClips>(
            kBeaconName.data());
    animation_ = new MofSpriteAnimationComponent(this);
    animation_->Load(sprite_, *clips);

    const auto range_image =
        RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
            kBeaconPowerUpRange.data());

    range_sprite_ = new SpriteComponent(this, 130 + 2);
    range_sprite_->SetAlignment(Mof::TEXALIGN_CENTERCENTER)
        .SetColor(MOF_ARGB(0, 255, 255, 255))
        .SetImage(*range_image)
        .SetOffset({cell_half.x, cell_half.y})
        .SetEnabled(false);
  }

  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition(GridPosition::VectorTo(GetPosition()));
  }
  electric_power_.Subscribe([&](bool x) {
    const auto sprite_resource =
        RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
            x ? kBeaconOnName.data() : kBeaconOffName.data());
    sprite_->SetImage(*sprite_resource);
    sprite_->FitClipRect();

    if (!x) {
      if (static_cast<int>(level_) == 2) {
        LevelDown();
      }
    }
  });

  SetName("Beacon");
  SetTag("Beacon");

  map_ =
      ComponentServiceLocator::Instance().Resolve<tile_map::TileMapComponent>();
  object_map_ = ComponentServiceLocator::Instance()
                    .Resolve<tile_map::ObjectTileMapComponent>();
}

BeaconActor::~BeaconActor() = default;

void BeaconActor::Start() {}

void BeaconActor::Input() {}

void BeaconActor::Update() {
  if (!is_deployed_ && animation_->IsEndMotion() &&
      animation_->IsMotion("Open")) {
    is_deployed_ = true;
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<BeaconTransmitter>(this, kBeaconTransmitterOffset);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<BeaconReceiver>(this, kBeaconReceiverOffset);
  }

  auto bottom_pos = GridPosition::VectorTo(GetPosition()) + GridPosition{0, 1};
  if (map_->GetCell(bottom_pos) == tile_map::kEmptyCell &&
      object_map_->GetCell(bottom_pos) < tile_map::kCanOnPlace) {
    Break();
  }
}

void BeaconActor::LevelUp() {
  GetComponent<TransmitterComponent>().lock()->SetLevel(2);
  {
    const auto cell_half = stage::kStageCellSizeHalf<Floating>;

    const auto circle =
        std::make_shared<Circle>(cell_half.x, cell_half.y, kPowerRadius + 128);
    const auto collision = GetComponent<CollisionComponent>().lock();
    collision->SetShape(circle);
    collision->Sync();
  }
  level_ = 2;
  const auto image = RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
      kBeaconPowerup.data());
  GetComponent<base_engine::SpriteComponent>().lock()->SetImage(*image);

  range_sprite_->SetEnabled(true);
  range_sprite_->SetColor(MOF_ARGB(255, 255, 255, 255));
}

void BeaconActor::LevelDown() {
  GetComponent<TransmitterComponent>().lock()->SetLevel(1);
  {
    const auto cell_half = stage::kStageCellSizeHalf<Floating>;

    const auto circle =
        std::make_shared<Circle>(cell_half.x, cell_half.y, kPowerRadius);
    const auto collision = GetComponent<CollisionComponent>().lock();
    collision->SetShape(circle);
    collision->Sync();
  }
  level_ = 1;
  const auto image = RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
      kBeaconOffName.data());
  GetComponent<SpriteComponent>().lock()->SetImage(*image);

  range_sprite_->SetEnabled(false);
  range_sprite_->SetColor(MOF_ARGB(0, 255, 255, 255));
}

void BeaconActor::SetOutline(const bool flg) const {
  sprite_outline_->SetEnabled(flg);
}

bool BeaconActor::IsOutline() const { return sprite_outline_->GetEnabled(); }

void BeaconActor::Close() {
  if (!animation_->IsEndMotion() && animation_->IsMotion("Close")) return;
  const auto sprite_resource =
      RC::GetResource<RC::AnimationResourcePack, RC::Sprite>(
          kBeaconName.data());
  sprite_->SetImage(*sprite_resource);
  sprite_outline_->SetEnabled(false);
  RemoveComponent(GetComponent<TransmitterComponent>().lock().get());
  RemoveComponent(GetComponent<ReceiverComponent>().lock().get());
  animation_->Play("Close");
  const auto list = GetChildren();
  for (const auto& child : list) {
    if (child.expired()) continue;
    RemoveChild(child.lock()->GetId());
    GetGame()->RemoveActor(child.lock().get());
  }
  const auto pos = GridPosition::VectorTo(GetPosition());
  
  ma_tween::DummyTween::TweenDummy(this, 0.5f).SetOnComplete([this, pos] {
    auto cell = object_map_->GetCell(pos);
    if ((cell == 10)) cell = 0;
    if ((cell == 1)) cell = 0;
    object_map_->SetCell(pos.x, pos.y, cell);
    GetGame()->RemoveActor(this);
  });
}

void BeaconActor::Break(bool fall) {
  if (!animation_->IsEndMotion() && animation_->IsMotion("Break")) return;
  const auto sprite_resource =
      RC::GetResource<RC::AnimationResourcePack, RC::Sprite>(
          kBeaconName.data());
  sprite_->SetImage(*sprite_resource);
  sprite_outline_->SetEnabled(false);
  RemoveComponent(GetComponent<TransmitterComponent>().lock().get());
  RemoveComponent(GetComponent<ReceiverComponent>().lock().get());
  animation_->Play("Break");
  const auto list = GetChildren();
  for (const auto& child : list) {
    if (child.expired()) continue;
    RemoveChild(child.lock()->GetId());
    GetGame()->RemoveActor(child.lock().get());
  }
  const auto pos = GridPosition::VectorTo(GetPosition());
  
  ma_tween::PositionYTween::TweenLocalPositionY(this, GetPosition().y + 128,
                                                0.5)
      .SetOnComplete([this, pos] {
        auto cell  = object_map_->GetCell(pos);
        if ((cell == 10)) cell = 0;
        if ((cell == 1)) cell = 0;
        object_map_->SetCell(pos.x, pos.y, cell);
        GetGame()->RemoveActor(this);
      });
  ;
}
