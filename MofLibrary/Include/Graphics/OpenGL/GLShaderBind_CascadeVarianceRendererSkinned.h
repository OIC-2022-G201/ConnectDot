/*************************************************************************//*!
					
					@file	GLShaderBind_CascadeVarianceRendererSkinned.h
					@brief	シャドウマップの影描画シェーダーバインド。<br>
							シャドウマップの影描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.11.09
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_CASCADEVARIANCERENDERERSKINNED__H__

#define		__GLSHADERBIND_CASCADEVARIANCERENDERERSKINNED__H__

//INCLUDE
#include	"GLShaderBind_SkinGeometryBase.h"
#include	"../ShaderEffect_CascadedShadowMap.h"

namespace Mof {

	/*******************************//*!
	@brief	シャドウマップの影描画シェーダーバインド。

			シャドウマップの影描画シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_CascadeVarianceRendererSkinned : public CShaderBind_SkinGeometryBase {
	public:
		/*******************************//*!
		@brief	シャドウマップ描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_SHADOWMAP = CShaderBind_SkinGeometryBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	シャドウマップ描画情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstShadowMapParam
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
		ConstShadowMapParam					m_ShadowMapParam;
	protected:
		/*******************//*!
		影マトリクスロケーション
		*//********************/
		GLuint								m_ShadowMatLocation;
		/*******************//*!
		カスケードオフセットロケーション
		*//********************/
		GLuint								m_CascadeOffsetLocation;
		/*******************//*!
		カスケードスケールロケーション
		*//********************/
		GLuint								m_CascadeScaleLocation;
		/*******************//*!
		最小パディングロケーション
		*//********************/
		GLuint								m_MinBorderPaddingLocation;
		/*******************//*!
		最大パディングロケーション
		*//********************/
		GLuint								m_MaxBorderPaddingLocation;
		/*******************//*!
		カスケードブレンド範囲ロケーション
		*//********************/
		GLuint								m_CascadeBlendAreaLocation;
		/*******************//*!
		影の強さロケーション
		*//********************/
		GLuint								m_ShadowPowerLocation;
		/*******************//*!
		テクスチャ
		*//********************/
		GLuint								m_ShadowMapTexLocation0;
		/*******************//*!
		テクスチャ
		*//********************/
		GLuint								m_ShadowMapTexLocation1;
		/*******************//*!
		テクスチャ
		*//********************/
		GLuint								m_ShadowMapTexLocation2;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_CascadeVarianceRendererSkinned();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_CascadeVarianceRendererSkinned(const CGLShaderBind_CascadeVarianceRendererSkinned& pObj);
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
	
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
		MOF_LIBRARYCLASS(CGLShaderBind_CascadeVarianceRendererSkinned,MOF_GLSHADERBINDCASCADEVARIANCERENDERERSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_CascadeVarianceRendererSkinned.inl"

	//置き換え
	typedef CGLShaderBind_CascadeVarianceRendererSkinned		CShaderBind_CascadeVarianceRendererSkinned;
	typedef CShaderBind_CascadeVarianceRendererSkinned*		LPShaderBind_CascadeVarianceRendererSkinned;
}

#endif

//[EOF]
