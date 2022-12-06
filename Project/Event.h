// @Event.h
// @brief
// @author ICE
// @date 2022/12/05
// 
// @details

#pragma once
#include <any>

class Event {
 public:

  explicit Event(std::any& sender) : sender_(sender), canceled_(false) {}

  virtual ~Event() = default;

  [[nodiscard]] std::any& GetSender() const { return sender_; }
  [[nodiscard]] bool GetCanceled() const { return canceled_; }
  void SetCanceled(const bool canceled) { this->canceled_ = canceled; }

 private:
  std::any& sender_;
  bool canceled_;
};
