#include "GameOverComponent.h"
#include "PositionYTween.h"

void GameOverComponent::Start()
{
	ma_tween::PositionYTween::TweenLocalPositionY(logo_, 370, 0.5f).SetOnComplete([this] {ButtonsAnimation(); });
}
