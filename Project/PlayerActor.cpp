#include "PlayerActor.h"

#include "InputManager.h"
#include "PlayerComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"

#include <Mof.h>
PlayerActor::PlayerActor(base_engine::Game* game)
    : Actor(game), input_manager_(nullptr) {}

PlayerActor::~PlayerActor() {}
void PlayerActor::Start() {
  new PlayerComponent(this, 100);
}

void PlayerActor::SetInput(InputManager* input_manager) {
  input_manager_ = input_manager;
}

void PlayerActor::Input() {
  float horizontal = input_manager_->MoveHorizontal();
        IsJumpStart = input_manager_->JumpFire();
        if (g_pInput->IsKeyPush(MOFKEY_1))
        {
            JumpMode = 1;
        }
        else if (g_pInput->IsKeyPush(MOFKEY_2))
        {
            JumpMode = 2;
        }
  move_vector_.x = horizontal * 3;
}

void PlayerActor::Update() {
    position_ += move_vector_;
    if (JumpMode == 1)
    {
        if (IsJumpStart && !JumpFlg)
        {
            JumpFlg = true;
            move_vector_.y = -10;
            return;
        }

        move_vector_.y += 0.3f;
        if (position_.y >= 500)
        {
            position_.y = 500;
            JumpFlg = false;
        }
    }
    if (JumpMode == 2)
    {
        if (IsJumpStart && !JumpFlg)
        {
          JumpFlg = true;
          move_vector_.y = -15;
          return;
        }

        move_vector_.y += 0.5f;
        if (position_.y >= 500)
        {
            position_.y = 500;
            JumpFlg = false;
        }
    }
}