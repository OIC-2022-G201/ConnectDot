// @file PylonTransmitter.h
// @brief Pylonの送電機ストラテジークラス
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once
#include "ISendablePower.h"

class PylonTransmitter : public ISendablePower {
 public:
  explicit PylonTransmitter();
  bool CanSending() override;
};
