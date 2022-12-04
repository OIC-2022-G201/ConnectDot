#include "SecondEnemyComponent.h"

namespace enemy
{
	void SecondEnemyComponent::Start()
	{
		physics_body_ = owner_->GetComponent<base_engine::PhysicsBodyComponent>();
		collision_ = owner_->GetComponent<base_engine::CollisionComponent>();
		GetVision()->SetFindRect(std::make_shared<base_engine::Rect>(-768, -768, 1024, 1024));
		GetVision()->SetChaseRect(std::make_shared<base_engine::Rect>(-768, -768, 1024, 1024));
		GetVision()->SetReverseWidth(0);

		auto base_body_ = new BaseBodyCreateComponent(owner_, 103);

		machine_.TransitionTo<EnemyIdle>();
	}

	void SecondEnemyComponent::ProcessInput()
	{
		machine_.ProcessInput();
	}

	void SecondEnemyComponent::Update()
	{
		machine_.Update();
	}

	void SecondEnemyComponent::OnCollision(const base_engine::SendManifold& manifold)
	{
		machine_.OnEvent(manifold.collision_b);
	}
}
