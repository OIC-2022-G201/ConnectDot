#include "BeaconActor.h"

#include "BeaconTransmitter.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "TransmitterComponent.h"

BeaconActor::BeaconActor(base_engine::Game* game) : Actor(game) {}

bool BeaconActor::PowerJoinCondition() { return true; }

void BeaconActor::OnPowerEnter() {}

void BeaconActor::OnPowerChanged() {}

void BeaconActor::OnPowerExit() {}

BeaconActor::~BeaconActor() {}

void BeaconActor::Start() {
  auto circle = std::make_shared<base_engine::Circle>(0, 0, 10);
  auto shape = new base_engine::ShapeRenderComponent(this, 110);
  shape->SetShape(circle);
  shape->SetFillMode(base_engine::FillMode::Yes).SetColor(MOF_COLOR_GREEN);
  auto collision = new base_engine::CollisionComponent(this, 100);
  collision->SetShape(circle);
  collision->SetObjectFilter();
  auto transmitter = new TransmitterComponent(this, 100);
  transmitter->Create<BeaconTransmitter>(1);
}

void BeaconActor::Input() {}

void BeaconActor::Update() {}

std::vector<IReceivablePower*> BeaconActor::GetTarget() {
  return SendTargetList();
}

void BeaconActor::Sending() {}
