/*************************************************************************//*!
					
					@file	XInputGamePad.h
					@brief	XInputでのゲームパッドでの各種入力の処理を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__XINPUTGAMEPAD__H__

#define		__XINPUTGAMEPAD__H__

//INCLUDE
#include	"../GamePad.h"
	
//DEFINE
			
//----------------------------------
////トリガーの値定義
//----------------------------------
#define		MOFXINPUT_TRIGGERMIN					0				//!<押下状態が最小位置
#define		MOFXINPUT_TRIGGERCENTER					128				//!<押下状態が中心位置
#define		MOFXINPUT_TRIGGERMAX					255				//!<押下状態が最大位置

//----------------------------------
////スティックの値定義
//----------------------------------
#define		MOFXINPUT_STICKMIN						-32768			//!<マイナス最大
#define		MOFXINPUT_STICKMINCENTER				-16384			//!<マイナス中心
#define		MOFXINPUT_STICKCENTER					0				//!<倒されていない
#define		MOFXINPUT_STICKCENTERPERMIT				6000			//!<誤差
#define		MOFXINPUT_STICKMAXCENTER				16383			//!<プラス中心
#define		MOFXINPUT_STICKMAX						32767			//!<プラス最大

namespace Mof {
	
	/*******************************//*!
	@brief	XInputボタン列挙

			XInputのボタン入力判定を行うものを列挙

	@author	CDW
	*//********************************/
	typedef enum XInputButton {
		XINPUT_DP_UP,												//!<方向パッド上
		XINPUT_DP_DOWN,												//!<方向パッド下
		XINPUT_DP_LEFT,												//!<方向パッド左
		XINPUT_DP_RIGHT,											//!<方向パッド右
	
		XINPUT_LS_PUSH,												//!<左スティック押下
		XINPUT_RS_PUSH,												//!<右スティック押下
	
		XINPUT_A,													//!<Aボタン
		XINPUT_B,													//!<Bボタン
		XINPUT_X,													//!<Xボタン
		XINPUT_Y,													//!<Yボタン

		XINPUT_L_BTN,												//!<Lボタン
		XINPUT_R_BTN,												//!<Rボタン

		XINPUT_L_TRIGGER,											//!<Lトリガー
		XINPUT_R_TRIGGER,											//!<Rトリガー

		XINPUT_START,												//!<STARTボタン
		XINPUT_BACK,												//!<BACKボタン

		XINPUT_MAX													//!<最大数
	}XInputButton;

	/*******************************//*!
	@brief	ゲームパッド生成情報構造体

			ゲームパッドの生成に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_XGAMEPADCREATEINFO : public tag_GAMEPADCREATEINFO {
		MofU32					No;									//!<コントローラー番号

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_XGAMEPADCREATEINFO() :
		No(0) ,
		tag_GAMEPADCREATEINFO() {
			Size = sizeof(tag_XGAMEPADCREATEINFO);
		}
	}XGAMEPADCREATEINFO,*LPXGAMEPADCREATEINFO;
	
	/*******************************//*!
	@brief	XInputゲームパッドクラス

			XInputゲームパッドの管理、入力処理を行うクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CXGamePad : public IGamePad {
	protected:
		/*******************//*!
		ゲームパッド
		*//********************/
		MofU32					m_ControllerNo;
		/*******************//*!
		入力情報
		*//********************/
		XINPUT_STATE			m_PadState;
		/*******************//*!
		直前の入力情報
		*//********************/
		XINPUT_STATE			m_PrevPadState;
		/*******************//*!
		パッド振動情報
		*//********************/
		XINPUT_VIBRATION		m_Vibration;
		/*******************//*!
		キー状態
		*//********************/
		MofBool					m_bButtonState[XINPUT_MAX];
		/*******************//*!
		直前のキー状態
		*//********************/
		MofBool					m_bPrevButtonState[XINPUT_MAX];
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CXGamePad();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CXGamePad();
		
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
				@brief			振動の開始
				@param[in]		LeftSpeed		左振動
				@param[in]		RightSpeed		右振動

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool StartVibration(MofU16 LeftSpeed,MofU16 RightSpeed);
		/*************************************************************************//*!
				@brief			振動の停止
				@param			None

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool StopVibration(void);

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
		/*************************************************************************//*!
				@brief			パッド状態取得<br>
								右スティックの横への傾きを取得する。
				@param			None

				@return			スティック横入力量(-1.0～1.0)
		*//**************************************************************************/
		virtual MofFloat GetRightStickHorizontal(void) const;
		/*************************************************************************//*!
				@brief			パッド状態取得<br>
								右スティックの縦への傾きを取得する。
				@param			None

				@return			スティック縦入力量(-1.0～1.0)
		*//**************************************************************************/
		virtual MofFloat GetRightStickVertical(void) const;
		

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CXGamePad,MOF_XINPUTGAMEPADCLASS_ID);
	};

	#include	"XInputGamePad.inl"
}

#endif

//[EOF]