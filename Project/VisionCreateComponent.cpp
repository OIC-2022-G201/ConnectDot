#include "VisionCreateComponent.h"
#include"EnemyVisionActor.h"
namespace enemy
{
	void VisionCreateComponent::Start()
	{
		auto dummy = new EnemyVisionActor(this->owner_->GetGame());
		dummy->SetParent(this->owner_);
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