/*************************************************************************//*!
					
					@file	GraphicsPlatform.h
					@brief	グラフィックス関連のプラットフォームごとのインクルードを行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GRAPHICSPLATFORM__H__

#define		__GRAPHICSPLATFORM__H__

#include	"GraphicsCommon.h"

#ifdef		MOFLIB_DIRECTX12

#include	"DirectX12/DX12DepthTarget.h"

#include	"DirectX12/DX12Texture.h"

#include	"DirectX12/DX12GeometryInstanced.h"
#include	"DirectX12/DX12MeshContainer.h"

#include	"DirectX12/DX12Shader.h"
#include	"DirectX12/DX12ShaderBuffer.h"
#include	"DirectX12/DX12ShaderResource.h"

#endif

#ifdef		MOFLIB_DIRECTX11

#include	"DirectX11/DX11DepthTarget.h"

#include	"DirectX11/DX11Font.h"

#include	"DirectX11/DX11Texture.h"

#include	"DirectX11/DX11GeometryInstanced.h"
#include	"DirectX11/DX11MeshContainer.h"

#include	"DirectX11/DX11Shader.h"
#include	"DirectX11/DX11ShaderBuffer.h"
#include	"DirectX11/DX11ShaderResource.h"
#include	"DirectX11/DX11ShaderBind_SpriteBase.h"
#include	"DirectX11/DX11ShaderBind_SpriteContainer.h"
#include	"DirectX11/DX11ShaderBind_SpriteInstancedBase.h"
#include	"DirectX11/DX11ShaderBind_SpriteInstancedColor.h"
#include	"DirectX11/DX11ShaderBind_2DPrimitiveBase.h"
#include	"DirectX11/DX11ShaderBind_3DPrimitiveBase.h"
#include	"DirectX11/DX11ShaderBind_SkinGeometryBase.h"
#include	"DirectX11/DX11ShaderBind_SimpleBlur.h"
#include	"DirectX11/DX11ShaderBind_GaussianBlur.h"
#include	"DirectX11/DX11ShaderBind_ShadowRenderer.h"
#include	"DirectX11/DX11ShaderBind_ShadowRendererSkinned.h"
#include	"DirectX11/DX11ShaderBind_CascadeVarianceRenderer.h"
#include	"DirectX11/DX11ShaderBind_CascadeVarianceRendererSkinned.h"
#include	"DirectX11/DX11ShaderBind_ToneMap.h"
#include	"DirectX11/DX11ShaderBind_BrightPass.h"
#include	"DirectX11/DX11ShaderBind_HDRBrightPass.h"
#include	"DirectX11/DX11ShaderBind_ToonEdge.h"
#include	"DirectX11/DX11ShaderBind_ToonShader.h"
#include	"DirectX11/DX11ShaderBind_ToonShaderSkinned.h"
#include	"DirectX11/DX11ShaderBind_DeferredLighting.h"
#include	"DirectX11/DX11ShaderBind_DepthOutput.h"
#include	"DirectX11/DX11ShaderBind_DepthOutputSkinned.h"
#include	"DirectX11/DX11ShaderBind_EdgeBaseOutput.h"
#include	"DirectX11/DX11ShaderBind_EdgeBaseOutputSkinned.h"
#include	"DirectX11/DX11ShaderBind_DepthOfField.h"
#include	"DirectX11/DX11ShaderBind_BumpMapping.h"
#include	"DirectX11/DX11ShaderBind_BumpMappingSkinned.h"
#include	"DirectX11/DX11ShaderBind_DownScale.h"
#include	"DirectX11/DX11ShaderBind_Bloom.h"

#include	"DirectX11/Shader/SpriteBase.h"
#include	"DirectX11/Shader/SpriteContainer.h"
#include	"DirectX11/Shader/SpriteInstanceBase.h"
#include	"DirectX11/Shader/SpriteInstanceColor.h"
#include	"DirectX11/Shader/2DPrimitiveBase.h"
#include	"DirectX11/Shader/3DPrimitiveBase.h"
#include	"DirectX11/Shader/SkinnedBase.h"
#include	"DirectX11/Shader/SimpleBlur.h"
#include	"DirectX11/Shader/GBlur.h"
#include	"DirectX11/Shader/ShadowMap_Texture.h"
#include	"DirectX11/Shader/ShadowMap_TextureSkinned.h"
#include	"DirectX11/Shader/ShadowMap_Renderer.h"
#include	"DirectX11/Shader/ShadowMap_RendererSkinned.h"
#include	"DirectX11/Shader/VarianceShadowMap_Texture.h"
#include	"DirectX11/Shader/VarianceShadowMap_TextureSkinned.h"
#include	"DirectX11/Shader/CascadeVarianceShadowMap_Renderer.h"
#include	"DirectX11/Shader/CascadeVarianceShadowMap_RendererSkinned.h"
#include	"DirectX11/Shader/CascadeShadowMap_Renderer.h"
#include	"DirectX11/Shader/CascadeShadowMap_RendererSkinned.h"
#include	"DirectX11/Shader/DownScale3x3Lum.h"
#include	"DirectX11/Shader/DownScale2x2.h"
#include	"DirectX11/Shader/ToneMap.h"
#include	"DirectX11/Shader/ToonEdge.h"
#include	"DirectX11/Shader/ToonShader.h"
#include	"DirectX11/Shader/ToonShaderSkinned.h"
#include	"DirectX11/Shader/SampleLuminance.h"
#include	"DirectX11/Shader/BrightPass.h"
#include	"DirectX11/Shader/HDRBrightPass.h"
#include	"DirectX11/Shader/DeferredLighting.h"
#include	"DirectX11/Shader/DepthOutput.h"
#include	"DirectX11/Shader/DepthOutputSkinned.h"
#include	"DirectX11/Shader/DepthOutput_Single.h"
#include	"DirectX11/Shader/DepthOutputSkinned_Single.h"
#include	"DirectX11/Shader/EdgeBaseOutput.h"
#include	"DirectX11/Shader/EdgeBaseOutputSkinned.h"
#include	"DirectX11/Shader/EdgeBaseOutput_Single.h"
#include	"DirectX11/Shader/EdgeBaseOutputSkinned_Single.h"
#include	"DirectX11/Shader/EdgeMaskOutput.h"
#include	"DirectX11/Shader/EdgeMaskOutputSkinned.h"
#include	"DirectX11/Shader/DepthOfField.h"
#include	"DirectX11/Shader/BumpMapping.h"
#include	"DirectX11/Shader/BumpMappingSkinned.h"
#include	"DirectX11/Shader/Bloom.h"

#endif

#ifdef		MOFLIB_DIRECTX9
#endif

#ifdef		MOFLIB_OPENGL

#include	"OpenGL/GLDepthTarget.h"

#include	"OpenGL/GLFont.h"

#include	"OpenGL/GLTexture.h"

#include	"OpenGL/GLGeometryInstanced.h"
#include	"OpenGL/GLMeshContainer.h"

#include	"OpenGL/GLShader.h"
#include	"OpenGL/GLShaderBind_SpriteBase.h"
#include	"OpenGL/GLShaderBind_2DPrimitiveBase.h"
#include	"OpenGL/GLShaderBind_3DPrimitiveBase.h"
#include	"OpenGL/GLShaderBind_SkinGeometryBase.h"
#include	"OpenGL/GLShaderBind_GaussianBlur.h"
#include	"OpenGL/GLShaderBind_SimpleBlur.h"
#include	"OpenGL/GLShaderBind_BumpMapping.h"
#include	"OpenGL/GLShaderBind_BumpMappingSkinned.h"
#include	"OpenGL/GLShaderBind_EdgeBaseOutput.h"
#include	"OpenGL/GLShaderBind_EdgeBaseOutputSkinned.h"
#include	"OpenGL/GLShaderBind_ToonShader.h"
#include	"OpenGL/GLShaderBind_ToonShaderSkinned.h"
#include	"OpenGL/GLShaderBind_ToonEdge.h"
#include	"OpenGL/GLShaderBind_ShadowRenderer.h"
#include	"OpenGL/GLShaderBind_ShadowRendererSkinned.h"
#include	"OpenGL/GLShaderBind_DepthOutput.h"
#include	"OpenGL/GLShaderBind_DepthOutputSkinned.h"
#include	"OpenGL/GLShaderBind_DepthOfField.h"
#include	"OpenGL/GLShaderBind_BrightPass.h"
#include	"OpenGL/GLShaderBind_DownScale.h"
#include	"OpenGL/GLShaderBind_HDRBrightPass.h"
#include	"OpenGL/GLShaderBind_ToneMap.h"
#include	"OpenGL/GLShaderBind_Bloom.h"
#include	"OpenGL/GLShaderBind_CascadeVarianceRenderer.h"
#include	"OpenGL/GLShaderBind_CascadeVarianceRendererSkinned.h"

#include	"OpenGL/Shader/glslSpriteBase.h"
#include	"OpenGL/Shader/glsl2DPrimitiveBase.h"
#include	"OpenGL/Shader/glsl3DPrimitiveBase.h"
#include	"OpenGL/Shader/glslSkinnedBase.h"
#include	"OpenGL/Shader/glslGBlur.h"
#include	"OpenGL/Shader/glslSimpleBlur.h"
#include	"OpenGL/Shader/glslBumpMapping.h"
#include	"OpenGL/Shader/glslBumpMappingSkinned.h"
#include	"OpenGL/Shader/glslToonShader.h"
#include	"OpenGL/Shader/glslToonShaderSkinned.h"
#include	"OpenGL/Shader/glslToonEdge.h"
#include	"OpenGL/Shader/glslShadowMap_Texture.h"
#include	"OpenGL/Shader/glslShadowMap_TextureSkinned.h"
#include	"OpenGL/Shader/glslShadowMap_Renderer.h"
#include	"OpenGL/Shader/glslShadowMap_RendererSkinned.h"
#include	"OpenGL/Shader/glslVarianceShadowMap_Texture.h"
#include	"OpenGL/Shader/glslVarianceShadowMap_TextureSkinned.h"
#include	"OpenGL/Shader/glslDepthOutput_Single.h"
#include	"OpenGL/Shader/glslDepthOutputSkinned_Single.h"
#include	"OpenGL/Shader/glslDepthOfField.h"
#include	"OpenGL/Shader/glslEdgeBaseOutput_Single.h"
#include	"OpenGL/Shader/glslEdgeBaseOutputSkinned_Single.h"
#include	"OpenGL/Shader/glslEdgeMaskOutput.h"
#include	"OpenGL/Shader/glslEdgeMaskOutputSkinned.h"
#include	"OpenGL/Shader/glslBrightPass.h"
#include	"OpenGL/Shader/glslSampleLuminance.h"
#include	"OpenGL/Shader/glslDownScale2x2.h"
#include	"OpenGL/Shader/glslDownScale3x3Lum.h"
#include	"OpenGL/Shader/glslHDRBrightPass.h"
#include	"OpenGL/Shader/glslToneMap.h"
#include	"OpenGL/Shader/glslBloom.h"
#include	"OpenGL/Shader/glslCascadeVarianceShadowMap_Renderer.h"
#include	"OpenGL/Shader/glslCascadeVarianceShadowMap_RendererSkinned.h"
#include	"OpenGL/Shader/glslCascadeShadowMap_Renderer.h"
#include	"OpenGL/Shader/glslCascadeShadowMap_RendererSkinned.h"

#endif

#endif

//[EOF]
