﻿#pragma once
#include <functional>
#include <memory>
#include <string_view>
#include <vector>

#include "BaseEngineCore.h"

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
  ActorWeakPtr FindTagActor(std::string_view tag);


  void AddSprite(class RenderComponent* render_component);
  void RemoveSprite(class RenderComponent* render_component);
  void Clear();
  void AddScene(std::string_view name);
  void AddScene(std::string_view name,const size_t index);

  void RemoveScene(Scene* scene);

  void SetNextFrameEvent(const std::function<void()>& event);

private:
  void CreateObjectRegister();
  void ProcessInput();
  void UpdateGame();
  std::vector<ActorWeakPtr> actor_id_cash_{1};
  std::vector<ActorPtr> actors_;
  std::vector<ActorPtr> actors_next_frame_delete_;
  std::vector<class RenderComponent*> sprites_;

  bool updating_actors_;
  bool clear_wait_actors_ = false;
  std::vector<ActorPtr> pending_actors_;

  uint64_t actor_id_max_ = 0;

  BaseEngineCore engine_;
  std::unique_ptr<GameManager> game_manager_;
  std::shared_ptr<ResourceContainer> resource_container_;
  std::vector<std::shared_ptr<Scene>> scenes_;
  std::vector<std::function<void()>> next_frame_event_;

 public:
  std::vector<std::function<void()>> debug_render_;
};
}  // namespace base_engine