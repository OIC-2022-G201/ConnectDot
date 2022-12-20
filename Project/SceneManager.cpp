#include "SceneManager.h"

#include "Scene.h"
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

bool SceneManager::SingleSceneLoad(const std::string_view name)
{
	game_->Clear();
  game_->AddScene(name,0);
	factory_map_[name]->Factory();
	return true;
}

bool SceneManager::AdditiveSceneLoad(const std::string_view name)
{
  game_->AddScene(name);
  factory_map_[name]->Factory();
  return true;
}
