#include "EnemyTurn.h"

#include "EnemyComponent.h"
#include "Enemy.h"

void enemy::EnemyTurn::Start()
{
	body_ = enemy_->PhysicsBody();
	is_move_ = false;
	body_.lock().get()->SetForceX(0);
}

void enemy::EnemyTurn::ProcessInput()
{
	
}

void enemy::EnemyTurn::Update()
{
	is_move_ = true;
}

void enemy::EnemyTurn::End()
{
	
}
