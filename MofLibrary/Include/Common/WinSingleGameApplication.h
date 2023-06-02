/*************************************************************************//*!
					
					@file	WinSingleGameApplication.h
					@brief	Windows上でのゲームアプリケーションの動作をライブラリ利用者が作成するための基底クラス。<br>
							ゲームのRun内でWindows用のメッセージ処理とシングルスレッドで更新と描画が実行される。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__WINSINGLEGAMEAPPLICATION__H__

#define		__WINSINGLEGAMEAPPLICATION__H__

//INCLUDE
#include	"Application.h"

namespace Mof {

	/*******************************//*!
	@brief	Windows上でのゲームアプリケーションの動作をライブラリ利用者が作成するための基底クラス

			Windows上でのゲームアプリケーションの動作をライブラリ利用者が作成するための基底クラス。<br>
			ゲームのRun内でWindows用のメッセージ処理とシングルスレッドで更新と描画が実行される。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CWinSingleGameApplication : public IApplication {
	private:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CWinSingleGameApplication();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CWinSingleGameApplication();
		/*************************************************************************//*!
				@brief			アプリケーションの初期化
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Initialize(void);
		/*************************************************************************//*!
				@brief			アプリケーションの実行
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Run(void);
		/*************************************************************************//*!
				@brief			アプリケーションの更新
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Update(void);
		/*************************************************************************//*!
				@brief			アプリケーションの描画
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(void);
		/*************************************************************************//*!
				@brief			アプリケーションの解放
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Release(void);
		
		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CWinSingleGameApplication,MOF_WINSINGLEGAMEAPPLICATIONCLASS_ID);
	};

	#include	"WinSingleGameApplication.inl"
	
	//置き換え
	typedef CWinSingleGameApplication		CSingleGameApplication;
}

#endif

//[EOF]