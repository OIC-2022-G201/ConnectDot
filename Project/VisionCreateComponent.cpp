#include "VisionCreateComponent.h"

#include "EnemyVisionActor.h"
#include "CollisionComponent.h"
#include "ShapeRenderComponent.h"
#include "EnemyVisionComponent.h"

namespace enemy
{
	void VisionCreateComponent::Start()
	{
		auto dummy = new EnemyVisionActor(this->owner_->GetGame());

		auto vision_component = new EnemyVisionComponent(dummy, 502);
		vision_component->SetParent(this->owner_);
	}

	void VisionCreateComponent::ProcessInput()
	{

	}

	void VisionCreateComponent::Update()
	{

	}

	void VisionCreateComponent::OnCollision(const base_engine::SendManifold& manifold)
	{
		
	}
}
