/*************************************************************************//*!
					
					@file	ShaderEffect_CascadeVarianceRenderer.h
					@brief	シャドウマップによる影描画シェーダークラス。

															@author	CDW
															@date	2015.06.10
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_CASCADEVARIANCERENDERER__H__

#define		__SHADEREFFECT_CASCADEVARIANCERENDERER__H__

//INCLUDE
#include	"ShaderEffect_ShadowTexture.h"

namespace Mof {
	
	/*******************************//*!
	@brief	シャドウマップによる影描画シェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_CascadeVarianceRenderer : public CShaderEffect_3DBase {
	protected:
		/*******************//*!
		影をずらす量
		*//********************/
		MofFloat	m_ShadowEpsilon;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_CascadeVarianceRenderer();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_CascadeVarianceRenderer();
		
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param[in]		Variance	バリアンスシャドウフラグ

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofBool Variance);
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			開始
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Begin();
		/*************************************************************************//*!
				@brief			終了
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool End();

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			シャドウマップのセット
				@param[in]		matShadowView				ライト視点のビュー行列
				@param[in]		matShadowProj				ライト視点の射影行列の配列
				@param[in]		fCascadePartitionsFrustum	視錐台の分割位置
				@param[in]		pShadowMapTextures			シャドウマップテクスチャの配列
				@param[in]		fCascadeBlendArea			カスケード境界のぼかし具合
				@param[in]		fShadowPower				ライトブリーディングを抑えるための値
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetShadowMap(const CMatrix44& matShadowView,const CMatrix44* matShadowProj,const MofFloat *fCascadePartitionsFrustum,const LPTexture* pShadowMapTextures,MofFloat fCascadeBlendArea,MofFloat fShadowPower);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_CascadeVarianceRenderer,MOF_SHADEREFFECTCASCADEVARIANCERENDERERCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_CascadeVarianceRenderer*			LPShaderEffect_CascadeVarianceRenderer;

#include	"ShaderEffect_CascadeVarianceRenderer.inl"

}

#endif

//[EOF]
