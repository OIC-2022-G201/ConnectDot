// @CollapsibleBlockActor.h
// @brief
// @author ICE
// @date 2022/12/27
//
// @details

#pragma once
#include "Actor.h"
#include "CollapsibleBlockReceiver.h"
#include "LoadObjectParameter.h"

class CollapsibleBlockActor : public base_engine::Actor {
 public:
  explicit CollapsibleBlockActor(base_engine::Game* game) : Actor(game) {}
  void Create(const LoadObject& object);
};
class CollapsibleBlockComponent final : public base_engine::Component {
 public:
  explicit CollapsibleBlockComponent(base_engine::Actor* owner,
                                     const int update_order = 100)
      : Component(owner, update_order) {}
  void SetElectric(const bool flg) { electric_power_ = flg; }
  [[nodiscard]] bool GetElectric() const { return electric_power_; }

 private:
  bool electric_power_ = false;
};