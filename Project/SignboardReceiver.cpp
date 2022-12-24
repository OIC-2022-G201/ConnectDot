#include "SignboardReceiver.h"

SignboardReceiver::SignboardReceiver(base_engine::SpriteComponent* display,
	base_engine::MofSpriteAnimationComponent* animation): display_(display),animation_(animation)
{}

int SignboardReceiver::Sequential()
{ return std::numeric_limits<int>::max(); }

bool SignboardReceiver::PowerJoinCondition()
{ return true; }

void SignboardReceiver::OnPowerEnter(TransmitterComponent* transmitter)
{
	display_->SetEnabled(true);
  animation_->Play("BeaconAnimation");
}

void SignboardReceiver::OnPowerChanged(TransmitterComponent* transmitter)
{}

void SignboardReceiver::OnPowerExit(TransmitterComponent* transmitter)
{
  animation_->Stop(true);
	display_->SetEnabled(false);
}

bool SignboardReceiver::IsWireless()
{ return false; }

base_engine::Vector2 SignboardReceiver::GetPosition() const
{
	return {64, 64};
}
