// @file BeaconTransmitter.h
// @brief ビーコン送電機
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once
#include "ISendablePower.h"

class BeaconTransmitter : public ISendablePower {
 public:
  explicit BeaconTransmitter(const int level);

  std::vector<IReceivablePower*> GetTarget() override;

  void Sending() override;

  bool CanSending() override
  {
	  return can_sending_;
  }

  void SetCanSending(bool can_sending) override
  {
	  can_sending_ = can_sending;
  }
 private:
  int level_;
  bool can_sending_ = false;
};
