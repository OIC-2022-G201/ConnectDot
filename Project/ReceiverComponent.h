// @file ReceiverComponent.h
// @brief 受電機コンポーネント
// @author ICE
// @date 2022/08/08
//
// @details
// 他ActorのTransmitterコンポーネントから受信してreceiver_のコールバックを呼び出す

#pragma once
#include <memory>

#include "Component.h"
#include "IReceivablePower.h"

class ReceiverComponent : public base_engine::Component {
 public:
  ReceiverComponent(base_engine::Actor* owner, int update_order)
      : Component(owner, update_order) {}

  ~ReceiverComponent() override {}
  void Start() override {}
  void Update() override {
    if (current_state_ == PowerState::kConnecting &&
        prev_state_ == PowerState::kDisconnect) {
      prev_state_ = PowerState::kDisconnected;
    }
    switch (prev_state_) {
      case PowerState::kDisconnected:
        current_state_ = PowerState::kDisconnect;
        prev_state_ = PowerState::kDisconnect;
        receiver_->OnPowerExit();
        break;
      case PowerState::kConnect:
        receiver_->OnPowerEnter();
        current_state_ = PowerState::kConnecting;
        break;
      case PowerState::kConnecting:
        receiver_->OnPowerChanged();
        break;
      case PowerState::kDisconnect:
        return;
        break;
      default:;
    }
    prev_state_ = PowerState::kDisconnect;
  }
  void OnCollision(const base_engine::SendManifold& manifold) override {}

 public:
  bool CanConnect() { return receiver_->PowerJoinCondition(); }
  void Connecting() {
    switch (current_state_) {
      case PowerState::kDisconnected:
        break;
      case PowerState::kDisconnect:
        current_state_ = PowerState::kConnect;
        break;
      case PowerState::kConnect:
        current_state_ = PowerState::kConnecting;
      case PowerState::kConnecting:
        break;
      default:;
    }
    prev_state_ = current_state_;
  }
  template <class T, class... _Types>
  void Create(_Types&&... args) {
    receiver_ = std::make_unique<T>(std::forward<_Types>(args)...);
  }

 private:
  enum class PowerState { kDisconnected, kDisconnect, kConnect, kConnecting };
  PowerState current_state_ = PowerState::kDisconnect;
  PowerState prev_state_ = PowerState::kDisconnect;
  std::unique_ptr<IReceivablePower> receiver_;
};
