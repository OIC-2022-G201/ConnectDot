/*************************************************************************//*!
					
					@file	DX11GameFramework.h
					@brief	DX11でのゲームフレームワークを提供するクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11GAMEFRAMEWORK__H__

#define		__DX11GAMEFRAMEWORK__H__

//INCLUDE
#include	"../WindowsGameFramework.h"
#include	"../../../Graphics/DirectX11/DX11Graphics.h"
#include	"../../../Input/DirectInput/DirectInput.h"
#include	"../../../Sound/XAudio/XAudioSound.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ゲームフレームワーク生成情報構造体

			ゲームフレームワークの生成に必要な情報をまとめた構造体<br>
			作成するフレームワークの種類によってこの構造体を継承した構造体を作成する。

	@author	CDW
	*//********************************/
	typedef struct tag_WINDOWSGAMEFRAMEWORKINITIALIZEINFO : public GAMEFRAMEWORKINITIALIZEINFO {
		WINDOWCREATEINFO			WindowCreateInfo;	//!<メインウインドウ生成情報
		DIRECTGRAPHICSCREATEINFO	GraphicsCreateInfo;	//!<グラフィックス生成情報
		DIRECTINPUTCREATEINFO		InputCreateInfo;	//!<インプット生成情報
		SOUNDCREATEINFO				SoundCreateInfo;	//!<サウンド生成情報

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_WINDOWSGAMEFRAMEWORKINITIALIZEINFO() :
		WindowCreateInfo() ,
		GraphicsCreateInfo() ,
		InputCreateInfo() ,
		SoundCreateInfo() ,
		GAMEFRAMEWORKINITIALIZEINFO() {
			Size = sizeof(tag_WINDOWSGAMEFRAMEWORKINITIALIZEINFO);
		}
	}WINDOWSGAMEFRAMEWORKINITIALIZEINFO,*LPWINDOWSGAMEFRAMEWORKINITIALIZEINFO;
	
	/*******************************//*!
	@brief	DX11でのゲームフレームワーククラス

			DX11でのゲームフレームワーククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11GameFramework : public CWindowsGameFramework {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11GameFramework();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11GameFramework();
		/*************************************************************************//*!
				@brief			フレームワークの初期化<br>
								下記の順序でフレームワークの初期化を実行します。<br>
								・ウインドウの生成<br>
								・DirectX11Graphicsの初期化<br>
								・DirectInputの初期化<br>
								・XAudio2の初期化<br>
								・アプリケーションの初期化<br>
								内部で利用しない機能が存在する場合、引数のpInfo->Flagメンバにて初期化フラグを設定してください。
				@param[in]		pInfo		フレームワークの初期化情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Initialize(LPFRAMEWORKINITIALIZEINFO pInfo);
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CDX11GameFramework,MOF_DX11GAMEFRAMEWORKCLASS_ID);
	};

}

#endif

//[EOF]