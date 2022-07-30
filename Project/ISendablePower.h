#pragma once
#include <vector>

class ISendablePower {
  std::vector< class IReceivablePower* > virtual GetTarget() = 0;
  void virtual Sending() = 0;
};
