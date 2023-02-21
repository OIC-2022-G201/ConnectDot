// @IMachineActionable.h
// @brief
// @author ICE
// @date 2022/11/29
// 
// @details

#pragma once
#include "Actor.h"
__interface IMachineActionable {
	void Action(base_engine::Actor* actor);
	bool CanInteractive(base_engine::Actor* actor);
};
