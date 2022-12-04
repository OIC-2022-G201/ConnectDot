#include "BaseBodyCreateComponent.h"

#include "DummyActor.h"
#include "BaseBodyComponent.h"

namespace enemy
{
	void BaseBodyCreateComponent::Start()
	{
		parent_ = new DummyActor(this->owner_->GetGame());
		auto base_body_ = new BaseBodyComponent(parent_, 520);
		base_body_->SetParent(this->owner_);
	}

	void BaseBodyCreateComponent::Update()
	{
		
	}

	void BaseBodyCreateComponent::ProcessInput()
	{
		
	}
}