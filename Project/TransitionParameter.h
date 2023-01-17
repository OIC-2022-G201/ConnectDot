#pragma once
#include "ITransitionFadeSystem.h"

constexpr TransitionFadeInfo kGoalToTitleFadeIn = {0.15f, EaseType::kOutcirc};
constexpr TransitionFadeInfo kGoalToTitleFadeout = {0.15f, EaseType::kOutsine};

constexpr TransitionFadeInfo kPauseToGameFadeIn = {0.3f, EaseType::kOutcirc};
constexpr TransitionFadeInfo kPauseToGameFadeOut = {0.3f, EaseType::kInsine};

constexpr TransitionFadeInfo kPauseToTitleFadeIn = {0.3f, EaseType::kOutcirc};
constexpr TransitionFadeInfo kPauseToTitleFadeOut = {0.3f, EaseType::kInsine};

constexpr TransitionFadeInfo kNewGameToGameFadeIn = {0.6f, EaseType::kOutcirc};
constexpr TransitionFadeInfo kNewGameToGameFadeOut = {1.65f, EaseType::kInquad};

constexpr TransitionFadeInfo kStageSelectToGameFadeIn = {0.6f,
                                                         EaseType::kOutcirc};
constexpr TransitionFadeInfo kStageSelectToGameFadeOut = {1.65f,
                                                          EaseType::kInquad};

constexpr TransitionFadeInfo kGameToTitleFadeIn = {0.3f, EaseType::kOutcirc};
constexpr TransitionFadeInfo kGameToTitleFadeOut = {0.3f, EaseType::kInsine};

constexpr TransitionFadeInfo kGameToGameFadeIn = {0.3f, EaseType::kOutcirc};
constexpr TransitionFadeInfo kGameToGameFadeOut = {0.3f, EaseType::kInsine};

constexpr TransitionFadeInfo kPlayerToGameOverFadeIn = {0.3f,
                                                        EaseType::kOutcirc};
constexpr TransitionFadeInfo kPlayerToGameOverFadeOut = {0.3f,
                                                         EaseType::kInsine};
constexpr TransitionFadeInfo kGameOverToGameFadeIn = {0.3f, EaseType::kOutcirc};
constexpr TransitionFadeInfo kGameOverToGameFadeOut = {0.3f, EaseType::kInsine};

constexpr TransitionFadeInfo kGameOverToTitleFadeIn = {0.3f, EaseType::kOutcirc};
constexpr TransitionFadeInfo kGameOverToTitleFadeOut = {0.3f, EaseType::kInsine};