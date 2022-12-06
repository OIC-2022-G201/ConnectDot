// @DoorComponent.h
// @brief
// @author ICE
// @date 2022/12/02
//
// @details

#pragma once
#include "Actor.h"
#include "Component.h"
#include "LoadObjectParameter.h"

class DoorActor final : public base_engine::Actor {
 public:
  explicit DoorActor(base_engine::Game* game);

  void Create(const LoadObject& object);
};

class DoorComponent final : public base_engine::Component {
 public:
  explicit DoorComponent(base_engine::Actor* owner);

  void Start() override;

  void Update() override;

  void SetElectric(const bool flg);
  [[nodiscard]] bool GetElectric() const;

private:
  bool electric_power_ = false;
};