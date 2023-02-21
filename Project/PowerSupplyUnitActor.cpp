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
#include "ResourceContainer.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace electronics;
using RC = ResourceContainer;

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
    is_fly_ = false;
    for (auto& part : object.object.parts) {
      auto t = std::get_if<stage::part::IsAirPart>(&part);
      if (t) {
        is_fly_ = true;
      }
    }
    {
      sprite_outline_ = new base_engine::SpriteComponent(
          this, draw_order::kPowerSupplyUnitDrawOrder + 1);
      const auto sprite_outline_resource =
          RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
              is_fly_ ? "AirPowerSupplyOutline" : "PowerSupplyOutline");
      sprite_outline_->SetImage(*sprite_outline_resource);
      sprite_outline_->SetEnabled(false);
    }
    {
      sprite_ = new base_engine::SpriteComponent(
          this, draw_order::kPowerSupplyUnitDrawOrder);

      const auto img = *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
          is_fly_ ? "AirPowerSupplyOff" : "PowerSupplyOff");
      sprite_->SetImage(img);
    }
  }

  {
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<PowerSupplyUnitTransmitter>(this);
    transmitter->SetCanRemote(can_remote_);
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<PowerSupplyUnitReceiver>(this, nullptr, transmitter);
    receiver->SetCanRemote(can_remote_);

    {
      const int level = 1;
      receiver->SetLevel(level);
    }
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

void PowerSupplyUnitActor::SetOutline(const bool flg) const {
  sprite_outline_->SetEnabled(flg);
}

bool PowerSupplyUnitActor::IsOutline() const {
  return sprite_outline_->GetEnabled();
}

void PowerSupplyUnitActor::SetOnImage(const bool flg) const {
  if (flg) {
    const auto img = *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
        IsFly() ? "AirPowerSupplyOn" : "PowerSupplyOn");
    sprite_->SetImage(img);

  } else {
    const auto img = *RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(
        is_fly_ ? "AirPowerSupplyOff" : "PowerSupplyOff");
    sprite_->SetImage(img);
  }
}
