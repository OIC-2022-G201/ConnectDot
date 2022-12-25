#pragma once

#include "Component.h"
#include "SendManifold.h"

using namespace base_engine;

namespace enemy
{
	class VisionCreateComponent final : public Component
	{
		Actor* vision_parent_;
	public:
		VisionCreateComponent(Actor* owner_, int update_order_) :Component(owner_, update_order_) {};
		~VisionCreateComponent() override {};
		void Start() override;
		void ProcessInput() override;
		void Update() override;
		void OnCollision(const SendManifold& manifold) override;
		Actor* GetVisionParent() { return vision_parent_; }
	};
}
