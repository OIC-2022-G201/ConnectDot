// @CollapsibleBlockReceiver.h
// @brief
// @author ICE
// @date 2022/12/27
// 
// @details

#pragma once

#include "Actor.h"
#include "IReceivablePower.h"
#include "TransmitterComponent.h"

class CollapsibleBlockReceiver final : public IReceivablePower {
 public:
  explicit CollapsibleBlockReceiver(class CollapsibleBlockComponent* component,
                                    base_engine::Actor* actor);

  int Sequential() override;
  bool PowerJoinCondition() override;
  void OnPowerEnter(TransmitterComponent* transmitter) override;
  void OnPowerChanged(TransmitterComponent* transmitter) override;
  void OnPowerExit(TransmitterComponent* transmitter) override;
  bool IsWireless() override;
  [[nodiscard]] base_engine::Vector2 GetPosition() const override;

private:
  class CollapsibleBlockComponent* component_ = nullptr;
  base_engine::Actor* owner_ = nullptr;
};
