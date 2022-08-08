#include "BeaconActor.h"

#include "BeaconTransmitter.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "TransmitterComponent.h"


BeaconActor::BeaconActor(base_engine::Game* game) : Actor(game) {}



BeaconActor::~BeaconActor() {}

void BeaconActor::Start() {
  auto circle = std::make_shared<base_engine::Circle>(0, 0, 200);
  auto shape = new base_engine::ShapeRenderComponent(this, 110);
  shape->SetShape(circle);
  shape->SetFillMode(base_engine::FillMode::Yes).SetColor(MOF_ARGB(255-128,255,255,0));
  auto collision = new base_engine::CollisionComponent(this, 100);
  collision->SetShape(circle);
  collision->SetObjectFilter(kBeaconObjectFilter);
  collision->SetTargetFilter(kBeaconTargetFilter);
  SetName("Beacon");
  auto transmitter = new TransmitterComponent(this, 100);
  transmitter->Create<BeaconTransmitter>(1);
}

void BeaconActor::Input() {}

void BeaconActor::Update() {}

