// @TileMapCollisionComponent.h
// @brief
// @author ICE
// @date 2022/10/20
// 
// @details

#pragma once
#include "CollisionComponent.h"
#include "Component.h"

class TileMapCollisionComponent : public base_engine::CollisionComponent
{
public:
    TileMapCollisionComponent(base_engine::Actor* owner, int update_order)
     : CollisionComponent(owner, update_order)
    {
    }
    
};
