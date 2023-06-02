/*************************************************************************//*!
					
					@file	Matrix44.h
					@brief	4×4行列演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MATRIX44__H__

#define		__MATRIX44__H__

//INCLUDE
#include	"Matrix33.h"

namespace Mof {
	
	//クオータニオン行列の前方定義
	struct MOFLIBRARY_API Quaternion;

	/*******************************//*!
	@brief	4x4行列構造体

			4x4行列を扱うための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API Matrix44 {
		union {
			struct {
				MofFloat				_11, _12, _13, _14;
				MofFloat				_21, _22, _23, _24;
				MofFloat				_31, _32, _33, _34;
				MofFloat				_41, _42, _43, _44;
			};
			MofFloat rc[4][4];
			MofFloat val[16];
		};
		
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		Matrix44();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		f11			11成分
				@param[in]		f12			12成分
				@param[in]		f13			13成分
				@param[in]		f14			14成分
				@param[in]		f21			21成分
				@param[in]		f22			22成分
				@param[in]		f23			23成分
				@param[in]		f24			24成分
				@param[in]		f31			31成分
				@param[in]		f32			32成分
				@param[in]		f33			33成分
				@param[in]		f34			34成分
				@param[in]		f41			41成分
				@param[in]		f42			42成分
				@param[in]		f43			43成分
				@param[in]		f44			44成分

				@return			None
		*//**************************************************************************/
		Matrix44(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
					MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
					MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
					MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 );
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pf			パラメーター（16個以上の配列であること）

				@return			None
		*//**************************************************************************/
		Matrix44( MofFloat* pf );
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピー行列

				@return			None
		*//**************************************************************************/
		Matrix44( const Matrix33& pObj );
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピー行列

				@return			None
		*//**************************************************************************/
		Matrix44( const Matrix44& pObj );
	
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			floatキャスト<br>
								内部の座標をfloatポインタとしてそのまま返す。
		*//**************************************************************************/
		operator LPMofFloat ();
		/*************************************************************************//*!
				@brief			+取得
		*//**************************************************************************/
		Matrix44 operator + () const;
		/*************************************************************************//*!
				@brief			-取得
		*//**************************************************************************/
		Matrix44 operator - () const;
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		Matrix44& operator = ( const Matrix33& m );
		/*************************************************************************//*!
				@brief			+=演算
		*//**************************************************************************/
		Matrix44& operator += ( const Matrix44& m );
		/*************************************************************************//*!
				@brief			-=演算
		*//**************************************************************************/
		Matrix44& operator -= ( const Matrix44& m );
		/*************************************************************************//*!
				@brief			floatとの*=演算
		*//**************************************************************************/
		Matrix44& operator *= ( const MofFloat m );
		/*************************************************************************//*!
				@brief			Matrix33との*=演算
		*//**************************************************************************/
		Matrix44& operator *= ( const Matrix33& m );
		/*************************************************************************//*!
				@brief			Matrix44との*=演算
		*//**************************************************************************/
		Matrix44& operator *= ( const Matrix44& m );
		/*************************************************************************//*!
				@brief			floatとの/=演算
		*//**************************************************************************/
		Matrix44& operator /= ( const MofFloat m );
		/*************************************************************************//*!
				@brief			+演算
		*//**************************************************************************/
		Matrix44 operator + ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			-演算
		*//**************************************************************************/
		Matrix44 operator - ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			floatとの*演算
		*//**************************************************************************/
		Matrix44 operator * ( const MofFloat m ) const;
		/*************************************************************************//*!
				@brief			Vector2との*演算
		*//**************************************************************************/
		Vector2 operator * ( const Vector2& v ) const;
		/*************************************************************************//*!
				@brief			Vector3との*演算
		*//**************************************************************************/
		Vector3 operator * ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Vector4との*演算
		*//**************************************************************************/
		Vector4 operator * ( const Vector4& v ) const;
		/*************************************************************************//*!
				@brief			Matrix33との*演算
		*//**************************************************************************/
		Matrix44 operator * ( const Matrix33& m ) const;
		/*************************************************************************//*!
				@brief			Matrix44との*演算
		*//**************************************************************************/
		Matrix44 operator * ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			floatとの/演算
		*//**************************************************************************/
		Matrix44 operator / ( const MofFloat m ) const;
		/*************************************************************************//*!
				@brief			配列指定によるMatrix44メンバへのアクセス
		*//**************************************************************************/
		MofFloat& operator [] ( int i );
		/*************************************************************************//*!
				@brief			配列指定によるMatrix44メンバへのアクセス
		*//**************************************************************************/
		const MofFloat& operator [] ( int i ) const;
		/*************************************************************************//*!
				@brief			==判断
		*//**************************************************************************/
		bool operator == ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			!=判断
		*//**************************************************************************/
		bool operator != ( const Matrix44& m ) const;
	}Matrix44;
	
	/*******************************//*!
	@brief	4x4行列演算クラス

			Matrix44構造体を扱うためのスタティッククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMatrix44Utilities {
	public:
		/*************************************************************************//*!
				@brief			単位行列設定
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Identity(Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			転置行列設定<br>
								入力行列と出力行列に同じ参照を設定する場合、引数が一つの方を利用すること
				@param[in]		InMat		入力行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Transpose(const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			転置行列設定
				@param[in,out]	OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Transpose(Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			左手座標系でTargetへの注視行列計算
				@param[in]		Pos			座標
				@param[in]		Target		注視座標
				@param[in]		Up			上方ベクトル
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void LookAtLH(const Vector3& Pos,const Vector3& Target,const Vector3& Up,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			右手座標系でTargetへの注視行列計算
				@param[in]		Pos			座標
				@param[in]		Target		注視座標
				@param[in]		Up			上方ベクトル
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void LookAtRH(const Vector3& Pos,const Vector3& Target,const Vector3& Up,Matrix44& OutMat);
	
		/*************************************************************************//*!
				@brief			左手座標系で射影行列計算
				@param[in]		vr			視野角
				@param[in]		Aspect		アスペクト比
				@param[in]		Near		最近面
				@param[in]		Far			最遠面
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void PerspectiveFovLH(const MofFloat vr,const MofFloat Aspect,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			左手座標系でパースペクティブ射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void PerspectiveLH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			左手座標系で正射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void OrthoLH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			左手座標系で正射影行列計算
				@param[in]		l			左
				@param[in]		r			右
				@param[in]		b			下
				@param[in]		t			上
				@param[in]		Near		最近面
				@param[in]		Far			最遠面
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void OrthoOffCenterLH(const MofFloat l,const MofFloat r,const MofFloat b,const MofFloat t,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			右手座標系で射影行列計算
				@param[in]		vr			視野角
				@param[in]		Aspect		アスペクト比
				@param[in]		Near		最近面
				@param[in]		Far			最遠面
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void PerspectiveFovRH(const MofFloat vr,const MofFloat Aspect,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			右手座標系でパースペクティブ射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void PerspectiveRH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			右手座標系で正射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void OrthoRH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			右手座標系で正射影行列計算
				@param[in]		l			左
				@param[in]		r			右
				@param[in]		b			下
				@param[in]		t			上
				@param[in]		Near		最近面
				@param[in]		Far			最遠面
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void OrthoOffCenterRH(const MofFloat l,const MofFloat r,const MofFloat b,const MofFloat t,const MofFloat Near,const MofFloat Far,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			行列式計算
				@param[in]		Mat			計算行列

				@return			行列式
		*//**************************************************************************/
		static MofFloat Determinant(const Matrix44& Mat);
		/*************************************************************************//*!
				@brief			逆行列計算
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Inverse(const Matrix44& InMat,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			補間計算
				@param[in]		m1			補間行列
				@param[in]		m2			補間行列
				@param[in]		t			補間時間(0～1)
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Interpolate(Matrix44& m1, Matrix44& m2, MofFloat t, Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			平行移動行列計算
				@param[in]		v			座標
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Translation(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			平行移動行列計算
				@param[in]		x			X座標
				@param[in]		y			Y座標
				@param[in]		z			Z座標
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Translation(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			平行移動行列計算<br>
								元行列 × 平行移動行列の結果を結果行列に設定する。
				@param[in]		InMat		元行列
				@param[in]		v			座標
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Translation(const Matrix44& InMat,const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			平行移動行列計算<br>
								元行列 × 平行移動行列の結果を結果行列に設定する。
				@param[in]		InMat		元行列
				@param[in]		x			X座標
				@param[in]		y			Y座標
				@param[in]		z			Z座標
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Translation(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			平行移動行列計算<br>
								平行移動行列 × 元行列の結果を結果行列に設定する。
				@param[in]		v			座標
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Translation(const Vector3& v,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			平行移動行列計算<br>
								平行移動行列 × 元行列の結果を結果行列に設定する。
				@param[in]		x			X座標
				@param[in]		y			Y座標
				@param[in]		z			Z座標
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Translation(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			スケーリング行列計算
				@param[in]		v			倍率
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			スケーリング行列計算
				@param[in]		s			倍率
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const MofFloat s,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			スケーリング行列計算
				@param[in]		x			X倍率
				@param[in]		y			Y倍率
				@param[in]		z			Z倍率
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								元行列 × 拡大行列の結果を結果行列に設定する。
				@param[in]		InMat		元行列
				@param[in]		v			倍率
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const Matrix44& InMat,const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								元行列 × 拡大行列の結果を結果行列に設定する。
				@param[in]		InMat		元行列
				@param[in]		s			倍率
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const Matrix44& InMat,const MofFloat s,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								元行列 × 拡大行列の結果を結果行列に設定する。
				@param[in]		InMat		元行列
				@param[in]		x			X倍率
				@param[in]		y			Y倍率
				@param[in]		z			Z倍率
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								拡大行列 × 元行列の結果を結果行列に設定する。
				@param[in]		v			倍率
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const Vector3& v,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								拡大行列 × 元行列の結果を結果行列に設定する。
				@param[in]		s			倍率
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const MofFloat s,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								拡大行列 × 元行列の結果を結果行列に設定する。
				@param[in]		x			X倍率
				@param[in]		y			Y倍率
				@param[in]		z			Z倍率
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void Scaling(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Y→Zの順で回転を行う
				@param[in]		v			回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationXYZ(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Y→Zの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationXYZ(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Z→Yの順で回転を行う
				@param[in]		v			回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationXZY(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Z→Yの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationXZY(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→X→Zの順で回転を行う
				@param[in]		v			回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationYXZ(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→X→Zの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationYXZ(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→Z→Xの順で回転を行う
				@param[in]		v			回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationYZX(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→Z→Xの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationYZX(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→X→Yの順で回転を行う
				@param[in]		v			回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationZXY(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→X→Yの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationZXY(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→Y→Xの順で回転を行う
				@param[in]		v			回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationZYX(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→Y→Xの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationZYX(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			X軸回転行列計算
				@param[in]		ax			X回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationX(const MofFloat ax,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			X軸回転行列計算<br>
								元行列 × X回転行列の結果を結果行列に設定する。
				@param[in]		InMat		元行列
				@param[in]		ax			X回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationX(const Matrix44& InMat,const MofFloat ax,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			X軸回転行列計算<br>
								X回転行列 × 元行列の結果を結果行列に設定する。
				@param[in]		ax			X回転
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationX(const MofFloat ax,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Y軸回転行列計算
				@param[in]		ay			Y回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationY(const MofFloat ay,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Y軸回転行列計算<br>
								元行列 × Y回転行列の結果を結果行列に設定する。
				@param[in]		InMat		元行列
				@param[in]		ay			Y回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationY(const Matrix44& InMat,const MofFloat ay,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Y軸回転行列計算<br>
								Y回転行列 × 元行列の結果を結果行列に設定する。
				@param[in]		ay			Y回転
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationY(const MofFloat ay,const Matrix44& InMat,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Z軸回転行列計算
				@param[in]		az			Z回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationZ(const MofFloat az,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Z軸回転行列計算<br>
								元行列 × Z回転行列の結果を結果行列に設定する。
				@param[in]		InMat		元行列
				@param[in]		az			Z回転
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationZ(const Matrix44& InMat,const MofFloat az,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			Z軸回転行列計算<br>
								Z回転行列 × 元行列の結果を結果行列に設定する。
				@param[in]		az			Z回転
				@param[in]		InMat		元行列
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationZ(const MofFloat az,const Matrix44& InMat,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			指定軸回転行列計算
				@param[in]		a			回転
				@param[in]		v			軸
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void RotationAxis(const MofFloat a,const CVector3& v,Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			元の姿勢から指定座標を向く行列の作成
				@param[in]		src			元の姿勢
				@param[in]		target		目標座標
				@param[in]		forward		前方方向
				@param[out]		out			結果行列

				@return			None
		*//**************************************************************************/
		static void RotateLookAt(Matrix44& src, Vector3& target, Vector3& forward, Matrix44& out);
		/*************************************************************************//*!
				@brief			元の姿勢から指定座標を向く行列の作成
				@param[in]		src			元の姿勢
				@param[in]		target		目標座標
				@param[out]		out			結果行列

				@return			None
		*//**************************************************************************/
		static void RotateLookAt(Matrix44& src, Vector3& target, Matrix44& out);

		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		src			元の姿勢
				@param[in]		pivot		中心
				@param[in]		Angle		回転角度
				@param[out]		out			出力行列

				@return			None
		*//**************************************************************************/
		static void RotateAroundLocal(Matrix44& src, Matrix44& pivot, Vector3& Angle, Matrix44& out);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		src			元の姿勢
				@param[in]		pivot		中心
				@param[in]		Angle		回転角度
				@param[out]		out			出力行列

				@return			None
		*//**************************************************************************/
		static void RotateAround(Matrix44& src, Matrix44& pivot, Vector3& Angle, Matrix44& out);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		src			元の姿勢
				@param[in]		pivot		中心
				@param[in]		Axis		回転軸
				@param[in]		Angle		回転角度
				@param[out]		out			出力行列

				@return			None
		*//**************************************************************************/
		static void RotateAround(Matrix44& src, Matrix44& pivot, Vector3& Axis, MofFloat Angle, Matrix44& out);

		/*************************************************************************//*!
				@brief			行列１と行列２の補間行列の作成
				@param[in]		m1			行列１
				@param[in]		m2			行列２
				@param[in]		t			補間時間
				@param[in,out]	o			結果行列

				@return			None
		*//**************************************************************************/
		static void Integrate(const Matrix44& m1,const Matrix44& m2,MofFloat t,Matrix44& o);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			結果行列の平行移動ベクトル設定
				@param[in]		v			平行移動
				@param[in,out]	OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void SetTranslation(const Vector3& v,Matrix44& OutMat);
		/*************************************************************************//*!
				@brief			結果行列の平行移動ベクトル設定
				@param[in]		x			X座標
				@param[in]		y			Y座標
				@param[in]		z			Z座標
				@param[in,out]	OutMat		結果行列

				@return			None
		*//**************************************************************************/
		static void SetTranslation(const MofFloat x,const MofFloat y,const MofFloat z,Matrix44& OutMat);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			元行列の平行移動ベクトル取得
				@param[in]		InMat		元行列
				@param[out]		v			平行移動

				@return			None
		*//**************************************************************************/
		static void GetTranslation(const Matrix44& InMat,Vector3& v);
		/*************************************************************************//*!
				@brief			元行列の拡大ベクトル取得
				@param[in]		InMat		元行列
				@param[out]		v			倍率

				@return			None
		*//**************************************************************************/
		static void GetScaling(const Matrix44& InMat,Vector3& v);
		/*************************************************************************//*!
				@brief			元行列の回転成分のみの行列取得
				@param[in]		InMat		元行列
				@param[out]		m			回転

				@return			None
		*//**************************************************************************/
		static void GetRotation(const Matrix44& InMat,Matrix33& m);
		/*************************************************************************//*!
				@brief			元行列の回転クオータニオン取得
				@param[in]		InMat		元行列
				@param[out]		q			回転

				@return			None
		*//**************************************************************************/
		static void GetRotation(const Matrix44& InMat,Quaternion& q);
		/*************************************************************************//*!
				@brief			元行列の回転ベクトル取得
				@param[in]		InMat		元行列
				@param[out]		v			回転

				@return			None
		*//**************************************************************************/
		static void GetRotation(const Matrix44& InMat,Vector3& v);
		/*************************************************************************//*!
				@brief			元行列の回転ベクトル取得
				@param[in]		InMat		元行列
				@param[out]		v			回転

				@return			None
		*//**************************************************************************/
		static void GetYawPitchRoll(const Matrix44& InMat,Vector3& v);

	private:
		//作成を禁止する
		CMatrix44Utilities(){};
		CMatrix44Utilities(const CMatrix44Utilities& pObj){};
	};

	/*******************************//*!
	@brief	4x4行列クラス

			Matrix44構造体を扱うための関数を含めたクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMatrix44 : public Matrix44 , public IMofBase {
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CMatrix44();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		f11			11成分
				@param[in]		f12			12成分
				@param[in]		f13			13成分
				@param[in]		f14			14成分
				@param[in]		f21			21成分
				@param[in]		f22			22成分
				@param[in]		f23			23成分
				@param[in]		f24			24成分
				@param[in]		f31			31成分
				@param[in]		f32			32成分
				@param[in]		f33			33成分
				@param[in]		f34			34成分
				@param[in]		f41			41成分
				@param[in]		f42			42成分
				@param[in]		f43			43成分
				@param[in]		f44			44成分

				@return			None
		*//**************************************************************************/
		CMatrix44(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
					MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
					MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
					MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 );
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pf			パラメーター（16個以上の配列であること）

				@return			None
		*//**************************************************************************/
		CMatrix44( MofFloat* pf );
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピー行列

				@return			None
		*//**************************************************************************/
		CMatrix44( const Matrix33& pObj );
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピー行列

				@return			None
		*//**************************************************************************/
		CMatrix44( const CMatrix33& pObj );
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピー行列

				@return			None
		*//**************************************************************************/
		CMatrix44( const Matrix44& pObj );
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピー行列

				@return			None
		*//**************************************************************************/
		CMatrix44( const CMatrix44& pObj );
		
		/*************************************************************************//*!
				@brief			単位行列設定
				@param			None

				@return			None
		*//**************************************************************************/
		void Identity(void);
		/*************************************************************************//*!
				@brief			転置行列設定
				@param			None

				@return			None
		*//**************************************************************************/
		void Transpose(void);

		/*************************************************************************//*!
				@brief			左手座標系でTargetへの注視行列計算
				@param[in]		Pos			座標
				@param[in]		Target		注視座標
				@param[in]		Up			上方ベクトル

				@return			None
		*//**************************************************************************/
		void LookAtLH(const Vector3& Pos,const Vector3& Target,const Vector3& Up);
		/*************************************************************************//*!
				@brief			右手座標系でTargetへの注視行列計算
				@param[in]		Pos			座標
				@param[in]		Target		注視座標
				@param[in]		Up			上方ベクトル

				@return			None
		*//**************************************************************************/
		void LookAtRH(const Vector3& Pos,const Vector3& Target,const Vector3& Up);

		/*************************************************************************//*!
				@brief			左手座標系で射影行列計算
				@param[in]		vr			視野角
				@param[in]		Aspect		アスペクト比
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		void PerspectiveFovLH(const MofFloat vr,const MofFloat Aspect,const MofFloat Near,const MofFloat Far);
		/*************************************************************************//*!
				@brief			左手座標系でパースペクティブ射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		void PerspectiveLH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far);
		/*************************************************************************//*!
				@brief			左手座標系で正射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		void OrthoLH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far);
				
		/*************************************************************************//*!
				@brief			右手座標系で射影行列計算
				@param[in]		vr			視野角
				@param[in]		Aspect		アスペクト比
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		void PerspectiveFovRH(const MofFloat vr,const MofFloat Aspect,const MofFloat Near,const MofFloat Far);
		/*************************************************************************//*!
				@brief			右手座標系でパースペクティブ射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		void PerspectiveRH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far);
		/*************************************************************************//*!
				@brief			右手座標系で正射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		void OrthoRH(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far);

		/*************************************************************************//*!
				@brief			行列式計算
				@param			None

				@return			行列式
		*//**************************************************************************/
		MofFloat Determinant(void) const;
		/*************************************************************************//*!
				@brief			逆行列計算
				@param			None

				@return			None
		*//**************************************************************************/
		void Inverse(void);
		/*************************************************************************//*!
				@brief			逆行列計算
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		void Inverse(Matrix44& OutMat) const;
		
		/*************************************************************************//*!
				@brief			補間計算
				@param[in]		m			補間行列
				@param[in]		t			補間時間(0～1)
				@param[out]		OutMat		結果行列

				@return			None
		*//**************************************************************************/
		void Interpolate(Matrix44& m, MofFloat t, Matrix44& OutMat);

		/*************************************************************************//*!
				@brief			平行移動行列計算
				@param[in]		v			座標

				@return			None
		*//**************************************************************************/
		void Translation(const Vector3& v);
		/*************************************************************************//*!
				@brief			平行移動行列計算
				@param[in]		x			X座標
				@param[in]		y			Y座標
				@param[in]		z			Z座標

				@return			None
		*//**************************************************************************/
		void Translation(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			平行移動行列計算<br>
								元行列 × 平行移動行列の結果を自身に設定する。
				@param[in]		InMat		元行列
				@param[in]		v			座標

				@return			None
		*//**************************************************************************/
		void Translation(const Matrix44& InMat,const Vector3& v);
		/*************************************************************************//*!
				@brief			平行移動行列計算<br>
								元行列 × 平行移動行列の結果を自身に設定する。
				@param[in]		InMat		元行列
				@param[in]		x			X座標
				@param[in]		y			Y座標
				@param[in]		z			Z座標

				@return			None
		*//**************************************************************************/
		void Translation(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			平行移動行列計算<br>
								平行移動行列 × 元行列の結果を自身に設定する。
				@param[in]		v			座標
				@param[in]		InMat		元行列

				@return			None
		*//**************************************************************************/
		void Translation(const Vector3& v,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			平行移動行列計算<br>
								平行移動行列 × 元行列の結果を自身に設定する。
				@param[in]		x			X座標
				@param[in]		y			Y座標
				@param[in]		z			Z座標
				@param[in]		InMat		元行列

				@return			None
		*//**************************************************************************/
		void Translation(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat);
		
		/*************************************************************************//*!
				@brief			スケーリング行列計算
				@param[in]		v			倍率

				@return			None
		*//**************************************************************************/
		void Scaling(const Vector3& v);
		/*************************************************************************//*!
				@brief			スケーリング行列計算
				@param[in]		s			倍率

				@return			None
		*//**************************************************************************/
		void Scaling(const MofFloat s);
		/*************************************************************************//*!
				@brief			スケーリング行列計算
				@param[in]		x			X倍率
				@param[in]		y			Y倍率
				@param[in]		z			Z倍率

				@return			None
		*//**************************************************************************/
		void Scaling(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								元行列 × 拡大行列の結果を自身に設定する。
				@param[in]		InMat		元行列
				@param[in]		v			倍率

				@return			None
		*//**************************************************************************/
		void Scaling(const Matrix44& InMat,const Vector3& v);
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								元行列 × 拡大行列の結果を自身に設定する。
				@param[in]		InMat		元行列
				@param[in]		s			倍率

				@return			None
		*//**************************************************************************/
		void Scaling(const Matrix44& InMat,const MofFloat s);
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								元行列 × 拡大行列の結果を自身に設定する。
				@param[in]		InMat		元行列
				@param[in]		x			X倍率
				@param[in]		y			Y倍率
				@param[in]		z			Z倍率

				@return			None
		*//**************************************************************************/
		void Scaling(const Matrix44& InMat,const MofFloat x,const MofFloat y,const MofFloat z);

		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								拡大行列 × 元行列の結果を自身に設定する。
				@param[in]		v			倍率
				@param[in]		InMat		元行列

				@return			None
		*//**************************************************************************/
		void Scaling(const Vector3& v,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								拡大行列 × 元行列の結果を自身に設定する。
				@param[in]		s			倍率
				@param[in]		InMat		元行列

				@return			None
		*//**************************************************************************/
		void Scaling(const MofFloat s,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			スケーリング行列計算<br>
								拡大行列 × 元行列の結果を自身に設定する。
				@param[in]		x			X倍率
				@param[in]		y			Y倍率
				@param[in]		z			Z倍率
				@param[in]		InMat		元行列

				@return			None
		*//**************************************************************************/
		void Scaling(const MofFloat x,const MofFloat y,const MofFloat z,const Matrix44& InMat);

		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Y→Zの順で回転を行う
				@param[in]		v			回転

				@return			None
		*//**************************************************************************/
		void RotationXYZ(const Vector3& v);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Y→Zの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationXYZ(const MofFloat x,const MofFloat y,const MofFloat z);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Z→Yの順で回転を行う
				@param[in]		v			回転

				@return			None
		*//**************************************************************************/
		void RotationXZY(const Vector3& v);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Z→Yの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationXZY(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→X→Zの順で回転を行う
				@param[in]		v			回転

				@return			None
		*//**************************************************************************/
		void RotationYXZ(const Vector3& v);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→X→Zの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationYXZ(const MofFloat x,const MofFloat y,const MofFloat z);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→Z→Xの順で回転を行う
				@param[in]		v			回転

				@return			None
		*//**************************************************************************/
		void RotationYZX(const Vector3& v);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→Z→Xの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationYZX(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→X→Yの順で回転を行う
				@param[in]		v			回転

				@return			None
		*//**************************************************************************/
		void RotationZXY(const Vector3& v);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→X→Yの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationZXY(const MofFloat x,const MofFloat y,const MofFloat z);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→Y→Xの順で回転を行う
				@param[in]		v			回転

				@return			None
		*//**************************************************************************/
		void RotationZYX(const Vector3& v);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→Y→Xの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationZYX(const MofFloat x,const MofFloat y,const MofFloat z);
		
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Yの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転

				@return			None
		*//**************************************************************************/
		void RotationXY(const MofFloat x,const MofFloat y);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Zの順で回転を行う
				@param[in]		x			X回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationXZ(const MofFloat x,const MofFloat z);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								X→Yの順で回転を行う
				@param[in]		x			X回転
				@param[in]		y			Y回転

				@return			None
		*//**************************************************************************/
		void RotationYX(const MofFloat x,const MofFloat y);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Y→Zの順で回転を行う
				@param[in]		y			Y回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationYZ(const MofFloat y,const MofFloat z);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→Xの順で回転を行う
				@param[in]		x			X回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationZX(const MofFloat x,const MofFloat z);
		/*************************************************************************//*!
				@brief			回転行列計算<br>
								Z→Yの順で回転を行う
				@param[in]		y			Y回転
				@param[in]		z			Z回転

				@return			None
		*//**************************************************************************/
		void RotationZY(const MofFloat y,const MofFloat z);

		/*************************************************************************//*!
				@brief			X軸回転行列計算
				@param[in]		ax			X回転

				@return			None
		*//**************************************************************************/
		void RotationX(const MofFloat ax);
		/*************************************************************************//*!
				@brief			X軸回転行列計算<br>
								元行列 × X回転行列の結果を自身に設定する。
				@param[in]		InMat		元行列
				@param[in]		ax			X回転

				@return			None
		*//**************************************************************************/
		void RotationX(const Matrix44& InMat,const MofFloat ax);
		/*************************************************************************//*!
				@brief			X軸回転行列計算<br>
								X回転行列 × 元行列の結果を自身に設定する。
				@param[in]		ax			X回転
				@param[in]		InMat		元行列

				@return			None
		*//**************************************************************************/
		void RotationX(const MofFloat ax,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			Y軸回転行列計算
				@param[in]		ay			Y回転

				@return			None
		*//**************************************************************************/
		void RotationY(const MofFloat ay);
		/*************************************************************************//*!
				@brief			Y軸回転行列計算<br>
								元行列 × Y回転行列の結果を自身に設定する。
				@param[in]		InMat		元行列
				@param[in]		ay			Y回転

				@return			None
		*//**************************************************************************/
		void RotationY(const Matrix44& InMat,const MofFloat ay);
		/*************************************************************************//*!
				@brief			Y軸回転行列計算<br>
								Y回転行列 × 元行列の結果を自身に設定する。
				@param[in]		ay			Y回転
				@param[in]		InMat		元行列

				@return			None
		*//**************************************************************************/
		void RotationY(const MofFloat ay,const Matrix44& InMat);
		/*************************************************************************//*!
				@brief			Z軸回転行列計算
				@param[in]		az			Z回転

				@return			None
		*//**************************************************************************/
		void RotationZ(const MofFloat az);
		/*************************************************************************//*!
				@brief			Z軸回転行列計算<br>
								元行列 × Z回転行列の結果を自身に設定する。
				@param[in]		InMat		元行列
				@param[in]		az			Z回転

				@return			None
		*//**************************************************************************/
		void RotationZ(const Matrix44& InMat,const MofFloat az);
		/*************************************************************************//*!
				@brief			Z軸回転行列計算<br>
								Z回転行列 × 元行列の結果を自身に設定する。
				@param[in]		az			Z回転
				@param[in]		InMat		元行列

				@return			None
		*//**************************************************************************/
		void RotationZ(const MofFloat az,const Matrix44& InMat);

		/*************************************************************************//*!
				@brief			指定軸回転行列計算
				@param[in]		a			回転
				@param[in]		v			軸

				@return			None
		*//**************************************************************************/
		void RotationAxis(const MofFloat a,const CVector3& v);

		/*************************************************************************//*!
				@brief			元の姿勢から指定座標を向く行列の作成
				@param[in]		target		目標座標
				@param[in]		forward		前方方向

				@return			None
		*//**************************************************************************/
		void RotateLookAt(Vector3& target, Vector3& forward);
		/*************************************************************************//*!
				@brief			元の姿勢から指定座標を向く行列の作成
				@param[in]		target		目標座標
				@param[in]		forward		前方方向
				@param[out]		out			結果行列

				@return			None
		*//**************************************************************************/
		void RotateLookAt(Vector3& target, Vector3& forward, Matrix44& out);
		/*************************************************************************//*!
				@brief			元の姿勢から指定座標を向く行列の作成
				@param[in]		target		目標座標

				@return			None
		*//**************************************************************************/
		void RotateLookAt(Vector3& target);
		/*************************************************************************//*!
				@brief			元の姿勢から指定座標を向く行列の作成
				@param[in]		target		目標座標
				@param[out]		out			結果行列

				@return			None
		*//**************************************************************************/
		void RotateLookAt(Vector3& target, Matrix44& out);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		pivot		中心
				@param[in]		Angle		回転角度

				@return			None
		*//**************************************************************************/
		void RotateAroundLocal(Matrix44& pivot, Vector3& Angle);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		pivot		中心
				@param[in]		Angle		回転角度
				@param[out]		out			出力行列

				@return			None
		*//**************************************************************************/
		void RotateAroundLocal(Matrix44& pivot, Vector3& Angle, Matrix44& out);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		pivot		中心
				@param[in]		Angle		回転角度

				@return			None
		*//**************************************************************************/
		void RotateAround(Matrix44& pivot, Vector3& Angle);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		pivot		中心
				@param[in]		Angle		回転角度
				@param[out]		out			出力行列

				@return			None
		*//**************************************************************************/
		void RotateAround(Matrix44& pivot, Vector3& Angle, Matrix44& out);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		pivot		中心
				@param[in]		Axis		回転軸
				@param[in]		Angle		回転角度

				@return			None
		*//**************************************************************************/
		void RotateAround(Matrix44& pivot, Vector3& Axis, MofFloat Angle);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をする行列を求める
				@param[in]		pivot		中心
				@param[in]		Axis		回転軸
				@param[in]		Angle		回転角度
				@param[out]		out			出力行列

				@return			None
		*//**************************************************************************/
		void RotateAround(Matrix44& pivot, Vector3& Axis, MofFloat Angle, Matrix44& out);

		/*************************************************************************//*!
				@brief			3x3成分のみの掛け算
				@param[in]		m			計算行列

				@return			None
		*//**************************************************************************/
		void Multiply3x3(const Matrix33& m);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			値の設定
				@param[in]		f11			11成分
				@param[in]		f12			12成分
				@param[in]		f13			13成分
				@param[in]		f14			14成分
				@param[in]		f21			21成分
				@param[in]		f22			22成分
				@param[in]		f23			23成分
				@param[in]		f24			24成分
				@param[in]		f31			31成分
				@param[in]		f32			32成分
				@param[in]		f33			33成分
				@param[in]		f34			34成分
				@param[in]		f41			41成分
				@param[in]		f42			42成分
				@param[in]		f43			43成分
				@param[in]		f44			44成分

				@return			None
		*//**************************************************************************/
		void SetValue(	MofFloat f11 ,MofFloat f12 ,MofFloat f13 ,MofFloat f14,
						MofFloat f21 ,MofFloat f22 ,MofFloat f23 ,MofFloat f24,
						MofFloat f31 ,MofFloat f32 ,MofFloat f33 ,MofFloat f34,
						MofFloat f41 ,MofFloat f42 ,MofFloat f43 ,MofFloat f44 );
		/*************************************************************************//*!
				@brief			内部平行移動ベクトル設定
				@param[in]		v			平行移動

				@return			None
		*//**************************************************************************/
		void SetTranslation(const Vector3& v);
		/*************************************************************************//*!
				@brief			内部平行移動ベクトル設定
				@param[in]		x			X座標
				@param[in]		y			Y座標
				@param[in]		z			Z座標

				@return			None
		*//**************************************************************************/
		void SetTranslation(const MofFloat x,const MofFloat y,const MofFloat z);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			内部3×3行列取得
				@param[out]		m			3×3行列

				@return			None
		*//**************************************************************************/
		void GetMatrix33(Matrix33& m) const;
		/*************************************************************************//*!
				@brief			内部平行移動ベクトル取得
				@param[out]		v			平行移動

				@return			None
		*//**************************************************************************/
		void GetTranslation(Vector3& v) const;
		/*************************************************************************//*!
				@brief			内部拡大ベクトル取得
				@param[out]		v			倍率

				@return			None
		*//**************************************************************************/
		void GetScaling(Vector3& v) const;
		/*************************************************************************//*!
				@brief			内部回転成分のみの行列取得
				@param[out]		m			回転

				@return			None
		*//**************************************************************************/
		void GetRotation(Matrix33& m) const;
		/*************************************************************************//*!
				@brief			内部回転クオータニオン取得
				@param[out]		q			回転

				@return			None
		*//**************************************************************************/
		void GetRotation(Quaternion& q) const;
		/*************************************************************************//*!
				@brief			内部回転ベクトル取得
				@param[out]		v			回転

				@return			None
		*//**************************************************************************/
		void GetRotation(Vector3& v) const;
		/*************************************************************************//*!
				@brief			内部回転ベクトル取得
				@param[out]		v			回転

				@return			None
		*//**************************************************************************/
		void GetYawPitchRoll(Vector3& v) const;
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------
		
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CMatrix44& operator = ( const Matrix33& m );
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CMatrix44& operator = ( const Matrix44& m );

		//クラス基本定義
		MOF_LIBRARYCLASS(CMatrix44,MOF_MATRIX44CLASS_ID);
	};

	//ポインタ置き換え
	typedef CMatrix44*			LPMatrix44;

	//INLINE INCLUDE
	#include	"Matrix44.inl"

}

#endif

//[EOF]