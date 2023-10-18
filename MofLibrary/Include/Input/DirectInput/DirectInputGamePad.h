/*************************************************************************//*!
					
					@file	DirectInputGamePad.h
					@brief	DirectInputでのゲームパッドでの各種入力の処理を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DIRECTINPUTGAMEPAD__H__

#define		__DIRECTINPUTGAMEPAD__H__

//INCLUDE
#include	"../GamePad.h"
				
namespace Mof {
	
	/*******************************//*!
	@brief	ゲームパッド生成情報構造体

			ゲームパッドの生成に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_DXGAMEPADCREATEINFO : public tag_GAMEPADCREATEINFO {
		LPWindow				pWindow;					//!<ウインドウ
		MofInputDevice			pInput;						//!<入力
		LPDIDEVICEINSTANCE		pInstance;					//!<デバイスインスタンス

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_DXGAMEPADCREATEINFO() :
		pWindow(NULL) ,
		pInput(NULL) ,
		pInstance(NULL) ,
		tag_GAMEPADCREATEINFO() {
			Size = sizeof(tag_DXGAMEPADCREATEINFO);
		}
	}DXGAMEPADCREATEINFO,*LPDXGAMEPADCREATEINFO;
	
	/*******************************//*!
	@brief	DirectInputゲームパッドクラス

			DirectInputゲームパッドの管理、入力処理を行うクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDXGamePad : public IGamePad {
	protected:
		/*******************//*!
		ゲームパッド
		*//********************/
		LPDIRECTINPUTDEVICE8	m_pGanePad;
		/*******************//*!
		入力情報
		*//********************/
		DIJOYSTATE2				m_PadState;
		/*******************//*!
		直前の入力情報
		*//********************/
		DIJOYSTATE2				m_PrevPadState;
		/*******************//*!
		ゲームパッド情報
		*//********************/
		DIDEVICEINSTANCE		m_PadInfo;

		/*************************************************************************//*!
				@brief			内部ゲームパッド軸定義
				@param[in]		DIDOInst		デバイスインスタンス情報
				@param[in]		ref				LPDIRECTINPUTDEVICEへの参照
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool CALLBACK EnumAxesCallback(LPCDIDEVICEOBJECTINSTANCE DIDOInst,LPMofVoid ref);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDXGamePad();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDXGamePad();
		
		/*************************************************************************//*!
				@brief			ゲームパッドオブジェクトの生成
				@param[in]		pInfo		ゲームパッドの生成情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPGAMEPADCREATEINFO pInfo);

		/*************************************************************************//*!
				@brief			入力キー更新
				@param			None

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool RefreshKey(void);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
				
		/*************************************************************************//*!
				@brief			ゲームパッドキー入力状態判定<br>
								キー番号のキーのPush(このフレームで入力された)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyPush(const MofU8 n) const;
		/*************************************************************************//*!
				@brief			ゲームパッドキー入力状態判定<br>
								キー番号のキーのHold(このフレームで入力されている)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyHold(const MofU8 n) const;
		/*************************************************************************//*!
				@brief			ゲームパッドキー入力状態判定<br>
								キー番号のキーのPull(このフレームで放された)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyPull(const MofU8 n) const;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			パッド取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param			None

				@return			パッド状態
		*//**************************************************************************/
		virtual MofGamePad GetPad(void);
		/*************************************************************************//*!
				@brief			パッド状態取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param			None

				@return			パッド状態
		*//**************************************************************************/
		virtual MofGamePadState* GetPadState(void);
		/*************************************************************************//*!
				@brief			パッド状態取得<br>
								スティックの横への傾きを取得する。
				@param			None

				@return			スティック横入力量(-1.0～1.0)
		*//**************************************************************************/
		virtual MofFloat GetStickHorizontal(void) const;
		/*************************************************************************//*!
				@brief			パッド状態取得<br>
								スティックの縦への傾きを取得する。
				@param			None

				@return			スティック縦入力量(-1.0～1.0)
		*//**************************************************************************/
		virtual MofFloat GetStickVertical(void) const;
		

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CDXGamePad,MOF_DXINPUTGAMEPADCLASS_ID);
	};

	#include	"DirectInputGamePad.inl"
}

#endif

//[EOF]