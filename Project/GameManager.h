// @GameManager.h
// @brief
// @author ICE
// @date 2022/12/03
// 
// @details

#pragma once
namespace base_engine
{
    class Game;
}

enum class GameState
{
    kNone,
    kInGame,
    kResult,
    kOutGame
};
class GameManager
{
  static GameManager* Instance()
  {
      return game_manager_;
  }


private:
  friend class base_engine::Game;
  inline static GameManager* game_manager_ = nullptr;
  GameManager() noexcept { game_manager_ = this; }
};