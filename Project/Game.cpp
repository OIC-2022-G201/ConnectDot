#include "Game.h"

#include <Mof.h>
#include <Utilities/GraphicsUtilities.h>

#include "Actor.h"
#include "ButtonCommandEventContainer.h"
#include "IBaseEngineCollider.h"
#include "InputManager.h"
#include "ParentTest.h"
#include "RenderComponent.h"
#include "ResourceContainer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "ServiceLocator.h"
#include "StageSceneFactory.h"
#include "TitlePresenter.h"
#include "TitleSceneFactory.h"
base_engine::IBaseEngineCollider* b_collision;

namespace base_engine {

bool Game::Initialize() {
  game_data_.Register();
  scene::SceneManager::Instance().Register(this);
  button::ButtonCommandEventContainer::Instance().SetGame(this);
  //  auto inputActor = new base_engine::InputActor(this);
  //  auto input = new InputManager(inputActor);

  resource_container_ = std::make_shared<ResourceContainer>();
  resource_container_->Register();

  BASE_ENGINE(Collider)->SetCallBack(this);
  scene::LoadScene(scene::kTitle);
  // ParentTest test(this);
  // test.Main();
  b_collision = BASE_ENGINE(Collider);

  return true;
}

void Game::Update() {
  CreateObjectRegister();
  ProcessInput();
  UpdateGame();
  b_collision->Collide();
  if (g_pInput->IsKeyPush(MOFKEY_N)) {
    scene::LoadScene(scene::kGame);
  }
}

void Game::Shutdown() { Clear(); }

void Game::AddActor(Actor* actor) { AddActor(actor, scenes_.front()); }

void Game::AddActor(Actor* actor, const std::weak_ptr<Scene> scene) {
  actor_id_max_++;
  actor->id_.id = actor_id_max_;
  auto actor_ptr = ActorPtr{actor};
  pending_actors_.emplace_back(actor_ptr);
  scene.lock()->AddActor(actor_ptr);
  actor_ptr->SetScene(scene);
}

void Game::RemoveActor(Actor* actor) {
  if (const auto iter = std::ranges::find_if(
          actors_, [actor](const ActorPtr& n) { return n.get() == actor; });
      iter != actors_.end()) {
    const auto scene = actor->GetScene().lock();
    std::iter_swap(iter, actors_.end() - 1);

  	actors_next_frame_delete_.emplace_back(actors_.back());
    
  	actors_.pop_back();
    auto t = actors_next_frame_delete_.back().use_count();
    if (scene) scene->Sync();
  }
}

void Game::RemoveActor(Actor* actor, const std::weak_ptr<Scene> scene) {
  if (scene.expired()) return;
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
  for (auto&& actor : actors_next_frame_delete_)
  {
    actor.reset();
  }
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
  for (int i = 0; i < actors_.size(); ++i)
  {
    auto actor = actors_[i];
    if (actors_.empty()) break;
    actor->UpdateActor();

    if (clear_wait_actors_) {
      clear_wait_actors_ = false;
      break;
    }
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

void Game::Clear() {
  clear_wait_actors_ = true;
  pending_actors_.clear();
  actors_.clear();
  actors_next_frame_delete_.clear();
  debug_render_.clear();
  scenes_.clear();
}

void Game::AddScene(std::string_view name) {
  scenes_.emplace_back(std::make_shared<Scene>(this, 0, name));
}
void Game::AddScene(std::string_view name, const size_t index) {
  scenes_.emplace_back(std::make_shared<Scene>(this, scenes_.size(), name));
}

void Game::RemoveScene(Scene* scene) {
  if (const auto iter = std::ranges::find_if(
          scenes_, [scene](auto& n) { return n.get() == scene; });
      iter != scenes_.end()) {
    std::iter_swap(iter, scenes_.end() - 1);
    scenes_.pop_back();
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
Game::~Game() {}

}  // namespace base_engine