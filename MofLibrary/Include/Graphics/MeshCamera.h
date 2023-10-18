/*************************************************************************//*!
					
					@file	MeshCamera.h
					@brief	メッシュカメラ基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHCAMERA__H__

#define		__MESHCAMERA__H__

//INCLUDE
#include	"Camera.h"
#include	"MeshCameraAnimationBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュコンテナインターフェイス

			メッシュコンテナインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshCamera : public IMofNamedObject , public IMofCopyObject< IMeshCamera > {
	private:
	public:
		/*************************************************************************//*!
				@brief			カメラ状態の計算
				@param[in]		pCam		適用カメラ

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CalculateCamera(LPCamera pCam) = 0;
		/*************************************************************************//*!
				@brief			カメラ状態の計算
				@param[in]		pCam		適用カメラ
				@param[in]		t			アニメーション時間
				@param[in]		bLoop		ループ
				@param[in]		pAnim		アニメーション名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CalculateCamera(LPCamera pCam, MofFloat t, MofBool bLoop, LPCMofChar pAnim) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			カメラ情報取得
				@param			None

				@return			カメラ情報
		*//**************************************************************************/
		virtual MOMCAMERAINFO& GetInfo(void) = 0;
		/*************************************************************************//*!
				@brief			アニメーションの取得
				@param			None

				@return			アニメーション配列
		*//**************************************************************************/
		virtual LPMeshCameraAnimationArray GetAnimation(void) = 0;
		/*************************************************************************//*!
				@brief			登録されていアニメーション取得
				@param[in]		pName			アニメーション名

				@return			アニメーション
		*//**************************************************************************/
		virtual LPMeshCameraAnimation GetAnimation(LPCMofChar pName) = 0;
		/*************************************************************************//*!
				@brief			アニメーション登録数取得
				@param			None

				@return			アニメーション登録数
		*//**************************************************************************/
		virtual MofU32 GetAnimationCount(void) = 0;
	};
	
	//ポインタ置き換え
	typedef IMeshCamera*			LPMeshCamera;
	typedef CDynamicArray< LPMeshCamera >		CMeshCameraArray,*LPMeshCameraArray;
}

#endif	//__MESHCONTAINER__H__

//[EOF]