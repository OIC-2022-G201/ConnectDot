#pragma once
#include <functional>
#include <memory>
#include <vector>

#include "BaseEngineCore.h"
#include "GameData.h"
#include "GameManager.h"

class ResourceContainer;

namespace base_engine {
	class Scene;
	struct ActorId;
using ActorPtr = std::shared_ptr<class Actor>;
using ActorWeakPtr = std::weak_ptr<class Actor>;
class Game {
 public:
  ~Game();
  bool Initialize();
  void Update();
  void Render() const;
  void Shutdown();

  void AddActor(Actor* actor);
  void AddActor(Actor* actor, const std::weak_ptr<Scene> scene);
  void RemoveActor(Actor* actor);
  void RemoveActor(Actor* actor, const std::weak_ptr<Scene> scene);

  ActorWeakPtr GetActor(ActorId id);
  void AddSprite(class RenderComponent* render_component);
  void RemoveSprite(class RenderComponent* render_component);
  void Clear();
  void AddScene(std::string_view name);
  void AddScene(std::string_view name,const size_t index);

  void RemoveScene(Scene* scene);
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

  BaseEngineCore engine_;
  GameData game_data_;
  std::unique_ptr<GameManager> game_manager_;
  std::shared_ptr<ResourceContainer> resource_container_;
  std::vector<std::shared_ptr<Scene>> scenes_;
 public:
  std::vector<std::function<void()>> debug_render_;
};
}  // namespace base_engine