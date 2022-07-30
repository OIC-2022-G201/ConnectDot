#pragma once
#include "Component.h"

class PlayerComponent final : public base_engine::Component
{
public:
    PlayerComponent(base_engine::Actor* owner, int update_order);

    void OnCollision(base_engine::CollisionComponent* collision) override;
};
