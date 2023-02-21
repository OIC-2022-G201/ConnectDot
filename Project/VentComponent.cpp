﻿#include "VentComponent.h"

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LeverStubReceiver.h"
#include "LoadObjectParameter.h"
#include "MachineConst.h"
#include "ObjectTileMapComponent.h"
#include "PlayerComponent.h"
#include "ReceiverComponent.h"
#include "ReleaseInfo.h"
#include "SignboardReceiver.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
#include "VentGroupLocator.h"
#include "VentReceiver.h"

using namespace base_engine;
using namespace draw_order;

VentActor::VentActor(base_engine::Game* game) : Actor(game) {}

void VentActor::Create(const LoadObject& object) {
  {
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y);
    if (kIsCollisionRenderMode) {
      const auto shape = new ShapeRenderComponent(this, 110);
      shape->SetShape(rect);
      shape->SetFillMode(electronics::kElectricAreaFillMode)
          .SetColor(electronics::kElectricAreaColor);
    }
    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kLeverObjectFilter);
    collision->SetTargetFilter(kLeverTargetFilter);
    collision->SetTrigger(true);
  }
  {
    const auto sign = new SpriteComponent(this, kVentDrawOrder);
    const auto& path = "gimmick/Objects/Vent/vent_green.png";

    sign->SetImage(BASE_ENGINE(Texture)->Get(path));
  }

  auto vent = new VentComponent(this);
  {
    for (auto& part : object.object.parts) {
      auto t = std::get_if<stage::part::TransitionTargetPart>(&part);
      if (t) {
        vent->SetTransitionTarget(t->GetRight(), t->GetLeft());
      }
    }
  }
  {
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<VentReceiver>(vent);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
    ComponentServiceLocator::Instance()
        .Resolve<tile_map::ObjectTileMapComponent>()
        ->SetCell(object.object.x, object.object.y, 1);
  }
  {
    const int tag = 1;
    // std::get<int>(*std::prev(object.parameters.end(), 2));
    ServiceLocator::Instance().Resolve<VentGroupLocator>()->RegisterVent(
        object.id, GetGame()->GetActor(GetId()));
  }
  SetName("VentActor");
}

VentComponent::VentComponent(base_engine::Actor* owner) : Component(owner) {}

void VentComponent::Start() {}

void VentComponent::Update() {}

void VentComponent::Action(base_engine::Actor* machine_operator) {
  const auto player =
      machine_operator->GetComponent<player::PlayerComponent>().lock();
  player->VentEnter(this);
}

bool VentComponent::CanInteractive(base_engine::Actor* actor) { return true; }

std::weak_ptr<base_engine::Actor> VentComponent::GetRight() const {
  return ServiceLocator::Instance().Resolve<VentGroupLocator>()->GetVentData(
      right_);
}

std::weak_ptr<base_engine::Actor> VentComponent::GetLeft() const {
  return ServiceLocator::Instance().Resolve<VentGroupLocator>()->GetVentData(
      left_);
}
