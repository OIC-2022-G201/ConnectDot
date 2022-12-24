#include "EnemyTurn.h"

#include "EnemyComponent.h"

namespace enemy {
	void EnemyTurn::Start()
	{
		body_ = enemy_->PhysicsBody();
		is_move_ = false;
		enemy_->ReverseDirection();
		body_.lock().get()->SetForceX(0);
		enemy_->GetAnimator()->ChangeMotion("Tati");
	}

	void EnemyTurn::ProcessInput()
	{
	
	}

	void EnemyTurn::Update()
	{
		is_move_ = true;
	}

	void EnemyTurn::End()
	{
	
	}
}
