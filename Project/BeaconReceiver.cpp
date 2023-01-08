#include "BeaconReceiver.h"

#include "BeaconActor.h"
#include "OneTimeEffectActor.h"
#include "TransmitterComponent.h"

BeaconReceiver::BeaconReceiver(BeaconActor* actor,
                               base_engine::Vector2 position)
    : position_(position), actor_(actor) {
  actor_->RegistryPart(this);
  const auto game = actor_->GetGame();

  effect_actor_ = OneTimeEffectActor::Create(
      game, actor_->GetPosition() + GetPosition(), "ConnectLightNormal", 130);
  actor_->AddChild(effect_actor_->GetId());
  effect_actor_->Hide();
  actor_->LevelUpTrigger().Subscribe(
      [this](bool _) { effect_actor_->SetImage("ConnectLightPowerup");
  });
}

int BeaconReceiver::Sequential() { return actor_->Sequential(); }

bool BeaconReceiver::PowerJoinCondition() { return true; }

void BeaconReceiver::OnPowerChanged(TransmitterComponent* transmitter) {}

void BeaconReceiver::OnPowerExit(TransmitterComponent* transmitter) {
  effect_actor_->Hide();
  actor_->SetElectricPower(false);
}

base_engine::Vector2 BeaconReceiver::GetPosition() const { return position_; }

void BeaconReceiver::OnPowerEnter(TransmitterComponent* transmitter) {
  effect_actor_->Show();
  effect_actor_->Play();
  actor_->SetElectricPower(true);
  OneTimeEffectActor::Create(
      actor_->GetGame(), actor_->GetPosition() + GetPosition(), "Spark", 140);
}
