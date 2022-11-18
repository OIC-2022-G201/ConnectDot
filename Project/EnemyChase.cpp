#include "EnemyChase.h"

#include "EnemyComponent.h"


void enemy::EnemyChase::Start()
{
	body_ = enemy_->PhysicsBody();
	is_find_ = true;
	body_.lock().get()->SetForceX(enemy_->GetDirection() == Left ? -Speed * 2 : Speed * 2);
}

void enemy::EnemyChase::Update()
{
	if (vision_ != nullptr && !vision_->IsFindPlayer())
		is_find_ = false;
}

void enemy::EnemyChase::ProcessInput()
{

}

void enemy::EnemyChase::OnEvent(base_engine::CollisionComponent* collision)
{

}

void enemy::EnemyChase::End()
{

}
