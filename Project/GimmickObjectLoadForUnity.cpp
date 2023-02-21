#include "GimmickObjectLoadForUnity.h"

#include <array>

#include "Part.h"
#include "TextArchive.h"
#include "VariantUtilities.h"
using namespace stage::part;
template <class Variant, size_t I = 0>
void VariantArchive(frozen::TextInputArchive& archive, Variant& v,
                    const size_t index) {
  if constexpr (I >= std::variant_size_v<Variant>)
    throw std::runtime_error{"Variant index " + std::to_string(I + index) +
                             " Over"};
  else if (index == 0) {
    v = Variant{std::in_place_index<I>};
    archive(v);
  } else
    VariantFromIndex<Variant, I + 1>(index - 1);
}

void GimmickObjectLoadForUnity::SetPart(base_engine::Actor* actor,
                                        std::filesystem::path path) {}

GimmickObjectParameter GimmickObjectLoadForUnity::GenerateObject(
    std::filesystem::path path) {
  constexpr std::array kPartTable = {
      "BeaconStack",     "ChangeImageName", "Dir",      "ElectricArea",
      "GimmickTarget",   "IsAir",           "RectArea", "Route",
      "TransitionPoint", "TransitionTarget"};
  std::ifstream os(path);
  {
    frozen::TextInputArchive archive(os);
    archive(object_);
    for (int i = 0; i < object_.part_count; ++i) {
      std::string part_name;
      int k;
      archive(part_name, k);
      PartVariant part;
      for (int part_type = 0; part_type < kPartTable.size(); ++part_type) {
        if (part_name == kPartTable[part_type]) {
          part = VariantFromIndex<decltype(part)>(part_type);
          break;
        }
      }

      std::visit(
          [&archive, &part](auto part_arg) {
            archive(part_arg);
            part = part_arg;
          },
          part);
      object_.parts.emplace_back(part);
    }
  }
  return object_;
}
