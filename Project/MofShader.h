// @MofShader.h
// @brief
// @author ICE
// @date 2023/01/14
//
// @details

#pragma once
#include <Graphics/Texture.h>

#include <memory>
#include <Graphics/ShaderBind.h>

#include "ShaderBase.h"

namespace base_engine {

class MofShader : public ShaderBase {
protected:
  class MofShaderImpl;
  std::unique_ptr<MofShaderImpl> impl_;

 public:

  MofShader(std::string_view file_path);
  ~MofShader();
  bool SetResource(size_t index, Mof::LPTexture resource) const;
  bool SetBuffer(size_t index, void* buffer) const;
  bool SetParameter(const Property& parameter) override {
    switch (parameter.type) {
      case PropertyType::kNone:
        break;
      case PropertyType::kResource:
        SetResource(parameter.id, static_cast<Mof::LPTexture>(parameter.data));
        break;
      case PropertyType::kBuffer:
        SetBuffer(parameter.id, parameter.data);
        break;
      default:;
    }
    return true;
  }

  bool CreateParameter(const PropertyInfo& parameter) override;
  
  bool Load(std::string_view name) override;
  bool Begin() override;

  bool End() override;

  [[nodiscard]] Mof::IShader* GetShader() const;
  [[nodiscard]] Mof::IShaderBind* GetShaderBind() const;
};
}  // namespace base_engine