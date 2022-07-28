#pragma once
#include "InputComponent.h"

class InputManager final : public base_engine::InputComponent {
  // InGame KeyValue
  float move_horizontal_;
  bool jump_fire_;
  bool place_beacon_fire_;
  bool collect_beacon_fire_;
  bool action_fire_;
  bool pause_fire_;
  bool sneak_fire_;

  Mof::Vector2 mouse_position_;
 public:
  explicit InputManager(base_engine::InputActor* owner);
  ~InputManager() override;
  void ProcessInput() override;
  void Update() override;

  [[nodiscard]] inline float MoveHorizontal() const;
  [[nodiscard]] inline bool JumpFire() const;

  [[nodiscard]] inline bool PlaceBeaconFire() const;

  [[nodiscard]] inline bool CollectBeaconFire() const;
  [[nodiscard]] inline bool ActionFire() const;
  [[nodiscard]] inline bool PauseFire() const;
  [[nodiscard]] inline bool SneakFire() const;

  [[nodiscard]] inline Mof::Vector2 MousePosition() const;
};
float InputManager::MoveHorizontal() const { return move_horizontal_; }

bool InputManager::JumpFire() const { return jump_fire_; }

bool InputManager::PlaceBeaconFire() const { return place_beacon_fire_; }

bool InputManager::CollectBeaconFire() const { return collect_beacon_fire_; }

bool InputManager::ActionFire() const { return action_fire_; }

bool InputManager::PauseFire() const { return pause_fire_; }

bool InputManager::SneakFire() const { return sneak_fire_; }
Mof::Vector2 InputManager::MousePosition() const { return mouse_position_; }