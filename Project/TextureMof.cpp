#include "TextureMof.h"

#include <ranges>

namespace base_engine {

TextureMof::TextureMof() { m_textures.reserve(128); }

TextureMof::~TextureMof()
{ Clear(); }

bool TextureMof::Load(std::string_view name)
{
    auto texture = new Mof::CTexture;
    if (!texture->Load(name.data())) return false;
    m_textures.insert({std::hash<std::string_view>{} (name), texture});
    return true;
}

TexturePtr TextureMof::Get(std::string_view name) {
  return m_textures[std::hash<std::string_view>{}(name)];
}

void TextureMof::Clear()
{
    for (const auto& val : m_textures | std::views::values) {
        val->Release();
        delete val;
    }
}

bool TextureMof::Release(std::string_view name)
{
  return m_textures[std::hash<std::string_view>{}(name)]->Release();
};

}  // namespace base_engine
