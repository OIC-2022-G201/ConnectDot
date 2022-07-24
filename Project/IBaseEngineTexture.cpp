#include "IBaseEngineTexture.h"
#include "TextureMof.h"
namespace base_engine {
IBaseEngineTexture* IBaseEngineTexture::Create() {
  return new TextureMof;
}

IBaseEngineTexture::~IBaseEngineTexture() = default;
}  // namespace base_engine