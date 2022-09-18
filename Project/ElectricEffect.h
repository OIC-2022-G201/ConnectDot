// @file ElectricEffect.h
// @brief
// @author ICE
// @date 2022/09/18
//
// @details

#pragma once

#include <array>

#include "Actor.h"
#include "BaseEngineCore.h"
#include "IBaseEngineTexture.h"
#include "MofSpriteAnimationComponent.h"
#include "SpriteComponent.h"
#include "VectorUtilities.h"

class ElectricEffect final : public base_engine::Actor {
  class ReceiverComponent* receiver_ = nullptr;
  class TransmitterComponent* transmitter_ = nullptr;
  base_engine::SpriteComponent* sprite_ = nullptr;
  base_engine::MofSpriteAnimationComponent* motion_ = nullptr;

 public:
  explicit ElectricEffect(base_engine::Game* game) : Actor(game) {}
  void SetTransmitter(TransmitterComponent* transmitter) {
    transmitter_ = transmitter;
  }

  void SetReceiver(ReceiverComponent* receiver) { receiver_ = receiver; }
  void Start() override {
  }
    void Update() override
  {
      int n = 3;
  }
  void Play(base_engine::Vector2 pos1, base_engine::Vector2 pos2)
  {
    sprite_ = new base_engine::SpriteComponent(this);
    sprite_->SetImage(
        BASE_ENGINE(Texture)->Get("Effect/Electric/ElectroCellMap.png"));
    motion_ = new base_engine::MofSpriteAnimationComponent(this);
    motion_->SetSpriteComponent(sprite_);
    const base_engine::Vector2 o_pos = pos1 - pos2;
    const float width = std::abs(base_engine::VectorUtilities::Length(o_pos));
    std::array animations = {base_engine::SpriteAnimationClip{
        "", 0, 0, width, 128, true, {{5, 0, 0}, {5, 0, 1}, {5, 0, 2}}}};
    sprite_->SetOffset(pos1);
    sprite_->SetAngle(std::atan2(o_pos.y,o_pos.x));
      motion_->Load(animations);
  }
};
