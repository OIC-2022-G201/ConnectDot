// @Material.h
// @brief
// @author ICE
// @date 2023/01/13
//
// @details

#pragma once
#include <memory>
#include <ranges>
#include <unordered_map>
#include <vector>

#include "ShaderBase.h"

namespace base_engine {
class Material {
 public:
  void SetShader(const std::shared_ptr<ShaderBase>& shader);

  [[nodiscard]] std::shared_ptr<ShaderBase> GetShader() const;

  bool Begin();
  bool End();

  bool SetParameter(const Property& property);

  bool CreateParameter(const PropertyInfo& property);

private:
  void BindShaderParameter();

  std::shared_ptr<ShaderBase> shader_;
  std::unordered_map<std::string, Property> parameters_;
  bool parameter_changed_ = false;
};
}  // namespace base_engine
