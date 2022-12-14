#include "SceneManager.h"

#include "StageSceneFactory.h"
#include "TitleSceneFactory.h"

using namespace scene;
using namespace base_engine;
bool SceneManager::Register(Game* game) {
  game_ = game;
  factory_map_[kGame] = std::make_unique<StageSceneFactory>(game_);
  factory_map_[kTitle] = std::make_unique<TitleSceneFactory>(game_);

  return true;
}
