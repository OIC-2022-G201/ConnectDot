/*************************************************************************//*!
					
					@file	GLShaderBind_ShadowRenderer.h
					@brief	シャドウマップの影描画シェーダーバインド。<br>
							シャドウマップの影描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.29
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_SHADOWRENDERER__H__

#define		__GLSHADERBIND_SHADOWRENDERER__H__

//INCLUDE
#include	"GLShaderBind_3DPrimitiveBase.h"

namespace Mof {

	/*******************************//*!
	@brief	シャドウマップの影描画シェーダーバインド。

			シャドウマップの影描画シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ShadowRenderer : public CShaderBind_3DPrimitiveBase {
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
		struct ConstShadowMapParam
		{
			Matrix44	mtxLightVP;
			MofFloat	ShadowMapSize;
			MofFloat	ShadowEpsilon;
		};
		/*******************//*!
		シャドウマップ描画情報設定
		*//********************/
		ConstShadowMapParam						m_ShadowMapParam;
	protected:
		/*******************//*!
		ライトマトリクスロケーション
		*//********************/
		GLuint									m_LightVPLocation;
		/*******************//*!
		シャドウマップサイズロケーション
		*//********************/
		GLuint									m_ShadowMapSizeLocation;
		/*******************//*!
		シャドウマップイプシロンロケーション
		*//********************/
		GLuint									m_ShadowEpsilonLocation;
		/*******************//*!
		テクスチャロケーション
		*//********************/
		GLuint									m_ShadowMapTexLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ShadowRenderer();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ShadowRenderer(const CGLShaderBind_ShadowRenderer& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_ShadowRenderer,MOF_GLSHADERBINDSHADOWRENDERERCLASS_ID);
	};
	
	#include	"GLShaderBind_ShadowRenderer.inl"

	//置き換え
	typedef CGLShaderBind_ShadowRenderer		CShaderBind_ShadowRenderer;
	typedef CShaderBind_ShadowRenderer*		LPShaderBind_ShadowRenderer;
}

#endif

//[EOF]
