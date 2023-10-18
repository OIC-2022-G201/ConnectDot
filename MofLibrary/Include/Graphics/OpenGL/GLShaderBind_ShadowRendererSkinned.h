/*************************************************************************//*!
					
					@file	GLShaderBind_ShadowRendererSkinned.h
					@brief	シャドウマップの影描画シェーダーバインド。(スキンメッシュ用)<br>
							シャドウマップの影描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.29
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_SHADOWRENDERERSKINNED__H__

#define		__GLSHADERBIND_SHADOWRENDERERSKINNED__H__

//INCLUDE
#include	"GLShaderBind_SkinGeometryBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	シャドウマップの影描画シェーダーバインド。(スキンメッシュ用)

			シャドウマップの影描画シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ShadowRendererSkinned : public CShaderBind_SkinGeometryBase {
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
		CGLShaderBind_ShadowRendererSkinned();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ShadowRendererSkinned(const CGLShaderBind_ShadowRendererSkinned& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_ShadowRendererSkinned,MOF_GLSHADERBINDSHADOWRENDERERSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_ShadowRendererSkinned.inl"

	//置き換え
	typedef CGLShaderBind_ShadowRendererSkinned		CShaderBind_ShadowRendererSkinned;
	typedef CShaderBind_ShadowRendererSkinned*		LPShaderBind_ShadowRendererSkinned;
}

#endif

//[EOF]
