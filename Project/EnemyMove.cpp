#include "EnemyMove.h"

#include "EnemyComponent.h"
#include "Enemy.h"

void enemy::EnemyMove::Start() {
	body_ = enemy_->PhysicsBody();
	is_find_ = false;
	is_turn_ = false;
	body_.lock().get()->SetForceX(enemy_->GetDirection() == Left ? -Speed : Speed);
}

void enemy::EnemyMove::Update() {

	if (vision_!=nullptr && vision_->IsFindPlayer())
		is_find_ = true;
}

void enemy::EnemyMove::ProcessInput() {
	
}

void enemy::EnemyMove::OnEvent(base_engine::CollisionComponent* collision)
{
	if (collision->GetActor()->GetTag() == "Field")
	{
		is_turn_ = true;
	}
}


void enemy::EnemyMove::End() {

}
