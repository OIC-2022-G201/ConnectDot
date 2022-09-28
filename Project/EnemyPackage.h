// @file EnemyPackage.h
// @brief 
// @author ICE
// @date 2022/09/27
// 
// @details

#pragma once
#include "ResourcePack.h"

struct EnemyPackage
{
    
    
};

void Test()
{
  asset_system::Resource<EnemyPackage> resorce;
  resorce.Register(1, EnemyPackage());
}