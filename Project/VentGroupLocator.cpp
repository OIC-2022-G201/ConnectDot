#include "VentGroupLocator.h"

bool VentGroupLocator::RegisterVent(const int tag, const WeakVent& vent) {
  const auto mask = CalcVentMask(tag);

  if (!vent_group_map_.contains(mask.group)) {
    vent_group_map_.emplace(mask.group, VentContainer{});
  }
  vent_group_map_[mask.group].emplace(mask.index, vent);
  return true;
}

VentGroupLocator::VentData VentGroupLocator::GetVentData(const int tag) const {
  VentData result;
  const auto [group, index] = CalcVentMask(tag);

  if (const auto vent_container = vent_group_map_.find(group);
      vent_container != vent_group_map_.end()) {
    const auto itr = vent_container->second.find(index);
    const auto begin = vent_container->second.begin();
    const auto end = std::ranges::prev(vent_container->second.end());

    if (begin != itr)
      result.pre_vent = std::ranges::prev(itr, 1, begin)->second;
    if (end != itr) result.next_vent = std::ranges::next(itr, 1, end)->second;
  }
  return result;
}

VentGroupLocator::WeakVent VentGroupLocator::GetNextVent(const int tag) const {
  return GetVentData(tag).next_vent;
}

VentGroupLocator::WeakVent VentGroupLocator::GetPrevVent(const int tag) const {
  return GetVentData(tag).pre_vent;
}

VentGroupLocator::VentMask VentGroupLocator::CalcVentMask(const int tag) {
  const VentMask result{tag / 100, tag % 100};
  return result;
}
