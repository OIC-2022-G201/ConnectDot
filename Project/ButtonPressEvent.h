// @ButtonPressEvent.h
// @brief
// @author ICE
// @date 2022/12/09
// 
// @details

#pragma once
#include <string>

#include "Event.h"

class ButtonPressEvent : public Event {
 public:
  explicit ButtonPressEvent(std::any& sender,std::string_view name) : Event(sender),event_name_(name) {}
  std::string event_name_;

};
