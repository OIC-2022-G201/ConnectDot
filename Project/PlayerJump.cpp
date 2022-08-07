#include "PlayerJump.h"

#include "PlayerComponent.h"

player::PlayerJump::PlayerJump(PlayerComponent* player) : player_(player) {}

void player::PlayerJump::Start() {
  is_idle_ = false;
  frame_ = 0;
}

void player::PlayerJump::Update() {
  frame_++;
  is_idle_ = frame_ > 20;
}

void player::PlayerJump::ProcessInput() {}

void player::PlayerJump::End() {}
