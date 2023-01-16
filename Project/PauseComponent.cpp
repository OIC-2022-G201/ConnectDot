#include "PauseComponent.h"

#include "ComponentServiceLocator.h"
#include "EventBus.h"
#include "InputManager.h"
#include "PauseEvent.h"
#include "PauseManager.h"

void PauseComponent::Update()
{
  if (InputManager::Instance()->PauseFire()) {
    std::any sender = this;
    PauseEvent e{sender, is_pause_};
    EventBus::FireEvent(e);
    is_pause_ = !is_pause_;
  }
}
