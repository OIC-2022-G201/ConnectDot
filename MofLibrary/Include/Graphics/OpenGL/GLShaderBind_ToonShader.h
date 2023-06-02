/*************************************************************************//*!
					
					@file	GLShaderBind_ToonShader.h
					@brief	トゥーンレンダリングシェーダーバインド。<br>
							トゥーンレンダリングシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.26
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_TOONSHADER__H__

#define		__GLSHADERBIND_TOONSHADER__H__

//INCLUDE
#include	"GLShaderBind_EdgeBaseOutput.h"

namespace Mof {

	/*******************************//*!
	@brief	トゥーンレンダリングシェーダーバインド。

			トゥーンレンダリングシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ToonShader : public CShaderBind_EdgeBaseOutput {
	public:
	protected:
		/*******************//*!
		テクスチャ
		*//********************/
		GLuint		m_ToonMapLocation;
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
		CGLShaderBind_ToonShader();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonShader(const CGLShaderBind_ToonShader& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGLShaderBind_ToonShader();
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_ToonShader,MOF_GLSHADERBINDTOONSHADERCLASS_ID);
	};
	
	#include	"GLShaderBind_ToonShader.inl"

	//置き換え
	typedef CGLShaderBind_ToonShader		CShaderBind_ToonShader;
	typedef CShaderBind_ToonShader*		LPShaderBind_ToonShader;
}

#endif

//[EOF]
