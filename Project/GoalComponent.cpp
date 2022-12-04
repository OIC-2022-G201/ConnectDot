﻿#include "GoalComponent.h"

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

void GoalActor::Create(const LoadObject& object) {
  GoalComponent::Create(this);
  SetName("GoalActor");
  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[2]).value;
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({pos.x, pos.y});
  }
}

void GoalComponent::OnCollision(const base_engine::SendManifold& manifold)
{
  int n = 3;
}

void GoalComponent::Create(base_engine::Actor* owner) {
  auto goal = new GoalComponent(owner);
  {
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect = std::make_shared<Rect>(0, 0, cell.x * 2, cell.y * 2);

    const auto shape = new ShapeRenderComponent(owner, 110);
    shape->SetShape(rect);
    shape->SetFillMode(static_cast<FillMode>(true))
        .SetColor(electronics::kElectricAreaColor);

    const auto collision = new CollisionComponent(owner);
    collision->SetShape(rect);
    collision->SetObjectFilter(CollisionLayer::kNone);
    collision->SetTargetFilter(CollisionLayer::kPlayerFilter);
    collision->SetTrigger(true);
  }
}
