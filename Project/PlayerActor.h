#pragma once

#include "Actor.h"
class InputManager;
namespace player {

class PlayerActor final : public base_engine::Actor {

 public:
  explicit PlayerActor(base_engine::Game* game);

  ~PlayerActor() override;
  void Input() override;
  void Update() override;
  void Start() override;
  void SetInput(InputManager* input_manager);
  void SetCamera(Actor* camera) { camera_ = camera; };

 private:
  Mof::Vector2 move_vector_;
  class PlayerComponent* player_component_ = nullptr;
  Actor* camera_ = nullptr;
  InputManager* input_manager_;
  int MaxBeacon() {
      return 2;
  }
  int have_beacon_count_ = MaxBeacon();
 public:
};
}  // namespace player