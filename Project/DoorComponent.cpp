#include "DoorComponent.h"

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DoorReceiver.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LoadObjectParameter.h"
#include "MachineConst.h"
#include "PlayerComponent.h"
#include "ReceiverComponent.h"
#include "SignboardReceiver.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace base_engine;
using namespace draw_order;

DoorActor::DoorActor(base_engine::Game* game) : Actor(game) {}

void DoorActor::Create(const LoadObject& object) {
  {
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y * 2);
    const auto shape = new ShapeRenderComponent(this, 110);
    shape->SetShape(rect);
    shape->SetFillMode(electronics::kElectricAreaFillMode)
        .SetColor(electronics::kElectricAreaColor);

    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kFieldObjectFilter);
    collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetTrigger(false);
  }
  {
    const auto sign = new SpriteComponent(this, kVentDrawOrder);
    const auto& path =
        std::get<LoadObject::TexturePath>(object.parameters[0]).value;
    sign->SetImage(BASE_ENGINE(Texture)->Get(path));
  }
  {
    auto vent = new DoorComponent(this);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<DoorReceiver>(vent, this);
  }
  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[2]).value;
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({pos.x, pos.y});
  }
  SetName("DoorActor");
  SetTag("Field");
}

DoorComponent::DoorComponent(base_engine::Actor* owner) : Component(owner) {}

void DoorComponent::Start() {}

void DoorComponent::Update() {}

void DoorComponent::SetElectric(const bool flg) { electric_power_ = flg; }

bool DoorComponent::GetElectric() const { return electric_power_; }
