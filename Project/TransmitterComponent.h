// @file TransmitterComponent.h
// @brief
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once
#include <memory>

#include "Actor.h"
#include "BeaconTransmitter.h"
#include "PylonTransmitter.h"
#include "CollisionComponent.h"
#include "Component.h"
#include "ISendablePower.h"

class TransmitterComponent : public base_engine::Component {
 public:
  template <SendablePower T, class... _Types>
  void Create(_Types&&... args) {
    transmitter_ = std::make_unique<T>(std::forward<_Types>(args)...);
  }

 private:
  std::unique_ptr<ISendablePower> transmitter_;

 public:
  TransmitterComponent(base_engine::Actor* owner, int update_order)
      : Component(owner, update_order) {}

  ~TransmitterComponent() override = default;
  void Start() override {}

  void Update() override {}
  void OnCollision(base_engine::CollisionComponent* collision) override
  {
    auto name = collision->GetActor()->GetName();
    int n = 3;
  }
};
