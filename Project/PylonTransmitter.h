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
  const ISendablePower* GetPrevious() override { return nullptr; }

  int Sequential() override { return 0; }
  void SetPrevious(ISendablePower* previous) override {}
  [[nodiscard]] base_engine::Vector2 Position() const override
  { return {64,64};  }
};
