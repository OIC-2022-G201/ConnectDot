/*************************************************************************//*!
					
					@file	Camera.h
					@brief	カメラ基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__CAMERA__H__

#define		__CAMERA__H__

//INCLUDE
#include	"Graphics.h"

namespace Mof {

	/*******************************//*!
	@brief	座標系タイプ列挙

			全体の座標系のタイプの列挙

	@author	CDW
	*//********************************/
	typedef enum CoordinateType {
		COORDINATETYPE_LEFTHAND,							//!<左手座標系
		COORDINATETYPE_RIGHTHAND,							//!<右手座標系
	}CoordinateType;
	
	
	/*******************************//*!
	@brief	カメラ基底インターフェイス

			カメラ基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API ICamera : public IMofNamedObject {
	public:
		/*******************************//*!
		@brief	プロジェクションタイプ列挙

				プロジェクションタイプの列挙

		@author	CDW
		*//********************************/
		typedef enum ProjectionType {
			PROJECTION_PERSPECTIVEFOV,						//!<パースペクティブ
			PROJECTION_PERSPECTIVE,							//!<パースペクティブ
			PROJECTION_ORTHO,								//!<正射影
		}ProjectionType;
		
		/*******************************//*!
		@brief	プロジェクション情報構造体

				プロジェクション行列の設定に必要な情報を格納する構造体

		@author	CDW
		*//********************************/
		typedef struct tag_PROJECTION {
			ProjectionType				Type;				//!<タイプ
			MofFloat					Fov;				//!<視野角
			MofFloat					Aspect;				//!<アスペクト比
			MofFloat					Width;				//!<幅
			MofFloat					Height;				//!<高さ
			MofFloat					Near;				//!<近平面
			MofFloat					Far;				//!<遠平面
		}Projection,*LPProjection;
		
		/*******************************//*!
		@brief	視錐台情報構造体

				視錐台情報を格納する構造体

		@author	CDW
		*//********************************/
		typedef struct tag_VIEWFRUSTUM {
			MofFloat					Near;				//!<近平面
			MofFloat					Far;				//!<遠平面
			CVector3					TopPlane;			//上平面
			CVector3					BottomPlane;		//下平面
			CVector3					LeftPlane;			//左平面
			CVector3					RightPlane;			//右平面

			tag_VIEWFRUSTUM() :
			Near(0.0f) ,
			Far(0.0f) ,
			TopPlane() ,
			BottomPlane() ,
			LeftPlane() ,
			RightPlane() {
			}
			tag_VIEWFRUSTUM(const tag_VIEWFRUSTUM& obj) :
			Near(obj.Near) ,
			Far(obj.Far),
			TopPlane(obj.TopPlane),
			BottomPlane(obj.BottomPlane),
			LeftPlane(obj.LeftPlane),
			RightPlane(obj.RightPlane) {
			}
		}ViewFrustum,*LPViewFrustum;

	protected:
	public:
		/*************************************************************************//*!
				@brief			カメラの更新<br>
								設定されている情報からカメラに必要な各種行列を計算しなおす
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Update(void) = 0;

		/*************************************************************************//*!
				@brief			Targetへの注視行列計算
				@param[in]		Pos			座標
				@param[in]		Target		注視座標
				@param[in]		Up			上方ベクトル

				@return			None
		*//**************************************************************************/
		virtual void LookAt(const Vector3& Pos,const Vector3& Target,const Vector3& Up) = 0;
		
		/*************************************************************************//*!
				@brief			射影行列計算
				@param[in]		fov			視野角
				@param[in]		Aspect		アスペクト比
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		virtual void PerspectiveFov(const MofFloat fov,const MofFloat Aspect,const MofFloat Near,const MofFloat Far) = 0;
		/*************************************************************************//*!
				@brief			パースペクティブ射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		virtual void Perspective(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far) = 0;
		/*************************************************************************//*!
				@brief			正射影行列計算
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Near		最近面
				@param[in]		Far			最遠面

				@return			None
		*//**************************************************************************/
		virtual void Ortho(const MofFloat w,const MofFloat h,const MofFloat Near,const MofFloat Far) = 0;

		/*************************************************************************//*!
				@brief			3D空間上の座標をスクリーン座標に変換する
				@param[in]		v			3D座標
				@param[out]		OutX		X座標出力
				@param[out]		OutY		Y座標出力
				@param[out]		OutZ		Z座標出力
				@param[out]		OutW		W座標出力

				@return			None
		*//**************************************************************************/
		virtual void WorldToScreen(const Vector3& v,MofFloat* OutX,MofFloat* OutY,MofFloat* OutZ = NULL,MofFloat* OutW = NULL) = 0;
		/*************************************************************************//*!
				@brief			スクリーン座標を3D空間上のレイに変換する
				@param[in]		px			X座標
				@param[in]		py			Y座標
				@param[out]		Out			3D座標出力

				@return			None
		*//**************************************************************************/
		virtual void ScreenToWorld(const MofFloat px,const MofFloat py,Vector3& Out) = 0;
		/*************************************************************************//*!
				@brief			スクリーン座標を3D空間上のレイに変換する
				@param[in]		p			座標
				@param[out]		Out			3D座標出力

				@return			None
		*//**************************************************************************/
		virtual void ScreenToWorld(const Vector2& p,Vector3& Out) = 0;
		/*************************************************************************//*!
				@brief			フラスタム内に存在するか判定する
				@param[in]		p			座標
				@param[out]		r			半径
				
				@return			TRUE		ある<br>
								FALSE		ない
		*//**************************************************************************/
		virtual MofBool IsFrustumInside(const Vector3& p,MofFloat r) = 0;
		/*************************************************************************//*!
				@brief			Y軸限定ビルボード行列計算
				@param[out]		Out			結果行列

				@return			None
		*//**************************************************************************/
		virtual void CalculateYBillBoardMatrix(CMatrix33& Out) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			座標系設定
				@param[in]		c			座標系
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetCoordinateType(const CoordinateType c) = 0;
		/*************************************************************************//*!
				@brief			ビューポート設定<br>
								画面サイズから自動的に設定を行う。
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPort(void) = 0;
		/*************************************************************************//*!
				@brief			ビューポート設定
				@param[in]		r			画面矩形
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPort(const Rectangle& r) = 0;
		/*************************************************************************//*!
				@brief			ビューポート設定
				@param[in]		px			X位置
				@param[in]		py			Y位置
				@param[in]		w			幅
				@param[in]		h			高さ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPort(const MofFloat px,const MofFloat py,const MofFloat w,const MofFloat h) = 0;
		/*************************************************************************//*!
				@brief			ビューポート設定
				@param[in]		px			X位置
				@param[in]		py			Y位置
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		n			最近
				@param[in]		f			最遠
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPort(const MofFloat px,const MofFloat py,const MofFloat w,const MofFloat h,const MofFloat n,const MofFloat f) = 0;
		/*************************************************************************//*!
				@brief			ビューポート設定
				@param[in]		v			ビューポート
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPort(const ViewPort& v) = 0;
		/*************************************************************************//*!
				@brief			カメラ座標設定
				@param[in]		v			設定座標
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPosition(const Vector3& v) = 0;
		/*************************************************************************//*!
				@brief			カメラ座標設定
				@param[in]		x			設定X座標
				@param[in]		y			設定Y座標
				@param[in]		z			設定Z座標
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetViewPosition(MofFloat x,MofFloat y,MofFloat z) = 0;
		/*************************************************************************//*!
				@brief			カメラ注視点設定
				@param[in]		v			設定座標
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTargetPosition(const Vector3& v) = 0;
		/*************************************************************************//*!
				@brief			カメラ注視点設定
				@param[in]		x			設定X座標
				@param[in]		y			設定Y座標
				@param[in]		z			設定Z座標
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTargetPosition(MofFloat x, MofFloat y, MofFloat z) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			カメラ位置取得
				@param			None

				@return			カメラ位置
		*//**************************************************************************/
		virtual CVector3& GetViewPosition(void) = 0;
		/*************************************************************************//*!
				@brief			カメラ位置取得
				@param			None

				@return			カメラ位置
		*//**************************************************************************/
		virtual const CVector3& GetViewPosition(void) const = 0;
		/*************************************************************************//*!
				@brief			注視点取得
				@param			None

				@return			注視点
		*//**************************************************************************/
		virtual CVector3& GetTargetPosition(void) = 0;
		/*************************************************************************//*!
				@brief			注視点取得
				@param			None

				@return			注視点
		*//**************************************************************************/
		virtual const CVector3& GetTargetPosition(void) const = 0;
		/*************************************************************************//*!
				@brief			視線ベクトル取得
				@param			None

				@return			視線ベクトル
		*//**************************************************************************/
		virtual CVector3& GetViewFront(void) = 0;
		/*************************************************************************//*!
				@brief			視線ベクトル取得
				@param			None

				@return			視線ベクトル
		*//**************************************************************************/
		virtual const CVector3& GetViewFront(void) const = 0;
		/*************************************************************************//*!
				@brief			上方ベクトル取得
				@param			None

				@return			上方ベクトル
		*//**************************************************************************/
		virtual CVector3& GetViewUp(void) = 0;
		/*************************************************************************//*!
				@brief			上方ベクトル取得
				@param			None

				@return			上方ベクトル
		*//**************************************************************************/
		virtual const CVector3& GetViewUp(void) const = 0;
		/*************************************************************************//*!
				@brief			ビューポート設定取得
				@param			None

				@return			ビューポート
		*//**************************************************************************/
		virtual LPViewPort GetViewPort(void) = 0;
		/*************************************************************************//*!
				@brief			ビュー行列取得
				@param			None

				@return			ビュー行列
		*//**************************************************************************/
		virtual CMatrix44& GetViewMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			ビュー行列取得
				@param			None

				@return			ビュー行列
		*//**************************************************************************/
		virtual const CMatrix44& GetViewMatrix(void) const = 0;
		/*************************************************************************//*!
				@brief			ビルボード行列取得
				@param			None

				@return			ビルボード行列
		*//**************************************************************************/
		virtual CMatrix33& GetBillBoardMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			ビルボード行列取得
				@param			None

				@return			ビルボード行列
		*//**************************************************************************/
		virtual const CMatrix33& GetBillBoardMatrix(void) const = 0;
		/*************************************************************************//*!
				@brief			プロジェクション行列取得
				@param			None

				@return			プロジェクション行列
		*//**************************************************************************/
		virtual CMatrix44& GetProjectionMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			プロジェクション行列取得
				@param			None

				@return			プロジェクション行列
		*//**************************************************************************/
		virtual const CMatrix44& GetProjectionMatrix(void) const = 0;
		/*************************************************************************//*!
				@brief			ビュープロジェクション行列取得
				@param			None

				@return			ビュープロジェクション行列
		*//**************************************************************************/
		virtual CMatrix44& GetViewProjectionMatrix(void) = 0;
		/*************************************************************************//*!
				@brief			ビュープロジェクション行列取得
				@param			None

				@return			ビュープロジェクション行列
		*//**************************************************************************/
		virtual const CMatrix44& GetViewProjectionMatrix(void) const = 0;
		/*************************************************************************//*!
				@brief			座標系取得
				@param			None

				@return			座標系
		*//**************************************************************************/
		virtual CoordinateType GetCoordinateType(void) const = 0;
		/*************************************************************************//*!
				@brief			プロジェクション情報構造体取得
				@param			None

				@return			座標系
		*//**************************************************************************/
		virtual const Projection& GetProjectionInfo(void) const = 0;
	};

	//ポインタ置き換え
	typedef ICamera*			LPCamera;
}

#endif

//[EOF]