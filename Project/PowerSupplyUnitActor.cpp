#include "PowerSupplyUnitActor.h"

#include <memory>

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LoadObjectParameter.h"
#include "ObjectTileMapComponent.h"
#include "PowerSupplyUnitReceiver.h"
#include "PowerSupplyUnitTransmitter.h"
#include "ReceiverComponent.h"

#include "ReleaseInfo.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace electronics;
void PowerSupplyUnitActor::Start() {}

void PowerSupplyUnitActor::Create(const LoadObject& object) {
  {
    const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Circle>(
        cell_half.x, cell_half.y, kPowerRadius / 4);
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
    const auto img =
        BASE_ENGINE(Texture)->Get(texture::kPowerSupplyUnitTextureKey);
    sprite->SetImage(img);
  }

  {
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<PowerSupplyUnitTransmitter>(this);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<PowerSupplyUnitReceiver>(this, nullptr, transmitter);

    int n = std::get<int>(object.parameters[object.parameters.size() - 2]);
    if (n > 1) {
      int k = 3;
    }
    receiver->SetLevel(n);
  }

  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[2]).value;
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({pos.x, pos.y});
    ComponentServiceLocator::Instance()
        .Resolve<tile_map::ObjectTileMapComponent>()
        ->SetCell(pos.x, pos.y, 1);
  }
}
