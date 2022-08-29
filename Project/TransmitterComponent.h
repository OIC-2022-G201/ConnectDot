// @file TransmitterComponent.h
// @brief
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once
#include <memory>

#include "Actor.h"
#include "CollisionComponent.h"
#include "Component.h"
#include "ISendablePower.h"

class TransmitterComponent : public base_engine::Component {
 public:
  TransmitterComponent(base_engine::Actor* owner, int update_order);

  ~TransmitterComponent() override;
  void Start() override;

  void Update() override;

  void OnCollision(const base_engine::SendManifold& manifold) override;

  void SetCanSending(bool can_sending)
  {
      transmitter_->SetCanSending(can_sending);
  }
public:
  template <SendablePower T, class... _Types>
  void Create(_Types&&... args) {
    transmitter_ = std::make_unique<T>(std::forward<_Types>(args)...);
  }

 private:
  std::vector<class ReceiverComponent*> target_;
  std::unique_ptr<ISendablePower> transmitter_;
};
