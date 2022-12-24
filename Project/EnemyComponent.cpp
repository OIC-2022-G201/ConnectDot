#include "EnemyComponent.h"

#include "IBaseEngineTexture.h"
#include "TexturePaths.h"
#include "Game.h"
#include "Mof.h"
#include "ShapeRenderComponent.h"

namespace enemy {
	void EnemyComponent::Start() {

		owner_->GetGame()->debug_render_.emplace_back([this]() {
			Mof::CGraphicsUtilities::RenderString(0, 180, "e_State:%d",
				machine_.current_state());

			Mof::CGraphicsUtilities::RenderString(0, 210, "e_force:x:%f,y:%f",
				physics_body_.lock()->GetForce().x,
				physics_body_.lock()->GetForce().y);
			});

		const auto enemy_shape = std::make_shared<Rect>(0, 0, 256, 256);
		physics_body_ = owner_->GetComponent<PhysicsBodyComponent>();
		collision_ = owner_->GetComponent<CollisionComponent>();
		collision_.lock()->SetShape(enemy_shape);
		owner_->GetComponent<ShapeRenderComponent>().lock().get()->SetShape(enemy_shape);
		GetVision()->SetFindRect(std::make_shared<Rect>(-256, 0, 256, 256));
		GetVision()->SetChaseRect(std::make_shared<Rect>(-256, -256, 512, 512));
		GetVision()->SetReverseWidth(256);
		sprite_ = owner_->GetComponent<SpriteComponent>();
		animator_ = owner_->GetComponent<ISpriteAnimationComponent>();
		animator_.lock()->Load(sprite_.lock().get(), "LivingEntity/Enemy/Enemy2.aei");
		sprite_.lock()->SetImage(BASE_ENGINE(Texture)->Get(texture::kEnemyTextureKey));
		machine_.TransitionTo<EnemyMove>();
	}

	void EnemyComponent::ProcessInput() {
		machine_.ProcessInput();
	}

	void EnemyComponent::Update() {
		direction.Subscribe([this](const bool dir)
			{
				switch (dir)
				{
				case Left:
					sprite_.lock()->SetFlip(Flip::kNone);
					break;
				case Right:
					sprite_.lock()->SetFlip(Flip::kHorizontal);
					break;
				}
			});
		physics_body_.lock()->AddForce({0, Gravity});
		machine_.Update();
	}

	void EnemyComponent::OnCollision(const SendManifold& manifold) {
		auto block_top = manifold.collision_b->AABB().Top;
		auto e_bottom = collision_.lock()->AABB().Bottom;
		auto diff = block_top - e_bottom;
		if(diff < -127)
			machine_.OnEvent(manifold.collision_b);
	}
}
