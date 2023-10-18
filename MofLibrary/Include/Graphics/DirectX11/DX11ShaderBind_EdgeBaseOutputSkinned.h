/*************************************************************************//*!
					
					@file	DX11ShaderBind_EdgeBaseOutputSkinned.h
					@brief	エッジ抽出シェーダー準備シェーダーバインド。<br>
							エッジ抽出シェーダー準備シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2015.06.01
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_EDGEBASEOUTPUTSKINNED__H__

#define		__DX11SHADERBIND_EDGEBASEOUTPUTSKINNED__H__

//INCLUDE
#include	"DX11ShaderBind_DepthOutputSkinned.h"

namespace Mof {

	/*******************************//*!
	@brief	エッジ抽出シェーダー準備シェーダーバインド。

			エッジ抽出シェーダー準備シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_EdgeBaseOutputSkinned : public CShaderBind_DepthOutputSkinned {
	public:
		/*******************************//*!
		@brief	入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_MASK = CShaderBind_DepthOutputSkinned::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	マスク情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstMaskParam
		{
			MofFloat Mask;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstMaskParam							m_MaskParam;
	protected:
		/*******************//*!
		スプライト情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstMask;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_EdgeBaseOutputSkinned();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_EdgeBaseOutputSkinned(const CDX11ShaderBind_EdgeBaseOutputSkinned& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_EdgeBaseOutputSkinned();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_EdgeBaseOutputSkinned,MOF_DX11SHADERBINDEDGEBASEOUTPUTSKINNEDCLASS_ID);
	};

	#include	"DX11ShaderBind_EdgeBaseOutputSkinned.inl"
	
	//置き換え
	typedef CDX11ShaderBind_EdgeBaseOutputSkinned		CShaderBind_EdgeBaseOutputSkinned;
	typedef CShaderBind_EdgeBaseOutputSkinned*			LPShaderBind_EdgeBaseOutputSkinned;
}

#endif

//[EOF]