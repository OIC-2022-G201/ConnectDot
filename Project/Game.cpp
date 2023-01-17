#include "Game.h"

#include <Mof.h>
#include <Utilities/GraphicsUtilities.h>

#include "Actor.h"
#include "ButtonCommandEventContainer.h"
#include "ComponentServiceLocator.h"
#include "GameData.h"
#include "IBaseEngineCollider.h"
#include "IBaseEngineRender.h"
#include "InputManager.h"
#include "ITransitionFadeSystem.h"
#include "ParentTest.h"
#include "ReleaseInfo.h"
#include "RenderComponent.h"
#include "ResourceContainer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "ShaderTest01.h"
#include "StageSceneFactory.h"
#include "TitlePresenter.h"
#include "TitleSceneFactory.h"
#include "TransitionParameter.h"
base_engine::IBaseEngineCollider* b_collision;

namespace base_engine {

bool Game::Initialize() {
  BASE_ENGINE(Render)->Initialize();
	{
		std::unique_ptr<GameData> game_data;

  	game_data = std::make_unique<GameData>(this);
  	game_data->Register();
	}
  actors_.reserve(1024);
  scene::SceneManager::Instance().Register(this);
  button::ButtonCommandEventContainer::Instance().SetGame(this);
  //  auto inputActor = new base_engine::InputActor(this);
  //  auto input = new InputManager(inputActor);

  resource_container_ = std::make_shared<ResourceContainer>();
  resource_container_->Register();

  BASE_ENGINE(Collider)->SetCallBack(this);
  ServiceLocator::Instance().Resolve<ITransitionFadeSystem>()->SceneTransition(
      scene::kTitle, kGameToTitleFadeIn, kGameToTitleFadeOut);
  //ShaderTest01 test(this);
  //test.Main();
  b_collision = BASE_ENGINE(Collider);

  return true;
}

void Game::Update() {
  CreateObjectRegister();
  ProcessInput();
  UpdateGame();
  b_collision->Collide();
  if (g_pInput->IsKeyPush(MOFKEY_N)) {
    ServiceLocator::Instance()
        .Resolve<ITransitionFadeSystem>()
        ->SceneTransition(scene::kGame, kGameToGameFadeIn, kGameToGameFadeOut);
  }
  if (g_pInput->IsKeyPush(MOFKEY_B))
  {
    g_pGraphics->SetScreenMode(false);
  }
  if (g_pInput->IsKeyPush(MOFKEY_V)) {
    g_pGraphics->SetScreenMode(true);
  }
}

void Game::Shutdown() { Clear(); }

void Game::AddActor(Actor* actor) {
  AddActor(actor, scenes_.empty() ? std::weak_ptr<Scene>{} : scenes_.front());
}

void Game::AddActor(Actor* actor, const std::weak_ptr<Scene> scene) {
  actor_id_max_++;
  actor->id_.id = actor_id_max_;
  auto actor_ptr = ActorPtr{actor};
  actor_id_cash_.emplace_back(actor_ptr);
  pending_actors_.emplace_back(actor_ptr);
  if (!scene.expired()) scene.lock()->AddActor(actor_ptr);
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
  if (actor_id_max_ < id.id) return ActorPtr{};
  return actor_id_cash_[id.id];
  return ActorPtr{};
}

ActorWeakPtr Game::FindTagActor(std::string_view tag) {
  if (const auto iter = std::ranges::find_if(
          actors_, [tag](const ActorPtr& n) { return n->GetTag() == tag; });
      iter != actors_.end()) {
    return *iter;
  }

  if (const auto iter = std::ranges::find_if(
          pending_actors_,
          [tag](const ActorPtr& n) { return n->GetTag() == tag; });
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
  for (int i = 0; i < next_frame_event_.size(); ++i) {
    next_frame_event_[i]();
  }
  next_frame_event_.clear();

  updating_actors_ = true;
  for (int i = 0; i < actors_next_frame_delete_.size(); ++i) {
    if (auto& actor = actors_next_frame_delete_[i]) actor.reset();
  }
  for (auto&& actor : actors_next_frame_delete_) {
    if (actor) actor.reset();
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
  for (int i = 0; i < actors_.size(); ++i) {
    auto actor = actors_[i];
    if (actors_.empty()) break;
    if (actor->Enable()) actor->UpdateActor();

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

void Game::SetNextFrameEvent(const std::function<void()>& event) {
  next_frame_event_.emplace_back(event);
}

void Game::Render() const {
  BASE_ENGINE(Render)->Begin();
  for (const auto sprite : sprites_) {
    // if (sprite->GetOwner().expired()) continue
    const auto owner = sprite->GetOwner();
    ;
    if (owner.expired() || !owner.lock()->Enable()) continue;
    if (sprite->GetEnabled()) sprite->Draw();
  }
  if (kStatusRenderMode) {
    for (auto& func : debug_render_) {
      func();
    }
    Mof::CGraphicsUtilities::RenderString(0, 0, MOF_COLOR_BLACK, "FPS:%d",
                                          Mof::CUtilities::GetFPS());
  }
  BASE_ENGINE(Render)->End();
}
Game::~Game() {}

}  // namespace base_engine