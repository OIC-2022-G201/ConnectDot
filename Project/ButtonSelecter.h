#pragma once
#include <array>
#include <optional>

#include "Actor.h"
#include "IBaseEngineTexture.h"
#include "ImageComponent.h"
class InputManager;
class Button;

class ButtonSelecter : public base_engine::Actor {
 public:
  explicit ButtonSelecter(base_engine::Game* game);
  void ArrowSync();

  ~ButtonSelecter() override;

  void Start() override;

  void SetInput(InputManager* input_manager);

  void SetSelect(size_t now_select_x, size_t now_select_y);

  void ChangeHover();

  void ButtonRegister(size_t x_, size_t y_, Button* button);

  void CreateCursor(base_engine::TexturePtr image, size_t order = 100,const base_engine::Vector2& offset = {0,0});

  /// <summary>
  /// �L�[����ł̐��l�ύX
  /// </summary>
  void Update() override;

  void SelectorMove();

  /// <summary>
  /// �I�𒆂̃{�^���̎��s
  /// </summary>
  void ButtonSelect();
  void OnEnable() override;

  void OnDisable() override;
private:
  bool enable_ = true;
  std::weak_ptr<base_engine::ImageComponent> cursor_;
  std::array<std::array<Button*, 15>, 15> buttongroupe_ =
      std::array<std::array<Button*, 15>, 15>();
  int now_select_x_ = 0;
  int now_select_y_ = 0;
  int prev_x_ = 0;
  int prev_y_ = 0;
  InputManager* input_manager_;
  std::function<void()> on_enable_action_;
  std::function<void()> on_disable_action_;
};