/*************************************************************************//*!
					
					@file	DefWindowProc.h
					@brief	ウインドウズで標準的なウインドウのメッセージ処理を行う。<br>
							基本プロシージャクラス

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DEFWINDOWPROC__H__

#define		__DEFWINDOWPROC__H__

//INCLUDE
#include	"WindowBase.h"

namespace Mof {
	/*******************************//*!
	@brief	ウインドウプロシージャ基本メッセージ処理クラス

			ウインドウのメッセージ処理を行う基本メッセージ処理クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDefWindowProc : public IWindowProc {
	protected:
		/*******************//*!
		ウインドウインターフェイス
		*//********************/
		LPWindow			m_pWindow;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDefWindowProc();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pWnd		ウインドウ

				@return			None
		*//**************************************************************************/
		CDefWindowProc(LPWindow pWnd);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDefWindowProc();
		/*************************************************************************//*!
				@brief			コールされるプロシージャ
				@param[in]		hWnd		ウインドウハンドル
				@param[in]		msg			メッセージ
				@param[in]		wpar		パラメーター１
				@param[in]		lpar		パラメーター２
				
				@return			内部でメッセージ処理を行った場合その結果を、<br>
								それ以外はDefWindowProc関数を参照。
		*//**************************************************************************/
		virtual MofProcResult WindowProc(MofWindowHandle hWnd,MofUInt msg,MofProcParamW wpar,MofProcParamL lpar);
		
		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CDefWindowProc,MOF_DEFWINDOWPROCCLASS_ID);
	};

}

#endif

//[EOF]