#include "EnemyActor.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "GridPosition.h"
#include "IBaseEngineTexture.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
using namespace base_engine;
using namespace draw_order;
EnemyActor::EnemyActor(base_engine::Game* game) : Actor(game) {}

EnemyActor::~EnemyActor() {}

void EnemyActor::Start() {
  {
      const auto sprite = new SpriteComponent(this, kEnemyDrawOrder);
    sprite->SetImage(BASE_ENGINE(Texture)->Get(texture::kEnemyTextureKey));
  }
  {
      
  }
  SetName("Enemy");
  SetPosition(GridPosition::GridTo({9,6}));
}

void EnemyActor::Update() {}

void EnemyActor::Create() {}
