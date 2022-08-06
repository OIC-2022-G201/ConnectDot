#pragma once

#include "Actor.h"
class InputManager;
namespace player {

class PlayerActor final : public base_engine::Actor {
  Mof::Vector2 move_vector_;
  class PlayerComponent* player_component_;

 public:
  explicit PlayerActor(base_engine::Game* game);

  ~PlayerActor() override;
  void Input() override;
  void Update() override;
  void Start() override;
  void SetInput(InputManager* input_manager);

 private:
  InputManager* input_manager_;

 public:
};
}  // namespace player