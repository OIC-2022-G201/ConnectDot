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
#include "SpriteComponent.h"

class ReceiverComponent : public base_engine::Component {
 public:
  void OnPowerExit() {
    current_state_ = PowerState::kDisconnect;
    prev_state_ = PowerState::kDisconnect;
    receiver_->OnPowerExit(sender_.lock().get());
  }
  void OnPowerEnter();

  void OnPowerChanged() { receiver_->OnPowerChanged(sender_.lock().get()); }

  ReceiverComponent(base_engine::Actor* owner, int update_order);

  ~ReceiverComponent() override {}
  void Start() override;

  void Update() override {
    if (current_state_ == PowerState::kConnecting &&
        prev_state_ == PowerState::kDisconnect) {
      prev_state_ = PowerState::kDisconnected;
    }
    switch (prev_state_) {
      case PowerState::kDisconnected:
        OnPowerExit();
        break;
      case PowerState::kConnect:
        OnPowerEnter();
        break;
      case PowerState::kConnecting:
        OnPowerChanged();
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
  bool CanConnect() const { return receiver_->PowerJoinCondition(); }
  void Connecting(std::weak_ptr<class TransmitterComponent> sender_weak);

  template <
      class T, class... Types,
      std::enable_if_t<std::is_constructible_v<T, Types...>, bool> = false>
  void Create(Types&&... args) {
    receiver_ = std::make_unique<T>(std::forward<Types>(args)...);
  }

  [[nodiscard]] base_engine::Vector2 GetPosition() const {
    return owner_->GetPosition() + receiver_->GetPosition();
  }

 private:
  enum class PowerState {
    kDisconnect,    //接続が切れている
    kDisconnected,  //接続が切れた瞬間
    kConnect,       //接続された瞬間
    kConnecting     //接続されている(kConnectの後から切れるまで)
  };
  PowerState current_state_ = PowerState::kDisconnect;
  PowerState prev_state_ = PowerState::kDisconnect;
  std::unique_ptr<IReceivablePower> receiver_;
  std::weak_ptr<class TransmitterComponent> sender_;

  class ElectricEffect* effect_ = nullptr;
};
