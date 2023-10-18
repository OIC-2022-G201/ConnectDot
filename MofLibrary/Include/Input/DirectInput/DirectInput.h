/*************************************************************************//*!
					
					@file	DirectInput.h
					@brief	DirectInputでの各種入力の処理を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DIRECTINPUT__H__

#define		__DIRECTINPUT__H__

//INCLUDE
#include	"../Input.h"

namespace Mof {
	
	/*******************************//*!
	@brief	インプット生成情報構造体

			インプット生成に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_DIRECTINPUTCREATEINFO : public tag_INPUTCREATEINFO {
		LPWindow				pWindow;					//!<ウインドウ

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_DIRECTINPUTCREATEINFO() :
		tag_INPUTCREATEINFO() ,
		pWindow(NULL) {
			Size = sizeof(tag_DIRECTINPUTCREATEINFO);
		}
	}DIRECTINPUTCREATEINFO,*LPDIRECTINPUTCREATEINFO;
	
	/*******************************//*!
	@brief	ゲームパッド列挙情報構造体

			ゲームパッドの列挙に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_GAMEPADENUMINFO {
		LPWindow				pWindow;					//!<ウインドウ
		MofInputDevice			pInput;						//!<入力
		LPGamePadArray			pPadArray;					//!<パッド列挙

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GAMEPADENUMINFO() :
		pWindow(NULL) ,
		pInput(NULL) ,
		pPadArray(NULL) {
		}
	}GAMEPADENUMINFO,*LPGAMEPADENUMINFO;
	
	/*******************************//*!
	@brief	DirectInputクラス

			DirectInputクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDirectInput : public IInput {
	protected:
		/*******************//*!
		ウインドウ
		*//********************/
		LPWindow					m_pWindow;
		/*******************//*!
		DirectInputオブジェクト
		*//********************/
		LPDIRECTINPUT8				m_pInput;
		/*******************//*!
		キーボード
		*//********************/
		LPDIRECTINPUTDEVICE8		m_pKeyboard;
		/*******************//*!
		キーボード状態
		*//********************/
		MofU8						m_bKeyboardState[MOFINPUT_KEYBOARDKEYMAX];
		/*******************//*!
		直前のキーボード状態
		*//********************/
		MofU8						m_bPrevKeyboardState[MOFINPUT_KEYBOARDKEYMAX];
		/*******************//*!
		マウス
		*//********************/
		LPDIRECTINPUTDEVICE8		m_pMouse;
		/*******************//*!
		マウス状態
		*//********************/
		DIMOUSESTATE2				m_MouseState;
		/*******************//*!
		直前のマウス状態
		*//********************/
		DIMOUSESTATE2				m_PrevMouseState;
		/*******************//*!
		ゲームパッド配列
		*//********************/
		LPGamePadArray				m_pGamePadArray;
		/*******************//*!
		タッチ情報
		*//********************/
		MOFTOUCHSTATE				m_Touch[MOF_TOUCHMAX];
		/*******************//*!
		タッチ情報
		*//********************/
		MOFTOUCHSTATE				m_PrevTouch[MOF_TOUCHMAX];

		/*************************************************************************//*!
				@brief			内部ゲームパッド列挙
				@param[in]		DIDInst			デバイスインスタンス情報
				@param[in]		Context			ゲームパッド生成情報への参照
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		static MofBool CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE* DIDInst,LPMofVoid Context);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDirectInput();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDirectInput();

		/*************************************************************************//*!
				@brief			インプットオブジェクトの生成
				@param[in]		pInfo		インプットの生成情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPINPUTCREATEINFO pInfo);
		
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
				@brief			キーボードキー入力状態判定<br>
								キー番号のキーのPush(このフレームで入力された)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyPush(const MofU8 n);
		/*************************************************************************//*!
				@brief			キーボードキー入力状態判定<br>
								キー番号のキーのHold(このフレームで入力されている)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyHold(const MofU8 n);
		/*************************************************************************//*!
				@brief			キーボードキー入力状態判定<br>
								キー番号のキーのPull(このフレームで放された)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyPull(const MofU8 n);

		/*************************************************************************//*!
				@brief			マウスボタン入力状態判定<br>
								ボタン番号のボタンのPush(このフレームで入力された)判定を行う
				@param[in]		n				ボタン番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsMouseKeyPush(const MofU8 n);
		/*************************************************************************//*!
				@brief			マウスボタン入力状態判定<br>
								ボタン番号のボタンのHold(このフレームで入力されている)判定を行う
				@param[in]		n				ボタン番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsMouseKeyHold(const MofU8 n);
		/*************************************************************************//*!
				@brief			マウスボタン入力状態判定<br>
								ボタン番号のボタンのPull(このフレームで放された)判定を行う
				@param[in]		n				ボタン番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsMouseKeyPull(const MofU8 n);

		/*************************************************************************//*!
				@brief			タッチ入力状態判定<br>
								タッチ番号のタッチのPush(このフレームで入力された)判定を行う
				@param[in]		n				タッチ番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsTouchPush(MofU32 n);
		/*************************************************************************//*!
				@brief			タッチ入力状態判定<br>
								タッチIDのタッチのPush(このフレームで入力された)判定を行う
				@param[in]		Id				タッチID

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsTouchPushById(MofS32 Id);
		/*************************************************************************//*!
				@brief			タッチ入力状態判定<br>
								タッチ番号のタッチのHold(このフレームで入力されている)判定を行う
				@param[in]		n				タッチ番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsTouchHold(MofU32 n);
		/*************************************************************************//*!
				@brief			タッチ入力状態判定<br>
								タッチIDのタッチのHold(このフレームで入力されている)判定を行う
				@param[in]		Id				タッチID

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsTouchHoldById(MofS32 Id);
		/*************************************************************************//*!
				@brief			タッチ入力状態判定<br>
								タッチ番号のタッチのPull(このフレームで放された)判定を行う
				@param[in]		n				タッチ番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsTouchPull(MofU32 n);
		/*************************************************************************//*!
				@brief			タッチ入力状態判定<br>
								タッチIDのタッチのPull(このフレームで放された)判定を行う
				@param[in]		Id				タッチID

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsTouchPullById(MofS32 Id);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			キー状態設定
				@param[in]		n				キー番号
				@param[in]		bState			キー状態
				
				@return			TRUE			設定成功<br>
								FALSE			設定失敗
		*//**************************************************************************/
		virtual MofBool SetKeyState(const MofU8 n,const MofBool bState);
		/*************************************************************************//*!
				@brief			キー状態設定
				@param[in]		n				キー番号
				@param[in]		bState			キー状態
				
				@return			TRUE			設定成功<br>
								FALSE			設定失敗
		*//**************************************************************************/
		virtual MofBool SetMouseState(const MofU8 n,const MofBool bState);
		/*************************************************************************//*!
				@brief			ホイール状態設定
				@param[in]		w				ホイール状態
				
				@return			TRUE			設定成功<br>
								FALSE			設定失敗
		*//**************************************************************************/
		virtual MofBool SetMouseWheel(const MofFloat w);
		/*************************************************************************//*!
				@brief			タッチ情報設定<br>
								タッチ入力が有効な場合のみ処理を実行。
				@param[in]		act				タッチ動作フラグ
				@param[in]		Id				タッチID
				@param[in]		x				タッチX座標
				@param[in]		y				タッチY座標
				
				@return			TRUE			設定成功<br>
								FALSE			設定失敗
		*//**************************************************************************/
		virtual MofBool SetTouchState(MofS32 act,MofS32 Id,MofFloat x,MofFloat y);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			インプットデバイス取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param			None

				@return			インプットデバイス
		*//**************************************************************************/
		virtual MofInputDevice GetDevice(void);
		/*************************************************************************//*!
				@brief			マウス座標を二つのfloat型のデータとして取得する
				@param[out]		px			マウスＸ座標
				@param[out]		py			マウスＹ座標
				
				@return			TRUE		正常に取得することができた
								FALSE		読み込みエラー
		*//**************************************************************************/
		virtual MofBool GetMousePos(MofFloat& px,MofFloat& py);
		/*************************************************************************//*!
				@brief			マウス座標をVector2型のデータとして取得する
				@param[out]		v			Vector2
				
				@return			TRUE		正常に取得することができた
								FALSE		読み込みエラー
		*//**************************************************************************/
		virtual MofBool GetMousePos(Vector2& v);
		/*************************************************************************//*!
				@brief			マウスのホイール移動を取得する
				@param			None
				
				@return			ホイール移動量
		*//**************************************************************************/
		virtual MofFloat GetMouseWheelMove(void);
		/*************************************************************************//*!
				@brief			マウス移動を二つのfloat型のデータとして取得する
				@param[out]		px			マウスＸ移動量
				@param[out]		py			マウスＹ移動量
				
				@return			TRUE		正常に取得することができた
								FALSE		読み込みエラー
		*//**************************************************************************/
		virtual MofBool GetMouseMove(MofFloat& px,MofFloat& py);
		/*************************************************************************//*!
				@brief			マウス移動をVector3型のデータとして取得する<br>
								x,yにはカーソルの移動量がzにはホイールの移動量が入る
				@param[out]		v			Vector3
				
				@return			TRUE		正常に取得することができた
								FALSE		読み込みエラー
		*//**************************************************************************/
		virtual MofBool GetMouseMove(Vector3& v);
		/*************************************************************************//*!
				@brief			ゲームパッド接続数取得
				@param			None

				@return			ゲームパッド接続数
		*//**************************************************************************/
		virtual MofU32 GetGamePadCount(void);
		/*************************************************************************//*!
				@brief			ゲームパッド取得
				@param			None

				@return			ゲームパッド
		*//**************************************************************************/
		virtual LPGamePadArray GetGamePad(void);
		/*************************************************************************//*!
				@brief			ゲームパッド取得<br>
								番号に接続されているパッドを取得する。<br>
								現在の接続数以上の値を指定した場合NULLを返す
				@param[in]		n			パッド番号

				@return			ゲームパッド
		*//**************************************************************************/
		virtual LPGamePad GetGamePad(MofU32 n);
		
		/*************************************************************************//*!
				@brief			タッチ認識最大数取得
				@param			None

				@return			タッチ認識最大数
		*//**************************************************************************/
		virtual MofU32 GetTouchMax();
		/*************************************************************************//*!
				@brief			タッチ状態取得
								タッチされてなければNULLを返す
				@param[in]		n			タッチ番号

				@return			タッチ状態
		*//**************************************************************************/
		virtual LPCMOFTOUCHSTATE GetTouchState(MofU32 n);
		/*************************************************************************//*!
				@brief			IDを使ってタッチ状態取得
								タッチされてなければNULLを返す
				@param[in]		Id			タッチID

				@return			タッチ状態
		*//**************************************************************************/
		virtual LPCMOFTOUCHSTATE GetTouchStateById(MofS32 Id);
		/*************************************************************************//*!
				@brief			直前のタッチ状態取得
								タッチされてなければNULLを返す
				@param[in]		n			タッチ番号

				@return			直前のタッチ状態
		*//**************************************************************************/
		virtual LPCMOFTOUCHSTATE GetPrevTouchState(MofU32 n);
		/*************************************************************************//*!
				@brief			IDを使って直前のタッチ状態取得
								タッチされてなければNULLを返す
				@param[in]		Id			タッチID

				@return			直前のタッチ状態
		*//**************************************************************************/
		virtual LPCMOFTOUCHSTATE GetPrevTouchStateById(MofS32 Id);
		/*************************************************************************//*!
				@brief			タッチ移動を二つのfloat型のデータとして取得する
				@param[in]		n			タッチ番号
				@param[out]		px			タッチＸ移動量
				@param[out]		py			タッチＹ移動量

				@return			TRUE		正常に取得することができた
								FALSE		読み込みエラー
		*//**************************************************************************/
		virtual MofBool GetTouchMove(MofU32 n,MofFloat& px,MofFloat& py);
		/*************************************************************************//*!
				@brief			タッチ移動を二つのfloat型のデータとして取得する
				@param[in]		Id			タッチID
				@param[out]		px			タッチＸ移動量
				@param[out]		py			タッチＹ移動量

				@return			TRUE		正常に取得することができた
								FALSE		読み込みエラー
		*//**************************************************************************/
		virtual MofBool GetTouchMoveById(MofS32 Id,MofFloat& px,MofFloat& py);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CDirectInput,MOF_DXINPUTCLASS_ID);
	};
	
	#include	"DirectInput.inl"
}

#endif

//[EOF]