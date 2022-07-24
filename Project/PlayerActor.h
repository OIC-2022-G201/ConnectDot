#pragma once

#include "Actor.h"
class PlayerActor final : public base_engine::Actor {
  Mof::Vector2 move_vector_;
 public:
  explicit PlayerActor(base_engine::Game* game);

  ~PlayerActor() override;
  void Input() override;
  void Update() override;
  void Start() override;
  void SetInput(class InputManager* input_manager);
private:
  class InputManager* input_manager_;

 public:
};
