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
  /// 決定ボタンを押した時の処理
  /// </summary>
  void OnPress();

  /// <summary>
  /// ボタンが選択された際の色付け
  /// </summary>
  void OnHover();

  /// <summary>
  /// ボタンが選択されていない際の色付け
  /// </summary>
  void OutHover();

	/// <summary>
  /// 強制的にホバー状態か変更する。
  /// イベントは実行されない
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