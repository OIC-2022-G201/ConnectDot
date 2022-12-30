#pragma once
#include "Actor.h"
#include "IBaseEngineTexture.h"
#include "ImageComponent.h"

class Button : public base_engine::Actor {
  base_engine::Vector2 camera_pos;

 public:
  explicit Button(base_engine::Game* game);

  ~Button() override = default;

  void Start() override;

  void SetButtonSprite(base_engine::TexturePtr texture);

  void SetChangeButtonSprite(base_engine::TexturePtr texture);

  void SetEvent(std::function<void()>);

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

  void OnEnable() override { button_sprite_->SetEnabled(true); }
  void OnDisable() override { button_sprite_->SetEnabled(false); }

 private:
  std::function<void()> event_;
  base_engine::TexturePtr button_texture_ = nullptr;
  base_engine::TexturePtr changebutton_texture_ = nullptr;
  base_engine::ImageComponent* button_sprite_ = nullptr;
};