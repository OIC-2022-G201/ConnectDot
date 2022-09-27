// @file WeakRefObject.h
// @brief
// @author ICE
// @date 2022/09/27
//
// @details

#pragma once
#include "Object.h"
#include "ObjectID.h"
namespace base_engine {
class Object;

class WeakRefObject {
  ObjectId ref_{};
  Object *instance_ = nullptr;
  

 public:

  explicit WeakRefObject(Object *p_object);
};
}  // namespace base_engine
