/*************************************************************************//*!
					
					@file	ShaderLinker.h
					@brief	シェーダー基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERLINKER__H__

#define		__SHADERLINKER__H__

//INCLUDE
#include	"Shader.h"
#include	"ShaderBindBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	シェーダーインターフェイス

			シェーダーの読み込み、設定を行うためのインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IShaderLinker : public IMofNamedObject {
	public:
		/*******************************//*!
		@brief	リンク型

				型情報。

		@author	濱田　享
		*//********************************/
		struct LinkType {
			enum Enum {
				BOOL,
				INT,
				UINT,
				FLOAT,

				FVECTOR2,
				FVECTOR3,
				FVECTOR4,

				IVECTOR2,
				IVECTOR3,
				IVECTOR4,

				MATRIX42,
				MATRIX43,
				MATRIX44,
			};
		};
		/*******************************//*!
		@brief	リンク型

				型情報。

		@author	濱田　享
		*//********************************/
		typedef struct tag_LINKDATA {
			/*******************//*!
			名前
			*//********************/
			CString					Name;
			/*******************//*!
			タイプ
			*//********************/
			LinkType::Enum			Type;
			/*******************//*!
			バッファ
			*//********************/
			LPShaderBuffer			pBuffer;
			/*******************//*!
			オフセット
			*//********************/
			MofU32					Offset;
			/*******************//*!
			サイズ
			*//********************/
			MofU32					Size;
			/*******************//*!
			実データ
			*//********************/
			union {
				bool				b;
				MofS32				i;
				MofU32				ui;
				MofFloat			f;
				MofS32				iv[4];
				MofFloat			fv[4];
				MofS32				im[4][4];
				MofFloat			m[4][4];
			};
		}LINKDATA,*LPLINKDATA;
		typedef CDynamicArray< LPLINKDATA > LinkArray,*LPLinkArray;
		
		/*******************************//*!
		@brief	リンク型

				型情報。

		@author	濱田　享
		*//********************************/
		typedef struct tag_LINKTEXTURE {
			/*******************//*!
			名前
			*//********************/
			CString					Name;
			/*******************//*!
			番号
			*//********************/
			MofU32					No;
			/*******************//*!
			バッファ
			*//********************/
			LPShaderResource		pBuffer;
		}LINKTEXTURE,*LPLINKTEXTURE;
		typedef CDynamicArray< LPLINKTEXTURE > LinkTextureArray,*LPLinkTextureArray;
	protected:
	public:
		/*************************************************************************//*!
				@brief			生成
				@param[in]		pShader			生成するシェーダー

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader) = 0;
		/*************************************************************************//*!
				@brief			生成
				@param[in]		pShader			生成するシェーダー
				@param[in]		pShaderBind		生成するシェーダー

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader,LPShaderBind pBind) = 0;

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			変数とのリンクの取得
				@param			None

				@return			変数とのリンク
		*//**************************************************************************/
		virtual LPLinkArray GetLink(void) = 0;
		/*************************************************************************//*!
				@brief			テクスチャとのリンクの取得
				@param			None

				@return			テクスチャとのリンク
		*//**************************************************************************/
		virtual LPLinkTextureArray GetTextureLink(void) = 0;
		/*************************************************************************//*!
				@brief			シェーダーの取得
				@param			None

				@return			シェーダー
		*//**************************************************************************/
		virtual LPShader GetShader(void) = 0;
		/*************************************************************************//*!
				@brief			シェーダーバインドの取得
				@param			None

				@return			シェーダーバインド
		*//**************************************************************************/
		virtual LPShaderBind GetShaderBind(void) = 0;
	};

	//ポインタ置き換え
	typedef IShaderLinker*			LPShaderLinker;
}

#endif

//[EOF]