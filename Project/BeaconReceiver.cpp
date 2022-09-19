#include "BeaconReceiver.h"

#include "TransmitterComponent.h"
#include "BeaconActor.h"
#include "ElectricEffect.h"
#include "ReceiverComponent.h"
BeaconReceiver::BeaconReceiver(BeaconActor* actor,
                               base_engine::Vector2 position)
    : position_(position), actor_(actor) {
  actor_->RegistryPart(this);
  const auto game = actor_->GetGame();
  effect_ = new ElectricEffect(game);
  effect_->SetReceiver(actor_->GetComponent<ReceiverComponent>());
}

int BeaconReceiver::Sequential() { return actor_->Sequential(); }

bool BeaconReceiver::PowerJoinCondition() { return true; }

void BeaconReceiver::OnPowerChanged(TransmitterComponent* transmitter) {}

void BeaconReceiver::OnPowerExit(TransmitterComponent* transmitter) {
  actor_->SetElectricPower(false);
}

base_engine::Vector2 BeaconReceiver::GetPosition() const
{
    return actor_->GetPosition() + position_;
}

void BeaconReceiver::OnPowerEnter(TransmitterComponent* transmitter)
{
    actor_->SetElectricPower(true);
  effect_->Play(transmitter->GetPosition(),GetPosition());
}
