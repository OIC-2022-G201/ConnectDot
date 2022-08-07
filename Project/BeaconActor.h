#pragma once
#include "Actor.h"
#include "IReceivablePower.h"
#include "ISendablePower.h"

class BeaconActor final : public base_engine::Actor,
                          public IReceivablePower,
                          public ISendablePower {
  using SendTargetList = std::vector<IReceivablePower*>;

 public:
  explicit BeaconActor(base_engine::Game* game);

  bool PowerJoinCondition() override;
  void OnPowerEnter() override;
  void OnPowerChanged() override;
  void OnPowerExit() override;

  ~BeaconActor() override;

  void Start() override;
  void Input() override;
  void Update() override;

 private:
  SendTargetList GetTarget() override;
  void Sending() override;
};
