#include "MoveFloorReceiver.h"
#include "ReceiverComponent.h"
#include "ElectronicsPower.h"
#include "PowerSupplyUnitActor.h"
#include "Actor.h"
#include "MoveFloorActor.h"




void MoveFloorReceiver::OnPowerEnter(TransmitterComponent* transmitter)
{
  receiver_ = target_->GetComponent<ReceiverComponent>();
  actor_->SetElectricPower(true);

  
}
void MoveFloorReceiver::OnPowerChanged(TransmitterComponent* transmitter) {}
void MoveFloorReceiver::OnPowerExit(TransmitterComponent* transmitter) 
{
  actor_->SetElectricPower(false);
  receiver_.reset();
}



