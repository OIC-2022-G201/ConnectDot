/*************************************************************************//*!
					
					@file	GLShaderBind_ToonShaderSkinned.h
					@brief	トゥーンレンダリングシェーダーバインド。<br>
							トゥーンレンダリングシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.26
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_TOONSHADERSKINNED__H__

#define		__GLSHADERBIND_TOONSHADERSKINNED__H__

//INCLUDE
#include	"GLShaderBind_EdgeBaseOutputSkinned.h"

namespace Mof {

	/*******************************//*!
	@brief	トゥーンレンダリングシェーダーバインド。

			トゥーンレンダリングシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ToonShaderSkinned : public CShaderBind_EdgeBaseOutputSkinned {
	public:
	protected:
		/*******************//*!
		テクスチャ
		*//********************/
		GLuint	m_ToonMapLocation;
		/*******************//*!
		テクスチャ
		*//********************/
		LPTexture	m_pToonMap;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonShaderSkinned();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonShaderSkinned(const CGLShaderBind_ToonShaderSkinned& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_ToonShaderSkinned();
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		/*************************************************************************//*!
				@brief			バインドの実行
				@param[in]		pGeom		ジオメトリ

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Bind(LPGeometry pGeom = NULL);
	
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
		MOF_LIBRARYCLASS(CGLShaderBind_ToonShaderSkinned,MOF_GLSHADERBINDTOONSHADERSKINNEDCLASS_ID);
	};
	
	#include	"GLShaderBind_ToonShaderSkinned.inl"

	//置き換え
	typedef CGLShaderBind_ToonShaderSkinned		CShaderBind_ToonShaderSkinned;
	typedef CShaderBind_ToonShaderSkinned*		LPShaderBind_ToonShaderSkinned;
}

#endif

//[EOF]
