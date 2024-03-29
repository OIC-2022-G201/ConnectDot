﻿#pragma once
#include "YesNo.h"

using DebugMode = base_engine::YesNo<struct DebugModeTag>;
constexpr DebugMode kIsCollisionRenderMode = DebugMode::No;
constexpr DebugMode kStatusRenderMode = DebugMode::No;
//constexpr DebugMode kIsCollisionRenderMode = DebugMode::Yes;