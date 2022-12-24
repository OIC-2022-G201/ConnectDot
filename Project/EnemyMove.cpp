#include "EnemyMove.h"

#include "EnemyComponent.h"
#include "Enemy.h"

namespace enemy {
	void EnemyMove::Start() {
		body_ = enemy_->PhysicsBody();
		vision_ = enemy_->GetVision();
		is_find_ = false;
		is_turn_ = false;
		enemy_->GetAnimator()->ChangeMotion("Move");
	}

 	void EnemyMove::Update() {

		body_.lock().get()->SetForceX(enemy_->GetDirection() == Left ? -Speed : Speed);
		if (vision_!=nullptr && vision_->IsFindPlayer())
			is_find_ = true;
	}

	void EnemyMove::ProcessInput() {
	
	}

	void EnemyMove::OnEvent(CollisionComponent* collision)
	{
		if (collision->GetActor()->GetTag() != "Dummy")
			is_turn_ = true;
	}


	void EnemyMove::End() {

	}
}
