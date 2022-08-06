#pragma once
#include "Component.h"
#include "Idle.h"
#include "Jump.h"
#include "StateMachine.h"

namespace player {

class PlayerComponent final : public base_engine::Component {
  til::Machine<Idle, Jump> machine_ = til::Machine{Idle{this}, Jump{}};

 public:
  PlayerComponent(base_engine::Actor* owner, int update_order);
  void Start() override
  { 
  }
  void ProcessInput() override { machine_.ProcessInput(); }
  void Update() override { machine_.Update(); }
  void OnCollision(base_engine::CollisionComponent* collision) override;
};
}  // namespace player