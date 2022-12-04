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

struct LoadObject;

class SignboardActor final : public base_engine::Actor
{
public:
    explicit SignboardActor(base_engine::Game* game);
    ~SignboardActor() override = default;
    void Start() override;

    void Update() override;

    void SetDisplayImage(base_engine::TexturePtr texture);
    void Create(const LoadObject& object);

private:
    base_engine::TexturePtr display_texture_ = nullptr;
    base_engine::SpriteComponent* display_ = nullptr;
};
