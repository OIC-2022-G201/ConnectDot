#include "BaseBodyCreateComponent.h"

#include "DummyActor.h"
#include "BaseBodyComponent.h"

namespace enemy
{
	void BaseBodyCreateComponent::Start()
	{
		body_parent_ = new DummyActor(this->owner_->GetGame());
		body_parent_->SetPosition(owner_->GetPosition());
		auto base_body_ = new BaseBodyComponent(body_parent_, 520);
		base_body_->SetParent(this->owner_);
	}

	void BaseBodyCreateComponent::Update()
	{
		
	}

	void BaseBodyCreateComponent::ProcessInput()
	{
		
	}
}