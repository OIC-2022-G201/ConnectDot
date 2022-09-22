#pragma once
#include <Graphics/DirectX11/DX11Texture.h>
#include <Graphics/Texture.h>

#include <unordered_map>

#include "IBaseEngineTexture.h"
namespace base_engine {
class TextureMof final : public IBaseEngineTexture {
  size_t count;
  std::unordered_map<size_t, Mof::LPTexture> m_textures;

 public:
  TextureMof();
  ~TextureMof() override;

  bool Load(std::string_view name) override;

  TexturePtr Get(std::string_view name) override;

  void Clear() override;

  bool Release(std::string_view name) override;
};
}  // namespace base_engine