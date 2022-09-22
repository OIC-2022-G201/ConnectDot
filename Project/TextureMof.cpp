#include "TextureMof.h"
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
    for (auto&& m_texture : m_textures) {
        m_texture.second->Release();
        delete m_texture.second;
    }
}

bool TextureMof::Release(std::string_view name)
{
  return m_textures[std::hash<std::string_view>{}(name)]->Release();
};

}  // namespace base_engine
