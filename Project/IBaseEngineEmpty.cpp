#include "IBaseEngineEmpty.h"
#include "BaseEngineEmpty.h"

namespace base_engine {
IBaseEngineEmpty* IBaseEngineEmpty::Create() { return new BaseEngineEmpty; }
IBaseEngineEmpty::~IBaseEngineEmpty() = default;
}  // namespace base_engine