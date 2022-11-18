#pragma once
#include  "Actor.h"
#include  "IReceivablePower.h"
#include "TransmitterComponent.h"
class MoveFloorReceiver : public IReceivablePower
{
public:
  MoveFloorReceiver(class MoveFloorActor* actor,
	                base_engine::Actor* target
	                )
		                : actor_(actor),target_(target) {}
 int Sequential() override { return 1000; }
  bool PowerJoinCondition() override { return true; }
 void OnPowerEnter(TransmitterComponent* transmitter) override;
 void OnPowerChanged(TransmitterComponent* transmitter) override;
 void OnPowerExit(TransmitterComponent* transmitter) override;
 bool IsWireless() override{return false;}
 [[nodiscard]] base_engine::Vector2 GetPosition() const override
 {
   return {64, 64};
 }

private:
  class MoveFloorActor* actor_ = nullptr;
 base_engine::Actor* target_ = nullptr;
  std::weak_ptr<class ReceiverComponent> receiver_;
 class TransmitterComponent* sender_ = nullptr;
};
