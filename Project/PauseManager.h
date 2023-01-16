// @PauseManager.h
// @brief
// @author ICE
// @date 2023/01/16
//
// @details

#pragma once
#include "Game.h"
#include "HandlerRegistration.h"
#include "ReactiveProperty.h"

class PauseManager {
  class PauseListener;

 public:
  explicit PauseManager(base_engine::Game* game);
  ~PauseManager();
  auto&& IsOpen()  { return is_open_.ToReadOnly(); }

 private:
  observable::ReactiveProperty<bool> is_open_ = false;

  std::unique_ptr<PauseListener> listener_;
  std::vector<std::shared_ptr<HandlerRegistration>> event_handlers_;
  base_engine::Game* game_ = nullptr;
};
