// @HandlerRegistration.h
// @brief
// @author ICE
// @date 2022/12/05
//
// @details

#pragma once
class HandlerRegistration {
 public:
  virtual ~HandlerRegistration() {}

  virtual void removeHandler() = 0;
};