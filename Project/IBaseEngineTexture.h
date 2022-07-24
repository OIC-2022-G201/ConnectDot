#pragma once
#include <string>
#include <Graphics/Texture.h>

namespace base_engine {
struct TextureHandle {
    
    size_t handle;
};
class IBaseEngineTexture {
 public:
  static IBaseEngineTexture* Create();

  virtual ~IBaseEngineTexture();

  virtual bool Load(const std::string& name) = 0;
  virtual Mof::LPTexture Get(const std::string& name) = 0;
  virtual bool Release(const std::string& name) = 0; 
  virtual void Clear() = 0;
};
}  // namespace base_engine