// @VentGroupLocator.h
// @brief
// @author ICE
// @date 2023/01/19
//
// @details

#pragma once
#include <map>
#include <memory>
#include <vector>


class VentGroupLocator {
  using VentContainer = std::vector<std::weak_ptr<class VentActor>>;
  std::map<int, VentContainer> vent_group_map_;
 public:
  bool RegisterVent(int group, std::weak_ptr<VentActor> vent);
};
