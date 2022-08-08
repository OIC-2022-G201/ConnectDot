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

 private:
  int level_;
};
