/*************************************************************************//*!
					
					@file	AndroidSingleGameApplication.h
					@brief	Android上でのゲームアプリケーションの動作をライブラリ利用者が作成するための基底クラス。<br>
							ゲームのRun内でAndroid用のメッセージ処理とシングルスレッドで更新と描画が実行される。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ANDROIDSINGLEGAMEAPPLICATION__H__

#define		__ANDROIDSINGLEGAMEAPPLICATION__H__

//INCLUDE
#include	"Application.h"

namespace Mof {

	/*******************************//*!
	@brief	Android上でのゲームアプリケーションの動作をライブラリ利用者が作成するための基底クラス

			Android上でのゲームアプリケーションの動作をライブラリ利用者が作成するための基底クラス。<br>
			ゲームのRun内でAndroid用のメッセージ処理とシングルスレッドで更新と描画が実行される。

	@author	濱田　享
	*//********************************/
	class MOFLIBRARY_API CAndroidSingleGameApplication : public IApplication {
	private:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CAndroidSingleGameApplication();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAndroidSingleGameApplication();
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
		MOF_LIBRARYCLASS_NOTCOPY(CAndroidSingleGameApplication,MOF_ANDROIDSINGLEGAMEAPPLICATIONCLASS_ID);
	};
	
	#include	"AndroidSingleGameApplication.inl"
	
	//置き換え
	typedef CAndroidSingleGameApplication		CSingleGameApplication;
}

#endif

//[EOF]