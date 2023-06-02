/*************************************************************************//*!
					
					@file	GLShaderBind_BumpMappingSkinned.h
					@brief	バンプマッピングシェーダーバインド。<br>
							バンプマッピングシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.23
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_BUMPMAPPINGSKINNED__H__

#define		__GLSHADERBIND_BUMPMAPPINGSKINNED__H__

//INCLUDE
#include	"GLShaderBind_SkinGeometryBase.h"

namespace Mof {

	/*******************************//*!
	@brief	バンプマッピングシェーダーバインド。

			バンプマッピングシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_BumpMappingSkinned : public CShaderBind_SkinGeometryBase {
	public:
	protected:
		/*******************//*!
		テクスチャ
		*//********************/
		GLuint									m_NormalMapLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_BumpMappingSkinned();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_BumpMappingSkinned(const CGLShaderBind_BumpMappingSkinned& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_BumpMappingSkinned();
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_BumpMappingSkinned,MOF_GLSHADERBINDBUMPMAPPINGSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_BumpMappingSkinned.inl"

	//置き換え
	typedef CGLShaderBind_BumpMappingSkinned		CShaderBind_BumpMappingSkinned;
	typedef CShaderBind_BumpMappingSkinned*		LPShaderBind_BumpMappingSkinned;
}

#endif

//[EOF]
