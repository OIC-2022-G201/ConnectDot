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
using EventKey = std::string;
class ButtonCommandEventContainer {
  using EventHashType = std::hash<std::string>;
  std::unordered_map<size_t, std::function<void()>> event_map_;
  void Register();
  void RegisterKey(EventKey key, const std::function<void()>& action);
public:
  ButtonCommandEventContainer() { Register(); }

  void Execute(const EventKey& key) const {
    event_map_.at(EventHashType{}(key))();
  }
  static ButtonCommandEventContainer& Instance() {
    static auto instance = new ButtonCommandEventContainer;
    return *instance;
  }
};
using ButtonEvent = ButtonCommandEventContainer;
}  // namespace button
