/*************************************************************************//*!
					
					@file	Framework.h
					@brief	アプリケーションフレームワークの基底処理を提供するインターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__FRAMEWORK__H__

#define		__FRAMEWORK__H__

//INCLUDE
#include	"Window/Window.h"
#include	"../Common/Application.h"

namespace Mof {

	/*******************************//*!
	@brief	フレームワーク生成情報構造体

			フレームワークの生成に必要な情報をまとめた構造体<br>
			作成するフレームワークの種類によってこの構造体を継承した構造体を作成する。

	@author	CDW
	*//********************************/
	typedef struct tag_FRAMEWORKINITIALIZEINFO {
		MofU32					Size;			//!<構造体サイズ
		MofU32					Flag;			//!<フレームワーク初期化フラグ
		LPApplication			pApplication;	//!<アプリケーション動作インターフェイス

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_FRAMEWORKINITIALIZEINFO() : 
		Size(sizeof(tag_FRAMEWORKINITIALIZEINFO)) ,
		Flag(0) ,
		pApplication() {
		}
	}FRAMEWORKINITIALIZEINFO,*LPFRAMEWORKINITIALIZEINFO;

	/*******************************//*!
	@brief	アプリケーションフレームワーク基底インターフェイス

			アプリケーションフレームワークの全ての基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IFramework : public IMofObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			フレームワークの初期化
				@param[in]		pInfo		フレームワークの初期化情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Initialize(LPFRAMEWORKINITIALIZEINFO pInfo) = 0;
		/*************************************************************************//*!
				@brief			アプリケーションの実行
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Run(void) = 0;
		/*************************************************************************//*!
				@brief			フレームワークハンドル取得
				@param			None
				
				@return			ハンドル
		*//**************************************************************************/
		virtual MofInstanceHandle GetHandle(void) = 0;
		/*************************************************************************//*!
				@brief			フレームワークウインドウ取得
				@param			None
				
				@return			ウインドウ
		*//**************************************************************************/
		virtual LPWindow GetWindow(void) = 0;
	};
	
	//ポインタ置き換え
	typedef IFramework*			LPFramework;

}

#endif

//[EOF]