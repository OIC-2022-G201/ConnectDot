#include "EnemyIdle.h"

#include "SecondEnemyComponent.h"

namespace enemy
{
	void EnemyIdle::Start()
	{
		body_ = enemy_->GetPhysicsBody();
		vision_ = enemy_->GetVision();
		is_find_ = false;

		body_.lock()->SetForce({ 0,0 });
	}

	void EnemyIdle::Update()
	{
		if (vision_ != nullptr && vision_->IsFindPlayer())
			is_find_ = true;
	}

	void EnemyIdle::ProcessInput()
	{
		
	}

	void EnemyIdle::OnEvent(CollisionComponent* collision)
	{
		
	}

	void EnemyIdle::End()
	{
		
	}
}
