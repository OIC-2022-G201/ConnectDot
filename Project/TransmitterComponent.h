// @file TransmitterComponent.h
// @brief
// @author ICE
// @date 2022/08/08
//
// @details

#pragma once
#include <deque>
#include <memory>

#include "Actor.h"
#include "CollisionComponent.h"
#include "Component.h"
#include "IConnectBindable.h"
#include "ISendablePower.h"
#include "ReceiverComponent.h"

class TransmitterComponent : public base_engine::Component {
 public:
  TransmitterComponent(base_engine::Actor* owner, int update_order);

  ~TransmitterComponent() override;
  void Start() override;

  void Update() override;

  void OnCollision(const base_engine::SendManifold& manifold) override;
  [[nodiscard]] int Level() const { return level_; }

  void SetLevel(const int level) { level_ = level; }

 public:
  template <
      SendablePower T, class... Types,
      std::enable_if_t<std::is_constructible_v<T, Types...>, bool> = false>
  void Create(Types&&... args) {
    transmitter_ = std::make_unique<T>(std::forward<Types>(args)...);
  }
  bool AddTarget(std::weak_ptr<class ReceiverComponent> target_weak);
  [[nodiscard]] base_engine::Vector2 GetPosition() const;
  /**
   * \brief 有線接続など、強制的な接続が可能か
   * \return true:成功 false:失敗
   */
  static bool CoercionCondition(const std::weak_ptr<ReceiverComponent>&);

  template <class T, class... Types,
            std::enable_if_t<std::is_constructible_v<T, Types...> &&
                                 std::is_base_of_v<IConnectBindable, T>,
                             bool> = false>
  void CreateConnectBind(Types&&... args) {
    connect_bindable_ = std::make_unique<T>(std::forward<Types>(args)...);
  }
  
  std::unique_ptr<IConnectBindable> connect_bindable_;
  std::deque<std::weak_ptr<class ReceiverComponent>> target_;
  std::unique_ptr<ISendablePower> transmitter_;
  int level_ = 1;
};
