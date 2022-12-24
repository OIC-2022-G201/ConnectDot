#include "EnemyBack.h"

#include "SecondEnemyComponent.h"
#include "Enemy.h"

namespace enemy
{
	void EnemyBack::Start()
	{
		body_ = enemy_->GetPhysicsBody();
		vision_ = enemy_->GetVision();
		sprite_ = enemy_->GetSprite();
		is_find_ = false;
		is_arrive_ = false;

		auto base = enemy_->GetBodyActor()->GetPosition();
		auto head = enemy_->GetCollision().lock()->AABB().GetCenter();
		auto back_direction = base - head;
		bool xflip = back_direction.x > 0;
		bool yflip = back_direction.y > 0;
		if (xflip && yflip) sprite_->SetFlip(Flip::kHorizontalAndVertical);
		else if (xflip)		sprite_->SetFlip(Flip::kHorizontal);
		else if (yflip)		sprite_->SetFlip(Flip::kVertical);
		else				sprite_->SetFlip(Flip::kNone);
	}

	void EnemyBack::Update()
	{
		if (vision_ != nullptr && vision_->IsFindPlayer())
			is_find_ = true;

		auto base = enemy_->GetBodyActor()->GetPosition();
		auto head = enemy_->GetCollision().lock()->AABB().GetTopLeft();
		auto back_direction = base - head;
		auto distance = sqrt(back_direction.x * back_direction.x + back_direction.y * back_direction.y);

		if (distance < Speed)
			is_arrive_ = true;

		back_direction /= distance;

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
