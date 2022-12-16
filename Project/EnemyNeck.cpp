#include "EnemyNeck.h"

#include "DrawOrder.h"
#include "BaseEngineCore.h"
#include "IBaseEngineTexture.h"
#include "TexturePaths.h"
#include "VectorUtilities.h"

namespace enemy
{
	void EnemyNeck::Start()
	{
		sprite_ = new SpriteComponent(this, draw_order::kEnemyNeckDrawOrder);
		sprite_->SetImage(BASE_ENGINE(Texture)->Get(texture::kEnemyNeckTextureKey));
	}

	void EnemyNeck::Update()
	{
		auto ne = body_pos_ - head_pos_;
		auto length = std::abs(VectorUtilities::Length(ne));
		sprite_->SetOffset(head_pos_);
		sprite_->SetClipRect({ 0,0,length,27 });
		sprite_->SetAngle(std::atan2(ne.y, ne.x));
	}

}
