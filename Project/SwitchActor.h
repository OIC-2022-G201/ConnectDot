#pragma once
#include "Actor.h"
#include "Component.h"
#include "LoadObjectParameter.h"
#include "TransmitterComponent.h"

class SwitchComponent final : public base_engine::Component {
 public:
  explicit SwitchComponent(base_engine::Actor* owner,
                           const int update_order = 100);
  void Update() override;
  void OnCollision(const base_engine::SendManifold& manifold) override;
  bool OnPush() const;
  void SetPushState(bool flg);

 private:
  bool on_push_ = false;
};

class SwitchActor final : public base_engine::Actor {
 public:
  explicit SwitchActor(base_engine::Game* game);

  void Start() override;
  void Input() override;
  void Update() override;
  void Create(const LoadObject& object);
  bool OnPush() const;
  void AddTarget(const base_engine::ActorWeakPtr& target) {
    if (target.expired()) return;
    targets_.emplace_back(target.lock().get());
  }
 private:
  class SwitchComponent* switch_;
  std::vector<Actor*> targets_;
  TransmitterComponent* transmitter_;
};
