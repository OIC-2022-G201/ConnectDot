#include "EnemyBack.h"

#include "SecondEnemyComponent.h"

namespace enemy
{
	void EnemyBack::Start()
	{
		body_ = enemy_->GetPhysicsBody();
		vision_ = enemy_->GetVision();
	}

	void EnemyBack::Update()
	{
		
	}

	void EnemyBack::ProcessInput()
	{

	}

	void EnemyBack::OnEvent(base_engine::CollisionComponent* collision)
	{

	}

	void EnemyBack::End()
	{

	}
}
