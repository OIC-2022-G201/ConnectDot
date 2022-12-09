#include "TitlePresenter.h"

#include <fstream>

#include "BinaryArchive.h"
#include "Frozen.h"
#include "UiFrozen.h"
#include "VariantFrozen.h"
#include "VectorFrozen.h"

void TitlePresenter::Load(const std::string_view path) {
  std::vector<PackageVariant> packages;
  {
    std::ifstream stream(path.data(), std::ios::binary);
    frozen::BinaryInputArchive archive(stream);
    archive(packages);
  }
  for (const auto& package : packages) {
    if (std::holds_alternative<ButtonFrozenPack>(package)) {

    } else {
    }
  }
}
