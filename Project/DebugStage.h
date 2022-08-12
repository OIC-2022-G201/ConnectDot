// @file DebugStage.h
// @brief 
// @author ICE
// @date 2022/08/12
// 
// @details

#pragma once
#include "Actor.h"

class DebugStage final : public base_engine::Actor
{
public:
    explicit DebugStage(base_engine::Game* game);

    void Start() override;
    void Update() override;
};
