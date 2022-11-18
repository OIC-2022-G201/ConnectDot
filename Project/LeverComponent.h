#pragma once
#include "CollisionComponent.h"
#include "Component.h"
#include "IPlayerAction.h"

#include "LeverReceiver.h"
class LeverComponent : public IPlayerAction, public base_engine::Component {
 public:
  LeverComponent(base_engine::Actor* owner, ReceiverComponent* target,
                 TransmitterComponent* transmitter, int update_order = 100)
      : Component(owner, update_order),
        target_(target),
        transmitter_(transmitter) {}
  
  void OnCollision(const base_engine::SendManifold& manifold) override {
    int n = 3;
    
  }
  void Action() override;

 private:
  
  class ReceiverComponent* target_ = nullptr;
  class TransmitterComponent* transmitter_ = nullptr;
};
