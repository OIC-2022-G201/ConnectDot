#include "EnemyChase2.h"

#include "SecondEnemyComponent.h"

namespace enemy
{
	void EnemyChase2::Start()
	{
		vision_ = enemy_->GetVision();
		body_ = enemy_->GetPhysicsBody();
		is_find_ = true;
	}

	void EnemyChase2::Update()
	{
		if (vision_ != nullptr && !vision_->IsFindPlayer())
			is_find_ = false;

		auto player_center_ = vision_->GetPlayerCenter();
		auto center_ = enemy_->GetCollision().lock()->AABB().GetCenter();
		auto chase_direction = player_center_ - center_;
		auto distance = sqrt(chase_direction.x * chase_direction.x + chase_direction.y * chase_direction.y);
		chase_direction /= distance;

		body_.lock()->SetForce(chase_direction);
	}

	void EnemyChase2::ProcessInput()
	{

	}

	void EnemyChase2::OnEvent(CollisionComponent* collision)
	{

	}

	void EnemyChase2::End()
	{

	}
}
