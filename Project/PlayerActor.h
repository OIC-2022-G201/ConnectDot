#pragma once

#include "Actor.h"

namespace tile_map {
class TileMapComponent;
}

class InputManager;
namespace player {

class PlayerActor final : public base_engine::Actor {
  using TileMapWeak =
      base_engine::ComponentDerivedWeakPtr<tile_map::TileMapComponent>;

 public:
  explicit PlayerActor(base_engine::Game* game);

  ~PlayerActor() override;
  void Input() override;
  void Update() override;
  void Start() override;
  void SetInput(InputManager* input_manager);
  void SetMap(const TileMapWeak& map) { map_ = map; }

 private:
  Mof::Vector2 move_vector_;
  class PlayerComponent* player_component_ = nullptr;
  InputManager* input_manager_;
  TileMapWeak map_;
};
}  // namespace player