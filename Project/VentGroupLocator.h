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
  using WeakVent = std::weak_ptr<base_engine::Actor>;
  using VentContainer = std::map<int, WeakVent>;

 public:
  struct VentData {
    WeakVent pre_vent = {};
    WeakVent next_vent = {};
  };

  bool RegisterVent(int tag, const WeakVent& vent);
  [[nodiscard]] VentData GetVentData(int tag) const;
  [[nodiscard]] WeakVent GetNextVent(int tag) const;
  [[nodiscard]] WeakVent GetPrevVent(int tag) const;

 private:
  struct VentMask {
    int group;
    int index;
  };
  static VentMask CalcVentMask(const int tag);
  std::map<int, VentContainer> vent_group_map_;
};
