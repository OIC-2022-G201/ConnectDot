#include "VisionCreateComponent.h"

#include "DummyActor.h"
#include "CollisionComponent.h"
#include "ShapeRenderComponent.h"
#include "EnemyVisionComponent.h"

namespace enemy
{
	void VisionCreateComponent::Start()
	{
		vision_parent_ = new DummyActor(this->owner_->GetGame());
		auto vision_component = new EnemyVisionComponent(vision_parent_, 510);
		vision_component->SetParent(this->owner_);
	}

	void VisionCreateComponent::ProcessInput()
	{

	}

	void VisionCreateComponent::Update()
	{

	}

	void VisionCreateComponent::OnCollision(const SendManifold& manifold)
	{
		
	}
}
