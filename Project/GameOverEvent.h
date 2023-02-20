#pragma once
#include "Event.h"

class GameOverEvent:public Event
{
public:
	explicit GameOverEvent(std::any& sender) : Event(sender) {}
};