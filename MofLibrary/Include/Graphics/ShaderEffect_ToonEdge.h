/*************************************************************************//*!
					
					@file	ShaderEffect_ToonEdge.h
					@brief	エッジシェーダークラス。

															@author	CDW
															@date	2015.05.22
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_TOONEDGE__H__

#define		__SHADEREFFECT_TOONEDGE__H__

//INCLUDE
#include	"ShaderEffect_2DBase.h"
#include	"ShaderEffect_EdgeBaseOutput.h"

namespace Mof {
	
	/*******************************//*!
	@brief	エッジシェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_ToonEdge : public CShaderEffect_2DBase {
	protected:
	public:
		
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
		@param[in]		pEffect		エッジ描画準備シェーダー
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex,LPShaderEffect_EdgeBaseOutput pEffect);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
		@brief			深度法線テクスチャの設定
		@param[in]		pTex		深度法線テクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDepthNormalTexture(LPTexture pTex);
		/*************************************************************************//*!
		@brief			マスクテクスチャの設定
		@param[in]		pTex		マスクテクスチャ
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetMaskTexture(LPTexture pTex);
		/*************************************************************************//*!
		@brief			エッジシェーダーの設定
		@param[in]		EdgeColor	エッジの色
		@param[in]		ThresholdD	深度エッジのしきい値
		@param[in]		ThresholdN	法線エッジのしきい値
		@param[in]		Atten		距離による不透明度の減衰値
		@param[in]		Far			カメラのFar
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetToonEdgeParam(Vector4& EdgeColor,MofFloat ThresholdD,MofFloat ThresholdN,MofFloat Atten,MofFloat Far);

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_ToonEdge,MOF_SHADEREFFECTTOONEDGECLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_ToonEdge*			LPShaderEffect_ToonEdge;

#include	"ShaderEffect_ToonEdge.inl"

}

#endif

//[EOF]