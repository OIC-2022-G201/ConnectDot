#include "InputManager.h"

#include <Mof.h>

inline bool IsKeyPush(const int key) { return g_pInput->IsKeyPush(key); }

inline bool IsKeyHold(const int key) { return g_pInput->IsKeyHold(key); }
inline Mof::Vector2 GetMousePos() {
  Vector2 result;
  g_pInput->GetMousePos(result);
  return result;
};
InputManager::InputManager(base_engine::InputActor* owner)
    : InputComponent(owner) {}

InputManager::~InputManager() {}

void InputManager::ProcessInput() {
  move_horizontal_ = 0;

  if (IsKeyHold(MOFKEY_A) || IsKeyHold(MOFKEY_LEFT)) {
    move_horizontal_ += -1;
  }
  if (IsKeyHold(MOFKEY_D) || IsKeyHold(MOFKEY_RIGHT)) {
    move_horizontal_ += 1;
  }

  jump_fire_ = IsKeyPush(MOFKEY_SPACE);
  place_beacon_fire_ = IsKeyPush(MOFKEY_Q);
  collect_beacon_fire_ = IsKeyPush(MOFKEY_E);
  pause_fire_ = IsKeyPush(MOFKEY_ESCAPE);
  sneak_fire_ = IsKeyHold(MOFKEY_LSHIFT) || IsKeyHold(MOFKEY_RSHIFT);
  mouse_position_ = GetMousePos();
}

void InputManager::Update() {}
