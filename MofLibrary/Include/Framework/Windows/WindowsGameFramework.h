/*************************************************************************//*!
					
					@file	WindowsGameFramework.h
					@brief	Windowsでのゲームフレームワークを提供するクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINDOWSGAMEFRAMEWORK__H__

#define		__WINDOWSGAMEFRAMEWORK__H__

//INCLUDE
#include	"../Window/Windows/WinWindow.h"
#include	"../GameFrameworkBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	Windowsでのゲームフレームワーククラス

			Windowsでのゲームフレームワーククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CWindowsGameFramework : public CGameFrameworkBase {
	protected:
		/*******************//*!
		インスタンスハンドル
		*//********************/
		MofInstanceHandle	m_Handle;
		/*******************//*!
		初期化終了フラグ
		*//********************/
		MofBool				m_bInitialize;
		/*******************//*!
		メインウインドウ
		*//********************/
		LPWindow			m_pWindow;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CWindowsGameFramework();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CWindowsGameFramework();
		/*************************************************************************//*!
				@brief			アプリケーションの実行
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Run(void);
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		/*************************************************************************//*!
				@brief			フレームワークハンドル取得
				@param			None
				
				@return			ハンドル
		*//**************************************************************************/
		virtual MofInstanceHandle GetHandle(void);
		/*************************************************************************//*!
				@brief			フレームワークウインドウ取得
				@param			None
				
				@return			ウインドウ
		*//**************************************************************************/
		virtual LPWindow GetWindow(void);
	};

	#include	"WindowsGameFramework.inl"
}

#endif

//[EOF]