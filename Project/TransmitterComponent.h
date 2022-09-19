﻿// @file TransmitterComponent.h
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
#include "ISendablePower.h"

class TransmitterComponent : public base_engine::Component {
 public:
  TransmitterComponent(base_engine::Actor* owner, int update_order);

  ~TransmitterComponent() override;
  void Start() override;

  void Update() override;

  void OnCollision(const base_engine::SendManifold& manifold) override;
  int Sequential() const { return transmitter_->Sequential(); }
 public:
  template <
      SendablePower T, class... Types,
      std::enable_if_t<std::is_constructible_v<T, Types...>, bool> = false>
  void Create(Types&&... args) {
    transmitter_ = std::make_unique<T>(std::forward<Types>(args)...);
  }

  [[nodiscard]] base_engine::Vector2 GetPosition() const;

private:
  std::deque<class ReceiverComponent*> target_;
  std::unique_ptr<ISendablePower> transmitter_;
};
