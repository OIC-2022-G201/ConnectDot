#include "Game.h"

#include <Utilities/GraphicsUtilities.h>

#include "BaseEngineCollision.h"
#include "CollisionComponent.h"
#include "IBaseEngineEmpty.h"
#include "IBaseEngineTexture.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "PlayerActor.h"
#include "Rect.h"
#include "RenderComponent.h"
#include "ShapeRenderComponent.h"
#include "SpriteComponent.h"

base_engine::IBaseEngineCollider* b_collision;
namespace base_engine {
bool Game::Initialize() {
  auto inputActor = new InputActor(this);
  auto input = new InputManager(inputActor);

  Actor* a = new Actor(this);
  a->SetPosition({0, 0});
  a->SetScale(1.0f);
  BASE_ENGINE(Texture)->Load("ice.png");
  BASE_ENGINE(Texture)->Load("Player.png");
  // Mof::CTexture texture;
  // texture.Load("ice.png");
  /*
  auto sc = new SpriteComponent(a, 100);
  sc->SetImage(BASE_ENGINE(Texture)->Get("ice.png"));
  auto collision = new CollisionComponent(a, 100);
  const auto shape_block = std::make_shared<Rect>(100, 100, 200, 200);
  collision->SetShape(shape_block);
  a->SetTag("Block");
  auto shape = new ShapeRenderComponent(a, 100);
  shape->SetShape(shape_block);
  a = new Actor(this);
  a->SetPosition({200, 3});
  a->SetScale(1.0f);
  sc = new SpriteComponent(a, 80);
  sc->SetImage(BASE_ENGINE(Texture)->Get("ice.png"));
  */
  auto player = new PlayerActor(this);
  player->SetInput(input);

  auto collision = new ShapeRenderComponent(a, 100);
  const auto shape_player = std::make_shared<Rect>(0, 1080-230, 1920, 1081);
  collision->SetShape(shape_player);

  collision = new ShapeRenderComponent(a, 100);
  collision->SetShape(std::make_shared<Rect>(0, 1080 - 30, 1920, 1081));
  auto playerSprite = new SpriteComponent(player, 100);
  playerSprite->SetImage(BASE_ENGINE(Texture)->Get("Player.png"));
  b_collision = BASE_ENGINE(Collider);
  return true;
}

void Game::Update() {
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

void Game::ProcessInput() {
  updating_actors_ = true;
  for (const auto actor : actors_) {
    actor->ProcessInput();
  }
  updating_actors_ = false;
}

void Game::UpdateGame() {
  updating_actors_ = true;

  for (auto pending : pending_actors_) {
    pending->StartActor();
    actors_.emplace_back(pending);
  }
  pending_actors_.clear();

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
  Mof::CGraphicsUtilities::RenderString(0, 0, MOF_COLOR_BLACK, "FPS:%d",
                                        Mof::CUtilities::GetFPS());
}

}  // namespace base_engine