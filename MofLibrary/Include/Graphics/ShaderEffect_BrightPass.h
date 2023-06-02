/*************************************************************************//*!
					
					@file	ShaderEffect_BrightPass.h
					@brief	高輝度抽出シェーダークラス。

															@author	CDW
															@date	2015.04.20
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_BRIGHTPASS__H__

#define		__SHADEREFFECT_BRIGHTPASS__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	高輝度抽出シェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_BrightPass : public CShaderEffect_2DBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
		@brief			高輝度の基準となる閾値を設定
		@param[in]		Threshold		閾値
				
		@return			None
		*//**************************************************************************/
		virtual MofBool SetThreshold(MofFloat Threshold);

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_BrightPass,MOF_SHADEREFFECTBRIGHTPASSCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_BrightPass*			LPShaderEffect_BrightPass;

#include	"ShaderEffect_BrightPass.inl"

}

#endif

//[EOF]