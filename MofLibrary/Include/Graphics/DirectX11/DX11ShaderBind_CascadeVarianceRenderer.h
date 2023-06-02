/*************************************************************************//*!
					
					@file	DX11ShaderBind_CascadeVarianceRenderer.h
					@brief	シャドウマップの影描画シェーダーバインド。<br>
							シャドウマップの影描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.06.10
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_CASCADEVARIANCERENDERER__H__

#define		__DX11SHADERBIND_CASCADEVARIANCERENDERER__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_3DPrimitiveBase.h"
#include	"../ShaderEffect_CascadedShadowMap.h"

namespace Mof {

	/*******************************//*!
	@brief	シャドウマップの影描画シェーダーバインド。

			シャドウマップの影描画シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_CascadeVarianceRenderer : public CShaderBind_3DPrimitiveBase {
	public:
		/*******************************//*!
		@brief	シャドウマップ描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_SHADOWMAP = CShaderBind_3DPrimitiveBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	シャドウマップ描画情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstShadowMapParam
		{
			Matrix44	m_Shadow;
			Vector4		m_vCascadeOffset[CShaderEffect_CascadedShadowMap::MAX_CASCADES];
			Vector4		m_vCascadeScale[CShaderEffect_CascadedShadowMap::MAX_CASCADES];

			MofFloat	m_fMinBorderPadding;
			MofFloat	m_fMaxBorderPadding;

			MofFloat	m_fCascadeBlendArea;
			MofFloat	m_fShadowPower;
		};
		/*******************//*!
		シャドウマップ描画情報設定
		*//********************/
		ConstShadowMapParam						m_ShadowMapParam;
	protected:
		/*******************//*!
		シャドウマップ描画情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstShadowMap;
		/*******************//*!
		テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pShadowMapTex0;
		/*******************//*!
		テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pShadowMapTex1;
		/*******************//*!
		テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pShadowMapTex2;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_CascadeVarianceRenderer();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_CascadeVarianceRenderer(const CDX11ShaderBind_CascadeVarianceRenderer& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_CascadeVarianceRenderer();
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			バッファの設定
				@param[in]		n			番号
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n);
		/*************************************************************************//*!
				@brief			バッファの設定
				@param[in]		n			番号
				@param[in]		pData		データ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			テクスチャの設定
				@param[in]		n			番号
				@param[in]		pTex		テクスチャ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			設定パラメーター数を取得する
				@param			None

				@return			パラメーターの数
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const { return PARAM_MAX; }

		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11ShaderBind_CascadeVarianceRenderer,MOF_DX11SHADERBINDCASCADEVARIANCERENDERERCLASS_ID);
	};
	
	#include	"DX11ShaderBind_CascadeVarianceRenderer.inl"

	//置き換え
	typedef CDX11ShaderBind_CascadeVarianceRenderer		CShaderBind_CascadeVarianceRenderer;
	typedef CShaderBind_CascadeVarianceRenderer*		LPShaderBind_CascadeVarianceRenderer;
}

#endif

//[EOF]