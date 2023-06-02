#include "GameOverComponent.h"

#include "PositionYTween.h"

void GameOverComponent::Start() {
  // Gameover ロゴの y 座標を 現在地 から 370 に 0.5 秒かけて移動する、
  // イージングを指定
  // 移動後にボタンのアニメーションを開始する
  ma_tween::PositionYTween::Tween(logo_, 370, 0.5f)
      .SetEase(EaseType::kInexpo)
      .SetOnComplete([this] { ButtonsAnimation(); });
}
