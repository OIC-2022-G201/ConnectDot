/*************************************************************************//*!
					
					@file	GLShaderBind_Bloom.h
					@brief	ブルームシェーダーバインド。<br>
							ブルームシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.11.09
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_BLOOM__H__

#define		__GLSHADERBIND_BLOOM__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	ブルームシェーダーバインド。
	
			ブルームシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_Bloom : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_BLOOM = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	トーンマップ情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstBloomParam
		{
			MofFloat BloomScale;
		};
		/*******************//*!
		トーンマップ情報設定
		*//********************/
		ConstBloomParam							m_BloomParam;
	protected:
		/*******************//*!
		トーンマップ情報入力コンスタントバッファ
		*//********************/
		GLuint									m_BloomScaleLocation;
		/*******************//*!
		ブルームテクスチャ
		*//********************/
		GLuint									m_BloomTexLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_Bloom();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_Bloom(const CGLShaderBind_Bloom& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_Bloom,MOF_GLSHADERBINDBLOOMCLASS_ID);
	};

	#include	"GLShaderBind_Bloom.inl"
	
	//置き換え
	typedef CGLShaderBind_Bloom		CShaderBind_Bloom;
	typedef CShaderBind_Bloom*			LPShaderBind_Bloom;
}

#endif

//[EOF]
