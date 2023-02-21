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

#include "Actor.h"

class VentGroupLocator {
  using VentKey = std::string;
  using WeakVent = std::weak_ptr<base_engine::Actor>;
  using VentContainer = std::map<VentKey, WeakVent>;

public:
  bool RegisterVent(VentKey tag, const WeakVent& vent);
  void Clear();;
  [[nodiscard]] WeakVent GetVentData(VentKey tag) const;

 private:
  VentContainer vent_container_;
};
