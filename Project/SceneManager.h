// @SceneManager.h
// @brief
// @author ICE
// @date 2022/12/15
//
// @details

#pragma once
#include <string_view>
#include <unordered_map>

#include "Game.h"
#include "ISceneFactory.h"

// TODO レベルファイルを読み込み、シーンを生成できるようにする
namespace scene {
constexpr std::string_view kTitle = "Title";
constexpr std::string_view kGame = "Game";

/**
 * \brief Used to load a Scene in a player.
 */
enum class LoadSceneMode
{
	/**
	 * \brief Clear all current loaded Scenes and loads a Scene.
	 */
	kSingle,
	/**
	 * \brief Adds the Scene to the current loaded Scenes.
	 */
	kAdditive
};

class SceneManager {
  base_engine::Game* game_ = nullptr;
  std::unordered_map<std::string_view, std::unique_ptr<ISceneFactory>>
      factory_map_;

 public:
  static SceneManager& Instance() {
    static SceneManager instance;
    return instance;
  }

  bool Register(base_engine::Game* game);

  bool LoadScene(const std::string_view name) {
    if (!game_) return false;

    game_->Clear();
    factory_map_[name]->Factory();
    return true;
  }

  bool LoadScene(const std::string_view name,LoadSceneMode mode)
  {
    if (!game_) return false;

    game_->Clear();
    factory_map_[name]->Factory();
    return true;
  }
};

inline bool LoadScene(const std::string_view name) {
  return SceneManager::Instance().LoadScene(name);
}
}  // namespace scene