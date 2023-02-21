// @Part.h
// @brief
// @author ICE
// @date 2023/02/22
//
// @details

#pragma once
#include <variant>

#include "BeaconStackPart.h"
#include "ChangeImageNamePart.h"
#include "DirPart.h"
#include "ElectricAreaPart.h"
#include "EmptyPart.h"
#include "GimmickTargetPart.h"
#include "IsAirPart.h"
#include "RectAreaPart.h"
#include "RoutePart.h"
#include "TransitionPointPart.h"
#include "TransitionTargetPart.h"

namespace stage::part {
using PartVariant = std::variant<BeaconStackPart, ChangeImageNamePart, DirPart,
                                 ElectricAreaPart, EmptyPart, GimmickTargetPart,
                                 IsAirPart, RectAreaPart, RoutePart,
                                 TransitionPointPart, TransitionTargetPart>;
}
