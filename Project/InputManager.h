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

  [[nodiscard]] float MoveHorizontal() const;
  [[nodiscard]] bool JumpFire() const;

  [[nodiscard]] bool PlaceBeaconFire() const;

  [[nodiscard]] bool CollectBeaconFire() const;
  [[nodiscard]] bool ActionFire() const;
  [[nodiscard]] bool PauseFire() const;
  [[nodiscard]] bool SneakFire() const;

  [[nodiscard]] Mof::Vector2 MousePosition() const;
};
inline float InputManager::MoveHorizontal() const { return move_horizontal_; }

inline bool InputManager::JumpFire() const { return jump_fire_; }

inline bool InputManager::PlaceBeaconFire() const { return place_beacon_fire_; }

inline bool InputManager::CollectBeaconFire() const {
  return collect_beacon_fire_;
}

inline bool InputManager::ActionFire() const { return action_fire_; }

inline bool InputManager::PauseFire() const { return pause_fire_; }

inline bool InputManager::SneakFire() const { return sneak_fire_; }
inline Mof::Vector2 InputManager::MousePosition() const {
  return mouse_position_;
}