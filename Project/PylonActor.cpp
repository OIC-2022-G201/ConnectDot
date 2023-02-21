#include "PylonActor.h"

#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "ObjectTileMapComponent.h"
#include "PylonTransmitter.h"
#include "Rect.h"
#include "ReleaseInfo.h"
#include "ResourceContainer.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"

using base_engine::Floating;
using base_engine::Vector2;
using namespace electronics;
using namespace pylon;
PylonActor::PylonActor(base_engine::Game* game) : Actor(game) {}

PylonActor::~PylonActor() {}

void PylonActor::Start() {}

void PylonActor::Update() {}

void PylonActor::Create(const LoadObject& object) {
  {
    const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Circle>(
        cell_half.x, cell_half.y, kPowerRadius);
    if (kIsCollisionRenderMode) {
      const auto shape = new base_engine::ShapeRenderComponent(this, 110);
      shape->SetShape(circle);
      shape->SetFillMode(kElectricAreaFillMode).SetColor(kElectricAreaColor);
    }
    const auto collision = new base_engine::CollisionComponent(this);
    collision->SetShape(circle);
    collision->SetObjectFilter(kPowerSupplyUnitObjectFilter);
    collision->SetTargetFilter(kPowerSupplyUnitTargetFilter);
    collision->SetTrigger(true);
  }

  {
    const auto sprite = new base_engine::SpriteComponent(
        this, draw_order::kPowerSupplyUnitDrawOrder);
    using RC = ResourceContainer;
    const auto img =
        *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("PowerSupplyOn");
    sprite->SetImage(img);
  }

  SetName("Pylon");

  {
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<PylonTransmitter>();
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
    ComponentServiceLocator::Instance()
        .Resolve<tile_map::ObjectTileMapComponent>()
        ->SetCell(object.object.x, object.object.y, 1);
  }
}
