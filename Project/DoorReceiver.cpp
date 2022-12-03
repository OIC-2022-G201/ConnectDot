#include "DoorReceiver.h"

#include "BaseEngineCore.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ContactRayCastCallBack.h"
#include "IBaseEngineCollider.h"
#include "PhysicsFixture.h"
#include "PhysicsWorldCallBack.h"
#include "StageConstitution.h"
using namespace base_engine;
using namespace physics;

DoorReceiver::DoorReceiver(DoorComponent* door, Actor* actor)
    : door_(door), owner_(actor) {}

void DoorReceiver::OnPowerEnter(TransmitterComponent* transmitter) {
  auto collision = owner_->GetComponent<CollisionComponent>().lock();

  collision->SetObjectFilter(CollisionLayer::kNone);
  collision->SetTrigger(true);
}

void DoorReceiver::OnPowerChanged(TransmitterComponent* transmitter) {

}

void DoorReceiver::OnPowerExit(TransmitterComponent* transmitter) {
  auto collision = owner_->GetComponent<CollisionComponent>().lock();
  collision->SetObjectFilter(kFieldObjectFilter);
  collision->SetTrigger(false);
}
