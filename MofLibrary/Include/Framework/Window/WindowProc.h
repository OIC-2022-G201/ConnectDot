/*************************************************************************//*!
					
					@file	WindowProc.h
					@brief	ウインドウのメッセージ処理を行う基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINDOWPROC__H__

#define		__WINDOWPROC__H__

//INCLUDE
#include	"../../Math/MathCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ウインドウプロシージャ基底インターフェイス

			ウインドウのメッセージ処理を行う基底インターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IWindowProc : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コールされるプロシージャ
				@param[in]		hWnd		ウインドウハンドル
				@param[in]		msg			メッセージ
				@param[in]		wpar		パラメーター１
				@param[in]		lpar		パラメーター２
				
				@return			内部でメッセージ処理を行った場合その結果を、<br>
								それ以外はDefWindowProc関数を参照。
		*//**************************************************************************/
		virtual MofProcResult WindowProc(MofWindowHandle hWnd,MofUInt msg,MofProcParamW wpar,MofProcParamL lpar) = 0;
	};

}

#endif

//[EOF]