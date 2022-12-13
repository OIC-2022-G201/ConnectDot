#include "Easer.h"

#include <array>
#include <numbers>
#include <stdexcept>
#include <unordered_map>

#include "EaseType.h"
#include "EnumExtension.h"

namespace ma_tween {

namespace {
#define _CONST_

_CONST_ float Linear(const float time) { return time; }
_CONST_ float InSine(const float x) {
  return 1 - cos((x * std::numbers::pi_v<float>) / 2);
}
_CONST_ float OutSine(const float x) {
  return sin((x * std::numbers::pi_v<float>) / 2);
}
_CONST_ float InOutSine(const float x) {
  return -(cos(std::numbers::pi_v<float> * x) - 1) / 2;
}
_CONST_ float InQuad(const float x) { return x * x; }
_CONST_ float OutQuad(const float x) { return 1 - (1 - x) * (1 - x); }
_CONST_ float InOutQuad(const float x) {
  return x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;
}
_CONST_ float InCubic(const float x) { return x * x * x; }
_CONST_ float OutCubic(const float x) { return 1 - pow(1 - x, 3); }
_CONST_ float InOutCubic(const float x) {
  return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}
_CONST_ float InQuart(const float x) { return x * x * x * x; }
_CONST_ float OutQuart(const float x) { return 1 - pow(1 - x, 4); }
_CONST_ float InoutQuart(const float x) {
  return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
}
_CONST_ float InQuint(const float x) { return x * x * x * x * x; }
_CONST_ float OutQuint(const float x) { return 1 - pow(1 - x, 5); }
_CONST_ float InOutQuint(const float x) {
  return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}
_CONST_ float InExpo(const float x) { return x == 0 ? 0 : pow(2, 10 * x - 10); }
_CONST_ float OutExpo(const float x) {
  return x == 1 ? 1 : 1 - pow(2, -10 * x);
}
_CONST_ float InOutExpo(const float x) {
  return x == 0    ? 0
         : x == 1  ? 1
         : x < 0.5 ? pow(2, 20 * x - 10) / 2
                   : (2 - pow(2, -20 * x + 10)) / 2;
}
_CONST_ float InCirc(const float x) { return 1 - sqrt(1 - pow(x, 2)); }
_CONST_ float OutCirc(const float x) { return sqrt(1 - pow(x - 1, 2)); }
_CONST_ float InOutCirc(const float x) {
  return x < 0.5 ? (1 - sqrt(1 - pow(2 * x, 2))) / 2
                 : (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}
_CONST_ float InBack(const float x) {
  constexpr float c1 = 1.70158;
  constexpr float c3 = c1 + 1;

  return c3 * x * x * x - c1 * x * x;
}
_CONST_ float OutBack(const float x) {
  const float c1 = 1.70158;
  const float c3 = c1 + 1;

  return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}
_CONST_ float InOutBack(const float x) {
  const float c1 = 1.70158;
  const float c2 = c1 * 1.525;

  return x < 0.5 ? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
                 : (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}
_CONST_ float InElastic(const float x) {
  const float c4 = (2 * std::numbers::pi_v<float>) / 3;

  return x == 0   ? 0
         : x == 1 ? 1
                  : -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * c4);
}
_CONST_ float OutElastic(const float x) {
  const float c4 = (2 * std::numbers::pi_v<float>) / 3;

  return x == 0   ? 0
         : x == 1 ? 1
                  : pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
}
_CONST_ float InOutElastic(const float x) {
  const float c5 = (2 * std::numbers::pi_v<float>) / 4.5;

  return x == 0   ? 0
         : x == 1 ? 1
         : x < 0.5
             ? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2
             : (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
}
_CONST_ float OutBounce(float x) {
  constexpr float n1 = 7.5625;

  if (constexpr float d1 = 2.75; x < 1 / d1) {
    return n1 * x * x;
  } else if (x < 2 / d1) {
    return n1 * (x -= 1.5f / d1) * x + 0.75f;
  } else if (x < 2.5 / d1) {
    return n1 * (x -= 2.25f / d1) * x + 0.9375f;
  } else {
    return n1 * (x -= 2.625f / d1) * x + 0.984375f;
  }
}
_CONST_ float InBounce(const float x) { return 1 - OutBounce(1 - x); }
_CONST_ float InOutBounce(const float x) {
  return (x < 0.5) ? ((1 - OutBounce(1 - 2 * x)) / 2) : ((1 + OutBounce(2 * x - 1)) / 2);
}

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
constexpr std::array<std::pair<EaseType, EasingMethod>, 31> kMethodMap{
    {{EaseType::kLinear, Linear},
     {EaseType::kInsine, InSine},
     {EaseType::kOutsine, OutSine},
     {EaseType::kInoutsine, InOutSine},
     {EaseType::kInquad, InQuad},
     {EaseType::kOutquad, OutQuad},
     {EaseType::kInoutquad, InOutQuad},
     {EaseType::kIncubic, InCubic},
     {EaseType::kOutcubic, OutCubic},
     {EaseType::kInoutcubic, InOutCubic},
     {EaseType::kInquart, InQuart},
     {EaseType::kOutquart, OutQuart},
     {EaseType::kInoutquart, InoutQuart},
     {EaseType::kInquint, InQuint},
     {EaseType::kOutquint, OutQuint},
     {EaseType::kInoutquint, InOutQuint},
     {EaseType::kInexpo, InExpo},
     {EaseType::kOutexpo, OutExpo},
     {EaseType::kInoutexpo, InOutExpo},
     {EaseType::kIncirc, InCirc},
     {EaseType::kOutcirc, OutCirc},
     {EaseType::kInoutcirc, InOutCirc},
     {EaseType::kInback, InBack},
     {EaseType::kOutback, OutBack},
     {EaseType::kInoutback, InOutBack},
     {EaseType::kInelastic, InElastic},
     {EaseType::kOutelastic, OutElastic},
     {EaseType::kInoutelastic, InOutElastic},
     {EaseType::kInbounce, InBounce},
     {EaseType::kOutbounce, OutBounce},
     {EaseType::kInoutbounce, InOutBounce}}};

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