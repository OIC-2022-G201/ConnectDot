#include "BaseBodyComponent.h"

#include "CollisionComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"
#include "DrawOrder.h"
#include "BaseEngineCore.h"
#include "IBaseEngineTexture.h"
#include "TexturePaths.h"

namespace enemy
{
	void BaseBodyComponent::Start()
	{
		auto temp_render = new ShapeRenderComponent(owner_, 200);
		auto shape_ = std::make_shared<Rect>(parent_->GetComponent<CollisionComponent>().lock()->GetShape()->AABB());
		temp_render->SetShape(shape_);
		temp_render->SetColor(MOF_COLOR_HRED);
		auto sprite = new SpriteComponent(owner_,draw_order::kEnemyBodyDrawOrder);
		sprite->SetImage(BASE_ENGINE(Texture)->Get(texture::kEnemyBodyTextureKey));
		sprite->SetOffset({ -64,-24 });

		neck_ = new EnemyNeck(owner_->GetGame());
		neck_->SetBodyPosition(owner_->GetPosition() + Vector2{48,12});
	}

	void BaseBodyComponent::Update()
	{
		neck_->SetHeadPosition(parent_->GetComponent<CollisionComponent>().lock()->AABB().GetCenter());
	}

	void BaseBodyComponent::ProcessInput()
	{
		
	}

	void BaseBodyComponent::OnCollision(const SendManifold& manifold)
	{
		
	}

}
