// @file DIActorContainer.cpp
// @brief 
// @author ICE
// @date 2022/11/20
// 
// @details
#include "DIActorContainer.h"
std::map<size_t, DiActorContainer::ActorCreateFunc>
    DiActorContainer::container_{};