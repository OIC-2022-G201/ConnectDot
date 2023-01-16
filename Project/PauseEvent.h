// @PauseEvent.h
// @brief
// @author ICE
// @date 2023/01/16
//
// @details

#pragma once
#include "Event.h"

class PauseEvent : public Event {
  bool is_open_ = true;

 public:
  explicit PauseEvent(std::any& sender, const bool open)
      : Event(sender), is_open_(open) {}

  [[nodiscard]] bool IsOpen() const { return is_open_; }
  [[nodiscard]] bool IsClose() const { return !is_open_; }
};
