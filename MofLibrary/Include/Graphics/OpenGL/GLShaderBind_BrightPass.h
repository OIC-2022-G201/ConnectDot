/*************************************************************************//*!
					
					@file	GLShaderBind_BrightPass.h
					@brief	高輝度抽出シェーダーバインド。<br>
							高輝度抽出シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.11.05
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_BRIGHTPASS__H__

#define		__GLSHADERBIND_BRIGHTPASS__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	高輝度抽出シェーダーバインド。
	
			高輝度抽出シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_BrightPass : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_THRESHOLD = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	閾値情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstThresholdParam
		{
			MofFloat Threshold;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstThresholdParam							m_ThresholdParam;
	protected:
		/*******************//*!
		スプライト情報入力コンスタントバッファ
		*//********************/
		GLuint										m_ThresholdLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_BrightPass();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_BrightPass(const CGLShaderBind_BrightPass& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_BrightPass,MOF_GLSHADERBINDBRIGHTPASSCLASS_ID);
	};

	#include	"GLShaderBind_BrightPass.inl"
	
	//置き換え
	typedef CGLShaderBind_BrightPass		CShaderBind_BrightPass;
	typedef CShaderBind_BrightPass*			LPShaderBind_BrightPass;
}

#endif

//[EOF]
