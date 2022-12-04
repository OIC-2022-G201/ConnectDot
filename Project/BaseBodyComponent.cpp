#include "BaseBodyComponent.h"

#include "CollisionComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"

namespace enemy
{
	void BaseBodyComponent::Start()
	{
		auto temp_render = new base_engine::ShapeRenderComponent(owner_, 200);
		auto shape_ = std::make_shared<base_engine::Rect>(parent_->GetComponent<base_engine::CollisionComponent>().lock().get()->AABB());
		temp_render->SetShape(shape_);
		temp_render->SetColor(MOF_COLOR_HRED);
	}

	void BaseBodyComponent::Update()
	{
		
	}

	void BaseBodyComponent::ProcessInput()
	{
		
	}

	void BaseBodyComponent::OnCollision(const base_engine::SendManifold& manifold)
	{
		
	}

}
