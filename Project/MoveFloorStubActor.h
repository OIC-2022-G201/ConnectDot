// @MoveFloorStubActor.h
// @brief
// @author ICE
// @date 2022/11/21
//
// @details

#pragma once
#include "Actor.h"
#include "GridPosition.h"
#include "IReceivablePower.h"
#include "LoadObjectParameter.h"

class TransmitterComponent;

class MoveFloorStubActor final : public base_engine::Actor {
 public:
  explicit MoveFloorStubActor(base_engine::Game* game) : Actor(game) {}

  void Create(const LoadObject& object);

 private:
  GridPosition to_position_{0, 0};
  GridPosition from_position_{0, 0};
  bool is_front_ = true;
  class MoveFloorStubReceiver : public IReceivablePower {
   public:
    MoveFloorStubReceiver(MoveFloorStubActor* actor) : actor_(actor){};
    int Sequential() override { return 1000; }
    bool PowerJoinCondition() override { return true; }
    void OnPowerEnter(TransmitterComponent* transmitter) override;
    void OnPowerChanged(TransmitterComponent* transmitter) override {}
    void OnPowerExit(TransmitterComponent* transmitter) override {}
    bool IsWireless() override { return false; }
    [[nodiscard]] base_engine::Vector2 GetPosition() const override {
      return {};
    }

   private:
    MoveFloorStubActor* actor_;
  };
};
