/*************************************************************************//*!
					
					@file	KeyFrame.h
					@brief	キーフレームクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__KEYFRAME__H__

#define		__KEYFRAME__H__

//INCLUDE
#include	"DynamicArray.h"
#include	"../Math/Quaternion.h"
#include	"../Collision/Rectangle.h"
#include	"../Collision/Circle.h"

//DEFINE

//!補間
#define		MOF_KEYFRAMEINTERPOLATIONCOUNT		16

namespace Mof {
	
	/*******************************//*!
	@brief	キーフレーム補間方法列挙

			キーフレーム補間方法列挙。

	@author	CDW
	*//********************************/
	typedef enum tag_KEYFRAMEINTERPOLATIONTYPE {
		KEYINTERPOLATION_NONE,						//!<補間を行わない
		KEYINTERPOLATION_LINEAR,					//!<リニア補間
		KEYINTERPOLATION_EASE,						//!<簡易イーズ
		KEYINTERPOLATION_HERMITE,					///<エルミート
		KEYINTERPOLATION_BEZIER1,					///<ベジェ
		KEYINTERPOLATION_BEZIER2,					///<ベジェ
		KEYINTERPOLATION_BEZIER2_VECTOR3,			///<ベジェ
		KEYINTERPOLATION_BEZIER2_VECTOR4,			///<ベジェ
	}KeyFrameInterpolationType;

	/*******************************//*!
	@brief	キーフレームクラス

			キーフレームクラス。

	@author	CDW
	*//********************************/
	template < typename T >
	class MOFLIBRARY_API CKeyFrame : public IMofBase , public IMofCopyObject< CKeyFrame< T > > {
		template < typename T2 > friend class CKeyFrameArray;
	protected:
		/*******************//*!
		フレーム内容
		*//********************/
		T								m_Value;
		/*******************//*!
		フレーム設置時間
		*//********************/
		MofFloat						m_Time;
		/*******************//*!
		フラグ
		*//********************/
		MofU32							m_Flag;
		/*******************//*!
		補間方法
		*//********************/
		KeyFrameInterpolationType		m_InterpolationType;
		/*******************//*!
		補間情報
		*//********************/
		MofFloat						m_InterpolationValue[MOF_KEYFRAMEINTERPOLATIONCOUNT];
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CKeyFrame();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		v			要素
				@param[in]		t			時間
				@param[in]		f			フラグ
				@param[in]		inter		補間方法
				@param[in]		pinterval	補間パラメーター

				@return			None
		*//**************************************************************************/
		CKeyFrame(const T& v,MofFloat t,MofU32 f,KeyFrameInterpolationType inter,LPCMofFloat pinterval);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーフレーム

				@return			None
		*//**************************************************************************/
		CKeyFrame(const CKeyFrame< T >& pObj);
		
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CKeyFrame();
		
		/*************************************************************************//*!
				@brief			コピーキーフレームの作成
				@param			None

				@return			作成されたコピーキーフレーム<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		CKeyFrame< T >* CreateCopyObject(void) const;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			データ設定
				@param[in]		v			データ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool SetValue(T& v);
		/*************************************************************************//*!
				@brief			時間設定
				@param[in]		t			データ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool SetTime(MofFloat t);
		/*************************************************************************//*!
				@brief			補間設定
				@param[in]		inter		補間方法
				@param[in]		pinterval	補間パラメーター

				@return			None
		*//**************************************************************************/
		MofBool SetInterpolation(KeyFrameInterpolationType inter, LPCMofFloat pinterval);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			時間取得
				@param			None

				@return			時間
		*//**************************************************************************/
		MofFloat GetTime(void) const;
		/*************************************************************************//*!
				@brief			フラグ取得
				@param			None

				@return			フラグ
		*//**************************************************************************/
		MofU32 GetFlag(void) const;
		/*************************************************************************//*!
				@brief			補間方法取得
				@param			None

				@return			補間方法
		*//**************************************************************************/
		KeyFrameInterpolationType GetInterpolationType(void) const;
		/*************************************************************************//*!
				@brief			補間情報取得
				@param			None

				@return			補間情報
		*//**************************************************************************/
		LPCMofFloat GetInterpolationValue(void) const;
		/*************************************************************************//*!
				@brief			データ取得
				@param			None

				@return			データ
		*//**************************************************************************/
		T& GetValue(void);
		/*************************************************************************//*!
				@brief			データ取得
				@param			None

				@return			データ
		*//**************************************************************************/
		const T& GetValue(void) const;

		//クラス基本定義
		MOF_LIBRARYCLASS(CKeyFrame,MOF_KEYFRAMECLASS_ID);
	};

	//INCLUDE
	#include	"KeyFrame.inl"

	//置き換え
	typedef CKeyFrame< MofBool >			CBoolKeyFrame,*LPBoolKeyFrame;
	typedef CKeyFrame< MofS32 >			CS32KeyFrame,*LPS32KeyFrame;
	typedef CKeyFrame< MofU32 >			CU32KeyFrame,*LPU32KeyFrame;
	typedef CKeyFrame< MofFloat >		CFloatKeyFrame,*LPFloatKeyFrame;
	typedef CKeyFrame< Vector2 >		CVector2KeyFrame,*LPVector2KeyFrame;
	typedef CKeyFrame< Vector3 >		CVector3KeyFrame,*LPVector3KeyFrame;
	typedef CKeyFrame< Vector4 >		CVector4KeyFrame,*LPVector4KeyFrame;
	typedef CKeyFrame< Quaternion >		CQuaternionKeyFrame,*LPQuaternionKeyFrame;
	typedef CKeyFrame< Rectangle >		CRectangleKeyFrame,*LPRectangleKeyFrame;
}

#endif

//[EOF]