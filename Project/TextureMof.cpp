#include "TextureMof.h"

#include <filesystem>
#include <ranges>
#include <Utilities/Utilities.h>

namespace base_engine {
namespace {
std::string PathToLocalStringPath(const std::filesystem::path& path) {
  return path.lexically_normal().generic_string();
}
size_t StringToHash(const std::string_view str)
{
  return std::hash<std::string_view>{}(str);
}
}  // namespace
TextureMof::TextureMof() {
    textures_.reserve(128);
}

TextureMof::~TextureMof()
{
  Clear();
  none_texture_.Release();
}

bool TextureMof::Load(std::string_view name) {
  if (name == "Default")
  {
    return none_texture_.Load("no-texture.png");
  }
  const std::filesystem::path local_path = name;
  if (!exists(local_path)) return false;
  const std::string texture_normal_path = PathToLocalStringPath(local_path);
  const auto hash = StringToHash(texture_normal_path);

  if (textures_.contains(hash)) return false;

  auto texture = new Mof::CTexture;
  if (!texture->Load(texture_normal_path.data())) {
    delete texture;
    return false;
  }
  textures_.insert({hash, texture});
  return true;
}

TexturePtr TextureMof::Get(std::string_view name) {
  const std::filesystem::path local_path = name;
  if (!exists(local_path)) return &none_texture_;
  const std::string texture_normal_path = PathToLocalStringPath(local_path);
  const auto hash = StringToHash(texture_normal_path);
  if (!textures_.contains(hash)) return &none_texture_;
  return textures_[hash];
}

void TextureMof::Clear() {
  for (const auto& val : textures_ | std::views::values) {
    val->Release();
    delete val;
  }
}

bool TextureMof::Release(std::string_view name) {
  const std::filesystem::path local_path = name;
  if (!exists(local_path)) return false;
  const std::string texture_normal_path = PathToLocalStringPath(local_path);
  const auto hash = StringToHash(texture_normal_path);
  if (!textures_.contains(hash)) return false;
  return textures_[std::hash<std::string_view>{}(name)]->Release();
};

}  // namespace base_engine
