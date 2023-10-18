/*************************************************************************//*!
					
					@file	GLShaderBind_DownScale.h
					@brief	縮小シェーダーバインド。<br>
							縮小シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.11.05
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_DOWNSCALE__H__

#define		__GLSHADERBIND_DOWNSCALE__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	縮小シェーダーバインド。
	
			縮小シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_DownScale : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_PIXELOFFSET = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	テクスチャサイズ情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstPixelOffsetParam
		{
			Vector2 PixelOffset;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstPixelOffsetParam							m_PixelOffsetParam;
	protected:
		/*******************//*!
		スプライト情報入力コンスタントバッファ
		*//********************/
		GLuint											m_PixelOffsetLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_DownScale();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_DownScale(const CGLShaderBind_DownScale& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_DownScale,MOF_GLSHADERBINDDOWNSCALECLASS_ID);
	};

	#include	"GLShaderBind_DownScale.inl"
	
	//置き換え
	typedef CGLShaderBind_DownScale		CShaderBind_DownScale;
	typedef CShaderBind_DownScale*			LPShaderBind_DownScale;
}

#endif

//[EOF]
