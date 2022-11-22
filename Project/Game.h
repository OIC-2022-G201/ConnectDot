#pragma once
#include <functional>
#include <memory>
#include <vector>

#include "BaseEngineCore.h"
#include "GameData.h"

namespace base_engine {
    struct ActorId;
    using ActorPtr = std::shared_ptr<class Actor>;
    using ActorWeakPtr = std::weak_ptr<class Actor>;
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

  ActorWeakPtr GetActor(ActorId id);
  void AddSprite(class RenderComponent* render_component);
  void RemoveSprite(class RenderComponent* render_component);

 private:
  void CreateObjectRegister();
  void ProcessInput();
  void UpdateGame();

  std::vector<ActorPtr> actors_;
  std::vector<ActorPtr> actors_next_frame_delete_;
  std::vector<class RenderComponent*> sprites_;

  bool updating_actors_;
  std::vector<ActorPtr> pending_actors_;

  uint64_t actor_id_max_ = 0;

 public:
  std::vector<std::function<void()>> debug_render_;
};
}  // namespace base_engine