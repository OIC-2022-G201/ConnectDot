// @file GridSnapComponent.h
// @brief 
// @author ICE
// @date 2022/08/20
// 
// @details

#pragma once
#include "Component.h"

class GridSnapComponent final : public base_engine::Component
{
public:
    GridSnapComponent(base_engine::Actor* owner, int update_order = component_update::kGrid)
        : Component(owner, update_order)
    {
    }

};
