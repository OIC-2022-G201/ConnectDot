#include "GameoverComponent.h"
#include "ResourceContainer.h"
using RC = ResourceContainer;
const float speed = 10;

void GameoverComponent::Start()
{
	logo_ = new base_engine::ImageComponent(owner_,101);
	const auto sprite_resource =
		RC::GetResource<RC::SpriteResourcePack, RC::Sprite>("GameoverLogo");
	logo_->SetImage(*sprite_resource);
	slide_ = -300;
}

void GameoverComponent::Update()
{
	if (slide_ + speed < 370)
		slide_ += speed;
	else
		slide_ = 370;

	owner_->SetPosition({ 356, slide_ });
}
