/*************************************************************************//*!
					
					@file	DX11ShaderBind_GaussianBlur.h
					@brief	ガウスぼかしシェーダーバインド。<br>
							ガウスぼかしシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_GAUSSIANBLUR__H__

#define		__DX11SHADERBIND_GAUSSIANBLUR__H__

//INCLUDE
#include	"../ShaderBind_GaussianBlurBase.h"

namespace Mof {

	/*******************************//*!
	@brief	シェーダーバインド基底インターフェイス

			シェーダーのためのバッファの設定を行うインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_GaussianBlur : public CShaderBind_GaussianBlurBase {
	public:
	protected:
		/*******************//*!
		シーン情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstScene;
		/*******************//*!
		スプライト情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstMesh;
		/*******************//*!
		ガウスぼかし情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstBlur;
		/*******************//*!
		サンプラー
		*//********************/
		ID3DX11EffectSamplerVariable*			m_pSampler;
		/*******************//*!
		テクスチャ
		*//********************/
		ID3DX11EffectShaderResourceVariable*	m_pTexture;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_GaussianBlur();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_GaussianBlur(const CDX11ShaderBind_GaussianBlur& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_GaussianBlur();
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pvb			頂点バッファ配列
				@param[in]		Cnt			頂点バッファ配列数
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateVertexLayout(LPVertexBuffer* pvb, MofU32 Cnt = 0);
		
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
				@brief			サンプラの設定<br>
								DirectX11で実行時のみ有効<br>
								DirectX9の場合はシェーダーでの指定が、OpenGL系の場合はテクスチャでの指定が有効になる。
				@param[in]		n			番号
				@param[in]		pSamp		サンプラ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetSamplerState(MofU32 n,MofSamplerState pSamp);
		/*************************************************************************//*!
				@brief			テクスチャの設定
				@param[in]		n			番号
				@param[in]		pTex		テクスチャ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);

		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11ShaderBind_GaussianBlur, MOF_DX11SHADERBINDGAUSSIANBLURCLASS_ID);
	};

	#include	"DX11ShaderBind_GaussianBlur.inl"
	
	//置き換え
	typedef CDX11ShaderBind_GaussianBlur		CShaderBind_GaussianBlur;
	typedef CShaderBind_GaussianBlur*			LPShaderBind_GaussianBlur;
}

#endif

//[EOF]