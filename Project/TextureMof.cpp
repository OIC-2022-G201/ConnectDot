#include "TextureMof.h"
namespace base_engine {

TextureMof::TextureMof() { m_textures.reserve(128); }

TextureMof::~TextureMof()
{ Clear(); }

bool TextureMof::Load(const std::string& name)
{
    auto texture = new Mof::CTexture;
    if (!texture->Load(name.c_str())) return false;
    m_textures.insert({name, texture});
    return true;
}

Mof::LPTexture TextureMof::Get(const std::string& name)
{
    return m_textures[name];
}

void TextureMof::Clear()
{
    for (auto&& m_texture : m_textures) {
        m_texture.second->Release();
        delete m_texture.second;
    }
}

bool TextureMof::Release(const std::string& name)
{
    return m_textures[name]->Release();
};

}  // namespace base_engine
