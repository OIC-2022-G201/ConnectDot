// @IConnectBindable.h
// @brief
// @author
// @date 2023/01/08
//
// @details

#pragma once
#include <memory>

class ReceiverComponent;
class TransmitterComponent;

class IConnectBindable {
 public:
  virtual bool Constraints(
      const std::weak_ptr<ReceiverComponent>& receiver,
      const std::weak_ptr<TransmitterComponent>& transmitter) = 0;
  virtual bool BindConnect(
      const std::shared_ptr<class ReceiverComponent>& receiver,
      std::weak_ptr<class TransmitterComponent> transmitter) = 0;
};
