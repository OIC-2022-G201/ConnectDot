/*************************************************************************//*!
					
					@file	SpriteAnimation.h
					@brief	スプライトアニメーションクラス。<br>
							スプライトの矩形変化でのアニメーションを行う。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITEANIMATION__H__

#define		__SPRITEANIMATION__H__

//INCLUDE
#include	"../Common/KeyFrameArray.h"
#include	"../Utilities/Utilities.h"

namespace Mof {
	
	/*******************************//*!
	@brief	スプライトアニメーション簡易作成用パターン構造体

			スプライトアニメーションをオフセットと幅、高さで作成する際の1パターンの内容。

	@author	CDW
	*//********************************/
	typedef struct tag_SPRITEANIMATIONCREATEPATTERN {
		MofFloat							Wait;						//!<フレームウェイト
		MofS32								No;							//!<パターン番号
		MofS32								Step;						//!<パターン段
	}SpriteAnimationCreatePattern,*LPSpriteAnimationCreatePattern;

	/*******************************//*!
	@brief	スプライトアニメーション簡易作成用構造体

			スプライトアニメーションをオフセットと幅、高さで作成するための構造体。

	@author	CDW
	*//********************************/
	template < int N > struct SpriteAnimationCreateFrame {
		CString								Name;						//!<アニメーション名
		MofFloat							OffsetX;					//!<Xオフセット位置
		MofFloat							OffsetY;					//!<Yオフセット位置
		MofFloat							Width;						//!<幅
		MofFloat							Height;						//!<高さ
		MofBool								bLoop;						//!<ループフラグ(TRUEならループ、FALSEなら最終フレームで停止)
		SpriteAnimationCreatePattern		Pattern[N];					//!<パターン
	};
	typedef SpriteAnimationCreateFrame< 30 > SpriteAnimationCreate,*LPSpriteAnimationCreate;

	/*******************************//*!
	@brief	スプライトアニメーションクラス

			スプライトアニメーションクラス。<br>
			スプライトの矩形変化でのアニメーションを行う。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSpriteAnimation : public IMofNamedObject {
	protected:
		/*******************//*!
		アニメーション名
		*//********************/
		CString						m_Name;
		/*******************//*!
		矩形リスト
		*//********************/
		CRectangleKeyFrameArray		m_RectKeyFrame;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CSpriteAnimation();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		frm				フレーム

				@return			None
		*//**************************************************************************/
		template < int N > CSpriteAnimation(SpriteAnimationCreateFrame< N >& frm);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーオブジェクト

				@return			None
		*//**************************************************************************/
		CSpriteAnimation(const CSpriteAnimation& pObj);

		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSpriteAnimation();
				
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Is
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			現在のモーションがループするかを判定する。
				@param			None
				
				@return			TRUE			ループする<br>
								FALE			ループしない
		*//**************************************************************************/
		virtual MofBool IsLoop(void);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前設定
				@param[in]		pName			設定する名前
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			モーションのループフラグの設定
				@param[in]		bLoop			ループフラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetLoop(MofBool bLoop);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			指定時間での矩形取得
				@param[in]		t				時間
				@param[out]		oRec			出力矩形
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool GetTimeRect(const MofFloat t,Rectangle& oRec);
		/*************************************************************************//*!
				@brief			指定時間でのフレーム番号取得
				@param[in]		t				時間

				@return			フレーム番号
		*//**************************************************************************/
		virtual MofU32 GetTimeFrameNo(const MofFloat t);
		/*************************************************************************//*!
				@brief			アニメーションの終了時間取得<br>
								ループをする場合でも最終のフレームの時間を返す
				@param			None
				
				@return			アニメーションの終了時間
		*//**************************************************************************/
		virtual MofFloat GetEndTime(void);
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CSpriteAnimation,MOF_SPRITEANIMATIONCLASS_ID);
	};

	#include	"SpriteAnimation.inl"

	//置き換え
	typedef CSpriteAnimation						*LPSpriteAnimation;
	typedef CDynamicArray< LPSpriteAnimation >		CSpriteAnimationArray,*LPSpriteAnimationArray;
}

#endif

//[EOF]