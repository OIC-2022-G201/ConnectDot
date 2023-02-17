#include "InputManager.h"

#include <Mof.h>

inline bool IsKeyPush(const int key) { return g_pInput->IsKeyPush(key); }
inline bool IsKeyHold(const int key) { return g_pInput->IsKeyHold(key); }

inline Mof::Vector2 GetMousePos() {
  Vector2 result;
  g_pInput->GetMousePos(result);
  return result;
};

InputManager* InputManager::Instance()
{
  return instance_;
}

InputManager::InputManager(base_engine::InputActor* owner)
  : InputComponent(owner) {
  instance_ = this;
}

InputManager::~InputManager()
{
  instance_ = nullptr;
}

void InputManager::ProcessInput() {
  move_horizontal_ = 0;
  button_horizontal_ = 0;
  button_vertical_ = 0;
  if (IsKeyHold(MOFKEY_A)) {
    move_horizontal_ += -1;
  }
  if (IsKeyHold(MOFKEY_D)) {
    move_horizontal_ += 1;
  }

  if (IsKeyPush(MOFKEY_A)) {
    button_horizontal_ += -1;
  }
  if (IsKeyPush(MOFKEY_D)) {
    button_horizontal_ += 1;
  }
  if (IsKeyPush(MOFKEY_W)) {
    button_vertical_ += -1;
  }
  if (IsKeyPush(MOFKEY_S)) {
    button_vertical_ += 1;
  }

  button_decision_ = IsKeyPush(MOFKEY_SPACE);
  button_back_ = IsKeyPush(MOFKEY_ESCAPE);
  jump_fire_ = IsKeyPush(MOFKEY_SPACE);
  place_beacon_fire_ = IsKeyPush(MOFKEY_S);
  collect_beacon_fire_ = IsKeyHold(MOFKEY_W);
  action_fire_ = IsKeyPush(MOFKEY_E);
  pause_fire_ = IsKeyPush(MOFKEY_ESCAPE);
  sneak_fire_ = IsKeyHold(MOFKEY_LSHIFT);
  mouse_position_ = GetMousePos();
}

void InputManager::Update() {}
