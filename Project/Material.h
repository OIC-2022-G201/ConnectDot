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
  void SetShader(const std::shared_ptr<ShaderBase>& shader) {
    shader_ = shader;
  }

  [[nodiscard]] std::shared_ptr<ShaderBase> GetShader() const { return shader_; }
  bool Begin() {
    BindShaderParameter();
    return shader_->Begin();
  }
  bool End() { return shader_->End(); }

  bool SetParameter(const Property& property) {
    parameters_[property.name] = property;
    parameter_changed_ = true;
    return true;
  }
  bool CreateParameter(const PropertyInfo& property) {
    return shader_->CreateParameter(property);
  }

 private:
  void BindShaderParameter() {
    if (!parameter_changed_) return;
    for (const auto& property : parameters_ | std::views::values) {
      shader_->SetParameter(property);
    }
    parameter_changed_ = false;
  }

  std::shared_ptr<ShaderBase> shader_;
  std::unordered_map<std::string, Property> parameters_;
  bool parameter_changed_ = false;
};
}  // namespace base_engine
