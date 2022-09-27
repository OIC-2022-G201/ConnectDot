// @file SignboardActor.h
// @brief 
// @author ICE
// @date 2022/09/20
// 
// @details

#pragma once
#include <string_view>

#include "Actor.h"
#include "IBaseEngineTexture.h"
#include "SpriteComponent.h"

class SignboardActor final : public base_engine::Actor
{
public:
    explicit SignboardActor(base_engine::Game* game);
    ~SignboardActor() override{}
    void Start() override;

    void Update() override;

    void SetDisplayImage(base_engine::TexturePtr texture);

private:
    base_engine::TexturePtr display_texture_ = nullptr;
    base_engine::SpriteComponent* display_ = nullptr;
};
