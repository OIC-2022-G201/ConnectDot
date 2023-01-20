#include "VentGroupLocator.h"

bool VentGroupLocator::RegisterVent(int group, std::weak_ptr<VentActor> vent)
{
  if(!vent_group_map_.contains(group))
  {
    vent_group_map_.emplace(group, VentContainer{});
  }
  vent_group_map_[group].emplace_back(vent);
  return true;
}
