// @file Object.h
// @brief 
// @author ICE
// @date 2022/09/25
// 
// @details

#pragma once
#include "ObjectID.h"

namespace base_engine
{
    class Object
    {
      ObjectId instance_id_;
    public:
      [[nodiscard]] ObjectId GetInstanceId() const { return instance_id_; }
    };
}
