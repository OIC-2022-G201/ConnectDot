#include "SecondEnemyComponent.h"

#include "Game.h"
#include "Mof.h"

namespace enemy
{
	void SecondEnemyComponent::Start()
	{
		/*owner_->GetGame()->debug_render_.emplace_back([this]() {
			Mof::CGraphicsUtilities::RenderString(0, 90, "e_State:%d",
				machine_.current_state());

			Mof::CGraphicsUtilities::RenderString(0, 150, "e_force:x:%f,y:%f",
				physics_body_.lock()->GetForce().x,
				physics_body_.lock()->GetForce().y);
			});*/

		physics_body_ = owner_->GetComponent<PhysicsBodyComponent>();
		collision_ = owner_->GetComponent<CollisionComponent>();
		collision_.lock()->SetTrigger(true);
		GetVision()->SetFindRect(std::make_shared<Rect>(-768, -768, 1024, 1024));
		GetVision()->SetChaseRect(std::make_shared<Rect>(-768, -768, 1024, 1024));
		GetVision()->SetReverseWidth(0);

		base_body_ = new BaseBodyCreateComponent(owner_, 103);

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

	void SecondEnemyComponent::OnCollision(const SendManifold& manifold)
	{
		machine_.OnEvent(manifold.collision_b);
	}
}
