#include "ConnectBind.h"

#include "ReceiverComponent.h"
#include "TransmitterComponent.h"
bool ConnectBind::BindConnect(
    const std::shared_ptr<ReceiverComponent>& receiver,
    const std::weak_ptr<TransmitterComponent> transmitter) {
  receiver->Connecting(transmitter);
  return true;
}

bool ConnectBind::Constraints(
    const std::weak_ptr<ReceiverComponent>& receiver,
    const std::weak_ptr<TransmitterComponent>& transmitter) {
  return 
         TransmitterComponent::CoercionCondition(receiver) ||
         receiver.lock()->Level() > transmitter.lock()->Level();
}
