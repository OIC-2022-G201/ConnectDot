#include "EventRegister.h"

#include "EventBus.h"
#include "GoalEvent.h"
#include <any>
class EventRegister::Impl {
  
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
