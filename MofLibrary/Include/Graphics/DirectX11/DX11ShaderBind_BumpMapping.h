/*************************************************************************//*!
					
					@file	DX11ShaderBind_BumpMapping.h
					@brief	バンプマッピングシェーダーバインド。<br>
							バンプマッピングシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.06.19
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_BUMPMAPPING__H__

#define		__DX11SHADERBIND_BUMPMAPPING__H__

//INCLUDE
#include	"../DirectX11/DX11ShaderBind_3DPrimitiveBase.h"

namespace Mof {

	/*******************************//*!
	@brief	バンプマッピングシェーダーバインド。

			バンプマッピングシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_BumpMapping : public CShaderBind_3DPrimitiveBase {
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
		CDX11ShaderBind_BumpMapping();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_BumpMapping(const CDX11ShaderBind_BumpMapping& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_BumpMapping();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_BumpMapping,MOF_DX11SHADERBINDBUMPMAPPINGCLASS_ID);
	};
	
	#include	"DX11ShaderBind_BumpMapping.inl"

	//置き換え
	typedef CDX11ShaderBind_BumpMapping		CShaderBind_BumpMapping;
	typedef CShaderBind_BumpMapping*		LPShaderBind_BumpMapping;
}

#endif

//[EOF]