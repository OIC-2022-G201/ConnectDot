/*************************************************************************//*!
					
					@file	ShaderEffect_HDRBrightPass.h
					@brief	HDR用高輝度抽出シェーダークラス。

															@author	CDW
															@date	2015.05.20
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_HDRBRIGHTPASS__H__

#define		__SHADEREFFECT_HDRBRIGHTPASS__H__

//INCLUDE
#include	"ShaderEffect_BrightPass.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	HDR用高輝度抽出シェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_HDRBrightPass : public CShaderEffect_BrightPass {
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
		/*************************************************************************//*!
		@brief			高輝度の基準となる閾値を設定
		@param[in]		Threshold			閾値
		@param[in]		MiddleGray			中間の明るさ
		@param[in]		HDRBrightPassOffset	オフセット
				
		@return			None
		*//**************************************************************************/
		virtual MofBool SetHDRBrightPassParam(MofFloat Threshold,MofFloat MiddleGray,MofFloat HDRBrightPassOffset);
		/*************************************************************************//*!
		@brief			明るさの基準となるテクスチャを設定
		@param[in]		pTex		テクスチャ
				
		@return			None
		*//**************************************************************************/
		virtual MofBool SetAdaptedLumTexture(LPTexture pTex);

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_HDRBrightPass,MOF_SHADEREFFECTHDRBRIGHTPASSCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_HDRBrightPass*			LPShaderEffect_HDRBrightPass;

#include	"ShaderEffect_HDRBrightPass.inl"

}

#endif

//[EOF]