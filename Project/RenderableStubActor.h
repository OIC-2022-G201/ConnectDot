// @file RenderableStubActor.h
// @brief
// @author ICE
// @date 2022/11/20
//
// @details

#pragma once
#include "Actor.h"
#include "LoadObjectParameter.h"

class RenderableStubActor final : public base_engine::Actor {
 public:
    explicit RenderableStubActor(base_engine::Game* game);

    void Create(const LoadObject& object);
};
