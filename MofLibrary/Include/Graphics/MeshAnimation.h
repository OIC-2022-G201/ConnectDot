/*************************************************************************//*!
					
					@file	MeshAnimation.h
					@brief	メッシュアニメーション基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHANIMATION__H__

#define		__MESHANIMATION__H__

//INCLUDE
#include	"MeshBoneAnimationBase.h"
#include	"MeshMorphingAnimationBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュアニメーションインターフェイス

			メッシュアニメーションインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshAnimation : public IMofNamedObject , public IMofCopyObject< IMeshAnimation > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			モーションのループフラグの設定
				@param[in]		bLoop			ループフラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetLoop(MofBool bLoop) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			アニメーションでの動作ボーン情報取得
				@param			None

				@return			アニメーションでの動作ボーン情報配列
		*//**************************************************************************/
		virtual LPMeshBoneAnimationArray GetBoneAnimation(void) = 0;
		/*************************************************************************//*!
				@brief			アニメーションでの動作モーフィング情報取得
				@param			None

				@return			アニメーションでの動作モーフィング情報配列
		*//**************************************************************************/
		virtual LPMeshMorphingAnimationArray GetMorphingAnimation(void) = 0;
		/*************************************************************************//*!
				@brief			アニメーションの時間取得
				@param			None

				@return			アニメーションの時間
		*//**************************************************************************/
		virtual MofFloat GetTime(void) = 0;
	};
	
	//ポインタ置き換え
	typedef IMeshAnimation*				LPMeshAnimation;
	typedef CDynamicArray< LPMeshAnimation >		CMeshAnimationArray,*LPMeshAnimationArray;
}

#endif	//__MESHANIMATION__H__

//[EOF]