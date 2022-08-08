#pragma once
#include <vector>
template <typename T>
concept SendablePower = requires(T& t) {
  {
    t.GetTarget()
    } -> std::convertible_to<std::vector<class IReceivablePower*>>;
  t.Sending();
};
class ISendablePower {
public:
    virtual ~ISendablePower() = default;
    std::vector<class IReceivablePower*> virtual GetTarget() = 0;
  void virtual Sending() = 0;
};
