/*************************************************************************//*!
					
					@file	GLDepthTarget.h
					@brief	OpenGL深度ターゲットクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GLDEPTHTARGET__H__

#define		__GLDEPTHTARGET__H__

//INCLUDE
#include	"../DepthTarget.h"

namespace Mof {
	
	/*******************************//*!
	@brief	OpenGL深度ターゲットクラス

			OpenGL深度ターゲットクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLDepthTarget : public IDepthTarget {
	protected:
		/*******************//*!
		作成グラフィックス
		*//********************/
		LPGraphics				m_pGraphics;
		/*******************//*!
		深度ターゲット
		*//********************/
		MofDepthTarget			m_depthId;
		/*******************//*!
		クリア深度値
		*//********************/
		MofFloat				m_ClearDepth;
		/*******************//*!
		クリアステンシル値
		*//********************/
		MofU32					m_ClearStensil;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLDepthTarget();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLDepthTarget();
		/*************************************************************************//*!
				@brief			深度ターゲットの生成
				@param[in]		pGraphics	グラフィックスインターフェイス
				@param[in]		Width		深度バッファ幅
				@param[in]		Height		深度バッファ高さ
				@param[in]		Format		深度バッファフォーマット
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPGraphics pGraphics,MofU32 Width,MofU32 Height,PixelFormat Format);
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			クリア深度値取得設定
				@param			Value	クリア深度値

				@return			None
		*//**************************************************************************/
		virtual void SetClearDepth(MofFloat Value);
		/*************************************************************************//*!
				@brief			クリアステンシル値設定
				@param			Value	クリアステンシル値

				@return			None
		*//**************************************************************************/
		virtual void SetClearStencil(MofU32 Value);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			深度ターゲット取得
				@param			None

				@return			深度ターゲット
		*//**************************************************************************/
		virtual MofDepthTarget GetTarget(void);
		/*************************************************************************//*!
				@brief			クリア深度値取得
				@param			None

				@return			クリア深度値
		*//**************************************************************************/
		virtual MofFloat GetClearDepth(void);
		/*************************************************************************//*!
				@brief			クリアステンシル値取得
				@param			None

				@return			クリアステンシル値
		*//**************************************************************************/
		virtual MofU32 GetClearStencil(void);
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CGLDepthTarget,MOF_GLDEPTHTARGETCLASS_ID);
	};

	#include	"GLDepthTarget.inl"

	//置き換え
	typedef CGLDepthTarget		CDepthTarget;
}

#endif

//[EOF]
