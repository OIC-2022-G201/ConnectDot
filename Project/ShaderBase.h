// @ShaderBase.h
// @brief
// @author ICE
// @date 2023/01/14
//
// @details

#pragma once
#include <string_view>

namespace base_engine {
enum class PropertyType { kNone, kResource, kBuffer };

struct Property {
  std::string name;
  size_t id;
  PropertyType type;
  void* data;
};

struct PropertyInfo {
  std::string name;
  PropertyType type;
  size_t data_size;
};
class ShaderBase {
 protected:
  
 public:
  virtual bool Load(std::string_view name) = 0;
  virtual bool Begin() = 0;
  virtual bool End() = 0;
  virtual bool SetParameter(const Property& parameter) = 0;
  virtual bool CreateParameter(const PropertyInfo& parameter) = 0;
};
}  // namespace base_engine
