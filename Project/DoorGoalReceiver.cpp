#include "DoorGoalReceiver.h"

DoorGoalReceiver::DoorGoalReceiver(DoorGoalActor* actor, base_engine::Actor* owner) {
}

int DoorGoalReceiver::Sequential() {
	return 1;
}

bool DoorGoalReceiver::PowerJoinCondition() {
	return true;
}

void DoorGoalReceiver::OnPowerEnter(TransmitterComponent* transmitter) {
}

void DoorGoalReceiver::OnPowerChanged(TransmitterComponent* transmitter) {
}

void DoorGoalReceiver::OnPowerExit(TransmitterComponent* transmitter) {
}

base_engine::Vector2 DoorGoalReceiver::GetPosition() const {
	return { 1,1 };
}
