#include "EnemyMove.h"

#include "EnemyComponent.h"
#include "Enemy.h"

void enemy::EnemyMove::Start() {
	body_ = enemy_->PhysicsBody();
	is_find_ = false;
	is_turn_ = false;
	direction *= -1;
}

void enemy::EnemyMove::Update() {

}

void enemy::EnemyMove::ProcessInput() {
	body_.lock().get()->SetForceX(direction*Speed);
}

void enemy::EnemyMove::OnEvent(base_engine::CollisionComponent* collision)
{
	if (collision->GetActor()->GetTag() == "Field")
		is_turn_ = true;
}


void enemy::EnemyMove::End() {

}
