// @TitleListener.h
// @brief
// @author ICE
// @date 2022/12/09
//
// @details

#pragma once
#include "ButtonSelecter.h"
#include "Component.h"
#include "HandlerRegistration.h"

class TitleComponent final : base_engine::Component {
  class TitleListener;

 public:
  friend class TitleSceneFactory;

  explicit TitleComponent(base_engine::Actor* owner);

  void Start() override;
  void Update() override;

  struct Popup {
    TitleComponent* title;
    base_engine::Actor* popup_actor = nullptr;
    bool is_animation = false;
    std::unordered_map<std::string, base_engine::Actor*> elements{};
    base_engine::Vector2 size;
    void Hide();
    void Show();
  };

 private:
  void NewGameEvent();
  void StageSelect(std::string_view name);
  void OpenStageSelectPopup();
  void OpenKeyGuidePopup();
  void CloseStageSelectPopup();

  Popup main_popup_;
  Popup stage_select_popup_;
  Popup key_guide_popup_;
  base_engine::Actor* line_actor_;
  std::weak_ptr<base_engine::ImageComponent> line_;
  std::array<Popup*, 3> popups_ = {&main_popup_, &stage_select_popup_,
                                   &key_guide_popup_};
  int current_popup_ = 0;
  bool can_;
  std::unique_ptr<TitleListener> listener_;
  std::shared_ptr<HandlerRegistration> handle_;
};
