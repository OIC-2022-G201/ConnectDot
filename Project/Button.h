#pragma once
#include "Actor.h"
#include "IBaseEngineTexture.h"
#include "ImageComponent.h"

class Button : public base_engine::Actor {
  base_engine::Vector2 camera_pos;

 public:
  explicit Button(base_engine::Game* game,int draw_order = 151);

  ~Button() override = default;

  void Start() override;

  void SetButtonSprite(base_engine::TexturePtr texture);

  void SetChangeButtonSprite(base_engine::TexturePtr texture);

  void SetEvent(const std::function<void()>& event);
  void SetHoverEvent(const std::function<void()>& event);

  void Update() override;

  /// <summary>
  /// ����{�^�������������̏���
  /// </summary>
  void OnPress();

  /// <summary>
  /// �{�^�����I�����ꂽ�ۂ̐F�t��
  /// </summary>
  void OnHover();

  /// <summary>
  /// �{�^�����I������Ă��Ȃ��ۂ̐F�t��
  /// </summary>
  void OutHover();

	/// <summary>
  /// �����I�Ƀz�o�[��Ԃ��ύX����B
  /// �C�x���g�͎��s����Ȃ�
  /// </summary>
  void SetHover(bool flg) const;

  void OnEnable() override { button_sprite_->SetEnabled(true); }
  void OnDisable() override { button_sprite_->SetEnabled(false); }

 private:
  std::vector<std::function<void()>> event_;
  std::vector<std::function<void()>> hover_event_;
  base_engine::TexturePtr button_texture_ = nullptr;
  base_engine::TexturePtr changebutton_texture_ = nullptr;
  base_engine::ImageComponent* button_sprite_ = nullptr;
};