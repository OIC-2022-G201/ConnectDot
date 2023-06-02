/*************************************************************************//*!
					
					@file	DX11ShaderBind_SimpleBlur.h
					@brief	単純ぼかしシェーダーバインド。<br>
							単純ぼかしシェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2014.06.17
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_SIMPLEBLUR__H__

#define		__DX11SHADERBIND_SIMPLEBLUR__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	単純ぼかしシェーダーバインド。

			単純ぼかしシェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_SimpleBlur : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_BLUR = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	ぼかし情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstBlurParam
		{
			Vector2 BlurStep;
			MofS32 BlurKernelBegin;
			MofS32 BlurKernelEnd;
			MofS32 BlurKernelSize;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstBlurParam							m_BlurParam;
	protected:
		/*******************//*!
		スプライト情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstBlur;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SimpleBlur();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_SimpleBlur(const CDX11ShaderBind_SimpleBlur& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_SimpleBlur();
		
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
		MOF_LIBRARYCLASS(CDX11ShaderBind_SimpleBlur,MOF_DX11SHADERBINDSIMPLEBLURCLASS_ID);
	};

	#include	"DX11ShaderBind_SimpleBlur.inl"
	
	//置き換え
	typedef CDX11ShaderBind_SimpleBlur		CShaderBind_SimpleBlur;
	typedef CShaderBind_SimpleBlur*			LPShaderBind_SimpleBlur;
}

#endif

//[EOF]