/*************************************************************************//*!
					
					@file	ShaderEffect_DepthOfField.h
					@brief	被写界深度シェーダークラス。

															@author	CDW
															@date	2015.04.29
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_DEPTHOFFIELD__H__

#define		__SHADEREFFECT_DEPTHOFFIELD__H__

//INCLUDE
#include	"ShaderEffect_GaussianBlur.h"

namespace Mof {
	
	/*******************************//*!
	@brief	被写界深度シェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_DepthOfField : public CShaderEffect_2DBase {
	protected:
		/*******************//*!
		ぼかしのサンプリング間隔
		*//********************/
		MofFloat m_BlurStep;
		/*******************//*!
		横方向ぼかし描画先テクスチャ
		*//********************/
		LPTexture m_pXBlurTex;
		/*******************//*!
		縦方向ぼかし描画先テクスチャ
		*//********************/
		LPTexture m_pYBlurTex;
		/*******************//*!
		ガウスぼかしシェーダー
		*//********************/
		LPShaderEffect_GaussianBlur m_pGBlur;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_DepthOfField();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_DepthOfField();
		
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();
		
		/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTarget		描画ターゲットのテクスチャ
		@param[in]		pTex		テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex);
		/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTarget		描画ターゲットのテクスチャ
		@param[in]		pTex		テクスチャ
		@param[in]		pDepthTex	深度テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex,LPTexture pDepthTex);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
		@brief			被写界深度のパラメータ設定
		@param[in]		FocalDistance		焦点距離
		@param[in]		FocalRange			ぼけない範囲
		@param[in]		FocalAttenuation	ぼけ始めてから最大までぼけるまでの距離
		@param[in]		Far			最遠面
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDoFParam(MofFloat FocalDistance,MofFloat FocalRange,MofFloat FocalAttenuation,MofFloat BlurStep,MofFloat Far);
		/*************************************************************************//*!
		@brief			深度テクスチャの設定
		@param[in]		pTex		深度テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDepthTexture(LPTexture pTex);

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_DepthOfField,MOF_SHADEREFFECTDEPTHOFFIELDCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_DepthOfField*			LPShaderEffect_DepthOfField;

#include	"ShaderEffect_DepthOfField.inl"

}

#endif

//[EOF]