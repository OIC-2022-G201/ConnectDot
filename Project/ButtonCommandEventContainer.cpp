﻿#include "ButtonCommandEventContainer.h"

#include "EventBus.h"
#include "SceneManager.h"
#include <windows.h>
void button::ButtonCommandEventContainer::Register() {
  RegisterKey("GameStartEvent", [] { scene::LoadScene(scene::kGame); });
  RegisterKey("QuitGameEvent", [this] { PostQuitMessage(0); });
}

void button::ButtonCommandEventContainer::RegisterKey(
    const EventKey key, const std::function<void()>& action) {
  event_map_[EventHashType{}(key)] = action;
}
