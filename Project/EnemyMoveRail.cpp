#include "EnemyMoveRail.h"

#include "PositionTween.h"
#include "StageConstitution.h"
#include "VectorUtilities.h"
namespace {
constexpr auto kProgressionRoundTrip =
    [](const std::vector<base_engine::Vector2>& routes, int max, int* process) {
      int result;
      if (const int num = (*process) % ((max * 2)); num > (max)-1) {
        result = 2 * max - (num + 1);
        (*process)++;
        return -routes[result];

      } else {
        result = num;
        (*process)++;
        return routes[result];
      }
    };
constexpr auto kProgressionLoop =
    [](const std::vector<base_engine::Vector2>& routes, int max, int* process) {
      const int result = *(process);
      (*process)++;
      if ((*process) >= max) {
        (*process) = 0;
      }
      return routes[result];
    };
}  // namespace

void EnemyMoveRail::SetType(const stage::part::RouteType type) {
  route_type_ = type;
  switch (route_type_) {
    case stage::part::RouteType::kRoundTrip:
      current_process_update_ = [](const RouteVector& route, int* process) {
        return kProgressionRoundTrip(route, route.size(), process);
      };
      break;
    case stage::part::RouteType::kLoop:
      current_process_update_ = [](const RouteVector& route, int* process) {
        return kProgressionLoop(route, route.size(), process);
      };
      break;
    case stage::part::RouteType::kOneWay:
      break;
    default:;
  }
}

void EnemyMoveRail::Update() {
  if (!current_process_update_) {
    current_process_update_ = [](const RouteVector& route, int* process) {
      return kProgressionRoundTrip(route, route.size(), process);
    };
  }
  if (route_.empty()) {
    return;
  }
  if (is_move_) return;
  is_move_ = true;
  const auto next_route = current_process_update_(route_, &current_process_);
  const auto& target_position =
      owner_->GetPosition() + next_route * stage::kStageCellWidth<float>;

  const auto length = base_engine::VectorUtilities::Length(next_route);

  ma_tween::PositionTween::Tween(owner_, target_position, 1.0f * length)
      .SetOnComplete([this] { is_move_ = false; });
}
