/*************************************************************************//*!
					
					@file	GLShaderBind_DepthOfField.h
					@brief	被写界深度シェーダーバインド。<br>
							被写界深度シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.10.30
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_DEPTHOFFIELD__H__

#define		__GLSHADERBIND_DEPTHOFFIELD__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	遅延ライティングシェーダーバインド。

			遅延ライティングシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_DepthOfField : public CGLShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_DEPTHOFFIELD = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	プリミティブ描画ライト情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstDoFParam
		{
			MofFloat	FocalDistance;
			MofFloat	FocalRange;
			MofFloat	FocalAttenuation;
			MofFloat	Far;
		};
		/*******************//*!
		プリミティブ描画ライト情報設定
		*//********************/
		ConstDoFParam						m_DoFParam;
	protected:
		/*******************//*!
		焦点距離ロケーション
		*//********************/
		GLuint								m_FocalDistanceLocation;
		/*******************//*!
		焦点幅ロケーション
		*//********************/
		GLuint								m_FocalRangeLocation;
		/*******************//*!
		変化距離ロケーション
		*//********************/
		GLuint								m_FocalAttenuationLocation;
		/*******************//*!
		最遠値ロケーション
		*//********************/
		GLuint								m_FarLocation;
		/*******************//*!
		ぼかしテクスチャ
		*//********************/
		GLuint								m_BlurTex;
		/*******************//*!
		深度テクスチャ
		*//********************/
		GLuint								m_DepthTex;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_DepthOfField();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_DepthOfField(const CGLShaderBind_DepthOfField& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_DepthOfField,MOF_GLSHADERBINDDEPTHOFFIELDCLASS_ID);
	};

	#include	"GLShaderBind_DepthOfField.inl"
	
	//置き換え
	typedef CGLShaderBind_DepthOfField		CShaderBind_DepthOfField;
	typedef CShaderBind_DepthOfField*			LPShaderBind_DepthOfField;
}

#endif

//[EOF]
