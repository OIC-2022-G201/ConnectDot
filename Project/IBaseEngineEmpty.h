#pragma once
namespace base_engine {
class IBaseEngineEmpty {
 public:
  static IBaseEngineEmpty* Create();

  virtual ~IBaseEngineEmpty();
};
}  // namespace base_engine

