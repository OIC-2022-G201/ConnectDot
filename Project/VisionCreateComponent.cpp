#include "VisionCreateComponent.h"
#include"EnemyVisionActor.h"
#include"PlayerComponent.h"
namespace enemy
{
	void VisionCreateComponent::Start()
	{
		auto dummy = new EnemyVisionActor(this->owner_->GetGame());
		dummy->SetParent(this->owner_);
		collision_ = dummy->GetComponent<base_engine::CollisionComponent>();
	}

	void VisionCreateComponent::ProcessInput()
	{

	}

	void VisionCreateComponent::Update()
	{

	}

	void VisionCreateComponent::OnCollision(const base_engine::SendManifold& manifold)
	{
		if(manifold.collision_b->GetActor()->GetComponent<player::PlayerComponent>().lock() != nullptr)
		{
			
		}
	}
}
