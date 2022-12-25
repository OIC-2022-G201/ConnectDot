// @file ElectricEffect.h
// @brief
// @author ICE
// @date 2022/09/18
//
// @details

#pragma once

#include <array>

#include "Actor.h"
#include "ISpriteAnimationComponent.h"
#include "SpriteComponent.h"
#include "VectorUtilities.h"

class ElectricEffect final : public base_engine::Actor {
  class ReceiverComponent* receiver_ = nullptr;
  class TransmitterComponent* transmitter_ = nullptr;
  base_engine::SpriteComponent* sprite_ = nullptr;
  base_engine::ISpriteAnimationComponent* motion_ = nullptr;

 public:
  explicit ElectricEffect(base_engine::Game* game) : Actor(game) {}

  void SetTransmitter(TransmitterComponent* transmitter) {
    transmitter_ = transmitter;
  }

  void Start() override {}
  void Update() override {}
  void Show() const { sprite_->SetEnabled(true); }
  void Hide() const { sprite_->SetEnabled(false); }
  // TODO テクスチャを取得するKEYをベタ書きしない
  void Play(base_engine::Vector2 pos1, base_engine::Vector2 pos2);
};