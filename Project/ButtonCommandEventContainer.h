// @ButtonCommandEventContainer.h
// @brief
// @author ICE
// @date 2022/12/15
//
// @details

#pragma once
#include <functional>
#include <unordered_map>

#include "Game.h"

namespace button {
using EventKey = std::string;
class ButtonCommandEventContainer {
  using EventHashType = std::hash<std::string>;
  std::unordered_map<size_t, std::function<void()>> event_map_;
  void Register();
  void RegisterKey(const EventKey& key, const std::function<void()>& action);
  base_engine::Game* game_;

 public:
  ButtonCommandEventContainer() { Register(); }

  void Execute(const EventKey& key) const {
    const auto hash = EventHashType{}(key);
    if (!event_map_.contains(hash)) return;
    event_map_.at(hash)();
  }
  static ButtonCommandEventContainer& Instance() {
    static auto instance = new ButtonCommandEventContainer;
    return *instance;
  }
  void SetGame(base_engine::Game* game) { game_ = game; }
};
using ButtonEvent = ButtonCommandEventContainer;
}  // namespace button
