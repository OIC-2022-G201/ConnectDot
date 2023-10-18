/*************************************************************************//*!
					
					@file	GraphicsCommon.h
					@brief	グラフィックス関連の基本定義を行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GRAPHICSCOMMON__H__

#define		__GRAPHICSCOMMON__H__

//INCLUDE
#include	"../Common/Lock.h"
#include	"../Framework/Window/Window.h"
#include	"../Math/Quaternion.h"
#include	"../Collision/Rectangle.h"
#include	"../Collision/Circle.h"
#include	"../Collision/Box.h"
#include	"../Collision/Sphere.h"
#include	"../Collision/Capsule.h"
#include	"../Collision/Ray.h"

//DEFINE

//!描画ターゲット設定最大数
#define		MOF_RENDERTARGET_MAX							( 8 )

namespace Mof {
		
	/*******************************//*!
	@brief	バッファメモリマップ方法列挙

			頂点バッファやインデックスバッファなどのメモリマップの利用方法を列挙

	@author	CDW
	*//********************************/
	enum tag_BUFFERMAP {
        BUFFERMAP_READ,								//!<読み込み専用でマップをおこなう
        BUFFERMAP_WRITE,							//!<書き込み専用でマップをおこなう
        BUFFERMAP_READ_WRITE,						//!<読み書き可能でマップをおこなう
        BUFFERMAP_WRITE_DISCARD,					//!<書き込み専用でマップをおこなう、マップをおこなうバッファが動的利用で作成されている必要がある
        BUFFERMAP_WRITE_NO_OVERWRITE,				//!<書き込み専用でマップをおこなう、マップをおこなうバッファが動的利用で作成されている必要がある

		BUFFERMAP_MAX,
	};

	/*******************************//*!
	@brief	ポリゴン描画構成列挙

			ポリゴン描画構成列挙。<br>
			ポリゴンのインデックスがどういった情報で構成されているかを定義する。

	@author	CDW
	*//********************************/
	typedef enum tag_PRIMITIVETOPOLOGY {
		PRIMITIVETOPOLOGY_POINTLIST,				//!<頂点のリストのみでポリゴンを構成する。
		PRIMITIVETOPOLOGY_LINELIST,					//!<線のリストでポリゴンを構成する。
		PRIMITIVETOPOLOGY_LINESTRIP,				//!<連続した線のリストでポリゴンを構成する。
		PRIMITIVETOPOLOGY_TRIANGLELIST,				//!<三角形のリストでポリゴンを形成する。
		PRIMITIVETOPOLOGY_TRIANGLESTRIP,			//!<連続した三角形のリストでポリゴンを形成する。
	}PrimitiveTopology;
	
	/*******************************//*!
	@brief	ポリゴン塗りつぶしモード列挙

			ポリゴン塗りつぶしモード列挙。

	@author	CDW
	*//********************************/
	typedef enum tag_FILLMODE {
		FILLMODE_SOLID,								//!<塗りつぶし描画
		FILLMODE_WIREFRAME,							//!<ワイヤーフレーム描画

		FILLMODE_MAX,
	}FillMode;
	
	/*******************************//*!
	@brief	カリングモード列挙

			カリングモード列挙。

	@author	CDW
	*//********************************/
	typedef enum tag_CULLMODE {
		CULLMODE_NONE,								//!<カリングをおこなわない
		CULLMODE_FRONT,								//!<前面をカリングする
		CULLMODE_BACK,								//!<背面をカリングする

		CULLMODE_MAX,
	}CullMode;

	/*******************************//*!
	@brief	ブレンディング方法列挙

			描画のアルファブレンディング方法を列挙

	@author	CDW
	*//********************************/
	typedef enum Blending {
		BLEND_NONE,								//!<ブレンディングなし
		BLEND_NORMAL,							//!<通常
		BLEND_ADD,								//!<加算合成
		BLEND_SUB,								//!<減算合成
		BLEND_SCREENADD,						//!<スクリーン加算
		BLEND_MULTIPLY,							//!<乗算合成
		BLEND_ONE,								//!<アルファ無視加算

		BLEND_MAX,								//!<最大数

		BLEND_USER,								//!<定義以外のユーザー指定のブレンド方法を設定中
	}Blending;
	
	/*******************************//*!
	@brief	比較方法列挙

			比較方法を列挙

	@author	CDW
	*//********************************/
	typedef enum tag_ComparisonFunc {
		COMPARISON_NEVER,
		COMPARISON_LESS,
		COMPARISON_EQUAL,
		COMPARISON_LESS_EQUAL,
		COMPARISON_GREATER,
		COMPARISON_NOT_EQUAL,
		COMPARISON_GREATER_EQUAL,
		COMPARISON_ALWAYS,
	}ComparisonFunc;

	/*******************************//*!
	@brief	ステンシル置き換え方法列挙

			ステンシルバッファ置き換え方法を列挙

	@author	CDW
	*//********************************/
	typedef enum tag_StencilOp {
		STENCIL_KEEP,							//!<ステンシルの情報を維持する
		STENCIL_ZERO,							//!<ステンシルの情報を０にする
		STENCIL_REPLACE,						//!<ステンシルの情報を参照値で上書きする
		STENCIL_INCR_SAT,						//!<ステンシルの情報のインクリメントをおこなう
		STENCIL_DECR_SAT,						//!<ステンシルの情報のデクリメントをおこなう
		STENCIL_INVERT,							//!<ステンシルの情報の反転をおこなう
		STENCIL_INCR,							//!<ステンシルの情報のインクリメントをおこなう
		STENCIL_DECR,							//!<ステンシルの情報のデクリメントをおこなう
	}StencilOp;

	/*******************************//*!
	@brief	頂点テンプレート列挙

			頂点の情報タイプを列挙

	@author	CDW
	*//********************************/
	typedef enum VertexFlag {
		VERTEXFLAG_UNKOWN			=	0x00000000,						//!<不明
		VERTEXFLAG_POSITION			=	0x00000001,						//!<頂点座標
		VERTEXFLAG_NORMAL			=	0x00000002,						//!<頂点法線
		VERTEXFLAG_TANGENT			=	0x00000004,						//!<頂点接線
		VERTEXFLAG_BINORMAL			=	0x00000008,						//!<頂点従法線
		VERTEXFLAG_TEXTURECOORDS1	=	0x00000010,						//!<頂点UV
		VERTEXFLAG_TEXTURECOORDS2	=	0x00000020,						//!<頂点UV
		VERTEXFLAG_TEXTURECOORDS3	=	0x00000040,						//!<頂点UV
		VERTEXFLAG_TEXTURECOORDS4	=	0x00000080,						//!<頂点UV
		VERTEXFLAG_COLOR1			=	0x00000100,						//!<頂点カラー
		VERTEXFLAG_COLOR2			=	0x00000200,						//!<頂点カラー
		VERTEXFLAG_COLOR3			=	0x00000400,						//!<頂点カラー
		VERTEXFLAG_COLOR4			=	0x00000800,						//!<頂点カラー
		VERTEXFLAG_COLORF1			=	0x00001000,						//!<頂点カラー
		VERTEXFLAG_COLORF2			=	0x00002000,						//!<頂点カラー
		VERTEXFLAG_COLORF3			=	0x00004000,						//!<頂点カラー
		VERTEXFLAG_COLORF4			=	0x00008000,						//!<頂点カラー

		VERTEXFLAG_WAIT1			=	0x00010000,						//!<頂点ウェイト１
		VERTEXFLAG_BLENDINDICES1	=	0x00020000,						//!<頂点ウェイト１
		VERTEXFLAG_WAIT2			=	0x00100000,						//!<頂点ウェイト２
		VERTEXFLAG_BLENDINDICES2	=	0x00200000,						//!<頂点ウェイト２
		VERTEXFLAG_WAIT3			=	0x01000000,						//!<頂点ウェイト３
		VERTEXFLAG_BLENDINDICES3	=	0x02000000,						//!<頂点ウェイト３
		VERTEXFLAG_WAIT4			=	0x10000000,						//!<頂点ウェイト４
		VERTEXFLAG_BLENDINDICES4	=	0x20000000,						//!<頂点ウェイト４
		
		VERTEXFLAG_WAIT				=	VERTEXFLAG_WAIT1,				//!<頂点ウェイト１
		VERTEXFLAG_BLENDINDICES		=	VERTEXFLAG_BLENDINDICES1,		//!<頂点ウェイト１

		VERTEXFLAG_POINTSIZE		=	0x00040000,						//!<頂点ポイントサイズ

		VERTEXFLAG_MATRIX			=	0x00080000,						//!<インスタンス用行列
		
		VERTEXFLAG_TEXTURECOORDSALL	=	0x000000F0,						//!<頂点UV
		VERTEXFLAG_COLORALL			=	0x0000FF00,						//!<頂点カラー
	}VertexFlag;

	/*******************************//*!
	@brief	ピクセルフォーマット列挙

			ピクセルフォーマットを列挙

	@author	CDW
	*//********************************/
	typedef enum tag_PixelFormat {
		PIXELFORMAT_UNKNOWN,											//!<不明なフォーマット

		PIXELFORMAT_R8G8B8A8_UNORM,										//!<RGBA各８ビットで構成する
		PIXELFORMAT_R16G16B16A16_UNORM,									//!<RGBA各１６ビットで構成する

		PIXELFORMAT_R16G16B16A16_FLOAT,									//!<RGBA各１６ビット浮動小数型で構成する
		PIXELFORMAT_R32G32B32A32_FLOAT,									//!<RGBA各３２ビット浮動小数型で構成する

		PIXELFORMAT_R16G16_FLOAT,										//!<RG各１６ビット浮動小数型で構成する
		PIXELFORMAT_R32G32_FLOAT,										//!<RG各３２ビット浮動小数型で構成する

		PIXELFORMAT_R16_FLOAT,											//!<R各１６ビット浮動小数型で構成する
		PIXELFORMAT_R32_FLOAT,											//!<R各３２ビット浮動小数型で構成する

		PIXELFORMAT_D32_FLOAT,											//!<深度３２ビット浮動小数型で構成する
		PIXELFORMAT_D24S8_UNORM,										//!<深度２４ビットとステンシル８ビットで構成する
		PIXELFORMAT_D32S8X24_FLOAT,										//!<深度３２ビットとステンシル８ビット浮動小数型で構成する
	}PixelFormat;
	
	/*******************************//*!
	@brief	バッファアクセスモード列挙

			バッファへのアクセスモードを列挙

	@author	CDW
	*//********************************/
	typedef enum tag_BufferAccess {
		BUFFERACCESS_GPUREADWRITE,
		BUFFERACCESS_GPUREAD,
		BUFFERACCESS_GPUREAD_CPUWRITE,
	}BufferAccess;
	
	/*******************************//*!
	@brief	平面軸列挙

			平面軸を列挙

	@author	CDW
	*//********************************/
	typedef enum tag_PlaneAxis {
		PLANEAXIS_XZ			=	0x01,		//!<XZ平面
		PLANEAXIS_XY			=	0x02,		//!<XY平面
		PLANEAXIS_YZ			=	0x04,		//!<YZ平面

		PLANEAXIS_ALL			=	0x07,		//!<全部
	}PlaneAxis;

	/*******************************//*!
	@brief	サンプリング方法列挙

			描画のテクスチャサンプリング方法を列挙

	@author	CDW
	*//********************************/
	enum tag_SAMPLER {
		SAMPLER_POINT,							//!<なし
		SAMPLER_LINER,							//!<線形補間
		SAMPLER_ANISOTROPIC,					//!<異方性フィルター

		SAMPLER_MAX,							//!<最大数

		SAMPLER_USER,							//!<定義以外のユーザー指定のテクスチャサンプリング方法を設定中
	};

	/*******************************//*!
	@brief	頂点データ

			レンダリング用の頂点データ<br>
			座標情報を保持する

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX {
		MofFloat					px;			//!<X座標
		MofFloat					py;			//!<Y座標
		MofFloat					pz;			//!<Z座標
	}VERTEX,*LPVERTEX;

	/*******************************//*!
	@brief	頂点データ

			レンダリング用の頂点データ<br>
			座標、色(U32)の情報を保持する

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_COLORU1 {
		MofFloat					px;			//!<X座標
		MofFloat					py;			//!<Y座標
		MofFloat					pz;			//!<Z座標

		MofU32						c;			//!<色
	}VERTEX_COLORU1,*LPVERTEX_COLORU1;

	/*******************************//*!
	@brief	頂点データ

			レンダリング用の頂点データ<br>
			座標、UVの情報を保持する

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_TEXTURE1 {
		MofFloat					px;			//!<X座標
		MofFloat					py;			//!<Y座標
		MofFloat					pz;			//!<Z座標

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV
	}VERTEX_TEXTURE1,*LPVERTEX_TEXTURE1;

	/*******************************//*!
	@brief	頂点データ

			レンダリング用の頂点データ<br>
			座標、UV、色(U32)の情報を保持する

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_TEXTURE1_COLORU1 {
		MofFloat					px;			//!<X座標
		MofFloat					py;			//!<Y座標
		MofFloat					pz;			//!<Z座標

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV

		MofU32						c;			//!<色
	}VERTEX_TEXTURE1_COLORU1,*LPVERTEX_TEXTURE1_COLORU1;

	/*******************************//*!
	@brief	頂点データ

			レンダリング用の頂点データ<br>
			座標、UV、色(U32)の情報を保持する

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_NORMAL_TEXTURE1_COLORU1 {
		MofFloat					px;			//!<X座標
		MofFloat					py;			//!<Y座標
		MofFloat					pz;			//!<Z座標

		MofFloat					nx;			//!<X法線
		MofFloat					ny;			//!<Y法線
		MofFloat					nz;			//!<Z法線

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV

		MofU32						c;			//!<色
	}VERTEX_NORMAL_TEXTURE1_COLORU1,*LPVERTEX_NORMAL_TEXTURE1_COLORU1;

	/*******************************//*!
	@brief	頂点データ

			レンダリング用の頂点データ<br>
			座標、色(U32)の情報を保持する

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_COLORF1 {
		MofFloat					px;			//!<X座標
		MofFloat					py;			//!<Y座標
		MofFloat					pz;			//!<Z座標

		MofFloat					cr;			//!<色
		MofFloat					cg;			//!<色
		MofFloat					cb;			//!<色
		MofFloat					ca;			//!<色
	}VERTEX_COLORF1,*LPVERTEX_COLORF1;

	/*******************************//*!
	@brief	頂点データ

			レンダリング用の頂点データ<br>
			座標、UV、色(U32)の情報を保持する

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_TEXTURE1_COLORF1 {
		MofFloat					px;			//!<X座標
		MofFloat					py;			//!<Y座標
		MofFloat					pz;			//!<Z座標

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV

		MofFloat					cr;			//!<色
		MofFloat					cg;			//!<色
		MofFloat					cb;			//!<色
		MofFloat					ca;			//!<色
	}VERTEX_TEXTURE1_COLORF1,*LPVERTEX_TEXTURE1_COLORF1;

	/*******************************//*!
	@brief	頂点データ

			レンダリング用の頂点データ<br>
			座標、UV、色(U32)の情報を保持する

	@author	CDW
	*//********************************/
	typedef struct tag_VERTEX_NORMAL_TEXTURE1_COLORF1 {
		MofFloat					px;			//!<X座標
		MofFloat					py;			//!<Y座標
		MofFloat					pz;			//!<Z座標

		MofFloat					nx;			//!<X法線
		MofFloat					ny;			//!<Y法線
		MofFloat					nz;			//!<Z法線

		MofFloat					tu;			//!<UV
		MofFloat					tv;			//!<UV

		MofFloat					cr;			//!<色
		MofFloat					cg;			//!<色
		MofFloat					cb;			//!<色
		MofFloat					ca;			//!<色
	}VERTEX_NORMAL_TEXTURE1_COLORF1,*LPVERTEX_NORMAL_TEXTURE1_COLORF1;

	/*******************************//*!
	@brief	プリミティブ情報入力コンスタントバッファ

	@author	CDW
	*//********************************/
	typedef struct tag_PrimitiveRenderParameter {
		Vector4					vOffset;
		Vector4					vSize;
		Vector4					Color1;
		Vector4					Color2;
		Vector4					Color3;
		Vector4					Color4;
		Matrix44				World;
	}PrimitiveRenderParameter,*LPPrimitiveRenderParameter;
	
	/*******************************//*!
	@brief	ビューポート情報構造体

			ビューポートの幅、高さなどビューポートの設定に必要な情報を集めた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_VIEWPORT {
		MofFloat				x;					//!<X座標
		MofFloat				y;					//!<Y座標
		MofFloat				w;					//!<幅
		MofFloat				h;					//!<高さ
		MofFloat				n;					//!<最近
		MofFloat				f;					//!<最遠
	}ViewPort,*LPViewPort;

}

//プラットフォームごとのインクルードと置き換え
#ifdef		MOFLIB_DIRECTX12
#include	"DirectX12/DX12Common.h"
#endif
#ifdef		MOFLIB_DIRECTX11
#include	"DirectX11/DX11Common.h"
#endif
#ifdef		MOFLIB_DIRECTX9
//LIBRARY
#pragma comment (lib,"d3d9.lib")
//INCLUDE
#include	<d3d9.h>
	typedef		LPDIRECT3DDEVICE9					MofGraphicsDevice;
	typedef		LPDIRECT3DSWAPCHAIN9				MofSwapChain;
	typedef		LPMofVoid							MofDeviceContext;
	typedef		LPDIRECT3DSURFACE9					MofRenderTarget;
	typedef		LPDIRECT3DSURFACE9					MofDepthTarget;
	typedef		LPDIRECT3DTEXTURE9					MofTexture;
	typedef		LPD3DXEFFECT						MofVertexShader;
	typedef		LPD3DXEFFECT						MofPixelShader;
	typedef		LPD3DXEFFECT						MofShaderEffect;
	typedef		ID3DX11Effect*						MofShaderEffect;
	typedef		LPDIRECT3DVERTEXBUFFER9				MofVertexBuffer;
	typedef		LPDIRECT3DVERTEXDECLARATION9		MofVertexLayout;
	typedef		LPDIRECT3DINDEXBUFFER9				MofIndexBuffer;
	typedef		MofU32								MofSamplerState;
#endif
#ifdef		MOFLIB_OPENGL
#include	"OpenGL/GLCommon.h"
#endif

#endif

//[EOF]
