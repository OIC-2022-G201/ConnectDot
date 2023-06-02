/*************************************************************************//*!
					
					@file	ShaderEffect_HDR.h
					@brief	HDRシェーダークラス。

															@author	CDW
															@date	2015.05.15
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_HDR__H__

#define		__SHADEREFFECT_HDR__H__

//INCLUDE
#include	"ShaderEffect_SampleLuminance.h"
#include	"ShaderEffect_DownScale.h"
#include	"ShaderEffect_BrightPass.h"
#include	"ShaderEffect_HDRBrightPass.h"
#include	"ShaderEffect_GaussianBlur.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	HDRシェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_HDR : public CShaderEffect_2DBase {
	protected:
		/*******************//*!
		トーンマップフラグ
		*//********************/
		MofBool							m_bToneMap;
		/*******************//*!
		輝度測定用テクスチャの配列
		*//********************/
		LPTextureArray					m_pTexLuminance;
		/*******************//*!
		トーンマップの基準となる輝度テクスチャ
		*//********************/
		LPTexture						m_pTexAdaptedLuminanceCur;
		/*******************//*!
		高輝度抽出先テクスチャ
		*//********************/
		LPTexture						m_pTexBright;
		/*******************//*!
		横方向ブラー出力先テクスチャ
		*//********************/
		LPTexture						m_pTexBloomX;
		/*******************//*!
		縦方向方向ブラー出力先テクスチャ
		*//********************/
		LPTexture						m_pTexBloomY;
		/*******************//*!
		色テクスチャから輝度へ変換するシェーダー
		*//********************/
		LPShaderEffect_SampleLuminance	m_pSampleLuminance;
		/*******************//*!
		輝度測定用の縮小シェーダー
		*//********************/
		LPShaderEffect_DownScale		m_pDownScale;
		/*******************//*!
		高輝度抽出シェーダー
		*//********************/
		LPShaderEffect_BrightPass		m_pBrightPass;
		/*******************//*!
		高輝度抽出シェーダー
		*//********************/
		LPShaderEffect_HDRBrightPass	m_pToneBrightPass;
		/*******************//*!
		ガウスぼかしシェーダー
		*//********************/
		LPShaderEffect_GaussianBlur		m_pGBlur;
		/*******************//*!
		瞳孔シミュレーションの変化速度(0.0f～1.0f)
		*//********************/
		MofFloat						m_LumTransitionSpeed;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_HDR();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		bTone		トーンマップ有効フラグ

				@return			None
		*//**************************************************************************/
		CShaderEffect_HDR(MofBool bTone);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_HDR();
		
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param[in]		TargetSize	描画先

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TargetSize);
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param[in]		TargetSize	描画先
				@param[in]		Bloom		ブルームスケール

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TargetSize, MofU32 Bloom);
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param[in]		TargetSize		描画先
				@param[in]		Bloom			ブルームスケール
				@param[in]		LumTexFormat	輝度テクスチャのフォーマット

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TargetSize, MofU32 Bloom, PixelFormat LumTexFormat);
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
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex,MofU32 BlurRepeat,LPMofFloat pBlurSteps);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			動向シミュレーションの変化速度
				@param[in]		MiddleGray	0.0f～1.0fの変化速度
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetLumTransitionSpeed(MofFloat Speed);
		/*************************************************************************//*!
				@brief			明るさの基準値を設定
				@param[in]		MiddleGray	明るさの基準値
				@param[in]		BloomScale	ブルームの明るさ倍率
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetToneMapParam(MofFloat MiddleGray,MofFloat BloomScale);
		/*************************************************************************//*!
				@brief			高輝度部抽出のパラメータ設定
				@param[in]		Threshold			閾値
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBrightPassParam(MofFloat Threshold);
		/*************************************************************************//*!
				@brief			高輝度部抽出のパラメータ設定
				@param[in]		Threshold			閾値
				@param[in]		MiddleGray			明るさの基準値
				@param[in]		BrightPassOffset	補正
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBrightPassParam(MofFloat Threshold,MofFloat MiddleGray,MofFloat BrightPassOffset);

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_HDR,MOF_SHADEREFFECTHDRCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_HDR*			LPShaderEffect_HDR;

#include	"ShaderEffect_HDR.inl"

}

#endif

//[EOF]