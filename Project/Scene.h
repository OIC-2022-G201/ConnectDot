// @Scene.h
// @brief
// @author ICE
// @date 2022/12/15
//
// @details Actorを保有するコンテナクラス

#pragma once
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "Game.h"

namespace base_engine {
class Game;
using ActorWeakPtr = std::weak_ptr<class Actor>;
using ActorPtr = std::shared_ptr<class Actor>;

class Scene {
  std::string name_;
  std::vector<ActorWeakPtr> actors_;
  size_t index_ = 0;

 public:
  Scene(Game* game, const size_t index, const std::string_view name)
      : name_(name), index_(index), game_(game) {}

  void AddActor(const ActorPtr& actor) { actors_.emplace_back(actor); }

  void Sync() {
    const auto remove_it =
        std::ranges::remove_if(actors_, [](const ActorWeakPtr& actor) {
          return actor.expired();
        }).begin();
    actors_.erase(remove_it, actors_.end());
  }

  void Clear() const {
    for (const auto& actor : actors_) {
      if (actor.expired()) continue;
      game_->RemoveActor(actor.lock().get());
    }
  }
  void SetIndex(const size_t index) { index_ = index; }

  [[nodiscard]] size_t GetIndex() const { return index_; }
  void Remove() {
    Clear();
    game_->RemoveScene(this);
  }

 private:
  Game* game_ = nullptr;
};
}  // namespace base_engine
