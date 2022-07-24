#include "IBaseEngineRender.h"

#include "RenderMof.h"
namespace base_engine {
IBaseEngineRender* IBaseEngineRender::Create() {
  return new RenderMof;
}

IBaseEngineRender::~IBaseEngineRender() = default;
}  // namespace base_engine