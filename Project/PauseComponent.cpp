#include "PauseComponent.h"

#include "ComponentServiceLocator.h"
#include "EventBus.h"
#include "InputManager.h"
#include "PauseEvent.h"
#include "PauseManager.h"

void PauseComponent::Start()
{
  open_se_ = new base_engine::AudioStreamComponent(owner_);
  open_se_->AssetLoad("PauseSE");
  open_se_->SetVolume(0.5f);
}

void PauseComponent::Update() {
  if (InputManager::Instance()->PauseFire()) {
    std::any sender = this;
    open_se_->Play(); 
    PauseEvent e{
        sender,
        !static_cast<bool>(
            ServiceLocator::Instance().Resolve<PauseManager>()->IsOpen())};
    EventBus::FireEvent(e);
  }
}
