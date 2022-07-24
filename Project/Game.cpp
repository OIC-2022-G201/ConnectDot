#include "Game.h"

#include <Utilities/GraphicsUtilities.h>

#include "IBaseEngineEmpty.h"
#include "IBaseEngineTexture.h"
#include "RenderComponent.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "PlayerActor.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"

namespace base_engine {
bool Game::Initialize() {
  auto inputActor = new InputActor(this);
  auto input = new InputManager(inputActor);

  Actor* a = new Actor(this);
  a->SetPosition({3, 3});
  a->SetScale(1.0f);
  auto sc = new SpriteComponent(a, 100);
  BASE_ENGINE(Texture)->Load("ice.png");
  sc->SetImage(BASE_ENGINE(Texture)->Get("ice.png"));

  a = new Actor(this);
  a->SetPosition({200, 3});
  a->SetScale(1.0f);
  sc = new SpriteComponent(a, 80);
  sc->SetImage(BASE_ENGINE(Texture)->Get("ice.png"));


  auto player = new PlayerActor(this);
  player->SetInput(input);
  auto shape = new ShapeRenderComponent(player, 110);
  shape->CreateRect(0, 0, 50, 50);
  shape->SetFillMode(FillMode::Yes).SetColor(MOF_COLOR_GREEN);
    return true;
}

void Game::Update() {
  ProcessInput();
  UpdateGame();
}

void Game::Shutdown() {
  while (!actors_.empty()) {
    delete actors_.back();
  }
}

void Game::AddActor(Actor* actor) { actors_.emplace_back(actor); }

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

  for (auto pending : pending_actors_) {
    pending->StartActor();
    actors_.emplace_back(pending);
  }
  pending_actors_.clear();

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
}

}  // namespace base_engine