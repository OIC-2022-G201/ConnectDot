// @file SignboardReceiver.h
// @brief
// @author ICE
// @date 2022/09/22
//
// @details

#pragma once
#include "IReceivablePower.h"
#include "SpriteComponent.h"
#undef max
class SignboardReceiver : public IReceivablePower {
 public:
  explicit SignboardReceiver(base_engine::SpriteComponent* display)
      : display_(display) {}

  int Sequential() override { return std::numeric_limits<int>::max(); }
  bool PowerJoinCondition() override { return true; }
  void OnPowerEnter(TransmitterComponent* transmitter) override {
    display_->SetEnabled(true);
    int n = 0;
  }
  void OnPowerChanged(TransmitterComponent* transmitter) override {}
  void OnPowerExit(TransmitterComponent* transmitter) override {
    display_->SetEnabled(false);
  }
  bool IsWireless() override { return false; }

  [[nodiscard]] base_engine::Vector2 GetPosition() const override {
    return {64, 64};
  }

 private:
  base_engine::SpriteComponent* display_ = nullptr;
};
