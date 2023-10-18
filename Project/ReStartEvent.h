#pragma once
#include "Event.h"

class ReStartEvent:public Event
{
public:
	explicit ReStartEvent(std::any& sender) : Event(sender) {}
};