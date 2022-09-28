// @file StageActor.h
// @brief 
// @author ICE
// @date 2022/09/28
// 
// @details

#pragma once
#include "Actor.h"

class StageActor final : public base_engine::Actor {
 public:
    explicit StageActor(base_engine::Game* game);

    void Start() override;
    void Update() override;
};
