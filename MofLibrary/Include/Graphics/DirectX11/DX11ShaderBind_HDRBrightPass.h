/*************************************************************************//*!
					
					@file	DX11ShaderBind_HDRBrightPass.h
					@brief	HDR用高輝度抽出シェーダーバインド。<br>
							HDR用高輝度抽出シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.05.18
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_HDRBRIGHTPASS__H__

#define		__DX11SHADERBIND_HDRBRIGHTPASS__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	HDR用高輝度抽出シェーダーバインド。
	
			HDR用高輝度抽出シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_HDRBrightPass : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_HDRBRIGHTPASS = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,

			PARAM_HDRTHRESHOLD,
		};
		/*******************************//*!
		@brief	閾値情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstHDRBrightPassParam
		{
			MofFloat Threshold;
			MofFloat MiddleGray;
			MofFloat BrightPassOffset;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstHDRBrightPassParam							m_HDRBrightPassParam;
	protected:
		/*******************//*!
		スプライト情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstHDRBrightPass;
		/*******************//*!
		輝度テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pAdaptedLumTex;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_HDRBrightPass();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_HDRBrightPass(const CDX11ShaderBind_HDRBrightPass& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_HDRBrightPass();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_HDRBrightPass,MOF_DX11SHADERBINDHDRBRIGHTPASSCLASS_ID);
	};

	#include	"DX11ShaderBind_HDRBrightPass.inl"
	
	//置き換え
	typedef CDX11ShaderBind_HDRBrightPass		CShaderBind_HDRBrightPass;
	typedef CShaderBind_HDRBrightPass*			LPShaderBind_HDRBrightPass;
}

#endif

//[EOF]