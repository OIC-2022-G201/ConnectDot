/*************************************************************************//*!
					
					@file	DX11ShaderBind_ToneMap.h
					@brief	トーンマップシェーダーバインド。<br>
							トーンマップシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.05.15
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_TONEMAP__H__

#define		__DX11SHADERBIND_TONEMAP__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	トーンマップシェーダーバインド。
	
			トーンマップシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_ToneMap : public CShaderBind_SpriteBase {
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
		SHADERPARAM_ALIGNMENT struct ConstToneMapParam
		{
			MofFloat MiddleGray;
			MofFloat BloomScale;
		};
		/*******************//*!
		トーンマップ情報設定
		*//********************/
		ConstToneMapParam							m_ToneMapParam;
	protected:
		/*******************//*!
		トーンマップ情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstToneMap;
		/*******************//*!
		輝度テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pAdaptedLumTex;
		/*******************//*!
		ブルームテクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pBloomTex;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToneMap();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToneMap(const CDX11ShaderBind_ToneMap& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_ToneMap();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_ToneMap,MOF_DX11SHADERBINDTONEMAPCLASS_ID);
	};

	#include	"DX11ShaderBind_ToneMap.inl"
	
	//置き換え
	typedef CDX11ShaderBind_ToneMap		CShaderBind_ToneMap;
	typedef CShaderBind_ToneMap*			LPShaderBind_ToneMap;
}

#endif

//[EOF]