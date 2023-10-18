/*************************************************************************//*!
					
					@file	GLShaderBind_ToonEdge.h
					@brief	トゥーン輪郭描画シェーダーバインド。<br>
							トゥーン輪郭描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.05.22
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_TOONEDGE__H__

#define		__GLSHADERBIND_TOONEDGE__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	トゥーン輪郭描画シェーダーバインド。

			トゥーン輪郭描画シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_ToonEdge : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_TOONEDGE = CShaderBind_SpriteBase::PARAM_MAX,
			PARAM_PIXELOFFSET,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	トゥーン輪郭情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstToonEdgeParam
		{
			Vector4  EdgeColor;
			MofFloat ThresholdD;
			MofFloat ThresholdN;
			MofFloat Atten;
			MofFloat Far;
		};
		/*******************//*!
		トゥーン輪郭情報設定
		*//********************/
		ConstToonEdgeParam							m_ToonEdgeParam;
		/*******************************//*!
		@brief	トゥーン輪郭情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstPixelOffsetParam
		{
			Vector2  PixelOffset;
		};
		/*******************//*!
		トゥーン輪郭情報設定
		*//********************/
		ConstPixelOffsetParam						m_PixelOffsetParam;
	protected:
		/*******************//*!
		トゥーン輪郭色ロケーション
		*//********************/
		GLuint									m_EdgeColorLocation;
		/*******************//*!
		トゥーン輪郭不透明度ロケーション
		*//********************/
		GLuint									m_EdgeAlphaLocation;
		/*******************//*!
		深度閾値ロケーション
		*//********************/
		GLuint									m_ThresholdDLocation;
		/*******************//*!
		法線閾値ロケーション
		*//********************/
		GLuint									m_ThresholdNLocation;
		/*******************//*!
		減衰地ロケーション
		*//********************/
		GLuint									m_AttenLocation;
		/*******************//*!
		最遠値ロケーション
		*//********************/
		GLuint									m_FarLocation;
		/*******************//*!
		オフセットロケーション
		*//********************/
		GLuint									m_PixelOffsetLocation;
		/*******************//*!
		深度法線テクスチャ
		*//********************/
		GLuint									m_DepthNormalTexLocation;
		/*******************//*!
		マスクテクスチャ
		*//********************/
		GLuint									m_MaskTexLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonEdge();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_ToonEdge(const CGLShaderBind_ToonEdge& pObj);
		
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
		MOF_LIBRARYCLASS(CGLShaderBind_ToonEdge,MOF_GLSHADERBINDTOONEDGECLASS_ID);
	};

	#include	"GLShaderBind_ToonEdge.inl"
	
	//置き換え
	typedef CGLShaderBind_ToonEdge		CShaderBind_ToonEdge;
	typedef CShaderBind_ToonEdge*			LPShaderBind_ToonEdge;
}

#endif

//[EOF]
