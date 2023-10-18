/*************************************************************************//*!
					
					@file	AndroidJNIGameFramework.h
					@brief	AndroidJNIでのゲームフレームワークを提供するクラス。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__ANDROIDJNIGAMEFRAMEWORK__H__

#define		__ANDROIDJNIGAMEFRAMEWORK__H__

//INCLUDE
#include	"../GameFrameworkBase.h"
#include	"../../Graphics/OpenGL/GLGraphics.h"
#include	"../../Sound/OpenSL/SLSound.h"
#include	"../../Input/Android/AndroidInput.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ゲームフレームワーク生成情報構造体

			ゲームフレームワークの生成に必要な情報をまとめた構造体<br>
			作成するフレームワークの種類によってこの構造体を継承した構造体を作成する。

	@author	濱田　享
	*//********************************/
	typedef struct tag_ANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO : public GAMEFRAMEWORKINITIALIZEINFO {
		WINDOWCREATEINFO		WindowCreateInfo;	//!<メインウインドウ生成情報
		GRAPHICSCREATEINFO		GraphicsCreateInfo;	//!<グラフィックス生成情報
		INPUTCREATEINFO			InputCreateInfo;	//!<インプット生成情報
		SOUNDCREATEINFO			SoundCreateInfo;	//!<サウンド生成情報

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_ANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO() :
		GAMEFRAMEWORKINITIALIZEINFO() ,
		WindowCreateInfo() ,
		GraphicsCreateInfo() ,
		InputCreateInfo() ,
		SoundCreateInfo() {
			Size = sizeof(tag_ANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO);
			Flag = MOF_FRAMEWORK_SOUNDINITIALIZE | MOF_FRAMEWORK_INPUTINITIALIZE;
		}
	}ANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO,*LPANDROIDJNIGAMEFRAMEWORKINITIALIZEINFO;
	
	/*******************************//*!
	@brief	AndroidJNIでのゲームフレームワーククラス

			AndroidJNIでのゲームフレームワーククラス。

	@author	濱田　享
	*//********************************/
	class MOFLIBRARY_API CAndroidJNIGameFramework : public CGameFrameworkBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CAndroidJNIGameFramework();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CAndroidJNIGameFramework();
		/*************************************************************************//*!
				@brief			フレームワークの初期化
				@param[in]		pInfo		フレームワークの初期化情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Initialize(LPFRAMEWORKINITIALIZEINFO pInfo);
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
		
		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CAndroidJNIGameFramework,MOF_ANDROIDJNIGAMEFRAMEWORKCLASS_ID);
	};
	
	#include	"AndroidJNIGameFramework.inl"
}

#endif

//[EOF]
