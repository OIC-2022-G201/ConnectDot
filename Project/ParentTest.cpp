#include "ParentTest.h"

#include "Actor.h"
#include "Component.h"
#include "IBaseEngineTexture.h"
#include "InputManager.h"
#include "SpriteComponent.h"

using namespace base_engine;

class TestComponent : public Component {
 public:
  TestComponent(Actor* owner) : Component(owner) {}

  void ProcessInput() override {
    if (InputManager::Instance()->ButtonDecision()) {
      owner_->GetGame()->RemoveActor(owner_);
    }
  }
};

void ParentTest::Main() {
  new InputManager(new InputActor(game_));
  auto p1 = new Actor(game_);
  (new SpriteComponent(p1))->SetImage(BASE_ENGINE(Texture)->Get("no-texture.png"));
  auto p11 = new Actor(game_);
  (new SpriteComponent(p11))
      ->SetImage(BASE_ENGINE(Texture)->Get("no-texture.png"));
  p11->SetPosition({100, 0});
  new TestComponent(p1);
  p1->AddChild(p11->GetId());
}
