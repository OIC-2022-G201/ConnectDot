#include "EnemyChase.h"

#include "EnemyComponent.h"

namespace enemy {
	void EnemyChase::Start()
	{
		body_ = enemy_->PhysicsBody();
		is_find_ = true;
	}

	void EnemyChase::Update()
	{
		if (vision_ != nullptr && !vision_->IsFindPlayer())
			is_find_ = false;

		auto player_center_x = vision_->GetPlayerCenterX();
		auto center_x = enemy_->GetCollision()->AABB().GetCenter().x;
		if (center_x < player_center_x) enemy_->SetDirection(Right);
		else enemy_->SetDirection(Left);

		body_.lock()->SetForceX(enemy_->GetDirection() == Left ? -ChaseSpeed : ChaseSpeed);
	}

	void EnemyChase::ProcessInput()
	{

	}

	void EnemyChase::OnEvent(base_engine::CollisionComponent* collision)
	{

	}

	void EnemyChase::End()
	{

	}
}