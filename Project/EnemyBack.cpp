#include "EnemyBack.h"

#include "SecondEnemyComponent.h"
#include "Enemy.h"

namespace enemy
{
	void EnemyBack::Start()
	{
		body_ = enemy_->GetPhysicsBody();
		vision_ = enemy_->GetVision();
		is_find_ = false;
		is_arrive_ = false;
	}

	void EnemyBack::Update()
	{
		if (vision_ != nullptr && vision_->IsFindPlayer())
			is_find_ = true;

		auto base_ = enemy_->GetBodyActor()->GetPosition();
		auto center_ = enemy_->GetCollision().lock()->AABB().GetTopLeft();
		auto back_direction = base_ - center_;
		auto distance_ = sqrt(back_direction.x * back_direction.x + back_direction.y * back_direction.y);

		if (distance_ < Speed)
			is_arrive_ = true;

		back_direction /= distance_;

		body_.lock()->SetForce(back_direction * Speed);
	}

	void EnemyBack::ProcessInput()
	{

	}

	void EnemyBack::OnEvent(CollisionComponent* collision)
	{

	}

	void EnemyBack::End()
	{

	}
}
