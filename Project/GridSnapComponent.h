// @file GridSnapComponent.h
// @brief
// @author ICE
// @date 2022/08/20
//
// @details

#pragma once
#include "Component.h"
#include "ConnectDotUpdateOrder.h"
#include "GridPosition.h"
#include "Vector.h"
#include "YesNo.h"

namespace grid {
using AutoSnap = base_engine::YesNo<struct YNAutoSnap>;
class GridSnapComponent final : public base_engine::Component {
 public:
  GridSnapComponent& SetSnapGridPosition(const GridPosition& position);
  GridSnapComponent& SetAutoSnap(AutoSnap snap);

 public:
  explicit GridSnapComponent(base_engine::Actor* owner,
                             int update_order = component_update::kGridSnap);
  void Update() override;

 private:
  AutoSnap auto_snap_ = AutoSnap::Yes;
};
}  // namespace grid