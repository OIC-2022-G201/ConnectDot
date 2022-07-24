#include "PlayerActor.h"
#include "InputManager.h"


PlayerActor::PlayerActor(base_engine::Game* game): Actor(game), input_manager_(nullptr)
{
}

PlayerActor::~PlayerActor()
{}
void PlayerActor::Start() {}

void PlayerActor::SetInput(InputManager* input_manager)
{
    input_manager_ = input_manager;
}

void PlayerActor::Input()
{

    float horizontal = input_manager_->MoveHorizontal();

    move_vector_.x = horizontal * 3;
    
}

void PlayerActor::Update()
{ position_ += move_vector_; }


