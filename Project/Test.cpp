#include "Test.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "SpriteComponent.h"
#include "TexturePaths.h"
#include "IBaseEngineTexture.h"
#include "GridPosition.h"
using namespace base_engine;
	Test::Test(base_engine::Game* game) : Actor(game){}

	Test:: ~Test(){}

	void Test::Start() {
		{
			auto testSprite = new SpriteComponent(this, draw_order::kTestDrawOrder);
			testSprite->SetImage(BASE_ENGINE(Texture)->Get(texture::kTestTextureKey));
		}
		SetName("Test");
		SetPosition(GridPosition::GridTo({ 4,6 }));
	}
void Test::Update() {}
//ƒRƒƒ“ƒg
