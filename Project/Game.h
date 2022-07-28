#pragma once
#include "Vector.h"
#include <vector>
#include <Graphics/CameraBase.h>

#include "BaseEngineCore.h"

namespace base_engine {
class Game {
  BaseEngineCore engine_;
 public:
  bool Initialize();
  void Update();
  void Render() const;
  void Shutdown();

  void AddActor(class Actor* actor);
  void RemoveActor(class Actor* actor);
  void AddSprite(class RenderComponent* render_component);
  void RemoveSprite(class RenderComponent* render_component);

 private:
  void ProcessInput();
  void UpdateGame();

  std::vector<class Actor*> actors_;
  std::vector<class RenderComponent*> sprites_;
  
  bool updating_actors_;
  std::vector<class Actor*> pending_actors_;

 public:
};
}  // namespace base_engine