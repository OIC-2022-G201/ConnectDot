#include "EnemyComponent.h"

#include "Game.h"
#include "Mof.h"

namespace enemy {
	void EnemyComponent::Start() {

		owner_->GetGame()->debug_render_.emplace_back([this]() {
			Mof::CGraphicsUtilities::RenderString(0, 90, "e_State:%d",
				machine_.current_state());

			Mof::CGraphicsUtilities::RenderString(0, 150, "e_force:x:%f,y:%f",
				physics_body_.lock()->GetForce().x,
				physics_body_.lock()->GetForce().y);
			});

		physics_body_ = owner_->GetComponent<base_engine::PhysicsBodyComponent>();
		collision_ = owner_->GetComponent<base_engine::CollisionComponent>();
		GetVision()->SetFindRect(std::make_shared<base_engine::Rect>(-256, 0, 256, 256));
		GetVision()->SetChaseRect(std::make_shared<base_engine::Rect>(-256, -256, 512, 512));
		GetVision()->SetReverseWidth(256);
		machine_.TransitionTo<EnemyMove>();
	}

	void EnemyComponent::ProcessInput() {
		machine_.ProcessInput();
	}

	void EnemyComponent::Update() {
		physics_body_.lock()->AddForce({0, Gravity});
		machine_.Update();
	}

	void EnemyComponent::OnCollision(const base_engine::SendManifold& manifold) {
		auto block_top = manifold.collision_b->AABB().Top;
		auto e_bottom = collision_.lock()->AABB().Bottom;
		auto diff = block_top - e_bottom;
		if(diff < -127)
			machine_.OnEvent(manifold.collision_b);
	}
}