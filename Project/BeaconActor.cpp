#include "BeaconActor.h"

#include "BeaconReceiver.h"
#include "BeaconTransmitter.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TransmitterComponent.h"

BeaconActor::BeaconActor(base_engine::Game* game) : Actor(game) {}

BeaconActor::~BeaconActor() {}

void BeaconActor::Start() {
  {
    auto cellhalf = stage::kStageCellSizeHalf<base_engine::Floating>;
    auto circle = std::make_shared<base_engine::Circle>(
        cellhalf.x, cellhalf.y, electronics::kPowerRadius);
    auto shape = new base_engine::ShapeRenderComponent(this, 110);
    shape->SetShape(circle);
    shape->SetFillMode(base_engine::FillMode::Yes)
        .SetColor(MOF_ARGB(255 - 128, 255, 255, 0));

    auto collision = new base_engine::CollisionComponent(this);
    collision->SetShape(circle);
    collision->SetObjectFilter(kBeaconObjectFilter);
    collision->SetTargetFilter(kBeaconTargetFilter);
    collision->SetTrigger(true);
  }

  {
    auto rect = std::make_shared<base_engine::Rect>(
        0, 0, stage::kStageCellSize<base_engine::Floating>.x,
        stage::kStageCellSize<base_engine::Floating>.y);

    auto shape_rect = new base_engine::ShapeRenderComponent(
        this, draw_order::kPylonDrawOrder);
    shape_rect->SetShape(rect);
    shape_rect->SetFillMode(base_engine::FillMode::Yes)
        .SetColor(MOF_ARGB(255, 0, 0, 255));
  }
  SetName("Beacon");

  {
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<BeaconTransmitter>(this);
  
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<BeaconReceiver>(this);
    std::get<BeaconReceiver*>(tuple_);
  }

  {
    auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition(GridPosition::VectorTo(GetPosition()));
  }
}

void BeaconActor::Input() {}

void BeaconActor::Update() {}
