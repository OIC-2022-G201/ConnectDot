#include "Game.h"

#include <Utilities/GraphicsUtilities.h>

#include "Button.h"
#include "ButtonSelecter.h"
#include "CameraComponent.h"
#include "CollisionComponent.h"
#include "DebugStage.h"
#include "EnemyActor.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "ObjectLoader.h"
#include "PlayerActor.h"
#include "PowerSupplyUnitActor.h"
#include "PylonActor.h"
#include "RenderComponent.h"
#include "SignboardActor.h"
#include "TexturePaths.h"

base_engine::IBaseEngineCollider* b_collision;
namespace base_engine {
bool Game::Initialize() {
  game_data_.Register();
  BASE_ENGINE(Collider)->SetCallBack(this);
  auto camera = new Actor(this);
  new CameraComponent(camera);

  auto stageActor = new DebugStage(this);

  auto inputActor = new InputActor(this);
  auto input = new InputManager(inputActor);

  auto pylon = new PylonActor(this);
  auto player = new player::PlayerActor(this);
  player->SetInput(input);
  player->SetCamera(camera);

  ObjectLoader object_loader{this};
  object_loader.Load("MapData/Stage1");

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
  actors_.clear();
  actors_next_frame_delete_.clear();
}

void Game::AddActor(Actor* actor) {
  actor_id_max_++;
  actor->id_.id = actor_id_max_;
  pending_actors_.emplace_back(actor);
}

void Game::RemoveActor(Actor* actor) {
  if (const auto iter = std::ranges::find_if(
          actors_, [actor](const ActorPtr& n) { return n.get() == actor; });
      iter != actors_.end()) {
    std::iter_swap(iter, actors_.end() - 1);
    actors_.pop_back();
  }
}

ActorWeakPtr Game::GetActor(ActorId id) {
  if (const auto iter = std::ranges::find_if(
          actors_, [id](const ActorPtr& n) { return n->GetId() == id; });
      iter != actors_.end()) {
    return *iter;
  }

  if (const auto iter = std::ranges::find_if(
          pending_actors_,
          [id](const ActorPtr& n) { return n->GetId() == id; });
      iter != pending_actors_.end()) {
    return *iter;
  }
  return ActorPtr{};
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

void Game::CreateObjectRegister() {
  updating_actors_ = true;
  actors_next_frame_delete_.clear();

  for (int i = 0; i < pending_actors_.size(); ++i) {
    pending_actors_[i]->StartActor();
    actors_.emplace_back(pending_actors_[i]);
  }
  pending_actors_.clear();

  for (auto&& actor : actors_) {
    actor->AddComponent();
  }
  updating_actors_ = false;
}

void Game::ProcessInput() {
  updating_actors_ = true;
  for (const auto& actor : actors_) {
    actor->ProcessInput();
  }
  updating_actors_ = false;
}

void Game::UpdateGame() {
  updating_actors_ = true;

  for (const auto& actor : actors_) {
    actor->UpdateActor();
  }
  updating_actors_ = false;

  std::vector<ActorPtr> dead_actors;
  for (const auto& actor : actors_) {
    if (actor->GetState() == Actor::kDead) {
      dead_actors.emplace_back(actor);
    }
  }
  for (auto&& actor : dead_actors) {
    actor.reset();
  }
}

void Game::Render() const {
  for (const auto sprite : sprites_) {
    if (sprite->GetEnabled()) sprite->Draw();
  }
  for (auto& func : debug_render_) {
    func();
  }
  Mof::CGraphicsUtilities::RenderString(0, 0, MOF_COLOR_BLACK, "FPS:%d",
                                        Mof::CUtilities::GetFPS());
}

}  // namespace base_engine