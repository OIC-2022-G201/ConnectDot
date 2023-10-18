/*************************************************************************//*!
					
					@file	KeyFrameArray.h
					@brief	キーフレーム配列クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__KEYFRAMEARRAY__H__

#define		__KEYFRAMEARRAY__H__

//INCLUDE
#include	"KeyFrame.h"

//!ベジェ最適解試行回数
#define		MOF_KEYINTERPOLATIONBEZIER1COUNT		8
#define		MOF_KEYINTERPOLATIONBEZIER2COUNT		16

namespace Mof {
	
	/*******************************//*!
	@brief	キーフレーム配列管理フラグ列挙

			キーフレーム配列の管理フラグ列挙。

	@author	CDW
	*//********************************/
	enum tag_KEYFRAMEARRAYFLAG {
		KEYFRAMEARRAY_ARRAYMEMBERDELETE		=		DYNAMICARRAY_ARRAYMEMBERDELETE,
		KEYFRAMEARRAY_ARRAYMEMBERCOPY		=		DYNAMICARRAY_ARRAYMEMBERCOPY,
		
		KEYFRAMEARRAY_LOOPALLFRAME			=		0x00010000,
		KEYFRAMEARRAY_LOOPSTARTFRAME		=		0x00020000,

		KEYFRAMEARRAY_FLAGALL				=		0xFFFFFFFF,
		KEYFRAMEARRAY_LOOPFLAG				=		KEYFRAMEARRAY_LOOPALLFRAME | KEYFRAMEARRAY_LOOPSTARTFRAME,
	};

	/*******************************//*!
	@brief	キーフレーム配列クラス内部特殊化定義

			キーフレーム配列クラスの内部テンプレートを
			定義する内部クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CKeyFrameArrayImpl {
	protected:
		/*************************************************************************//*!
				@brief			内部補間
				@param[in]		Data1		前のキーの値
				@param[in]		Data2		今のキーの値
				@param[in]		t			補間時間
				@param[out]		Out			出力

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		template < typename TX > struct InterpolationImpl {
			static MofBool GetInterpolationValue(const TX& Data1,const TX& Data2, const MofFloat t,TX& Out)
			{
				Out = Data1 + (TX)((Data2 - Data1) * t);
				return TRUE;
			}
			static MofBool GetInterpolateBezierValue(const TX& Data1, const TX& Data2, const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t, TX& Out)
			{
				MofFloat vt = CKeyFrameArrayImpl::GetInterpolateBezierTime(x1, x2, y1, y2, pt, nt, t);
				return GetInterpolationValue(Data1, Data2, vt, Out);
			}
			static MofBool GetVector3TimeInterpolationValue(const TX& Data1, const TX& Data2, const Vector3& t, TX& Out)
			{
				Out = Data1 + (TX)((Data2 - Data1) * t.x);
				return TRUE;
			}
			static MofBool GetVector4TimeInterpolationValue(const TX& Data1, const TX& Data2, const Vector4& t, TX& Out)
			{
				Out = Data1 + (TX)((Data2 - Data1) * t.x);
				return TRUE;
			}
		};
		/*************************************************************************//*!
				@brief			エルミート補間で現在の時間を求める
				@param[in]		x1			Xコントロールポイント
				@param[in]		x2			Xコントロールポイント
				@param[in]		x			現在位置
				
				@return			時間
		*//**************************************************************************/
		static MofFloat GetInterpolateHermiteTime(const MofFloat x1, const MofFloat x2, const MofFloat t);
		/*************************************************************************//*!
				@brief			３次ベジェ補間で現在の時間を求める
				@param[in]		x1			Xコントロールポイント
				@param[in]		x2			Xコントロールポイント
				@param[in]		y1			Yコントロールポイント
				@param[in]		y2			Yコントロールポイント
				@param[in]		pt			前のキーの時間
				@param[in]		nt			次のキーの時間
				@param[in]		t			現在位置
				
				@return			時間
		*//**************************************************************************/
		static MofFloat GetInterpolateBezierTime(const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat pt, const MofFloat nt, const MofFloat t);
		/*************************************************************************//*!
				@brief			３次ベジェ補間で現在の時間を求める
				@param[in]		x1			Xコントロールポイント
				@param[in]		x2			Xコントロールポイント
				@param[in]		y1			Yコントロールポイント
				@param[in]		y2			Yコントロールポイント
				@param[in]		x			現在位置
				
				@return			時間
		*//**************************************************************************/
		static MofFloat GetInterpolateBezierTime(const MofFloat x1, const MofFloat x2, const MofFloat y1, const MofFloat y2, const MofFloat x);
	public:
	};

	/*******************************//*!
	@brief	キーフレーム配列クラス

			キーフレーム配列クラス。

	@author	CDW
	*//********************************/
	template < typename T >
	class MOFLIBRARY_API CKeyFrameArray : public CDynamicArray< CKeyFrame< T >* > , public CKeyFrameArrayImpl {
	protected:
		/*************************************************************************//*!
				@brief			データのソートを実行する比較関数
				@param[in]		A			フレームＡ
				@param[in]		B			フレームＢ

				@return			<0			Aが前
								>0			Bが前
								0			同一
		*//**************************************************************************/
		static int KeySortCompare(const void* A,const void* B);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CKeyFrameArray();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピー配列

				@return			None
		*//**************************************************************************/
		CKeyFrameArray(const CKeyFrameArray< T >& pObj);
		
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CKeyFrameArray();

		/*************************************************************************//*!
				@brief			キーフレームの追加
				@param[in]		Time		追加キーフレーム時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AddKeyFrame(MofFloat Time);
		/*************************************************************************//*!
				@brief			キーフレームの追加
				@param[in]		Data		追加キーフレーム内容
				@param[in]		Time		追加キーフレーム時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool AddKeyFrame(const T& Data,MofFloat Time);
		/*************************************************************************//*!
				@brief			キーフレームの削除
				@param[in]		Time		削除キーフレーム時間
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool DeleteKeyFrame(MofFloat Time);
		
		/*************************************************************************//*!
				@brief			配列のソートを実行する
				@param[in]		pFunc			比較関数
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Sort(int (*pFunc)(const void *, const void *) = KeySortCompare);
		
		/*************************************************************************//*!
				@brief			ループフラグがあるかを判定する
				@param			None
				
				@return			TRUE			ループする<br>
								FALSE			ループしない
		*//**************************************************************************/
		virtual MofBool IsLoop(void);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ループフラグの設定
				@param[in]		Loop		ループフラグ<br>
											ループを有効にする場合はKEYFRAMEARRAY_LOOPALLFRAMEかKEYFRAMEARRAY_LOOPSTARTFRAMEを指定<br>
											ループを無効にする場合は0を指定する。
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool SetLoop(MofU32 Loop);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			最初のキーフレームの時間取得
				@param			None

				@return			最初のキーフレームの時間
		*//**************************************************************************/
		MofFloat GetStartKeyTime(void) const;
		/*************************************************************************//*!
				@brief			最終のキーフレームの時間取得
				@param			None

				@return			最終のキーフレームの時間
		*//**************************************************************************/
		MofFloat GetLastKeyTime(void) const;
		/*************************************************************************//*!
				@brief			今の時間のループの終了時間取得
				@param[in]		t			時間

				@return			今の時間のループの終了時間
		*//**************************************************************************/
		MofFloat GetLoopLastTime(MofFloat t) const;
		/*************************************************************************//*!
				@brief			指定時間のキーを取得
				@param[in]		t			時間

				@return			NULL		キーが見つからない<br>
								それ以外	見つけたキーフレーム
		*//**************************************************************************/
		CKeyFrame< T >* GetKeyFrame(MofFloat t) const;
		/*************************************************************************//*!
				@brief			指定時間のキー番号を取得
				@param[in]		t			時間

				@return			配列要素番号
		*//**************************************************************************/
		MofU32 GetKeyFrameNo(MofFloat t) const;
		/*************************************************************************//*!
				@brief			指定時間のキーを取得
				@param[in]		t			時間

				@return			NULL		キーが見つからない<br>
								それ以外	見つけたキーフレーム
		*//**************************************************************************/
		CKeyFrame< T >* GetNowKeyFrame(MofFloat t) const;
		/*************************************************************************//*!
				@brief			指定時間のキー番号を取得
				@param[in]		t			時間

				@return			配列要素番号
		*//**************************************************************************/
		MofU32 GetNowKeyFrameNo(MofFloat t) const;
		/*************************************************************************//*!
				@brief			指定時間のキーを取得
				@param[in]		t			時間

				@return			NULL		キーが見つからない<br>
								それ以外	見つけたキーフレーム
		*//**************************************************************************/
		CKeyFrame< T >* GetNextKeyFrame(MofFloat t) const;
		/*************************************************************************//*!
				@brief			指定時間のキー番号を取得
				@param[in]		t			時間

				@return			配列要素番号
		*//**************************************************************************/
		MofU32 GetNextKeyFrameNo(MofFloat t) const;
		/*************************************************************************//*!
				@brief			指定時間のキー状態を取得
				@param[in]		Time		時間
				@param[out]		Out			出力
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool GetTimeState(MofFloat Time,T& Out) const;

		//クラス基本定義
		MOF_LIBRARYCLASS(CKeyFrameArray,MOF_KEYFRAMEARRAYCLASS_ID);
	};

	//INCLUDE
	#include	"KeyFrameArray.inl"

	//置き換え
	typedef CKeyFrameArray< MofBool >		CBoolKeyFrameArray,*LPBoolKeyFrameArray;
	typedef CKeyFrameArray< MofS32 >		CS32KeyFrameArray,*LPS32KeyFrameArray;
	typedef CKeyFrameArray< MofU32 >		CU32KeyFrameArray,*LPU32KeyFrameArray;
	typedef CKeyFrameArray< MofFloat >		CFloatKeyFrameArray,*LPFloatKeyFrameArray;
	typedef CKeyFrameArray< Vector2 >		CVector2KeyFrameArray, *LPVector2KeyFrameArray;
	typedef CKeyFrameArray< Vector3 >		CVector3KeyFrameArray,*LPVector3KeyFrameArray;
	typedef CKeyFrameArray< Vector4 >		CVector4KeyFrameArray,*LPVector4KeyFrameArray;
	typedef CKeyFrameArray< Quaternion >	CQuaternionKeyFrameArray,*LPQuaternionKeyFrameArray;
	typedef CKeyFrameArray< Rectangle >		CRectangleKeyFrameArray,*LPRectangleKeyFrameArray;
}

#endif

//[EOF]