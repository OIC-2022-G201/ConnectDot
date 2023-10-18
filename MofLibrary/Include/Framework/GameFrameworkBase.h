/*************************************************************************//*!
					
					@file	GameFrameworkBase.h
					@brief	ゲームフレームワークの基底処理を提供するクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GAMEFRAMEWORKBASE__H__

#define		__GAMEFRAMEWORKBASE__H__

//INCLUDE
#include	"Framework.h"
#include	"../Graphics/Graphics.h"
#include	"../Input/Input.h"
#include	"../Sound/Sound.h"

namespace Mof {

//!グラフィックス初期化フラグ
#define		MOF_FRAMEWORK_GRAPHICSINITIALIZE						0x00000001
//!サウンド初期化フラグ
#define		MOF_FRAMEWORK_SOUNDINITIALIZE							0x00000002
//!インプット初期化フラグ
#define		MOF_FRAMEWORK_INPUTINITIALIZE							0x00000004
//!アプリケーション初期化フラグ
#define		MOF_FRAMEWORK_APPLICATIONINITIALIZE						0x00000008
//!基本初期化フラグ
#define		MOF_FRAMEWORK_DEFAULTINITIALIZE							(MOF_FRAMEWORK_GRAPHICSINITIALIZE | MOF_FRAMEWORK_SOUNDINITIALIZE | MOF_FRAMEWORK_INPUTINITIALIZE | MOF_FRAMEWORK_APPLICATIONINITIALIZE)

	/*******************************//*!
	@brief	ゲームフレームワーク生成情報構造体

			ゲームフレームワークの生成に必要な情報をまとめた構造体<br>
			作成するフレームワークの種類によってこの構造体を継承した構造体を作成する。

	@author	CDW
	*//********************************/
	typedef struct tag_GAMEFRAMEWORKINITIALIZEINFO : public FRAMEWORKINITIALIZEINFO {
		MofU32					FPS;			//!<FPS

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GAMEFRAMEWORKINITIALIZEINFO() :
		FRAMEWORKINITIALIZEINFO() ,
		FPS(60) {
			Size = sizeof(tag_GAMEFRAMEWORKINITIALIZEINFO);
			Flag = MOF_FRAMEWORK_DEFAULTINITIALIZE;
		}
	}GAMEFRAMEWORKINITIALIZEINFO,*LPGAMEFRAMEWORKINITIALIZEINFO;
	
	/*******************************//*!
	@brief	ゲームフレームワーク基底クラス

			ゲームフレームワークの全ての基底となるクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGameFrameworkBase : public IFramework {
	protected:
		/*******************//*!
		動作アプリケーション
		*//********************/
		LPApplication		m_pApplication;
		/*******************//*!
		グラフィックス
		*//********************/
		LPGraphics			m_pGraphics;
		/*******************//*!
		インプット
		*//********************/
		LPInput				m_pInput;
		/*******************//*!
		サウンド
		*//********************/
		LPSound				m_pSound;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGameFrameworkBase();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGameFrameworkBase();
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
	private:
		//コピーを禁止する
		CGameFrameworkBase(const CGameFrameworkBase& pObj){};
	};

}

#endif

//[EOF]