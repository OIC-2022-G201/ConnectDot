#include "IBaseEngineCanvasRender.h"

#include "CanvasRender.h"
namespace base_engine {
IBaseEngineCanvasRender* base_engine::IBaseEngineCanvasRender::Create() {
  return new CanvasRender;
}

IBaseEngineCanvasRender::~IBaseEngineCanvasRender() = default;
}  // namespace base_engine
