#include "Easer.h"

#include <array>
#include <stdexcept>
#include <unordered_map>

#include "EaseType.h"
#include "EnumExtension.h"

namespace ma_tween {

namespace {
constexpr float Linear(const float time) { return time; }

template <typename Key, typename Value, std::size_t Size>
struct Map {
  std::array<std::pair<Key, Value>, Size> data;

  [[nodiscard]] constexpr Value at(const Key &key) const {
    const auto itr =
        std::find_if(begin(data), end(data),
                     [&key](const auto &v) { return v.first == key; });
    if (itr != end(data)) {
      return itr->second;
    } else {
      throw std::range_error("Not Found");
    }
  }
};

using EasingMethod = std::add_pointer_t<float(float)>;
constexpr std::array<std::pair<EaseType, EasingMethod>, 1> kMethodMap{
    {{EaseType::kLinear, Linear}}};

static_assert(kMethodMap.size() == ee::ElementCount<EaseType>());
EasingMethod LookAtMethod(const EaseType sv) {
  static constexpr auto map =
      Map<EaseType, EasingMethod, kMethodMap.size()>{{kMethodMap}};
  return map.at(sv);
}
}  // namespace
float Easer::Apply(const EaseType &ease, const float time) {
  return LookAtMethod(ease)(time);
}
}  // namespace ma_tween