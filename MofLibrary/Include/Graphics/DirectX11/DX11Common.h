/*************************************************************************//*!
					
					@file	DX11Common.h
					@brief	グラフィックス関連の基本定義を行う。

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
#define		MOF_DEFAULTFONTFACE					"ＭＳ ゴシック"

namespace Mof {

	typedef		VERTEX_NORMAL_TEXTURE1_COLORU1		DefaultGeometryVertex;
#define		DEFAULT_GEOMETRYVERTEXCOLOR(v)			v.c = MOF_COLOR_WHITE;

	namespace DX11Impl {
		/*************************************************************************//*!
				@brief			DX11内部用フォーマット変換関数
				@param[in]		f			フォーマット
				
				@return			DirectX11用フォーマット
		*//**************************************************************************/
		DXGI_FORMAT ConvertFormat(PixelFormat f);
		/*************************************************************************//*!
				@brief			DX11内部用アクセスモード変換関数
				@param[in]		am			アクセスモード
				
				@return			DirectX11用アクセスモード
		*//**************************************************************************/
		D3D11_USAGE ConvertUsage(BufferAccess am);
		/*************************************************************************//*!
				@brief			DX11内部用比較関数変換関数
				@param[in]		f			比較関数
				
				@return			DirectX11用比較関数
		*//**************************************************************************/
		D3D11_COMPARISON_FUNC ConvertComparisonFunc(ComparisonFunc f);
		/*************************************************************************//*!
				@brief			DX11内部用ステンシル処理変換関数
				@param[in]		op			ステンシル処理
				
				@return			DirectX11用ステンシル処理
		*//**************************************************************************/
		D3D11_STENCIL_OP ConvertStencilOp(StencilOp op);
	}

}

#endif