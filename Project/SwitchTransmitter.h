// @SwitchTransmitter.h
// @brief
// @author ICE
// @date 2023/02/24
// 
// @details

#pragma once
#include "ISendablePower.h"

class SwitchTransmitter : public ISendablePower {
 public:
  explicit SwitchTransmitter(class SwitchActor* actor)
      : actor_(actor) {}

  const ISendablePower* GetPrevious() override { return previous_; }
  void SetPrevious(ISendablePower* previous) override { previous_ = previous; }

  bool CanSending() override;
  [[nodiscard]] base_engine::Vector2 GetPosition() const override { return {}; }

 private:
  base_engine::Vector2 position_;
  ISendablePower* previous_ = nullptr;
  class SwitchActor* actor_ = nullptr;
};
