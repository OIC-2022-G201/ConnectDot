#include "VisionCreateComponent.h"

#include "DummyActor.h"
#include "CollisionComponent.h"
#include "ShapeRenderComponent.h"
#include "EnemyVisionComponent.h"

namespace enemy
{
	void VisionCreateComponent::Start()
	{
		parent_ = new DummyActor(this->owner_->GetGame());
		auto vision_component = new EnemyVisionComponent(parent_, 510);
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
