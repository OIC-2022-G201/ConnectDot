#pragma once
#include <functional>
#include <memory>
#include <vector>


#include "BaseEngineCore.h"
#include "GameData.h"

namespace base_engine {
    using ActorPtr = std::shared_ptr<class Actor>;
class Game {
  BaseEngineCore engine_;
  GameData game_data_;
 public:
  bool Initialize();
  void Update();
  void Render() const;
  void Shutdown();

  void AddActor(Actor* actor);
  void RemoveActor(Actor* actor);
  void AddSprite(class RenderComponent* render_component);
  void RemoveSprite(class RenderComponent* render_component);

 private:
  void CreateObjectRegister();
  void ProcessInput();
  void UpdateGame();

  std::vector<ActorPtr> actors_;
  std::vector<class RenderComponent*> sprites_;
  
  bool updating_actors_;
  std::vector<ActorPtr> pending_actors_;

 public:
  std::vector<std::function<void()>> debug_render_;
};
}  // namespace base_engine