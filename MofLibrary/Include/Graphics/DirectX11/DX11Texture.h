/*************************************************************************//*!
					
					@file	DX11Texture.h
					@brief	DirectX11テクスチャ基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11TEXTURE__H__

#define		__DX11TEXTURE__H__

//INCLUDE
#include	"../TextureBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11テクスチャクラス

			DirectX11でのテクスチャ読み込み、描画を行うクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11Texture : public CTextureBase {
	protected:
		/*******************//*!
		テクスチャ
		*//********************/
		ID3D11Texture2D*			m_pTexture;
		/*******************//*!
		シェーダーリソース
		*//********************/
		ID3D11ShaderResourceView*	m_pShaderResourceView;
		/*******************//*!
		描画ターゲット
		*//********************/
		LPRenderTarget				m_pRenderTarget;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11Texture();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーテクスチャ

				@return			None
		*//**************************************************************************/
		CDX11Texture(const CDX11Texture& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11Texture();

		/*************************************************************************//*!
				@brief			テクスチャの読み込み
				@param[in]		pName		ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			メモリからのテクスチャの読み込み
				@param[in]		pName		名前
				@param[in]		pData		メモリアドレス
				@param[in]		Size		サイズ
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size);
		
		/*************************************************************************//*!
				@brief			テクスチャの保存
				@param[in]		pName		ファイル名
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Save(LPCMofChar pName);

		/*************************************************************************//*!
				@brief			テクスチャの生成
				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Format		フォーマット
				@param[in]		Usage		管理方法
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(const MofU32 w, const MofU32 h, const PixelFormat Format, const BufferAccess Usage);
		/*************************************************************************//*!
				@brief			描画ターゲット用テクスチャの生成<br>
								D3D11_TEXTURE2D_DESC構造体のBindFlagsにD3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE<br>
								CPUAccessFlagsに0を設定してテクスチャを生成する。<br>
								テクスチャ生成後、描画ターゲットの生成も実行される。

				@param[in]		w			幅
				@param[in]		h			高さ
				@param[in]		Format		フォーマット
				@param[in]		Usage		管理方法
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool CreateTarget(const MofU32 w, const MofU32 h, const PixelFormat Format, const BufferAccess Usage);
		
		/*************************************************************************//*!
				@brief			テクスチャのコピー生成
				@param			None
				
				@return			作成されたコピーテクスチャ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual ITexture* CreateCopyObject(void) const;
		
		/*************************************************************************//*!
				@brief			バッファのマップ
				@param[in]		mt				マップタイプ
				@param[out]		pRowPitch		横のバイト数
				
				@return			マップされたメモリアドレスを返す。<br>
								失敗の場合NULLになる。
		*//**************************************************************************/
		virtual LPMofVoid Map(MofU32 mt, LPMofU32 pRowPitch = NULL);
		/*************************************************************************//*!
				@brief			バッファのアンマップ
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool UnMap(void);

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
				@brief			テクスチャ取得<br>
								m_pShaderResourceViewを取得する。<br>
								描画ターゲットとして使用しているテクスチャの場合、<br>
								この関数の実行でCreateShaderResourceViewを実行しm_pShaderResourceViewを生成する。
				@param			None

				@return			テクスチャ
		*//**************************************************************************/
		virtual MofTexture GetTexture(void);
		/*************************************************************************//*!
				@brief			テクスチャ取得<br>
								m_pTextureを取得する。
				@param			None

				@return			テクスチャ
		*//**************************************************************************/
		virtual MofTextureHandle GetTextureHandle(void);
		/*************************************************************************//*!
				@brief			テクスチャへ描画するための描画ターゲットを取得<br>
								CreateTargetで生成されたテクスチャにのみ有効。<br>
								m_pShaderResourceViewが生成されている場合、この関数の実行でm_pShaderResourceViewは解放される。
				@param			None
				
				@return			描画ターゲットを返す。
								失敗の場合NULLになる。
		*//**************************************************************************/
		virtual LPRenderTarget GetRenderTarget(void);

		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11Texture,MOF_DX11TEXTURECLASS_ID);
	};

	#include	"DX11Texture.inl"
	
	//置き換え
	typedef CDX11Texture		CTexture;

}

#endif

//[EOF]