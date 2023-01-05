#pragma once
#include "BeaconActor.h"
#include "Event.h"

class BeaconPowerUpActionEvent : public Event {
  bool is_end_;

 public:
  explicit BeaconPowerUpActionEvent(std::any& sender, bool end)
      : Event(sender), is_end_(end) {}

  bool IsEnd() const { return is_end_; }
};
