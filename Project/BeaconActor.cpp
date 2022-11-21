#include "BeaconActor.h"

#include "BaseEngineCore.h"
#include "BeaconReceiver.h"
#include "BeaconTransmitter.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "ReceiverComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace electronics;
using namespace beacon;
BeaconActor::BeaconActor(base_engine::Game* game) : Actor(game)
{
  {
    const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Circle>(
        cell_half.x, cell_half.y, kPowerRadius);
    const auto shape = new base_engine::ShapeRenderComponent(this, 110);
    shape->SetShape(circle);
    shape->SetFillMode(kElectricAreaFillMode).SetColor(kElectricAreaColor);
    RegistryPart(shape);
    const auto collision = new base_engine::CollisionComponent(this);
    collision->SetShape(circle);
    collision->SetObjectFilter(kBeaconObjectFilter);
    collision->SetTargetFilter(kBeaconTargetFilter);
    collision->SetTrigger(true);
  }

  {
    const auto sign = new base_engine::SpriteComponent(this, 130);
    sign->SetImage(BASE_ENGINE(Texture)->Get(texture::kBeaconTextureKey));
  }
  SetName("Beacon");
  SetTag("Beacon");

  {
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<BeaconTransmitter>(this, kBeaconTransmitterOffset);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<BeaconReceiver>(this, kBeaconReceiverOffset);
  }

  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition(GridPosition::VectorTo(GetPosition()));
  }
  electric_power_.Subscribe([&](bool x) {
    std::get<base_engine::ShapeRenderComponent*>(tuple_)->SetColor(
        MOF_ARGB(255 - 128, 0, 255, 0));
  });
}

BeaconActor::~BeaconActor() {}

void BeaconActor::Start() {
  
}

void BeaconActor::Input() {}

void BeaconActor::Update() {}
