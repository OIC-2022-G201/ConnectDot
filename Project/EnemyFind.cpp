#include "EnemyFind.h"

#include "EnemyComponent.h"

namespace enemy {
	void EnemyFind::Start()
	{
		body_ = enemy_->PhysicsBody();
		body_.lock().get()->SetForceX(0);
	}

	void EnemyFind::Update()
	{
	
	}

	void EnemyFind::ProcessInput()
	{
	
	}

	void EnemyFind::OnEvent(base_engine::CollisionComponent* collision)
	{
	
	}

	void EnemyFind::End()
	{
	
	}
}
