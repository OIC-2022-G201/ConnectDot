#include "VentGroupLocator.h"

bool VentGroupLocator::RegisterVent(const VentKey tag, const WeakVent& vent) {
  vent_container_.emplace(tag, vent);
  return true;
}

VentGroupLocator::WeakVent VentGroupLocator::GetVentData(
    const VentKey tag) const {
  const auto result = vent_container_.find(tag);
  if (result==vent_container_.end())
  {
    return WeakVent{};
  }
  return result->second;
}
