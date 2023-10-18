/*************************************************************************//*!
					
					@file	DX11ShaderBind_DepthOfField.h
					@brief	被写界深度シェーダーバインド。<br>
							被写界深度シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.04.27
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_DEPTHOFFIELD__H__

#define		__DX11SHADERBIND_DEPTHOFFIELD__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	遅延ライティングシェーダーバインド。

			遅延ライティングシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_DepthOfField : public CDX11ShaderBind_SpriteBase {
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
		SHADERPARAM_ALIGNMENT struct ConstDoFParam
		{
			MofFloat	FocalDistance;
			MofFloat	FocalRange;
			MofFloat	FocalAttenuation;
			MofFloat	Far;
		};
		/*******************//*!
		プリミティブ描画ライト情報設定
		*//********************/
		ConstDoFParam							m_DoFParam;
	protected:
		/*******************//*!
		ライト情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstDoF;
		/*******************//*!
		ぼかしテクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pBlurTex;
		/*******************//*!
		深度テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pDepthTex;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_DepthOfField();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_DepthOfField(const CDX11ShaderBind_DepthOfField& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_DepthOfField();
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
	
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_DepthOfField,MOF_DX11SHADERBINDDEPTHOFFIELDCLASS_ID);
	};

	#include	"DX11ShaderBind_DepthOfField.inl"
	
	//置き換え
	typedef CDX11ShaderBind_DepthOfField		CShaderBind_DepthOfField;
	typedef CShaderBind_DepthOfField*			LPShaderBind_DepthOfField;
}

#endif

//[EOF]