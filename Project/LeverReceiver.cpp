#include "LeverReceiver.h"

#include "Actor.h"
#include "ElectronicsPower.h"
#include "LeverActor.h"
#include "ReceiverComponent.h"
#include "TransmitterComponent.h"

void LeverReceiver::OnPowerEnter(TransmitterComponent* transmitter) {
  receiver_ = target_->GetComponent<ReceiverComponent>();
  actor_->SetElectricPower(true);
  actor_->SetSequential(transmitter->Sequential() + 5);
}

 void LeverReceiver::OnPowerChanged(TransmitterComponent* transmitter) {
}

void LeverReceiver::OnPowerExit(TransmitterComponent* transmitter){
  actor_->SetElectricPower(false);
  receiver_.reset();
}


