#pragma once

#include "Component.h"
#include "SendManifold.h"
namespace enemy
{
	class VisionCreateComponent final : public base_engine::Component
	{
		base_engine::Actor* parent_;
	public:
		VisionCreateComponent(base_engine::Actor* owner_, int update_order_) :Component(owner_, update_order_) {};
		~VisionCreateComponent() {};
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const base_engine::SendManifold& manifold) override;
		base_engine::Actor* GetParent() { return parent_; }
	};
}
