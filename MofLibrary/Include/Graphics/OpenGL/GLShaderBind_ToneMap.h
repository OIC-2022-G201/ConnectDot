/*************************************************************************//*!
					
					@file	GLShaderBind_ToneMap.h
					@brief	トーンマップシェーダーバインド。<br>
							トーンマップシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.11.06
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_TONEMAP__H__

#define		__GLSHADERBIND_TONEMAP__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	トーンマップシェーダーバインド。
	
			トーンマップシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ToneMap : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_TONEMAP = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	トーンマップ情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstToneMapParam
		{
			MofFloat MiddleGray;
			MofFloat BloomScale;
		};
		/*******************//*!
		トーンマップ情報設定
		*//********************/
		ConstToneMapParam				m_ToneMapParam;
	protected:
		/*******************//*!
		基準輝度ロケーション
		*//********************/
		GLuint							m_MiddleGrayLocation;
		/*******************//*!
		ブルームの明るさロケーション
		*//********************/
		GLuint							m_BloomScaleLocation;
		/*******************//*!
		輝度テクスチャロケーション
		*//********************/
		GLuint							m_AdaptedLumTexLocation;
		/*******************//*!
		ブルームテクスチャロケーション
		*//********************/
		GLuint							m_BloomTexLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToneMap();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToneMap(const CGLShaderBind_ToneMap& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_ToneMap,MOF_GLSHADERBINDTONEMAPCLASS_ID);
	};

	#include	"GLShaderBind_ToneMap.inl"
	
	//置き換え
	typedef CGLShaderBind_ToneMap		CShaderBind_ToneMap;
	typedef CShaderBind_ToneMap*			LPShaderBind_ToneMap;
}

#endif

//[EOF]
