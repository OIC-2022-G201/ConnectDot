#include "testActor.h"
#include "SpriteComponent.h"
#include "DrawOrder.h"
#include "BaseEngineCore.h"
#include "IBaseEngineTexture.h"
#include "TexturePaths.h"

testActor::testActor(base_engine::Game* game) :Actor(game) {}	//:�ȍ~�͊��N���X�̃R���X�g���N�^�̈���
testActor::~testActor() {}

void testActor::Start() {
	auto testSprite = new base_engine::SpriteComponent(this, draw_order::kTestDrawOrder);
	testSprite->SetImage(BASE_ENGINE(Texture)->Get(texture::kTestTextureKey));
}

void testActor::Update() {}