/*************************************************************************//*!
					
					@file	MeshMorphingAnimation.h
					@brief	メッシュアニメーション基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHMORPHINGANIMATION__H__

#define		__MESHMORPHINGANIMATION__H__

//INCLUDE
#include	"Bone.h"
#include	"../Common/KeyFrameArray.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュアニメーションインターフェイス

			メッシュアニメーションインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshMorphingAnimation : public IMofNamedObject , public IMofCopyObject< IMeshMorphingAnimation > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			パラメーターキー設定<br>
								古いデータがある場合解放される
				@param[in]		pKey			設定するキー
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetParameterKey(LPFloatKeyFrameArray pKey) = 0;
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
				@brief			アニメーションの時間取得
				@param			None

				@return			アニメーションの時間
		*//**************************************************************************/
		virtual MofFloat GetTime(void) = 0;
		/*************************************************************************//*!
				@brief			パラメーターキー取得
				@param			None

				@return			パラメーターキー
		*//**************************************************************************/
		virtual LPFloatKeyFrameArray GetParameterKey(void) = 0;
	};
	
	//ポインタ置き換え
	typedef IMeshMorphingAnimation*				LPMeshMorphingAnimation;
	typedef CDynamicArray< LPMeshMorphingAnimation >		CMeshMorphingAnimationArray,*LPMeshMorphingAnimationArray;
}

#endif	//__MESHMORPHINGANIMATION__H__

//[EOF]