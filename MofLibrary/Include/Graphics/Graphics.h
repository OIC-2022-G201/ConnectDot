/*************************************************************************//*!
					
					@file	Graphics.h
					@brief	グラフィックスの処理を行う基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GRAPHICS__H__

#define		__GRAPHICS__H__

//INCLUDE
#include	"VertexBuffer.h"
#include	"IndexBuffer.h"

namespace Mof {

	// 前方定義
	class IRenderTarget;
	typedef IRenderTarget* LPRenderTarget;
	class IDepthTarget;
	typedef IDepthTarget* LPDepthTarget;
	class IShader;
	typedef IShader* LPShader;

	/*******************************//*!
	@brief	グラフィックス生成情報構造体

			グラフィックスの生成に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_GRAPHICSCREATEINFO {
		MofU32					Size;						//!<構造体サイズ
		MofU32					Buffers;					//!<バッファの数
		MofBool					bMultiThread;				//!<マルチスレッド利用フラグ
		MofBool					bMSAA;						//!<MSAA有効フラグ
		MofU32					RefreshRate;				//!<リフレッシュレート
		MofU32					Flags;						//!<生成フラグ

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GRAPHICSCREATEINFO() :
		Size(sizeof(tag_GRAPHICSCREATEINFO)),
		Buffers(1) ,
		bMultiThread(TRUE) ,
		bMSAA(TRUE) ,
		RefreshRate(60) ,
		Flags(0) {
		}
	}GRAPHICSCREATEINFO,*LPGRAPHICSCREATEINFO;
	
	/*******************************//*!
	@brief	ディスプレイモード情報構造体

			ディスプレイモード構造体

	@author	CDW
	*//********************************/
	typedef struct tag_DISPLAYMODE {
		MofS32					RefreshRate;				//!<リフレッシュレート
		MofS32					Width;						//!<幅
		MofS32					Height;						//!<高さ
	}DISPLAYMODE,*LPDISPLAYMODE;

	/*******************************//*!
	@brief	ディスプレイモード情報リスト構造体

			ディスプレイモードを列挙した構造体

	@author	CDW
	*//********************************/
	typedef struct tag_DISPLAYMODELIST {
		MofU32					DisplayModeCount;			//!<ディスプレイモード数
		LPDISPLAYMODE			pMode;						//!<モード
			
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_DISPLAYMODELIST() :
		DisplayModeCount(0) ,
		pMode(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~tag_DISPLAYMODELIST() {
			MOF_SAFE_DELETE_ARRAY(pMode);
		}
	}DISPLAYMODELIST,*LPDISPLAYMODELIST;
	
	/*******************************//*!
	@brief	グラフィックスステータス構造体

			グラフィックスのステータスを表す構造体

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_GRAPHICSSTATUS {
		//----------------------------------------------------------------------------
		////現在の設定を保存するためのパラメーター
		//----------------------------------------------------------------------------
		Blending				BlendType[MOF_RENDERTARGET_MAX];						//!<現在の設定ブレンドタイプ
		MofBool					bColorWriteEnable;										//!<色書き込み有効フラグ
		MofBool					bMSAA;													//!<MSAA有効フラグ
		MofU32					MSAACount;												//!<MSAA設定
		MofU32					MSAAQuality;											//!<MSAA設定
		MofBool					bAlphaToCoverageEnable;									//!<標準のブレンドステートでのアルファカバレッジフラグ
		MofBool					bDepthEnable;											//!<深度バッファ有効フラグ
		MofBool					bDepthWriteEnable;										//!<深度バッファ書き込み有効フラグ
		ComparisonFunc			DepthFunc;												//!<深度バッファ比較関数
		MofBool					bStencilEnable;											//!<ステンシルバッファ有効フラグ
		MofU32					StencilRef;												//!<ステンシル比較値
		ComparisonFunc			StencilFunc;											//!<置き換え関数
		StencilOp				StencilPassOp;											//!<置き換え関数
		StencilOp				StencilZFailOp;											//!<置き換え関数
		StencilOp				StencilFailOp;											//!<置き換え関数
		PrimitiveTopology		Topology;												//!<現在の設定プリミティブ描画方法
		FillMode				FillType;												//!<現在の設定塗りつぶしモード
		CullMode				CullType;												//!<現在の設定カリングモード
		LPVertexBuffer			pVertexBuffer;											//!<現在の設定頂点バッファ
		LPIndexBuffer			pIndexBuffer;											//!<現在の設定インデックスバッファ
		MofVertexLayout			pVertexLayout;											//!<現在の設定頂点レイアウト
		LPRenderTarget			pRenderTargets[MOF_RENDERTARGET_MAX];					//!<描画ターゲット
		LPDepthTarget			pDepthTarget;											//!<深度ターゲット
		MofU32					RenderTargetCount;										//!<描画ターゲットの数
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GRAPHICSSTATUS() :
		bColorWriteEnable(TRUE) ,
		bMSAA(TRUE) ,
		MSAACount(1) ,
		MSAAQuality(0) ,
		bAlphaToCoverageEnable(FALSE) ,
		bDepthEnable(FALSE) ,
		bDepthWriteEnable(TRUE) ,
		DepthFunc(COMPARISON_LESS) ,
		bStencilEnable(FALSE) ,
		StencilRef(0) ,
		StencilFunc(COMPARISON_NEVER) ,
		StencilPassOp(STENCIL_KEEP) ,
		StencilZFailOp(STENCIL_KEEP) ,
		StencilFailOp(STENCIL_KEEP) ,
		Topology(PRIMITIVETOPOLOGY_POINTLIST) ,
		FillType(FILLMODE_SOLID) ,
		CullType(CULLMODE_BACK) ,
		pVertexBuffer(NULL) ,
		pIndexBuffer(NULL) ,
		pVertexLayout(NULL),
		pDepthTarget(NULL),
		RenderTargetCount(1) {
			memset(pRenderTargets, 0, sizeof(LPRenderTarget) * MOF_RENDERTARGET_MAX);
			for (int i = 0; i < MOF_RENDERTARGET_MAX; i++)
			{
				BlendType[i] = BLEND_NORMAL;
			}
		}
	}GRAPHICSSTATUS,*LPGRAPHICSSTATUS;

	/*******************************//*!
	@brief	グラフィックス基底インターフェイス

			グラフィックスの基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IGraphics : public IMofObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			グラフィックスオブジェクトの生成
				@param[in]		pInfo		グラフィックスの生成情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPGRAPHICSCREATEINFO pInfo) = 0;
		
		/*************************************************************************//*!
				@brief			画面モードを設定する<br>
								Windows版のみ処理を実行する。<br>
								Android版ではこの処理の結果は必ずFALSEになる。
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeScreenMode(void) = 0;

		/*************************************************************************//*!
				@brief			描画の開始
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderStart(void) = 0;
		/*************************************************************************//*!
				@brief			全ターゲットのクリア
				@param[in]		d			深度
				@param[in]		s			ステンシル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ClearTarget(void) = 0;
		/*************************************************************************//*!
				@brief			全ターゲットのクリア
				@param[in]		r			赤
				@param[in]		g			緑
				@param[in]		b			青
				@param[in]		a			アルファ
				@param[in]		d			深度
				@param[in]		s			ステンシル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ClearTarget(MofFloat r,MofFloat g,MofFloat b,MofFloat a,MofFloat d,MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			描画ターゲットのクリア
				@param[in]		r			赤
				@param[in]		g			緑
				@param[in]		b			青
				@param[in]		a			アルファ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ClearRenderTarget(MofFloat r,MofFloat g,MofFloat b,MofFloat a) = 0;
		/*************************************************************************//*!
				@brief			深度ステンシルターゲットのクリア
				@param[in]		d			深度
				@param[in]		s			ステンシル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ClearDepthStencilTarget(MofFloat d,MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			深度ターゲットのクリア
				@param[in]		d			深度
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ClearDepthTarget(MofFloat d) = 0;
		/*************************************************************************//*!
				@brief			ステンシルターゲットのクリア
				@param[in]		s			ステンシル
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ClearStencilTarget(MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			描画の終了
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderEnd(void) = 0;
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			描画用バッファサイズを設定する
				@param[in]		sw				幅
				@param[in]		sh				高さ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBackBufferSize(MofS32 sw, MofS32 sh) = 0;
		/*************************************************************************//*!
				@brief			スクリーンモードを設定する
				@param[in]		m			TRUE:ウインドウモード、:FALSE:フルスクリーンモード

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetScreenMode(MofBool m) = 0;
		/*************************************************************************//*!
				@brief			描画用画面サイズを設定する
				@param[in]		sw				幅
				@param[in]		sh				高さ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetScreenSize(MofS32 sw,MofS32 sh) = 0;
		/*************************************************************************//*!
				@brief			ビューポート設定
				@param[in]		px			X位置
				@param[in]		py			Y位置
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		n			最近
				@param[in]		f			最遠
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPort(const MofFloat px,const MofFloat py,const MofFloat w,const MofFloat h,const MofFloat n,const MofFloat f) = 0;
		/*************************************************************************//*!
				@brief			ビューポート設定
				@param[in]		v			ビューポート
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPort(const ViewPort& v) = 0;
		/*************************************************************************//*!
				@brief			ブレンドステートの設定
				@param[in]		Blend		ブレンド方法
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBlending(Blending Blend) = 0;
		/*************************************************************************//*!
				@brief			ブレンドステートの設定
				@param[in]		Blend		ブレンド方法
				@param[in]		target		ターゲット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBlending(Blending Blend, MofS32 target) = 0;
		/*************************************************************************//*!
				@brief			色書き込みの設定
				@param[in]		bEnable		有効フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetColorWriteEnable(MofBool bEnable) = 0;
		/*************************************************************************//*!
				@brief			深度バッファの設定
				@param[in]		bEnable		判定有効フラグ
				@param[in]		bWEnable	書き込み有効フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable,MofBool bWEnable) = 0;
		/*************************************************************************//*!
				@brief			深度バッファの設定
				@param[in]		bEnable		判定有効フラグ
				@param[in]		bWEnable	書き込み有効フラグ
				@param[in]		fn			比較関数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable,MofBool bWEnable,ComparisonFunc fn) = 0;
		/*************************************************************************//*!
				@brief			深度バッファの設定
				@param[in]		bEnable		有効フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDepthEnable(MofBool bEnable) = 0;
		/*************************************************************************//*!
				@brief			深度バッファ書き込みの設定
				@param[in]		bEnable		有効フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDepthWriteEnable(MofBool bEnable) = 0;
		/*************************************************************************//*!
				@brief			深度バッファの設定
				@param[in]		fn			比較関数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDepthFunction(ComparisonFunc fn) = 0;
		/*************************************************************************//*!
				@brief			ステンシルバッファの設定
				@param[in]		bEnable		有効フラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetStencilEnable(MofBool bEnable) = 0;
		/*************************************************************************//*!
				@brief			ステンシルバッファの設定
				@param[in]		ref			設定数値
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetStencilValue(MofU32 ref) = 0;
		/*************************************************************************//*!
				@brief			ステンシルバッファの設定
				@param[in]		fn			置き換え比較関数
				@param[in]		PassOp		置き換え比較関数
				@param[in]		ZFailOp		置き換え比較関数
				@param[in]		FailOp		置き換え比較関数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetStencilControl(ComparisonFunc fn,StencilOp PassOp,StencilOp ZFailOp,StencilOp FailOp) = 0;
		/*************************************************************************//*!
				@brief			プリミティブ描画方法設定
				@param[in]		Topology	描画方法
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTopology(PrimitiveTopology Topology) = 0;
		/*************************************************************************//*!
				@brief			塗りつぶし描画方法設定
				@param[in]		Mode		塗りつぶし方法
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetFillMode(FillMode Mode) = 0;
		/*************************************************************************//*!
				@brief			カリング方法設定
				@param[in]		Mode		カリング方法
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetCullMode(CullMode Mode) = 0;
		/*************************************************************************//*!
				@brief			シェーダー設定
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetShader(LPShader pShader) = 0;
		/*************************************************************************//*!
				@brief			頂点バッファ設定
				@param[in]		pBuff		頂点バッファ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff) = 0;
		/*************************************************************************//*!
				@brief			頂点バッファ設定
				@param[in]		pBuff1		頂点バッファ
				@param[in]		pBuff2		頂点バッファ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetVertexBuffer(LPVertexBuffer pBuff1, LPVertexBuffer pBuff2) = 0;
		/*************************************************************************//*!
				@brief			頂点レイアウト設定
				@param[in]		pLayout		頂点レイアウト
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetVertexLayout(MofVertexLayout pLayout) = 0;
		/*************************************************************************//*!
				@brief			インデックスバッファ設定
				@param[in]		pBuff		インデックスバッファ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetIndexBuffer(LPIndexBuffer pBuff) = 0;
		/*************************************************************************//*!
				@brief			描画ターゲット設定
				@param[in]		pRenderTarget	描画ターゲット
				@param[in]		pDepthTarget	深度ターゲット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetRenderTarget(LPRenderTarget pRenderTarget, LPDepthTarget pDepthTarget) = 0;
		/*************************************************************************//*!
				@brief			描画ターゲット設定
				@param[in]		NumViews		描画ターゲットの数
				@param[in]		ppRenderTarget	描画ターゲット配列へのポインタ
				@param[in]		pDepthTarget	深度ターゲット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetMultiRenderTarget(MofU32 NumViews,LPRenderTarget* ppRenderTarget,LPDepthTarget pDepthTarget) = 0;
		/*************************************************************************//*!
				@brief			描画ターゲット数を変えずに指定した番号の描画ターゲットを差し替える
				@param[in]		index			インデックス
				@param[in]		pRenderTarget	描画ターゲット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetRenderTargetAt(MofU32 index,LPRenderTarget pRenderTarget) = 0;
		/*************************************************************************//*!
				@brief			描画ターゲット数を変えずに指定した番号の描画ターゲットを差し替える
				@param[in]		index			インデックス
				@param[in]		pRenderTarget	描画ターゲット
				@param[in]		pDepthTarget	深度ターゲット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetRenderTargetAt(MofU32 index,LPRenderTarget pRenderTarget, LPDepthTarget pDepthTarget) = 0;
		/*************************************************************************//*!
				@brief			描画ターゲット数設定
				@param			NumViews	描画ターゲット数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetRenderTargetCount(MofU32 NumViews) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			グラフィックスデバイス取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param			None

				@return			グラフィックスデバイス
		*//**************************************************************************/
		virtual MofGraphicsDevice GetDevice(void) = 0;
		/*************************************************************************//*!
				@brief			スワップチェイン取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param			None

				@return			スワップチェイン
		*//**************************************************************************/
		virtual MofSwapChain GetSwapChain(void) = 0;
		/*************************************************************************//*!
				@brief			コンテキスト取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param			None

				@return			コンテキスト
		*//**************************************************************************/
		virtual MofDeviceContext GetDeviceContext(void) = 0;
		/*************************************************************************//*!
				@brief			サンプラーステート取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param[in]		s		取得するサンプルタイプ(tag_SAMPLER列挙体の値を設定する)

				@return			サンプラーステート
		*//**************************************************************************/
		virtual MofSamplerState GetSamplerState(MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			ターゲットウインドウの幅取得
				@param			None

				@return			ターゲットウインドウの幅
		*//**************************************************************************/
		virtual MofS32 GetTargetWidth(void) = 0;
		/*************************************************************************//*!
				@brief			ターゲットウインドウの高さ取得
				@param			None

				@return			ターゲットウインドウの高さ
		*//**************************************************************************/
		virtual MofS32 GetTargetHeight(void) = 0;
		/*************************************************************************//*!
				@brief			対応画面サイズリスト取得設定
				@param[out]		pList		インデックスバッファ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool GetDisplayModeList(LPDISPLAYMODELIST pList) = 0;
		/*************************************************************************//*!
				@brief			設定情報取得
				@param			None
				
				@return			グラフィック設定
		*//**************************************************************************/
		virtual const GRAPHICSSTATUS& GetStatus(void) = 0;
		/*************************************************************************//*!
				@brief			現在の描画ターゲット取得
				@param			None
				
				@return			現在の描画ターゲット
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTarget(void) = 0;
		/*************************************************************************//*!
				@brief			指定した番号の描画ターゲット取得
				@param[in]		index		インデックス
				
				@return			現在の描画ターゲット
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTargetAt(MofU32 index) = 0;
		/*************************************************************************//*!
				@brief			現在の描画ターゲット数を取得
				@param			None
				
				@return			現在の描画ターゲット数
		*//**************************************************************************/
		virtual MofU32 GetRenderTargetCount(void) = 0;
		/*************************************************************************//*!
				@brief			現在の深度ターゲット取得
				@param[out]		None
				
				@return			現在の深度ターゲット
		*//**************************************************************************/
		virtual LPDepthTarget GetDepthTarget(void) = 0;
		/*************************************************************************//*!
				@brief			ブレンドステート取得
				@param[out]		None
				
				@return			現在のブレンドステート
		*//**************************************************************************/
		virtual Blending GetBlending(void) = 0;
	};

	//ポインタ置き換え
	typedef IGraphics*			LPGraphics;
}

#endif

//[EOF]