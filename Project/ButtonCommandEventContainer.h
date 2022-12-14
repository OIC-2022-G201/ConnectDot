// @ButtonCommandEventContainer.h
// @brief
// @author ICE
// @date 2022/12/15
//
// @details

#pragma once
#include <functional>
#include <unordered_map>
namespace button {
using EventKey = std::string_view;
class ButtonCommandEventContainer {
  std::unordered_map<EventKey, std::function<void()>> event_map_;
  void Register();

 public:
  ButtonCommandEventContainer() { Register(); }

  void Execute(const EventKey key) const { event_map_.at(key)(); }
  static ButtonCommandEventContainer& Instance() {
    static ButtonCommandEventContainer instance;
    return instance;
  }
};
}  // namespace button
