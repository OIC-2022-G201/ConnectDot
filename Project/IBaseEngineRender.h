#pragma once

namespace base_engine {
class IBaseEngineRender {
public:
  static IBaseEngineRender* Create();
  virtual ~IBaseEngineRender();
};
}  // namespace base_engine