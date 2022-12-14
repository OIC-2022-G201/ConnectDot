#pragma once
#include "InputComponent.h"

class InputManager final : public base_engine::InputComponent {
  inline static InputManager* instance_ = nullptr;
  // InGame KeyValue
  float move_horizontal_{};
  float button_horizontal_{};
  float button_vertical_{};
  bool button_decision_{};
  bool jump_fire_{};
  bool place_beacon_fire_{};
  bool collect_beacon_fire_{};
  bool action_fire_{};
  bool pause_fire_{};
  bool sneak_fire_{};

  Mof::Vector2 mouse_position_;
 public:
  static InputManager* Instance();
  explicit InputManager(base_engine::InputActor* owner);
  ~InputManager() override;
  void ProcessInput() override;
  void Update() override;

  [[nodiscard]] float MoveHorizontal() const;
  [[nodiscard]] float ButtonHorizontal() const;
  [[nodiscard]] float ButtonVertical() const;

  [[nodiscard]] bool ButtonDecision() const;
  [[nodiscard]] bool JumpFire() const;

  [[nodiscard]] bool PlaceBeaconFire() const;

  [[nodiscard]] bool CollectBeaconFire() const;
  [[nodiscard]] bool ActionFire() const;
  [[nodiscard]] bool PauseFire() const;
  [[nodiscard]] bool SneakFire() const;

  [[nodiscard]] Mof::Vector2 MousePosition() const;
};
inline float InputManager::MoveHorizontal() const { return move_horizontal_; }

inline float InputManager::ButtonHorizontal() const { return button_horizontal_; }

inline float InputManager::ButtonVertical() const { return button_vertical_; }

inline bool InputManager::ButtonDecision() const { return button_decision_; }

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