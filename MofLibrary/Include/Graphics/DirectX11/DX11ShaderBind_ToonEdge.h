/*************************************************************************//*!
					
					@file	DX11ShaderBind_ToonEdge.h
					@brief	トゥーン輪郭描画シェーダーバインド。<br>
							トゥーン輪郭描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.05.22
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_TOONEDGE__H__

#define		__DX11SHADERBIND_TOONEDGE__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	トゥーン輪郭描画シェーダーバインド。

			トゥーン輪郭描画シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_ToonEdge : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_TOONEDGE = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	トゥーン輪郭情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstToonEdgeParam
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
	protected:
		/*******************//*!
		トゥーン輪郭情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstToonEdge;
		/*******************//*!
		深度法線テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pDepthNormalTex;
		/*******************//*!
		マスクテクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pMaskTex;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToonEdge();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_ToonEdge(const CDX11ShaderBind_ToonEdge& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_ToonEdge();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_ToonEdge,MOF_DX11SHADERBINDTOONEDGECLASS_ID);
	};

	#include	"DX11ShaderBind_ToonEdge.inl"
	
	//置き換え
	typedef CDX11ShaderBind_ToonEdge		CShaderBind_ToonEdge;
	typedef CShaderBind_ToonEdge*			LPShaderBind_ToonEdge;
}

#endif

//[EOF]