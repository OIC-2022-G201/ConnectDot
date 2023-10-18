/*************************************************************************//*!
					
					@file	GLShaderBind_EdgeBaseOutputSkinned.h
					@brief	エッジ抽出シェーダー準備シェーダーバインド。<br>
							エッジ抽出シェーダー準備シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.06.01
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_EDGEBASEOUTPUTSKINNED__H__

#define		__GLSHADERBIND_EDGEBASEOUTPUTSKINNED__H__

//INCLUDE
#include	"GLShaderBind_DepthOutputSkinned.h"

namespace Mof {

	/*******************************//*!
	@brief	エッジ抽出シェーダー準備シェーダーバインド。

			エッジ抽出シェーダー準備シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_EdgeBaseOutputSkinned : public CShaderBind_DepthOutputSkinned {
	public:
		/*******************************//*!
		@brief	入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_MASK = CShaderBind_SkinGeometryBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	マスク情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		struct ConstMaskParam
		{
			MofFloat Mask;
		};
		/*******************//*!
		マスク情報設定
		*//********************/
		ConstMaskParam							m_MaskParam;
	protected:
		/*******************//*!
		マスク値ロケーション
		*//********************/
		GLuint									m_MaskValueLocation;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_EdgeBaseOutputSkinned();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CGLShaderBind_EdgeBaseOutputSkinned(const CGLShaderBind_EdgeBaseOutputSkinned& pObj);

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
		MOF_LIBRARYCLASS(CGLShaderBind_EdgeBaseOutputSkinned,MOF_GLSHADERBINDEDGEBASEOUTPUTSKINNEDCLASS_ID);
	};

	#include	"GLShaderBind_EdgeBaseOutputSkinned.inl"
	
	//置き換え
	typedef CGLShaderBind_EdgeBaseOutputSkinned		CShaderBind_EdgeBaseOutputSkinned;
	typedef CShaderBind_EdgeBaseOutputSkinned*			LPShaderBind_EdgeBaseOutputSkinned;
}

#endif

//[EOF]
