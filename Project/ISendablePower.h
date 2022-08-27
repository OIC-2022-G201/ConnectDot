#pragma once
#include <vector>
#include "IReceivablePower.h"

template <typename T>
concept SendablePower = requires(T& t) {
  {
    t.GetTarget()
    } -> std::convertible_to<std::vector<IReceivablePower*>>;
  t.Sending();
};
class ISendablePower {
public:
    virtual ~ISendablePower() = default;
    std::vector<IReceivablePower*> virtual GetTarget() = 0;
  void virtual Sending() = 0;
  bool virtual CanSending() = 0;
};
