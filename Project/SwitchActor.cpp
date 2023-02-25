#include "SwitchActor.h"

#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ConveyorReceiver.h"
#include "DrawOrder.h"
#include "GimmickCreateHelper.h"
#include "GridSnapComponent.h"
#include "PhysicsBodyComponent.h"
#include "ReceiverComponent.h"
#include "Rect.h"
#include "SwitchTransmitter.h"
using namespace base_engine;
using namespace draw_order;

SwitchActor::SwitchActor(base_engine::Game* game) : Actor(game) {}

bool SwitchActor::OnPush() const { return switch_->OnPush(); }

void SwitchActor::Start() {}

void SwitchActor::Input() {}

void SwitchActor::Update() {
  for (const auto& target : targets_) {
    const auto receiver = target->GetComponent<ReceiverComponent>();
    if (receiver.expired()) continue;
    transmitter_->AddTarget(receiver);
  }
  switch_->SetPushState(false);
}

void SwitchActor::Create(const LoadObject& object) {
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
  }

  {
    GimmickCreateHelper::SpriteCreateKey(this, "SwitchOff",
                                         object.object.color_type, 100);
  }
  {
    const auto collision = new CollisionComponent(this);
    const auto shape_enemy = std::make_shared<Rect>(0, 96, 128, 128);
    collision->SetShape(shape_enemy);
    collision->SetObjectFilter(kFieldObjectFilter);
    collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetTrigger(false);
  }
  { switch_ = new SwitchComponent(this);
  }
  {
    transmitter_ = new TransmitterComponent(this, 100);
    transmitter_->Create<SwitchTransmitter>(this);
    transmitter_->SetCanRemote(true);
  }
  SetName("Field");
  SetTag("Field");
}

SwitchComponent::SwitchComponent(base_engine::Actor* owner,
                                 const int update_order)
    : Component(owner, update_order) {}

void SwitchComponent::Update() { on_push_ = false; }

bool SwitchComponent::OnPush() const { return on_push_; }

void SwitchComponent::SetPushState(bool flg) { on_push_ = flg; }

void SwitchComponent::OnCollision(const base_engine::SendManifold& manifold) {
  on_push_ = true;
}
