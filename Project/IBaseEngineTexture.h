#pragma once
#include <Graphics/Texture.h>

#include <string>

namespace base_engine {
struct TextureHandle {
  size_t handle;
};

using TexturePtr = Mof::LPTexture;

class IBaseEngineTexture {
 public:
  static IBaseEngineTexture* Create();

  virtual ~IBaseEngineTexture();

  virtual bool Load(std::string_view name) = 0;
  virtual TexturePtr Get(std::string_view name) = 0;
  virtual bool Release(std::string_view name) = 0;
  virtual void Clear() = 0;
};
}  // namespace base_engine