#include "GameOverComponent.h"

#include "PositionYTween.h"

void GameOverComponent::Start() {
  // Gameover ���S�� y ���W�� ���ݒn ���� 370 �� 0.5 �b�����Ĉړ�����A
  // �C�[�W���O���w��
  // �ړ���Ƀ{�^���̃A�j���[�V�������J�n����
  ma_tween::PositionYTween::Tween(logo_, 370, 0.5f)
      .SetEase(EaseType::kInexpo)
      .SetOnComplete([this] { ButtonsAnimation(); });
}
