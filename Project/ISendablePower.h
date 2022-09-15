#pragma once
#include <vector>
class ReceiverComponent;
template <typename T>
concept SendablePower = requires(T& t, ReceiverComponent* r) {
  t.Sending(r);
};
class ISendablePower {
public:
    virtual ~ISendablePower() = default;
  void virtual Sending(class ReceiverComponent*) = 0;
};
