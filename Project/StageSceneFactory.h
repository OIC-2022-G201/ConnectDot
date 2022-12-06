// @StageSceneFactory.h
// @brief
// @author ICE
// @date 2022/12/06
// 
// @details

#pragma once
#include "ISceneFactory.h"

namespace base_engine
{
    class Game;
}

class StageSceneFactory : public ISceneFactory {
public:
    explicit StageSceneFactory(base_engine::Game* game)
        : game_(game)
    {
    }

    void Factory() override;
private:
    base_engine::Game* game_ = nullptr;
};
