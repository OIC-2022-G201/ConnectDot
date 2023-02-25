#include "ConveyorReceiver.h"

#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "ConveyorActor.h"
#include "MofSpriteAnimationComponent.h"
#include "ObjectTileMapComponent.h"

int ConveyorReceiver::Sequential() { return 1000; }

bool ConveyorReceiver::PowerJoinCondition()
{ return true; }

void ConveyorReceiver::OnPowerEnter(TransmitterComponent* transmitter)
{
  const auto collision =
      owner_->GetComponent<base_engine::CollisionComponent>().lock();
  component_->SetElectric(true);
}

void ConveyorReceiver::OnPowerChanged(TransmitterComponent* transmitter)
{
}

void ConveyorReceiver::OnPowerExit(TransmitterComponent* transmitter)
{
  component_->SetElectric(false);
}

bool ConveyorReceiver::IsWireless()
{ return false; }

base_engine::Vector2 ConveyorReceiver::GetPosition() const
{ return {}; }
