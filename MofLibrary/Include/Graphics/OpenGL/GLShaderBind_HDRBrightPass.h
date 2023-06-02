/*************************************************************************//*!
					
					@file	GLShaderBind_HDRBrightPass.h
					@brief	HDR用高輝度抽出シェーダーバインド。<br>
							HDR用高輝度抽出シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.11.06
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_HDRBRIGHTPASS__H__

#define		__GLSHADERBIND_HDRBRIGHTPASS__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	HDR用高輝度抽出シェーダーバインド。
	
			HDR用高輝度抽出シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_HDRBrightPass : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_HDRBRIGHTPASS = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	閾値情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstHDRBrightPassParam
		{
			MofFloat Threshold;
			MofFloat MiddleGray;
			MofFloat BrightPassOffset;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstHDRBrightPassParam					m_HDRBrightPassParam;
	protected:
		/*******************//*!
		閾値ロケーション
		*//********************/
		GLuint									m_ThresholdLocation;
		/*******************//*!
		基準輝度ロケーション
		*//********************/
		GLuint									m_MiddleGrayLocation;
		/*******************//*!
		オフセットロケーション
		*//********************/
		GLuint									m_BrightPassOffsetLocation;
		/*******************//*!
		輝度テクスチャ
		*//********************/
		GLuint									m_AdaptedLumTexLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_HDRBrightPass();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_HDRBrightPass(const CGLShaderBind_HDRBrightPass& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_HDRBrightPass,MOF_GLSHADERBINDHDRBRIGHTPASSCLASS_ID);
	};

	#include	"GLShaderBind_HDRBrightPass.inl"
	
	//置き換え
	typedef CGLShaderBind_HDRBrightPass		CShaderBind_HDRBrightPass;
	typedef CShaderBind_HDRBrightPass*			LPShaderBind_HDRBrightPass;
}

#endif

//[EOF]
