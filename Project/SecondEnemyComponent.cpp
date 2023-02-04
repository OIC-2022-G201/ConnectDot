#include "SecondEnemyComponent.h"

#include "IBaseEngineTexture.h"
#include "TexturePaths.h"
#include "Game.h"
#include "Mof.h"
#include "ReleaseInfo.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"

namespace enemy
{
	void SecondEnemyComponent::Start()
	{
		owner_->GetGame()->debug_render_.emplace_back([this]() {
			Mof::CGraphicsUtilities::RenderString(0, 240, "e2_State:%d",
				machine_.current_state());

			Mof::CGraphicsUtilities::RenderString(0, 270, "e2_force:x:%f,y:%f",
				physics_body_.lock()->GetForce().x,
				physics_body_.lock()->GetForce().y);
			});

		const auto size = stage::kStageCellSize<MofFloat>;
		const auto enemy_shape = std::make_shared<Rect>(0, 0, size.x, size.y);
		physics_body_ = owner_->GetComponent<PhysicsBodyComponent>();
		collision_ = owner_->GetComponent<CollisionComponent>();
		collision_.lock()->SetShape(enemy_shape);
		collision_.lock()->SetTrigger(true);
    if (kIsCollisionRenderMode)
    {
      owner_->GetComponent<ShapeRenderComponent>()
          .lock()->SetShape(enemy_shape);
    }
		float lt = -768; float rb = 896;
		GetVision()->SetFindRect(std::make_shared<Rect>(lt, lt, rb, rb));
		GetVision()->SetChaseRect(std::make_shared<Rect>(lt, lt, rb, rb));
		GetVision()->SetReverseWidth(0);
		base_body_ = new BaseBodyCreateComponent(owner_, 103);
		sprite_ = owner_->GetComponent<SpriteComponent>();
		sprite_.lock()->SetImage(BASE_ENGINE(Texture)->Get(texture::kEnemyHeadTextureKey));
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
