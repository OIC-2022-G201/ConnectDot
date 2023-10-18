/*************************************************************************//*!
					
					@file	Bone.h
					@brief	ボーン基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__BONE__H__

#define		__BONE__H__

//INCLUDE
#include	"MomCommon.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ボーンフラグ列挙

			ボーンに付加できる動作フラグ列挙

	@author	CDW
	*//********************************/
	typedef enum tag_BONEFLAG {
		BONEFLAG_REVISE								=	0x00000001,				//!<補正計算
	}BoneFlag;

	/*******************************//*!
	@brief	ボーンウェイト

			ボーンウェイト。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_BONEWEIGHT {
		/*******************//*!
		インデックス
		*//********************/
		MofU32					Index;
		/*******************//*!
		ウェイト
		*//********************/
		MofFloat				Weight;
	}BONEWEIGHT,*LPBONEWEIGHT;
	typedef CDynamicArray< BONEWEIGHT >		CBoneWeightArray,*LPBoneWeightArray;

	/*******************************//*!
	@brief	ボーンウェイト

			ボーンウェイト。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_GEOMETRYBONEWEIGHT : public IMofCopyObject< tag_GEOMETRYBONEWEIGHT > {
		/*******************//*!
		名前
		*//********************/
		CString					GeometryName;
		/*******************//*!
		ウェイト
		*//********************/
		CBoneWeightArray		Weights;
		
		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GEOMETRYBONEWEIGHT() :
		GeometryName() ,
		Weights() {
		}
		
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピーウェイト

				@return			None
		*//**************************************************************************/
		tag_GEOMETRYBONEWEIGHT(const tag_GEOMETRYBONEWEIGHT& pObj) :
		GeometryName(pObj.GeometryName) ,
		Weights(pObj.Weights) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_GEOMETRYBONEWEIGHT(){
			GeometryName.SetString(NULL);
			Weights.Release();
		}
		
		/*************************************************************************//*!
				@brief			コピーバッファの作成
				@param			None

				@return			作成されたコピーバッファ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual tag_GEOMETRYBONEWEIGHT* CreateCopyObject(void) const{
			return new tag_GEOMETRYBONEWEIGHT(*this);
		}
	}GEOMETRYBONEWEIGHT,*LPGEOMETRYBONEWEIGHT;
	typedef CDynamicArray< LPGEOMETRYBONEWEIGHT >		CGeometryBoneWeightArray,*LPGeometryBoneWeightArray;
	
	/*******************************//*!
	@brief	ボーンウェイト

			ボーンウェイト。

	@author	CDW
	*//********************************/
	typedef MOF_ALIGNED16_STRUCT tag_BONEIKJOINT {
		/*******************//*!
		対応ボーン名
		*//********************/
		CString					Target;
		/*******************//*!
		制限半径
		*//********************/
		MofFloat				Restriction;
		/*******************//*!
		比率
		*//********************/
		MofFloat				Weight;
		/*******************//*!
		フラグ
		*//********************/
		MofU32					Flag;
		/*******************//*!
		制限角度
		*//********************/
		CVector3				MinRestriction;
		/*******************//*!
		制限角度
		*//********************/
		CVector3				MinSingleRestriction;
		/*******************//*!
		制限角度
		*//********************/
		CVector3				MaxRestriction;
		/*******************//*!
		制限角度
		*//********************/
		CVector3				MaxSingleRestriction;
		
		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_BONEIKJOINT() :
		Target() ,
		Restriction(MOF_MATH_2PI) ,
		Weight(1.0f) ,
		Flag(0) ,
		MinRestriction(-MOF_MATH_2PI, -MOF_MATH_2PI, -MOF_MATH_2PI) ,
		MinSingleRestriction(-MOF_MATH_2PI, -MOF_MATH_2PI, -MOF_MATH_2PI) ,
		MaxRestriction(MOF_MATH_2PI, MOF_MATH_2PI, MOF_MATH_2PI) ,
		MaxSingleRestriction(MOF_MATH_2PI, MOF_MATH_2PI, MOF_MATH_2PI) {
		}
		
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピーウェイト

				@return			None
		*//**************************************************************************/
		tag_BONEIKJOINT(const tag_BONEIKJOINT& pObj) :
		Target(pObj.Target) ,
		Restriction(pObj.Restriction) ,
		Weight(pObj.Weight) ,
		Flag(pObj.Flag) ,
		MinRestriction(pObj.MinRestriction) ,
		MinSingleRestriction(pObj.MinSingleRestriction) ,
		MaxRestriction(pObj.MaxRestriction) ,
		MaxSingleRestriction(pObj.MaxSingleRestriction) {
		}
		
		
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		tag_BONEIKJOINT& operator = ( const tag_BONEIKJOINT& v ){
			Target = v.Target;
			Restriction = v.Restriction;
			Weight = v.Weight;
			Flag = v.Flag;
			MinRestriction = v.MinRestriction;
			MinSingleRestriction = v.MinSingleRestriction;
			MaxRestriction = v.MaxRestriction;
			MaxSingleRestriction = v.MaxSingleRestriction;
			return *this;
		}

		MOF_ALIGNED_NEW_OPERATOR(tag_BONEIKJOINT);
	}BONEIKJOINT,*LPBONEIKJOINT;
	typedef CDynamicArray< BONEIKJOINT >		CBoneIKJointArray,*LPBoneIKJointArray;

	/*******************************//*!
	@brief	ボーンＩＫ

			ボーンＩＫ。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API tag_BONEIKINFO : public IMofCopyObject< tag_BONEIKINFO > {
		/*******************//*!
		対応ボーン名
		*//********************/
		CString					Target;
		/*******************//*!
		反復回数
		*//********************/
		MofS32					Iteration;
		/*******************//*!
		制限半径
		*//********************/
		MofFloat				Restriction;
		/*******************//*!
		誤差
		*//********************/
		MofFloat				Tolerance;
		/*******************//*!
		ジョイント
		*//********************/
		CBoneIKJointArray		Joint;

		/*************************************************************************//*!
				@brief			コンストラクタ<br>
								全てのパラメーターをデフォルトで作成する。
				@param			None

				@return			None
		*//**************************************************************************/
		tag_BONEIKINFO() :
		Target() ,
		Iteration(5) ,
		Restriction(0.0f) ,
		Tolerance(0.01f) ,
		Joint() {
		}
		
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピーウェイト

				@return			None
		*//**************************************************************************/
		tag_BONEIKINFO(const tag_BONEIKINFO& pObj) :
		Target(pObj.Target) ,
		Iteration(pObj.Iteration) ,
		Restriction(pObj.Restriction) ,
		Tolerance(pObj.Tolerance) ,
		Joint(pObj.Joint) {
		}
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~tag_BONEIKINFO(){
			Target.SetString(NULL);
			Joint.Release();
		}
		
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		tag_BONEIKINFO& operator = ( const tag_BONEIKINFO& v ){
			Target = v.Target;
			Iteration = v.Iteration;
			Restriction = v.Restriction;
			Tolerance = v.Tolerance;
			Joint = v.Joint;
			return *this;
		}

		/*************************************************************************//*!
				@brief			コピーバッファの作成
				@param			None

				@return			作成されたコピーバッファ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual tag_BONEIKINFO* CreateCopyObject(void) const{
			return new tag_BONEIKINFO(*this);
		}
	}BONEIKINFO,*LPBONEIKINFO;
	typedef CDynamicArray< LPBONEIKINFO >		CBoneIKInfoArray,*LPBoneIKInfoArray;

	/*******************************//*!
	@brief	ボーンインターフェイス

			ボーンインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IBone : public IMofNamedObject , public IMofCopyObject< IBone > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ID設定
				@param[in]		id				ID
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetID(MofU32 id) = 0;
		/*************************************************************************//*!
				@brief			フラグ設定
				@param[in]		flg				フラグ
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetFlag(MofU32 flg) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ID取得
				@param			None

				@return			ID
		*//**************************************************************************/
		virtual MofU32 GetID(void) = 0;
		/*************************************************************************//*!
				@brief			フラグ取得
				@param			None

				@return			フラグ
		*//**************************************************************************/
		virtual MofU32 GetFlag(void) = 0;
		/*************************************************************************//*!
				@brief			親の名前取得
				@param			None

				@return			親の名前
		*//**************************************************************************/
		virtual LPString GetParentName(void) = 0;
		/*************************************************************************//*!
				@brief			変換行列取得
				@param			None

				@return			変換行列
		*//**************************************************************************/
		virtual CMatrix44& GetMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			変換行列取得
				@param[out]		pos				座標変換
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool GetLocalTranslation(Vector3& pos) = 0;
		/*************************************************************************//*!
				@brief			オフセット行列取得
				@param			None

				@return			オフセット行列
		*//**************************************************************************/
		virtual CMatrix44& GetOffsetMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			オフセット行列取得
				@param			None

				@return			オフセット行列
		*//**************************************************************************/
		virtual CMatrix33& GetRotationOffsetMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			ウェイト配列取得
				@param			None

				@return			ウェイト配列
		*//**************************************************************************/
		virtual LPGeometryBoneWeightArray GetWeightsArray(void) = 0;
		/*************************************************************************//*!
				@brief			ＩＫ配列取得
				@param			None

				@return			ＩＫ配列
		*//**************************************************************************/
		virtual LPBoneIKInfoArray GetIKsArray(void) = 0;
	};
	
	//ポインタ置き換え
	typedef IBone*				LPBone;
	typedef CDynamicArray< LPBone >		CBoneArray,*LPBoneArray;
}

#endif	//__BONE__H__

//[EOF]