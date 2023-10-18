/*************************************************************************//*!
					
					@file	MeshMotionController.h
					@brief	メッシュモーション管理クラス。<br>
							メッシュアニメーションの時間と状態を管理する。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHMOTIONCONTROLLER__H__

#define		__MESHMOTIONCONTROLLER__H__

//INCLUDE
#include	"MotionController.h"
#include	"MeshAnimation.h"
#include	"CCDIK.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュモーションボーンフレーム状態構造体

			メッシュモーションボーンフレーム状態構造体。<br>
			フレームごとのボーン情報を保存するための構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_BONEFRAMESTATE {
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
		CQuaternion					Angle;
	}BONEFRAMESTATE,*LPBONEFRAMESTATE;

	/*******************************//*!
	@brief	メッシュモーションボーン状態管理構造体

			メッシュモーションボーン状態管理構造体。<br>
			アニメーション中の各ボーンの状態や補間を管理するための構造体。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_BONEMOTIONSTATE : public IMofNamedObjectImpl {
		/*******************//*!
		ID(配列内の番号が格納される)
		*//********************/
		MofU32						ID;
		/*******************//*!
		対応ボーン
		*//********************/
		LPBone						pBone;
		/*******************//*!
		対応ＩＫ
		*//********************/
		LPCCDJoint					pIKJoint;
		/*******************//*!
		対応アニメーション
		*//********************/
		LPMeshBoneAnimation			pNowAnimation;
		
		/*******************//*!
		対応アニメーション開始時間
		*//********************/
		MofFloat					AnimationStartTime;
		/*******************//*!
		対応アニメーション時間
		*//********************/
		MofFloat					AnimationTime;
		/*******************//*!
		対応アニメーション補間時間
		*//********************/
		MofFloat					TransitionTime;
		/*******************//*!
		対応アニメーション更新速度
		*//********************/
		MofFloat					AnimationSpeed;
		/*******************//*!
		対応アニメーションロック
		*//********************/
		MotionLock					Lock;
		/*******************//*!
		現在状態
		*//********************/
		BONEFRAMESTATE				NowState;
		/*******************//*!
		保管状態
		*//********************/
		BONEFRAMESTATE				TransitionState;
		/*******************//*!
		対応アニメーション行列
		*//********************/
		CMatrix44					AnimationMatrix;
		/*******************//*!
		対応ボーン行列
		*//********************/
		CMatrix44					BoneMatrix;
		/*******************//*!
		補正行列
		*//********************/
		CMatrix44					ReviseMatrix;
		/*******************//*!
		最終描画行列
		*//********************/
		CMatrix44					RenderMatrix;
		/*******************//*!
		IKウェイト
		*//********************/
		MofFloat					IKWait;

		/*******************//*!
		親ボーン
		*//********************/
		tag_BONEMOTIONSTATE*		pParent;
		/*******************//*!
		子ボーン
		*//********************/
		typedef CDynamicArray< tag_BONEMOTIONSTATE* >		CBoneMotionStateChildArray,*LPBoneMotionStateChildArray;
		LPBoneMotionStateChildArray	pChild;

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_BONEMOTIONSTATE() :
		ID(0) ,
		pBone(NULL) ,
		pIKJoint(NULL) ,
		pNowAnimation(NULL) ,
		AnimationStartTime(0.0f) ,
		AnimationTime(0.0f) ,
		TransitionTime(0.0f) ,
		AnimationSpeed(1.0f) ,
		Lock(MOTIONLOCK_OFF) ,
		AnimationMatrix() ,
		BoneMatrix() ,
		ReviseMatrix() ,
		RenderMatrix() ,
		IKWait(1.0f) ,
		pParent(NULL) ,
		pChild(NULL) {
			pChild = new CBoneMotionStateChildArray();
			pChild->SetFlag(0);
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_BONEMOTIONSTATE(){
			MOF_SAFE_DELETE(pChild);
		}

		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void){
			if(pBone)
			{
				return pBone->GetName();
			}
			return NULL;
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_BONEMOTIONSTATE);
	}BONEMOTIONSTATE,*LPBONEMOTIONSTATE;
	typedef CDynamicArray< LPBONEMOTIONSTATE >		CBoneMotionStateArray,*LPBoneMotionStateArray;
	
	/*******************************//*!
	@brief	メッシュモーションモーフィングフレーム状態構造体

			メッシュモーションモーフィングフレーム状態構造体。<br>
			フレームごとのモーフィング情報を保存するための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MORPHINGFRAMESTATE {
		/*******************//*!
		状態
		*//********************/
		MofFloat					FValue;
	}MORPHINGFRAMESTATE,*LPMORPHINGFRAMESTATE;

	/*******************************//*!
	@brief	メッシュモーションボーン状態管理構造体

			メッシュモーションボーン状態管理構造体。<br>
			アニメーション中の各ボーンの状態や補間を管理するための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_MORPHINGMOTIONSTATE : public IMofNamedObjectImpl {
		/*******************//*!
		ID(配列内の番号が格納される)
		*//********************/
		MofU32						ID;
		/*******************//*!
		ジオメトリの名前
		*//********************/
		CString						Name;
		
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
		現在状態
		*//********************/
		MORPHINGFRAMESTATE			NowState;
		/*******************//*!
		対応アニメーション
		*//********************/
		LPMeshMorphingAnimation		pNowAnimation;

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_MORPHINGMOTIONSTATE() :
		ID(0) ,
		Name() ,
		AnimationStartTime(0.0f) ,
		AnimationTime(0.0f) ,
		AnimationSpeed(1.0f) ,
		NowState() ,
		pNowAnimation(NULL) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_MORPHINGMOTIONSTATE(){
			Name.SetString(NULL);
		}

		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void){
			return &Name;
		}
	}MORPHINGMOTIONSTATE,*LPMORPHINGMOTIONSTATE;
	typedef CDynamicArray< LPMORPHINGMOTIONSTATE >		CMorphingMotionStateArray,*LPMorphingMotionStateArray;
	
	/*******************************//*!
	@brief	メッシュモーション状態管理構造体

			メッシュモーション状態管理構造体。<br>
			アニメーション中の各状態や補間を管理するための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_GEOMETRYMOTION : public IMofNamedObjectImpl {
		/*******************//*!
		ジオメトリの名前
		*//********************/
		CString						Name;
		/*******************//*!
		ジオメトリの元頂点
		*//********************/
		LPMofVoid					pVertex;
		/*******************//*!
		対応ボーンＩＤ配列
		*//********************/
		CU32Array					No;

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param[in]		pName		名前
				@param[in]		Cnt			ボーン対応数

				@return			None
		*//**************************************************************************/
		tag_GEOMETRYMOTION(LPCMofChar pName,MofU32 Cnt) :
		Name(pName) ,
		pVertex(NULL) ,
		No(Cnt) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_GEOMETRYMOTION(){
			Name.SetString(NULL);
			MOF_SAFE_FREE(pVertex,"GEOMETRYMOTION");
			No.Release();
		}

		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void){
			return &Name;
		}
	}GEOMETRYMOTION,*LPGEOMETRYMOTION;
	typedef CDynamicArray< LPGEOMETRYMOTION >		CGeometryMotionArray,*LPGeometryMotionArray;

	/*******************************//*!
	@brief	メッシュモーション管理クラス

			メッシュモーション管理クラス。<br>
			メッシュアニメーションの時間と状態を管理する。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMeshMotionController : public IMotionController {
	protected:
		/*******************//*!
		ワールドマトリクス
		*//********************/
		CMatrix44					m_WorldMatrix;
		/*******************//*!
		モーション時間
		*//********************/
		MofFloat					m_MotionTime;
		/*******************//*!
		モーション番号
		*//********************/
		MofS32						m_MotionNo;
		
		/*******************//*!
		ボーン配列
		*//********************/
		LPBoneArray					m_pBone;
		/*******************//*!
		アニメーション配列
		*//********************/
		LPMeshAnimationArray		m_pAnimation;
		/*******************//*!
		ボーン状態配列
		*//********************/
		LPBoneMotionStateArray		m_pBoneState;
		/*******************//*!
		モーフィング状態配列
		*//********************/
		LPMorphingMotionStateArray	m_pMorphingState;
		/*******************//*!
		ＩＫ配列
		*//********************/
		LPCCDIKArray				m_pIKs;
		/*******************//*!
		ジオメトリ対応配列
		*//********************/
		LPGeometryMotionArray		m_pGeometryMotion;
		
		/*************************************************************************//*!
				@brief			行列状態を更新(内部再帰用関数)
				@param[in]		pBS				更新ボーン情報
				@param[in]		wMat			ワールドマトリクス
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrix(LPBONEMOTIONSTATE pBS,const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			行列状態を更新(内部再帰用関数)
				@param[in]		pJoint			ＩＫ情報

				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RefreshIKBoneMatrix(LPCCDJoint pJoint);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CMeshMotionController();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pBone		ボーン
				@param[in]		pAnim		アニメーション

				@return			None
		*//**************************************************************************/
		CMeshMotionController(LPBoneArray pBone,LPMeshAnimationArray pAnim);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーオブジェクト

				@return			None
		*//**************************************************************************/
		CMeshMotionController(const CMeshMotionController& pObj);

		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CMeshMotionController();
		
		/*************************************************************************//*!
				@brief			現在の状態を更新
				@param			None
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Refresh(void);
		/*************************************************************************//*!
				@brief			ボーン行列状態を更新
				@param[in]		wMat			ワールドマトリクス
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrix(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			行列状態を更新
				@param[in]		wMat			ワールドマトリクス
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrixOnly(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			描画行列の位置のみを更新
				@param[in]		wMat			ワールドマトリクス
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrixPosition(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			描画行列の位置のみを更新
				@param[in]		pos				位置
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RefreshBoneMatrixPosition(const Vector3& pos);
		/*************************************************************************//*!
				@brief			モーフィング状態を更新
				@param[in]		pGeom			更新ジオメトリ
	
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RefreshMorphing(LPGeometry pGeom);
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
				@param[in]		n				モーション番号
				@param[in]		spd				モーション再生速度
				@param[in]		bLoop			ループフラグ
				@param[in]		bSame			同一モーションでの更新フラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeMotion(MofU32 n, MofFloat spd, MofBool bLoop, MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			現在のモーションを変更
				@param[in]		n				モーション番号
				@param[in]		nt				モーション時間
				@param[in]		spd				モーション再生速度
				@param[in]		tTime			モーション補間時間
				@param[in]		bLoop			ループフラグ
				@param[in]		Lock			変更ロックフラグ
				@param[in]		bSame			同一モーションでの更新フラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeMotion(MofU32 n,MofFloat nt,MofFloat spd,MofFloat tTime,MofBool bLoop,MotionLock Lock,MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			現在のモーションを変更
				@param[in]		str				モーション名
				@param[in]		bSame			同一モーションでの更新フラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeMotionByName(LPCMofChar str,MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			現在のモーションを変更
				@param[in]		str				モーション名
				@param[in]		spd				モーション再生速度
				@param[in]		bLoop			ループフラグ
				@param[in]		bSame			同一モーションでの更新フラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeMotionByName(LPCMofChar str, MofFloat spd, MofBool bLoop, MofBool bSame = TRUE);
		/*************************************************************************//*!
				@brief			現在のモーションを変更
				@param[in]		str				モーション名
				@param[in]		nt				モーション時間
				@param[in]		spd				モーション再生速度
				@param[in]		tTime			モーション補間時間
				@param[in]		bLoop			ループフラグ
				@param[in]		Lock			変更ロックフラグ
				@param[in]		bSame			同一モーションでの更新フラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeMotionByName(LPCMofChar str, MofFloat nt, MofFloat spd, MofFloat tTime, MofBool bLoop, MotionLock Lock, MofBool bSame = TRUE);
				
		/*************************************************************************//*!
				@brief			モーションの変更をロックする
				@param[in]		Lock			変更ロックフラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool ChangeLock(MotionLock Lock);
		
		
		/*************************************************************************//*!
				@brief			ボーンの追加<br>
								既存のボーンの場合は、上書きフラグがTRUEなら情報を置き換える。
				@param[in]		pBone			ボーン
				@param[in]		bOW				上書きフラグ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool AddBone(LPBoneArray pBone, MofBool bOW = TRUE);
		/*************************************************************************//*!
				@brief			ボーンの追加<br>
								既存のボーンの場合は、上書きフラグがTRUEなら情報を置き換える。
				@param[in]		pBone			ボーン
				@param[in]		bOW				上書きフラグ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool AddBone(LPBone pBone, MofBool bOW = TRUE);

		/*************************************************************************//*!
				@brief			アニメーションの追加<br>
								既存のアニメーションの場合は、<br>
								追加アニメーションにのみ存在するボーンがある場合のみ情報を追加する。
				@param[in]		pAnim			アニメーション

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool AddAnimation(LPMeshAnimationArray pAnim);
		/*************************************************************************//*!
				@brief			アニメーションの追加<br>
								既存のアニメーションの場合は、<br>
								追加アニメーションにのみ存在するボーンがある場合のみ情報を追加する。
				@param[in]		pAnim			アニメーション

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool AddAnimation(LPMeshAnimation pAnim);

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
		/*************************************************************************//*!
				@brief			登録されているボーン数取得
				@param			None

				@return			登録されているボーン数
		*//**************************************************************************/
		virtual MofS32 GetBoneCount(void);
		/*************************************************************************//*!
				@brief			登録されているモーション取得
				@param[in]		n				モーション番号

				@return			登録されているモーション
		*//**************************************************************************/
		virtual LPMeshAnimation GetMotion(MofU32 n);
		/*************************************************************************//*!
				@brief			登録されているモーション取得
				@param[in]		pName			モーション名

				@return			登録されているモーション
		*//**************************************************************************/
		virtual LPMeshAnimation GetMotionByName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			登録されているモーション取得
				@param[in]		pName			モーション名

				@return			登録されているモーションの番号
								MOF_U32_MAX			指定名のモーションが登録されていない
		*//**************************************************************************/
		virtual MofU32 GetMotionNoByName(LPCMofChar pName) const;
		/*************************************************************************//*!
				@brief			ボーン状態取得
				@param[in]		n				ボーン番号

				@return			ボーン状態
		*//**************************************************************************/
		virtual LPBONEMOTIONSTATE GetBoneState(MofU32 n);
		/*************************************************************************//*!
				@brief			ボーン状態取得
				@param[in]		Name			検索するボーン名

				@return			ボーン状態
		*//**************************************************************************/
		virtual LPBONEMOTIONSTATE GetBoneState(LPCMofChar Name);
		/*************************************************************************//*!
				@brief			ワールドマトリクス取得
				@param[in]		None

				@return			ワールドマトリクス
		*//**************************************************************************/
		virtual CMatrix44& GetWorldMatrix(void);
		/*************************************************************************//*!
				@brief			4×3行列として描画行列を取得取得
				@param[out]		pOut			行列出力用配列(対応ボーン本数×4×3より多い配列を確保しておく必要がある)
				@param[out]		cnt				行列出力用配列の数
	
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool GetRenderMatrix43(LPMofFloat pOut, MofU32 cnt);
		/*************************************************************************//*!
				@brief			4×3行列として描画行列を取得取得<br>
								対応ボーン名リストに対応するボーン情報のみの配列を設定する。<br>
								一度取得を行うと内部にジオメトリ名と対応ボーンの配列が作成される。
				@param[in]		pName			描画ジオメトリ名
				@param[in]		pBNArray		描画対応ボーン名リスト
				@param[out]		pOut			行列出力用配列(対応ボーン本数×4×3より多い配列を確保しておく必要がある)
				@param[out]		cnt				行列出力用配列の数
	
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool GetRenderMatrix43(LPMofChar pName,LPStringArray pBNArray,LPMofFloat pOut, MofU32 cnt);
		/*************************************************************************//*!
				@brief			4×4行列として描画行列を取得取得
				@param[out]		pOut			行列出力用配列(対応ボーン本数×4×4より多い配列を確保しておく必要がある)
				@param[out]		cnt				行列出力用配列の数
	
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool GetRenderMatrix44(LPMofFloat pOut, MofU32 cnt);
		/*************************************************************************//*!
				@brief			4×4行列として描画行列を取得取得<br>
								対応ボーン名リストに対応するボーン情報のみの配列を設定する。<br>
								一度取得を行うと内部にジオメトリ名と対応ボーンの配列が作成される。
				@param[in]		pName			描画ジオメトリ名
				@param[in]		pBNArray		描画対応ボーン名リスト
				@param[out]		pOut			行列出力用配列(対応ボーン本数×4×4より多い配列を確保しておく必要がある)
				@param[out]		cnt				行列出力用配列の数
	
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool GetRenderMatrix44(LPMofChar pName,LPStringArray pBNArray,LPMofFloat pOut, MofU32 cnt);

		//クラス基本定義
		MOF_LIBRARYCLASS(CMeshMotionController,MOF_MESHMOTIONCONTROLLERCLASS_ID);
	};

	#include	"MeshMotionController.inl"

	typedef CMeshMotionController *LPMeshMotionController;
}

#endif

//[EOF]