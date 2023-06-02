/*************************************************************************//*!
					
					@file	ShaderEffect_Bloom.h
					@brief	Bloomシェーダークラス。

															@author	CDW
															@date	2015.11.09
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_BLOOM__H__

#define		__SHADEREFFECT_BLOOM__H__

//INCLUDE
#include	"ShaderEffect_BrightPass.h"
#include	"ShaderEffect_GaussianBlur.h"

namespace Mof {
	
	/*******************************//*!
	@brief	Bloomシェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_Bloom : public CShaderEffect_2DBase {
	protected:
		/*******************//*!
		高輝度抽出先テクスチャ
		*//********************/
		LPTexture m_pTexBright;
		/*******************//*!
		横方向ブラー出力先テクスチャ
		*//********************/
		LPTexture m_pTexBloomX;
		/*******************//*!
		縦方向方向ブラー出力先テクスチャ
		*//********************/
		LPTexture m_pTexBloomY;
		/*******************//*!
		高輝度抽出シェーダー
		*//********************/
		LPShaderEffect_BrightPass m_pBrightPass;
		/*******************//*!
		ガウスぼかしシェーダー
		*//********************/
		LPShaderEffect_GaussianBlur m_pGBlur;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_Bloom();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_Bloom();
		
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param[in]		Bloom		ブルームスケール

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofU32 Bloom);
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTarget		描画ターゲットのテクスチャ
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTex);
		/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTarget		描画ターゲットのテクスチャ
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex);
		/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTarget		描画ターゲットのテクスチャ
		@param[in]		pTex		テクスチャ
		@param[in]		BlurRepeat	ぼかし回数
		@param[in]		pBlurSteps	回数ごとのぼかし幅の配列
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTarget,LPTexture pTex,MofU32 BlurRepeat,LPMofFloat pBlurSteps);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ブルームの明るさ倍率設定
				@param[in]		BloomScale	ブルームの明るさ倍率
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBloomScale(MofFloat BloomScale);
		/*************************************************************************//*!
				@brief			高輝度部抽出のパラメータ設定
				@param[in]		Threshold			閾値
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBrightPassParam(MofFloat Threshold);

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_Bloom,MOF_SHADEREFFECTBLOOMCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_Bloom*			LPShaderEffect_Bloom;

#include	"ShaderEffect_Bloom.inl"

}

#endif

//[EOF]