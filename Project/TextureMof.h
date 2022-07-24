#pragma once
#include <Graphics/DirectX11/DX11Texture.h>
#include <Graphics/Texture.h>

#include <unordered_map>

#include "IBaseEngineTexture.h"
namespace base_engine {
class TextureMof final : public IBaseEngineTexture {
  size_t count;
  std::unordered_map<std::string, Mof::LPTexture> m_textures;

 public:
  TextureMof();
  ~TextureMof() override;

  bool Load(const std::string& name) override;

  Mof::LPTexture Get(const std::string& name) override;

  void Clear() override;

  bool Release(const std::string& name) override;
};
}  // namespace base_engine