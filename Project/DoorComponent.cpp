#include "DoorComponent.h"

#include <filesystem>

#include "BaseEngineCore.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DoorReceiver.h"
#include "DrawOrder.h"
#include "GimmickCreateHelper.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LoadObjectParameter.h"
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

    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kFieldObjectFilter);
    collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetTrigger(false);
  }
  {
    const auto path = "gimmick/Objects/Door/Door.png";
    GimmickCreateHelper::AnimationCreatePath(
        this, path, object.object.color_type, false, kVentDrawOrder);
  }
  {
    auto vent = new DoorComponent(this);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<DoorReceiver>(vent, this);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
  }
  SetName("DoorActor");
  SetTag("Field");
}

DoorComponent::DoorComponent(base_engine::Actor* owner) : Component(owner) {}

void DoorComponent::Start() {}

void DoorComponent::Update() {}

void DoorComponent::SetElectric(const bool flg) { electric_power_ = flg; }

bool DoorComponent::GetElectric() const { return electric_power_; }
