#include "MofShader.h"

#include "MofShaderImpl.h"
base_engine::MofShader::MofShader(const std::string_view name) {
  impl_ = std::make_unique<MofShaderImpl>();
  impl_->Load(name);
}

bool base_engine::MofShader::SetResource(const size_t index,
                                         const Mof::LPTexture resource) const {
  return impl_->SetResource(index, resource);
}

bool base_engine::MofShader::SetBuffer(const size_t index, void* buffer) const {
  return impl_->SetBuffer(index, buffer);
}

bool base_engine::MofShader::CreateParameter(const PropertyInfo& parameter) {
  return impl_->CreateParameter(parameter);
}

bool base_engine::MofShader::Load(const std::string_view name) {
  return impl_->Load(name);
}

bool base_engine::MofShader::Begin() { return impl_->Begin(); }

bool base_engine::MofShader::End() { return impl_->End(); }

Mof::IShader* base_engine::MofShader::GetShader() const {
  return impl_->GetShader();
}

Mof::IShaderBind* base_engine::MofShader::GetShaderBind() const {
  return impl_->GetShaderBind();
}
