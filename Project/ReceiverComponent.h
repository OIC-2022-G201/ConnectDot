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
#include "ISpriteAnimationComponent.h"
#include "SpriteComponent.h"
class ReceiverComponent : public base_engine::Component {
 public:
  ~ReceiverComponent() override;
  void OnPowerExit();
  void OnPowerEnter();

  void OnPowerChanged() const;

  ReceiverComponent(base_engine::Actor* owner, int update_order);

  void Start() override;

  void Update() override;

  bool CanConnect() const;
  virtual bool CanConnectCheck(
      const std::weak_ptr<class TransmitterComponent>& sender_weak) const;

  bool IsWireless() const;

  bool Disconnect();
  virtual void Connecting(
      std::weak_ptr<class TransmitterComponent> sender_weak);
  [[nodiscard]] int Sequential() const;

  template <
      class T, class... Types,
      std::enable_if_t<std::is_constructible_v<T, Types...>, bool> = false>
  void Create(Types&&... args) {
    receiver_ = std::make_unique<T>(std::forward<Types>(args)...);
  }
  void ECreate();

  [[nodiscard]] base_engine::Vector2 GetPosition() const;

  bool IsConnect() const;

  bool EqualSender(
      const std::weak_ptr<class TransmitterComponent>& sender_weak) const;

  [[nodiscard]] int Level() const;

  void SetLevel(const int level);

  [[nodiscard]] std::weak_ptr<base_engine::Actor> GetSenderActor() const;
  void FlowSparkEffect() const;

 protected:
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
  std::vector<std::weak_ptr<class TransmitterComponent>> senders_;
  size_t wait_frame_ = 0;
  std::weak_ptr<base_engine::Actor> effect_{};
  base_engine::ISpriteAnimationComponent* flow_spark_animation_ = nullptr;
  int level_ = 1;

  bool next_frame_disconnect_ = false;
};
