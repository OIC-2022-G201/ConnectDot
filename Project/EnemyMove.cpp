#include "EnemyMove.h"

#include "EnemyComponent.h"
#include "Enemy.h"

namespace enemy {
	void EnemyMove::Start() {
		body_ = enemy_->PhysicsBody();
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
		if (collision->GetActor()->GetTag() == "Field")
		{
			is_turn_ = true;
		}
	}


	void EnemyMove::End() {

	}
}
