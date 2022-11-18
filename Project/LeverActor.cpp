#include "LeverActor.h"

#include <Utilities/InputUtilities.h>

#include <memory>

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "IPlayerAction.h"
#include "InputManager.h"
#include "LeverComponent.h"
#include "LeverReceiver.h"
#include "LeverTransmitter.h"
#include "MoveFloorActor.h"
#include "ReceiverComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace electronics::electricity;

void LeverActor::Start() {
  {
    const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Rect>(0, 0, 128, 128);
    const auto shape = new base_engine::ShapeRenderComponent(this, 110);
    shape->SetShape(circle);
    shape->SetFillMode(kElectricAreaFillMode).SetColor(kElectricAreaColor);
    const auto collision = new base_engine::CollisionComponent(this);
    collision->SetShape(circle);
    collision->SetObjectFilter(kPowerSupplyUnitTargetFilter);
    collision->SetTargetFilter(kMoveFloorTargetFilter);
    target_layer_ = collision->GetTargetFilter();
    collision->SetTrigger(true);
    SetTag("Lever");
  }

  {
    const auto sign =
        new base_engine::SpriteComponent(this, draw_order::kLeverDrawOrder);
    const auto img = BASE_ENGINE(Texture)->Get(texture::kLeverTextureKey);
    sign->SetImage(img);
  }

  {
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<LeverTransmitter>(this);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<LeverReceiver>(this, target_, transmitter);

     lever_component_=new LeverComponent(this,receiver,transmitter,100);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({5, 7});
  }
}
