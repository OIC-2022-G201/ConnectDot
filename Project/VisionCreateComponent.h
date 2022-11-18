#pragma once

#include "Component.h"
#include "SendManifold.h"
namespace enemy
{
	class VisionCreateComponent final : public base_engine::Component
	{
		
	public:
		VisionCreateComponent(base_engine::Actor* owner_, int update_order_) :Component(owner_, update_order_) {};
		~VisionCreateComponent() {};
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const base_engine::SendManifold& manifold) override;
	};
}
