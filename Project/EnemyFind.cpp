#include "EnemyFind.h"

#include "EnemyComponent.h"


void enemy::EnemyFind::Start()
{
	body_ = enemy_->PhysicsBody();
	body_.lock().get()->SetForceX(0);
}

void enemy::EnemyFind::Update()
{
	
}

void enemy::EnemyFind::ProcessInput()
{
	
}

void enemy::EnemyFind::OnEvent(base_engine::CollisionComponent* collision)
{
	
}

void enemy::EnemyFind::End()
{
	
}
