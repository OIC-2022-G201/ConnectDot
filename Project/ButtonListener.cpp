#include "ButtonListener.h"

#include "ButtonCommandEventContainer.h"
#include "EventBus.h"

ButtonListener::ButtonListener(base_engine::Actor* owner) : Component(owner) {}

void ButtonListener::Start() {
  this->event_handler_ = EventBus::AddHandler(*this);
}

void ButtonListener::OnEvent(ButtonPressEvent& press) {
  button::ButtonEvent::Instance().Execute(press.event_name_);
}
