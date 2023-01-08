// @ConnectBind.h
// @brief
// @author
// @date 2023/01/08
//
// @details

#pragma once
#include "IConnectBindable.h"

class ConnectBind : public IConnectBindable {
 public:
    bool BindConnect(const std::shared_ptr<ReceiverComponent>& receiver,
        std::weak_ptr<TransmitterComponent> transmitter) override;
    bool Constraints(const std::weak_ptr<ReceiverComponent>& receiver,
        const std::weak_ptr<TransmitterComponent>& transmitter) override;
};
