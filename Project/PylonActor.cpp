#include "PylonActor.h"

#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "PylonTransmitter.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TransmitterComponent.h"

using base_engine::Floating;
using base_engine::Vector2;

PylonActor::PylonActor(base_engine::Game* game) : Actor(game) {}

PylonActor::~PylonActor() {}

void PylonActor::Start() {
  {
    auto cellhalf = stage::kStageCellSizeHalf<Floating>;
    auto circle = std::make_shared<base_engine::Circle>(
        cellhalf.x, cellhalf.y, electronics::kPowerRadius);
    auto shape = new base_engine::ShapeRenderComponent(
        this, draw_order::kElectromagneticArea);
    shape->SetShape(circle);
    shape->SetFillMode(base_engine::FillMode::Yes)
        .SetColor(MOF_ARGB(255 - 32, 255, 255, 0));

    auto collision = new base_engine::CollisionComponent(this);
    collision->SetShape(circle);
    collision->SetObjectFilter(kBeaconObjectFilter);
    collision->SetTargetFilter(kBeaconTargetFilter);
    collision->SetTrigger(true);
  }

  {
    auto rect = std::make_shared<base_engine::Rect>(
        0, 0, stage::kStageCellSize<Floating>.x,
        stage::kStageCellSize<Floating>.y);

    auto shape_rect = new base_engine::ShapeRenderComponent(
        this, draw_order::kPylonDrawOrder);
    shape_rect->SetShape(rect);
    shape_rect->SetFillMode(base_engine::FillMode::Yes)
        .SetColor(MOF_ARGB(255, 0, 0, 255));
  }

  SetName("Pylon");

  {
    auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<PylonTransmitter>();
  }
  {
    auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({3, 5});
  }
}

void PylonActor::Update() {}
