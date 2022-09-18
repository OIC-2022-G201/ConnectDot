#include "ReceiverComponent.h"

#include "TransmitterComponent.h"

void ReceiverComponent::Connecting(TransmitterComponent* sender)
{
    if (sender->Sequential() >= receiver_->Sequential()) return;
    if (sender_ != nullptr) {
        if (sender_->Sequential() < sender->Sequential()) sender_ = sender;
    } else {
        sender_ = sender;
    }
    switch (current_state_) {
    case PowerState::kDisconnected:
        break;
    case PowerState::kDisconnect:
        current_state_ = PowerState::kConnect;
        break;
    case PowerState::kConnect:
        current_state_ = PowerState::kConnecting;
    case PowerState::kConnecting:
        break;
    default:;
    }
    prev_state_ = current_state_;
    return;
}
