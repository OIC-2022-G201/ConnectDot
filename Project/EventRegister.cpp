#include "EventRegister.h"

#include "EventBus.h"
#include "GoalEvent.h"
#include "PlayerListener.h"
#include <any>
class EventRegister::Impl {
  PlayerListener player_listener_;

 public:
  void Register()
  {

  }
};

EventRegister::EventRegister()
{
    impl_ = std::make_shared<Impl>();
}

void EventRegister::Register() const { impl_->Register(); }
