// @MofShaderImpl.h
// @brief
// @author ICE
// @date 2023/01/14
//
// @details

#pragma once
#include <Graphics/DirectX11/DX11Shader.h>
#include <Graphics/DirectX11/DX11ShaderBind_2DPrimitiveBase.h>
#include <Mof.h>
#include <Utilities/GraphicsUtilities.h>

#include "ShaderBase.h"

namespace base_engine {

class MofShaderImpl {
  Mof::CShader shader_;
  Mof::CShaderBind_2DPrimitiveBase shader_bind_;

 public:
  MofShaderImpl() = default;
  ~MofShaderImpl() = default;

  bool SetResource(const size_t index, const Mof::LPTexture resource) {
    const auto data = shader_bind_.GetShaderResource(index);
    if (!data) return false;
    return data->SetResource(resource);
  }
  bool SetBuffer(const size_t index, void* buffer) {
    const auto data = shader_bind_.GetShaderBuffer(index);
    if (!data) return false;
    return data->SetBuffer(buffer);
  }
  bool Load(const std::string_view name) {
    const MofU32 sw = g_pGraphics->GetTargetWidth();
    const MofU32 sh = g_pGraphics->GetTargetHeight();

    shader_.Load(name.data());
    shader_bind_.Create(&shader_);
    Mof::CGraphicsUtilities::SetScreenSize(sw, sh, &shader_bind_);

    return true;
  }

  bool CreateParameter(const PropertyInfo& parameter) {
    switch (parameter.type) {
      case PropertyType::kNone:
        return false;
        break;
      case PropertyType::kResource:
        shader_bind_.CreateShaderResource(parameter.name.data());
        break;
      case PropertyType::kBuffer:
        shader_bind_.CreateShaderBuffer(parameter.name.data(),
                                        parameter.data_size);
        break;
      default:;
    }
    return true;
  }
  bool Begin() { return true; }
  bool End() { return true; }

  Mof::IShader* GetShader() { return &shader_; }
  Mof::IShaderBind* GetShaderBind() { return &shader_bind_; }
};
}  // namespace base_engine