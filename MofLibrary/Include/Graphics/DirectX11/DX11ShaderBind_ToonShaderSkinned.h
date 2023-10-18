/*************************************************************************//*!
					
					@file	DX11ShaderBind_ToonShaderSkinned.h
					@brief	トゥーンレンダリングシェーダーバインド。<br>
							トゥーンレンダリングシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.05.27
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_TOONSHADERSKINNED__H__

#define		__DX11SHADERBIND_TOONSHADERSKINNED__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_EdgeBaseOutputSkinned.h"

namespace Mof {

	/*******************************//*!
	@brief	トゥーンレンダリングシェーダーバインド。

			トゥーンレンダリングシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_ToonShaderSkinned : public CShaderBind_EdgeBaseOutputSkinned {
	public:
	protected:
		/*******************//*!
		テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pToonMap;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToonShaderSkinned();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToonShaderSkinned(const CDX11ShaderBind_ToonShaderSkinned& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_ToonShaderSkinned();
		
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
				@brief			テクスチャの設定
				@param[in]		n			番号
				@param[in]		pTex		テクスチャ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);

		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11ShaderBind_ToonShaderSkinned,MOF_DX11SHADERBINDTOONSHADERSKINNEDCLASS_ID);
	};
	
	#include	"DX11ShaderBind_ToonShaderSkinned.inl"

	//置き換え
	typedef CDX11ShaderBind_ToonShaderSkinned		CShaderBind_ToonShaderSkinned;
	typedef CShaderBind_ToonShaderSkinned*		LPShaderBind_ToonShaderSkinned;
}

#endif

//[EOF]