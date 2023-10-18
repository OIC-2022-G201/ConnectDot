/*************************************************************************//*!
					
					@file	ShaderEffect_GaussianBlur.h
					@brief	ガウスぼかしシェーダークラス。

															@author	CDW
															@date	2015.04.17
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_GAUSSIANBLUR__H__

#define		__SHADEREFFECT_GAUSSIANBLUR__H__

//INCLUDE
#include	"ShaderEffect_BlurBase.h"
#include	"ShaderBind_GaussianBlurBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ガウスぼかしシェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_GaussianBlur : public CShaderEffect_BlurBase {
	protected:		
		MofFloat	m_SampleStepX;	//<!サンプリングするピクセルの横間隔
		MofFloat	m_SampleStepY;	//<!サンプリングするピクセルの縦間隔
		MofS32		m_TexWidth;		//<!テクスチャのサイズ
		MofS32		m_TexHeight;	//<!テクスチャのサイズ
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_GaussianBlur();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_GaussianBlur();
		
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();
		
		/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		col			描画色
		@param[in]		Alignment	アライメント（TextureAlignmentからフラグの組み合わせで指定）
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,LPTexture pTex);
		/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTarget		描画ターゲットのテクスチャ
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex);

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
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY,MofS32 TexWidth,MofS32 TexHeight);
		/*************************************************************************//*!
				@brief			ぼかしのパラメータの設定
				@param[in]		SampleStepX		サンプリングするピクセルの横間隔
				@param[in]		SampleStepY		サンプリングするピクセルの縦間隔

				@return			None
		*//**************************************************************************/
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY);

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_GaussianBlur,MOF_SHADEREFFECTGAUSSIANBLURCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_GaussianBlur*			LPShaderEffect_GaussianBlur;

#include	"ShaderEffect_GaussianBlur.inl"

}

#endif

//[EOF]