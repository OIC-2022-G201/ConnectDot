#include "EnemyMove.h"

#include "EnemyComponent.h"
#include "Enemy.h"

namespace enemy {
	void EnemyMove::Start() {
		body_ = enemy_->PhysicsBody();
		vision_ = enemy_->GetVision();
		is_find_ = false;
		is_turn_ = false;
		body_.lock().get()->SetForceX(enemy_->GetDirection() == Left ? -Speed : Speed);
	}

	void EnemyMove::Update() {

		if (vision_!=nullptr && vision_->IsFindPlayer())
			is_find_ = true;
	}

	void EnemyMove::ProcessInput() {
	
	}

	void EnemyMove::OnEvent(base_engine::CollisionComponent* collision)
	{
		//float a;
		//if(enemy_->GetDirection() == Left)
		//	a = collision->AABB().Right - enemy_->GetCollision()->AABB().Left;
		//else a = enemy_->GetCollision()->AABB().Right - collision->AABB().Left;

		//if(a > 0)
			is_turn_ = true;
	}


	void EnemyMove::End() {

	}
}
