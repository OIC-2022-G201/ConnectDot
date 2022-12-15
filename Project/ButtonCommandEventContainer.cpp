#include "ButtonCommandEventContainer.h"

#include "SceneManager.h"

void button::ButtonCommandEventContainer::Register() {
  RegisterKey("GameStartEvent", [] { scene::LoadScene(scene::kGame); });
}

void button::ButtonCommandEventContainer::RegisterKey(
    const EventKey key, const std::function<void()>& action) {
  event_map_[EventHashType{}(key)] = action;
}
