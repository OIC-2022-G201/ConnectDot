#include "Game.h"

#include <Utilities/GraphicsUtilities.h>

#include "BaseEngineCollision.h"
#include "CollisionComponent.h"
#include "DebugStage.h"
#include "GameWindow.h"
#include "IBaseEngineEmpty.h"
#include "IBaseEngineTexture.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "PlayerActor.h"
#include "PylonActor.h"
#include "Rect.h"
#include "RenderComponent.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"

base_engine::IBaseEngineCollider* b_collision;
namespace base_engine {
bool Game::Initialize() {
  auto stageActor = new DebugStage(this);

  auto inputActor = new InputActor(this);
  auto input = new InputManager(inputActor);

  BASE_ENGINE(Texture)->Load("ice.png");
  BASE_ENGINE(Texture)->Load("Player.png");

  auto pylon = new PylonActor(this);
  auto player = new player::PlayerActor(this);
  player->SetInput(input);

  b_collision = BASE_ENGINE(Collider);
  return true;
}

void Game::Update() {
  CreateObjectRegister();
  ProcessInput();
  UpdateGame();
  b_collision->Collide();
}

void Game::Shutdown() {
  while (!actors_.empty()) {
    delete actors_.back();
  }
}

void Game::AddActor(Actor* actor) { pending_actors_.emplace_back(actor); }

void Game::RemoveActor(Actor* actor) {
  auto iter = std::find(actors_.begin(), actors_.end(), actor);
  if (iter != actors_.end()) {
    std::iter_swap(iter, actors_.end() - 1);
    actors_.pop_back();
  }
}

void Game::AddSprite(RenderComponent* render_component) {
  const int my_draw_order = render_component->GetDrawOrder();
  auto iter = sprites_.begin();
  for (; iter != sprites_.end(); ++iter) {
    if (my_draw_order < (*iter)->GetDrawOrder()) {
      break;
    }
  }

  sprites_.insert(iter, render_component);
}

void Game::RemoveSprite(RenderComponent* render_component) {
  auto iter = std::ranges::find(sprites_, render_component);
  sprites_.erase(iter);
}

void Game::CreateObjectRegister()
{
  updating_actors_ = true;
  for (auto pending : pending_actors_) {
    pending->StartActor();
    actors_.emplace_back(pending);
  }
  pending_actors_.clear();

  
  for (auto actor : actors_) {
    actor->AddComponent();
  }
    updating_actors_ = false;
}

void Game::ProcessInput() {
  updating_actors_ = true;
  for (const auto actor : actors_) {
    actor->ProcessInput();
  }
  updating_actors_ = false;
}

void Game::UpdateGame() {
  updating_actors_ = true;



  for (auto actor : actors_) {
    actor->UpdateActor();
  }
  updating_actors_ = false;

  std::vector<Actor*> dead_actors;
  for (auto actor : actors_) {
    if (actor->GetState() == Actor::kDead) {
      dead_actors.emplace_back(actor);
    }
  }
  for (const auto actor : dead_actors) {
    delete actor;
  }
}

void Game::Render() const {
  for (const auto sprite : sprites_) {
    sprite->Draw();
  }
  for (auto func : debug_render_) {
    func();
  }
  Mof::CGraphicsUtilities::RenderString(0, 0, MOF_COLOR_BLACK, "FPS:%d",
                                        Mof::CUtilities::GetFPS());
}

}  // namespace base_engine