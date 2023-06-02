/*************************************************************************//*!
					
					@file	DX11ShaderBind_BumpMappingSkinned.h
					@brief	バンプマッピングシェーダーバインド。<br>
							バンプマッピングシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.06.22
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_BUMPMAPPINGSKINNED__H__

#define		__DX11SHADERBIND_BUMPMAPPINGSKINNED__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_SkinGeometryBase.h"

namespace Mof {

	/*******************************//*!
	@brief	バンプマッピングシェーダーバインド。

			バンプマッピングシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_BumpMappingSkinned : public CShaderBind_SkinGeometryBase {
	public:
	protected:
		/*******************//*!
		テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pNormalMap;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_BumpMappingSkinned();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_BumpMappingSkinned(const CDX11ShaderBind_BumpMappingSkinned& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_BumpMappingSkinned();
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pvb			頂点バッファ配列
				@param[in]		Cnt			頂点バッファ配列数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool CreateVertexLayout(LPVertexBuffer* pvb,MofU32 Cnt);
	
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_BumpMappingSkinned,MOF_DX11SHADERBINDBUMPMAPPINGSKINNEDCLASS_ID);
	};
	
	#include	"DX11ShaderBind_BumpMappingSkinned.inl"

	//置き換え
	typedef CDX11ShaderBind_BumpMappingSkinned		CShaderBind_BumpMappingSkinned;
	typedef CShaderBind_BumpMappingSkinned*		LPShaderBind_BumpMappingSkinned;
}

#endif

//[EOF]