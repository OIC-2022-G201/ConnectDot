#include "BeaconActor.h"

#include "BeaconReceiver.h"
#include "BeaconTransmitter.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "MofSpriteAnimationComponent.h"
#include "ReceiverComponent.h"
#include "Rect.h"
#include "ResourceContainer.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TransmitterComponent.h"
using namespace electronics;
using namespace beacon;
using RC = ResourceContainer;
constexpr std::string_view kBeaconName = "Beacon";
constexpr std::string_view kBeaconOffName = "BeaconOff";
constexpr std::string_view kBeaconOnName = "BeaconOn";
constexpr std::string_view kBeaconPowerup = "BeaconPowerup";
class BeaconDummyComponent : public base_engine::Component,
                             public IMachineActionable {
 public:
  BeaconDummyComponent(BeaconActor* owner, int update_order = 100)
      : Component(owner, update_order) {}

  void Action(base_engine::Actor* actor) override
  {
    owner_->GetComponent<TransmitterComponent>().lock()->SetLevel(2);
    const auto image = RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(kBeaconPowerup.data());
    owner_->GetComponent<base_engine::SpriteComponent>().lock()->SetImage(*image);
    
  }

};
BeaconActor::BeaconActor(base_engine::Game* game) : Actor(game) {
  {
    const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Circle>(
        cell_half.x, cell_half.y, kPowerRadius);
    if (false) {
      const auto shape = new base_engine::ShapeRenderComponent(this, 110);
      shape->SetShape(circle);
      shape->SetFillMode(kElectricAreaFillMode).SetColor(kElectricAreaColor);
      RegistryPart(shape);
    }
    const auto collision = new base_engine::CollisionComponent(this);
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
    sprite_ = new base_engine::SpriteComponent(this, 130);
    const auto sprite_resource =
        RC::GetResource<RC::AnimationResourcePack, RC::Sprite>(
            kBeaconName.data());
    sprite_->SetImage(*sprite_resource);
    const auto clips =
        RC::GetResource<RC::AnimationResourcePack, RC::AnimationClips>(
            kBeaconName.data());
    animation_ = new base_engine::MofSpriteAnimationComponent(this);
    animation_->Load(sprite_, *clips);
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
  });

  SetName("Beacon");
  SetTag("Beacon");
}

BeaconActor::~BeaconActor() = default;

void BeaconActor::Start() {}

void BeaconActor::Input() {}

void BeaconActor::Update() {
  if (!is_deployed_ && animation_->IsEndMotion()) {
    is_deployed_ = true;
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<BeaconTransmitter>(this, kBeaconTransmitterOffset);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<BeaconReceiver>(this, kBeaconReceiverOffset);
  }
}

