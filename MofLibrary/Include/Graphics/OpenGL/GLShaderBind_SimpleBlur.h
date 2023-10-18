/*************************************************************************//*!
					
					@file	GLShaderBind_SimpleBlur.h
					@brief	単純ぼかしシェーダーバインド。<br>
							単純ぼかしシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.26
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_SIMPLEBLUR__H__

#define		__GLSHADERBIND_SIMPLEBLUR__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	単純ぼかしシェーダーバインド。

			単純ぼかしシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_SimpleBlur : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_BLUR = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	ぼかし情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstBlurParam
		{
			Vector2 BlurStep;
			MofS32 BlurKernelBegin;
			MofS32 BlurKernelEnd;
			MofS32 BlurKernelSize;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstBlurParam							m_BlurParam;
	protected:
		/*******************//*!
		ぼかしサンプリング間隔ロケーション
		*//********************/
		GLuint									m_BlurStepLocation;
		/*******************//*!
		ぼかし開始ロケーション
		*//********************/
		GLuint									m_BlurKernelBegin;
		/*******************//*!
		ぼかし終了ロケーション
		*//********************/
		GLuint									m_BlurKernelEnd;
		/*******************//*!
		ぼかしサンプリング回数ロケーション
		*//********************/
		GLuint									m_BlurKernelSize;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_SimpleBlur();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_SimpleBlur(const CGLShaderBind_SimpleBlur& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_SimpleBlur,MOF_GLSHADERBINDSIMPLEBLURCLASS_ID);
	};

	#include	"GLShaderBind_SimpleBlur.inl"
	
	//置き換え
	typedef CGLShaderBind_SimpleBlur		CShaderBind_SimpleBlur;
	typedef CShaderBind_SimpleBlur*		LPShaderBind_SimpleBlur;
}

#endif

//[EOF]
