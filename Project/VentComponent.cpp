#include "VentComponent.h"


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
#include "VentReceiver.h"

using namespace base_engine;
using namespace draw_order;

VentActor::VentActor(base_engine::Game* game): Actor(game)
{
      
}

void VentActor::Create(const LoadObject& object)
{
  {
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y);
    const auto shape = new ShapeRenderComponent(this, 110);
    shape->SetShape(rect);
    shape->SetFillMode(electronics::kElectricAreaFillMode)
        .SetColor(electronics::kElectricAreaColor);

    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
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
  { auto lever = new VentComponent(this); }
  {
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<VentReceiver>(this);
  }
  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[2]).value;
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({pos.x, pos.y});
  }
  SetName("VentActor");
}
