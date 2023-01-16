#include "Material.h"

void base_engine::Material::SetShader(const std::shared_ptr<ShaderBase>& shader)
{
	shader_ = shader;
}

std::shared_ptr<base_engine::ShaderBase> base_engine::Material::GetShader() const
{ return shader_; }

bool base_engine::Material::Begin()
{
	BindShaderParameter();
	return shader_->Begin();
}

bool base_engine::Material::End()
{ return shader_->End(); }

bool base_engine::Material::SetParameter(const Property& property)
{
	parameters_[property.name] = property;
	parameter_changed_ = true;
	BindShaderParameter();
	return true;
}

bool base_engine::Material::CreateParameter(const PropertyInfo& property)
{
	return shader_->CreateParameter(property);
}

void base_engine::Material::BindShaderParameter()
{
	if (!parameter_changed_) return;
	for (const auto& property : parameters_ | std::views::values) {
		if(!shader_->SetParameter(property))
		{
			throw std::exception{"Not Parameter"};
		}
	}
	parameter_changed_ = false;
}
