// @file PylonActor.h
// @brief 
// @author ICE
// @date 2022/08/08
// 
// @details

#pragma once
#include "Actor.h"

class PylonActor : public base_engine::Actor {
public:
    explicit PylonActor(base_engine::Game* game);

    ~PylonActor() override;
    void Start() override;
    void Update() override;
};
