// @file ReceiverComponent.h
// @brief 
// @author ICE
// @date 2022/08/08
// 
// @details

#pragma once
#include "Component.h"

class ReceiverComponent : base_engine::Component
{
public:
    ReceiverComponent(base_engine::Actor* owner, int update_order)
        : Component(owner, update_order)
    {
    }

    ~ReceiverComponent() override{}
    void Start() override{}
    void Update() override{}
    void OnCollision(base_engine::CollisionComponent* collision) override{}
};
