// @Scene.h
// @brief
// @author ICE
// @date 2022/12/15
//
// @details Actorを保有するコンテナクラス

#pragma once
#include <memory>
#include <string>
#include <vector>

namespace base_engine {
using ActorWeakPtr = std::weak_ptr<class Actor>;
using ActorPtr = std::shared_ptr<class Actor>;

class Scene {
  std::string name_;
  std::vector<ActorWeakPtr> actors_;

 public:
  void AddActor(const ActorPtr& actor) {
    
    actors_.emplace_back(actor);
  }
};
}  // namespace base_engine
