#pragma once
#include "Event.h"

class QuitEvent :public Event
{
public:
	explicit QuitEvent(std::any& sender) : Event(sender) {}
};