#pragma once
#include <vector>
class ReceiverComponent;
template <typename T>
concept SendablePower = requires(T& t) {
  t.CanSending();
};
class ISendablePower {
public:
    virtual ~ISendablePower() = default;
    bool virtual CanSending() = 0;
};
