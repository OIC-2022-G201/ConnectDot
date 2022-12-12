#include "TitleListener.h"

#include "ButtonPressEvent.h"
#include "EventBus.h"
#include "EventHandler.h"

class TitleComponent::TitleListener final
    : public EventHandler<ButtonPressEvent> {
 public:
  void OnEvent(ButtonPressEvent& press) override;
};
void TitleComponent::TitleListener::OnEvent(ButtonPressEvent& press) {
  int n = 3;
}

TitleComponent::TitleComponent(base_engine::Actor* owner) : Component(owner) {}

void TitleComponent::Start() {
  listener_ = std::make_unique<TitleListener>();
  handle_ = EventBus::AddHandler(*listener_);
}
