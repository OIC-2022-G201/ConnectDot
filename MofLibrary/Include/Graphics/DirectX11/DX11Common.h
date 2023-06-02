/*************************************************************************//*!
					
					@file	DX11Common.h
					@brief	�O���t�B�b�N�X�֘A�̊�{��`���s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11COMMON__H__

#define		__DX11COMMON__H__

//LIBRARY
#pragma comment (lib,"d3d11.lib")
#pragma comment (lib,"dxgi.lib")
#pragma comment (lib,"d3dcompiler.lib")
#if defined(DEBUG) || defined(_DEBUG)

#if _MSC_VER >= 1910

#pragma comment (lib,"DirectXTex2017_md32_d.lib")
#pragma comment (lib,"Effects112017_md32_d.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"DirectXTex2015_md32_d.lib")
#pragma comment (lib,"Effects112015_md32_d.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"DirectXTex2013_md32_d.lib")
#pragma comment (lib,"Effects112013_md32_d.lib")

#else

#pragma comment (lib,"DirectXTex_md32_d.lib")
#pragma comment (lib,"Effects11_md32_d.lib")

#endif // _MSC_VER == 1800

#else

#if _MSC_VER >= 1910

#pragma comment (lib,"DirectXTex2017_md32.lib")
#pragma comment (lib,"Effects112017_md32.lib")

#elif _MSC_VER == 1900

#pragma comment (lib,"DirectXTex2015_md32.lib")
#pragma comment (lib,"Effects112015_md32.lib")

#elif _MSC_VER == 1800

#pragma comment (lib,"DirectXTex2013_md32.lib")
#pragma comment (lib,"Effects112013_md32.lib")

#else

#pragma comment (lib,"DirectXTex_md32.lib")
#pragma comment (lib,"Effects11_md32.lib")

#endif // _MSC_VER == 1800

#endif

//INCLUDE
#include	<d3d11.h>
#include	<d3dcompiler.h>
#include	"Effects11/d3dx11effect.h"
#include	"DirectXTex/DirectXTex.h"
typedef		ID3D11Device*						MofGraphicsDevice;
typedef		IDXGIFactory*						MofGIFactory;
typedef		IDXGISwapChain*						MofSwapChain;
typedef		ID3D11DeviceContext*				MofDeviceContext;
typedef		ID3D11RenderTargetView*				MofRenderTarget;
typedef		ID3D11DepthStencilView*				MofDepthTarget;
typedef		ID3D11ShaderResourceView*			MofTexture;
typedef		ID3D11Texture2D*					MofTextureHandle;
typedef		ID3D11VertexShader*					MofVertexShader;
typedef		ID3D11PixelShader*					MofPixelShader;
typedef		ID3DX11Effect*						MofShaderEffect;
typedef		ID3D11Buffer*						MofVertexBuffer;
typedef		ID3D11InputLayout*					MofVertexLayout;
typedef		ID3D11Buffer*						MofIndexBuffer;
typedef		ID3D11SamplerState*					MofSamplerState;
typedef		HFONT								MofFont;

//DEFINE
#define		SHADERPARAM_ALIGNMENT				__declspec(align(16))
#define		SHADERCOMPILE_DEFAULTFLAG			D3DCOMPILE_ENABLE_STRICTNESS
#define		SHADERLOAD_DEFAULT(f)				(LPMofVoid)f,f##Size
#define		MOF_DEFAULTFONTFACE					"�l�r �S�V�b�N"

namespace Mof {

	typedef		VERTEX_NORMAL_TEXTURE1_COLORU1		DefaultGeometryVertex;
#define		DEFAULT_GEOMETRYVERTEXCOLOR(v)			v.c = MOF_COLOR_WHITE;

	namespace DX11Impl {
		/*************************************************************************//*!
				@brief			DX11�����p�t�H�[�}�b�g�ϊ��֐�
				@param[in]		f			�t�H�[�}�b�g
				
				@return			DirectX11�p�t�H�[�}�b�g
		*//**************************************************************************/
		DXGI_FORMAT ConvertFormat(PixelFormat f);
		/*************************************************************************//*!
				@brief			DX11�����p�A�N�Z�X���[�h�ϊ��֐�
				@param[in]		am			�A�N�Z�X���[�h
				
				@return			DirectX11�p�A�N�Z�X���[�h
		*//**************************************************************************/
		D3D11_USAGE ConvertUsage(BufferAccess am);
		/*************************************************************************//*!
				@brief			DX11�����p��r�֐��ϊ��֐�
				@param[in]		f			��r�֐�
				
				@return			DirectX11�p��r�֐�
		*//**************************************************************************/
		D3D11_COMPARISON_FUNC ConvertComparisonFunc(ComparisonFunc f);
		/*************************************************************************//*!
				@brief			DX11�����p�X�e���V�������ϊ��֐�
				@param[in]		op			�X�e���V������
				
				@return			DirectX11�p�X�e���V������
		*//**************************************************************************/
		D3D11_STENCIL_OP ConvertStencilOp(StencilOp op);
	}

}

#endif