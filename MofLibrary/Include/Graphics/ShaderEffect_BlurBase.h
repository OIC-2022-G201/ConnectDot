/*************************************************************************//*!
					
					@file	ShaderEffect_BlurBase.h
					@brief	ぼかしシェーダー基底クラス。

															@author	CDW
															@date	2015.06.17
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_BLURBASE__H__

#define		__SHADEREFFECT_BLURBASE__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ガウスぼかしシェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_BlurBase : public CShaderEffect_2DBase {
	protected:
	public:

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ぼかしのパラメータの設定
				@param[in]		SampleStepX		サンプリングするピクセルの横間隔
				@param[in]		SampleStepY		サンプリングするピクセルの縦間隔
				@param[in]		TexWidth		テクスチャのサイズ
				@param[in]		TexHeight		テクスチャのサイズ

				@return			None
		*//**************************************************************************/
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY,MofS32 TexWidth,MofS32 TexHeight) = 0;
		/*************************************************************************//*!
				@brief			ぼかしのパラメータの設定
				@param[in]		SampleStepX		サンプリングするピクセルの横間隔
				@param[in]		SampleStepY		サンプリングするピクセルの縦間隔

				@return			None
		*//**************************************************************************/
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY) = 0;

	};

	// 置き換え
	typedef CShaderEffect_BlurBase*			LPShaderEffect_BlurBase;
}

#endif

//[EOF]