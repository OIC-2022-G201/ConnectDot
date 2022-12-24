// @file SignboardReceiver.h
// @brief
// @author ICE
// @date 2022/09/22
//
// @details

#pragma once
#include "IReceivablePower.h"
#include "MofSpriteAnimationComponent.h"
#include "SpriteComponent.h"
#undef max
class SignboardReceiver : public IReceivablePower {
 public:
  explicit SignboardReceiver(base_engine::SpriteComponent* display,
                             base_engine::MofSpriteAnimationComponent* animation);

  int Sequential() override;
  bool PowerJoinCondition() override;

  void OnPowerEnter(TransmitterComponent* transmitter) override;
  void OnPowerChanged(TransmitterComponent* transmitter) override;

  void OnPowerExit(TransmitterComponent* transmitter) override;
  bool IsWireless() override;

  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

private:
  base_engine::SpriteComponent* display_ = nullptr;
  base_engine::MofSpriteAnimationComponent* animation_ = nullptr;
};
