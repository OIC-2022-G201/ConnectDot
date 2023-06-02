/*************************************************************************//*!
					
					@file	DX11Shader.cpp
					@brief	DirectX11シェーダークラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADER__H__

#define		__DX11SHADER__H__

//INCLUDE
#include	"../ShaderBase.h"
#include	"DX11ShaderTechnique.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11シェーダークラス

			DirectX11でのシェーダー読み込み、設定を行うクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Shader : public CShaderBase {
	protected:
		/*******************//*!
		シェーダー
		*//********************/
		ID3DX11Effect*		    m_pShader;
		/*******************//*!
		シェーダー
		*//********************/
		D3DX11_EFFECT_DESC		m_Desc;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Shader();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11Shader(const CDX11Shader& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Shader();
		
		/*************************************************************************//*!
				@brief			シェーダーの読み込み<br>
								Microsoft提供のEffects11ライブラリを使用。<br>
								テクニックの指定に対応。
				@param[in]		pName		ファイル名
				@param[in]		Flags		読み込みフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,MofU32 Flags = D3DCOMPILE_ENABLE_STRICTNESS);
		/*************************************************************************//*!
				@brief			シェーダーの読み込み<br>
								Microsoft提供のEffects11ライブラリを使用。<br>
								テクニックの指定に対応。
				@param[in]		pS			シェーダー
				@param[in]		SSize		シェーダーサイズ
				@param[in]		Flags		読み込みフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPMofVoid pS,MofU32 SSize,MofU32 Flags = D3DCOMPILE_ENABLE_STRICTNESS);
		/*************************************************************************//*!
				@brief			シェーダーの読み込み<br>
								頂点シェーダー、ピクセルシェーダー個別読み込み
				@param[in]		pVName		頂点シェーダーファイル名
				@param[in]		pPName		ピクセルシェーダーファイル名
				@param[in]		Flags		読み込みフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pVName,LPCMofChar pPName,MofU32 Flags = D3DCOMPILE_ENABLE_STRICTNESS);
		/*************************************************************************//*!
				@brief			シェーダーの読み込み<br>
								頂点シェーダー、ピクセルシェーダーを渡すことで生成
				@param[in]		pVS			頂点シェーダー
				@param[in]		VSSize		頂点シェーダーサイズ
				@param[in]		pPS			ピクセルシェーダー
				@param[in]		PSSize		ピクセルシェーダーサイズ
				@param[in]		Flags		読み込みフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPMofVoid pVS,MofU32 VSSize,LPMofVoid pPS,MofU32 PSSize,MofU32 Flags = D3DCOMPILE_ENABLE_STRICTNESS);
		
		/*************************************************************************//*!
				@brief			コンパイル済みシェーダーの生成<br>
								Microsoft提供のEffects11ライブラリを使用。<br>
								テクニックの指定に対応。
				@param[in]		pName		ファイル名
				@param[in]		Flags		読み込みフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPCMofChar pName,MofU32 Flags = 0);
		/*************************************************************************//*!
				@brief			コンパイル済みシェーダーの生成<br>
								Microsoft提供のEffects11ライブラリを使用。<br>
								テクニックの指定に対応。
				@param[in]		pS			シェーダー
				@param[in]		SSize		シェーダーサイズ
				@param[in]		Flags		読み込みフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPMofVoid pS, MofU32 SSize, MofU32 Flags = 0);
		/*************************************************************************//*!
				@brief			シェーダーの生成<br>
								Microsoft提供のEffects11ライブラリを使用。<br>
								テクニックの指定に対応。
				@param[in]		pVName		頂点シェーダーファイル名
				@param[in]		pPName		ピクセルシェーダーファイル名
				@param[in]		Flags		読み込みフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPCMofChar pVName, LPCMofChar pPName, MofU32 Flags = 0);
		/*************************************************************************//*!
				@brief			シェーダーの生成<br>
								Microsoft提供のEffects11ライブラリを使用。<br>
								テクニックの指定に対応。
				@param[in]		pVS			頂点シェーダー
				@param[in]		VSSize		頂点シェーダーサイズ
				@param[in]		pPS			ピクセルシェーダー
				@param[in]		PSSize		ピクセルシェーダーサイズ
				@param[in]		Flags		読み込みフラグ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPMofVoid pVS, MofU32 VSSize, LPMofVoid pPS, MofU32 PSSize, MofU32 Flags = 0);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			シェーダーの取得
				@param			None

				@return			シェーダー
		*//**************************************************************************/
		virtual MofShaderEffect GetShader(void);
		/*************************************************************************//*!
				@brief			シェーダーの取得
				@param			None

				@return			シェーダー
		*//**************************************************************************/
		virtual MofVertexShader GetVertexShader(void);
		/*************************************************************************//*!
				@brief			シェーダーの取得
				@param			None

				@return			シェーダー
		*//**************************************************************************/
		virtual MofPixelShader GetPixelShader(void);
		/*************************************************************************//*!
				@brief			設定バッファの数取得
				@param			None

				@return			設定バッファ
		*//**************************************************************************/
		virtual MofU32 GetBufferCount(void) const;
		/*************************************************************************//*!
				@brief			設定バッファの数取得
				@param			None

				@return			設定バッファ
		*//**************************************************************************/
		virtual MofU32 GetGlobalVariableCount(void) const;
		/*************************************************************************//*!
				@brief			設定バッファの数取得
				@param			None

				@return			設定バッファ
		*//**************************************************************************/
		virtual MofU32 GetInterfaceCount(void) const;

		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11Shader,MOF_DX11SHADERCLASS_ID);
	};

	#include	"DX11Shader.inl"
	
	//置き換え
	typedef CDX11Shader		CShader;
}

#endif

//[EOF]