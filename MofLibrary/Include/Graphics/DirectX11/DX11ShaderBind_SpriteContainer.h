/*************************************************************************//*!
					
					@file	DX11ShaderBind_SpriteContainer.h
					@brief	基本スプライトシェーダーバインド。<br>
							標準的なスプライト描画シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_SPRITECONTAINER__H__

#define		__DX11SHADERBIND_SPRITECONTAINER__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	シェーダーバインド基底インターフェイス

			シェーダーのためのバッファの設定を行うインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_SpriteContainer : public CDX11ShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_VERTEX = CDX11ShaderBind_SpriteBase::ConstParam::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	スプライト描画スプライト情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstVertexParam
		{
			Vector2		cbvPosition1;
			Vector2		cbvPosition2;
			Vector2		cbvPosition3;
			Vector2		cbvPosition4;

			Vector4		cbvColor1;
			Vector4		cbvColor2;
			Vector4		cbvColor3;
			Vector4		cbvColor4;
			Vector4		cbvColorRate;
		};
		/*******************//*!
		プリミティブ描画プリミティブ情報設定
		*//********************/
		ConstVertexParam						m_VertexParam;
	protected:
		/*******************//*!
		シーン情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstVertex;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SpriteContainer();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SpriteContainer(const CDX11ShaderBind_SpriteContainer& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_SpriteContainer();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_SpriteContainer,MOF_DX11SHADERBINDSPRITEBASECLASS_ID);
	};

	#include	"DX11ShaderBind_SpriteContainer.inl"
	
	//置き換え
	typedef CDX11ShaderBind_SpriteContainer			CShaderBind_SpriteContainer;
	typedef CShaderBind_SpriteContainer*			LPShaderBind_SpriteContainer;
}

#endif

//[EOF]