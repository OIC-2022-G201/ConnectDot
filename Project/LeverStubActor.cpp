#include "LeverStubActor.h"

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LeverStubReceiver.h"
#include "LoadObjectParameter.h"
#include "MachineConst.h"
#include "ReceiverComponent.h"
#include "SignboardReceiver.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace base_engine;
using namespace draw_order;

LeverStubActor::LeverStubActor(base_engine::Game* game) : Actor(game) {}

void LeverStubActor::Create(const LoadObject& object) {
  {
    constexpr auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Circle>(
        cell_half.x, cell_half.y, electronics::kPowerRadius);
    const auto shape = new base_engine::ShapeRenderComponent(this, 110);
    shape->SetShape(circle);
    shape->SetFillMode(electronics::kElectricAreaFillMode)
        .SetColor(electronics::kElectricAreaColor);

    const auto collision = new base_engine::CollisionComponent(this);
    collision->SetShape(circle);
    collision->SetObjectFilter(kLeverObjectFilter);
    collision->SetTargetFilter(kLeverTargetFilter);
    collision->SetTrigger(true);
  }
  {
    const auto sign = new SpriteComponent(this, kSignboardDrawOrder);
    const auto& path =
        std::get<LoadObject::TexturePath>(object.parameters[0]).value;
    sign->SetImage(BASE_ENGINE(Texture)->Get(path));
  }
  {

  } {
    auto lever = new LeverStubComponent(this);
    const auto transmitter = new TransmitterComponent(this, 100);
    transmitter->Create<LeverStubTransmitter>(this);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<LeverStubReceiver>(this);
  }
  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[2]).value;
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::Yes).SetSnapGridPosition({pos.x, pos.y});
  }
  SetName("LeverStubActor");
}
