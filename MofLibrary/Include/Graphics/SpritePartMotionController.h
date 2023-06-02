/*************************************************************************//*!
					
					@file	SpritePartMotionController.h
					@brief	スプライトパーツモーション管理クラス。<br>
							スプライトパーツアニメーションの時間と状態を管理する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITEPARTMOTIONCONTROLLER__H__

#define		__SPRITEPARTMOTIONCONTROLLER__H__

//INCLUDE
#include	"MotionController.h"
#include	"SpriteContainerAnimation.h"

namespace Mof {
	
	/*******************************//*!
	@brief	スプライトパーツモーションフレーム状態構造体

			スプライトパーツモーションフレーム状態構造体。<br>
			フレームごとのパーツ情報を保存するための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_PARTFRAMESTATE {
		/*******************//*!
		座標
		*//********************/
		CVector3					Pos;
		/*******************//*!
		スケール
		*//********************/
		CVector3					Scale;
		/*******************//*!
		回転
		*//********************/
		CVector3					Angle;
		/*******************//*!
		色
		*//********************/
		CVector4					Color;
		/*******************//*!
		アライメントオフセット
		*//********************/
		CVector3					AlignmentOffset;
		/*******************//*!
		サイズ
		*//********************/
		CVector3					Size;
		/*******************//*!
		アンカー
		*//********************/
		CVector3					Anchor;
		/*******************//*!
		頂点
		*//********************/
		CVector2					Vertex[4];
		/*******************//*!
		頂点
		*//********************/
		CVector4					VertexColor[4];
		/*******************//*!
		頂点
		*//********************/
		MofFloat					VertexColorRate;
		/*******************//*!
		UV座標
		*//********************/
		CVector2					UVPos;
		/*******************//*!
		UVスケール
		*//********************/
		CVector2					UVScale;
		/*******************//*!
		UV回転
		*//********************/
		MofFloat					UVAngle;

		MOF_ALIGNED_NEW_OPERATOR(tag_PARTFRAMESTATE);
	}PARTFRAMESTATE,*LPPARTFRAMESTATE;

	/*******************************//*!
	@brief	スプライトパーツモーションボーン状態管理構造体

			スプライトパーツモーションボーン状態管理構造体。<br>
			アニメーション中の各ボーンの状態や補間を管理するための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_PARTMOTIONSTATE : public IMofNamedObjectImpl {
		/*******************//*!
		ID(配列内の番号が格納される)
		*//********************/
		MofU32						ID;
		/*******************//*!
		対応ボーン
		*//********************/
		LPSprite2DPart				pSprite;
		/*******************//*!
		対応アニメーション
		*//********************/
		LPSpritePartAnimation		pNowAnimation;
		
		/*******************//*!
		対応アニメーション開始時間
		*//********************/
		MofFloat					AnimationStartTime;
		/*******************//*!
		対応アニメーション時間
		*//********************/
		MofFloat					AnimationTime;
		/*******************//*!
		対応アニメーション更新速度
		*//********************/
		MofFloat					AnimationSpeed;
		/*******************//*!
		基本表示
		*//********************/
		MofBool						bBaseShow;
		/*******************//*!
		現在状態
		*//********************/
		PARTFRAMESTATE				NowState;
		/*******************//*!
		対応アニメーション行列
		*//********************/
		CMatrix44					AnimationMatrix;
		/*******************//*!
		最終描画行列
		*//********************/
		CMatrix44					RenderMatrix;

		/*******************//*!
		親パーツ
		*//********************/
		tag_PARTMOTIONSTATE*		pParent;
		/*******************//*!
		子パーツ
		*//********************/
		typedef CDynamicArray< tag_PARTMOTIONSTATE* >		CPartMotionStateChildArray,*LPPartMotionStateChildArray;
		LPPartMotionStateChildArray	pChild;

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_PARTMOTIONSTATE() :
		ID(0) ,
		pSprite(NULL) ,
		pNowAnimation(NULL) ,
		AnimationStartTime(0.0f) ,
		AnimationTime(0.0f) ,
		AnimationSpeed(1.0f) ,
		bBaseShow(TRUE) ,
		NowState() ,
		AnimationMatrix() ,
		RenderMatrix() ,
		pParent(NULL) ,
		pChild(NULL) {
			pChild = new CPartMotionStateChildArray();
			pChild->SetFlag(0);
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_PARTMOTIONSTATE(){
			MOF_SAFE_DELETE(pChild);
		}

		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void){
			if(pSprite)
			{
				return pSprite->GetName();
			}
			return NULL;
		}
	}PARTMOTIONSTATE,*LPPARTMOTIONSTATE;
	typedef CDynamicArray< LPPARTMOTIONSTATE >		CPartMotionStateArray,*LPPartMotionStateArray;

	/*******************************//*!
	@brief	スプライトパーツモーション管理クラス

			スプライトパーツモーション管理クラス。<br>
			スプライトパーツアニメーションの時間と状態を管理する。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSpritePartMotionController : public IMotionController {
	protected:
		/*******************//*!
		ワールドマトリクス
		*//********************/
		CMatrix44						m_WorldMatrix;
		/*******************//*!
		モーション時間
		*//********************/
		MofFloat						m_MotionTime;
		/*******************//*!
		モーション番号
		*//********************/
		MofS32							m_MotionNo;
		
		/*******************//*!
		アニメーション配列
		*//********************/
		LPSpriteContainerAnimationArray	m_pAnimation;
		/*******************//*!
		スプライト状態配列
		*//********************/
		LPPartMotionStateArray			m_pPartState;
		
		/*************************************************************************//*!
				@brief			スプライト状態を作成
				@param[in]		pPart
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool CreatePartMotionState(LPSprite2DPart pPart);
		/*************************************************************************//*!
				@brief			行列状態を更新(内部再帰用関数)
				@param[in]		pPS				更新スプライト情報
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Refresh(LPPARTMOTIONSTATE pPS);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CSpritePartMotionController();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pPart		スプライト
				@param[in]		pAnim		アニメーション

				@return			None
		*//**************************************************************************/
		CSpritePartMotionController(LPSprite2DPart pPart,LPSpriteContainerAnimationArray pAnim);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーオブジェクト

				@return			None
		*//**************************************************************************/
		CSpritePartMotionController(const CSpritePartMotionController& pObj);

		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSpritePartMotionController();
		
		/*************************************************************************//*!
				@brief			現在の状態を更新
				@param			None
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Refresh(void);
		/*************************************************************************//*!
				@brief			現在のモーション状態を更新
				@param[in]		t				更新時間
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool AddTimer(MofFloat t);

		/*************************************************************************//*!
				@brief			現在のモーションを変更
				@param[in]		n				モーション番号
				@param[in]		bSame			同一モーションでの更新フラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeMotion(MofU32 n,MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			現在のモーションを変更
				@param[in]		str				モーション名
				@param[in]		bSame			同一モーションでの更新フラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeMotionByName(LPCMofChar str,MofBool bSame = TRUE);
				
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
				@brief			現在のモーションが終了しているかを判定する。<br>
								モーションがループする場合はTRUEになることはない
				@param			None
				
				@return			TRUE			終了済み<br>
								FALE			まだ終了していない
		*//**************************************************************************/
		virtual MofBool IsEndMotion(void);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			現在のモーション時間を設定
				@param[in]		t				設定時間
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTime(MofFloat t);
		/*************************************************************************//*!
				@brief			モーションのループフラグの設定
				@param[in]		n				モーション番号
				@param[in]		bLoop			ループフラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetMotionLoop(MofU32 n,MofBool bLoop);
		/*************************************************************************//*!
				@brief			モーションのループフラグの設定
				@param[in]		str				モーション名
				@param[in]		bLoop			ループフラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetMotionLoopByName(LPCMofChar str,MofBool bLoop);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			現在のモーション時間取得
				@param			None

				@return			現在のモーション時間
		*//**************************************************************************/
		virtual MofFloat GetTime(void) const;
		/*************************************************************************//*!
				@brief			現在のモーション番号取得
				@param			None

				@return			現在のモーション番号
		*//**************************************************************************/
		virtual MofS32 GetMotionNo(void) const;
		/*************************************************************************//*!
				@brief			登録されているモーション数取得
				@param			None

				@return			登録されているモーション数
		*//**************************************************************************/
		virtual MofS32 GetMotionCount(void) const;

		//クラス基本定義
		MOF_LIBRARYCLASS(CSpritePartMotionController,MOF_SPRITEPARTMOTIONCONTROLLERCLASS_ID);
	};

	#include	"SpritePartMotionController.inl"

	typedef CSpritePartMotionController *LPSpritePartMotionController;
}

#endif

//[EOF]