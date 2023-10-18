/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowTexture.h
					@brief	シャドウマップ用深度テクスチャ描画シェーダー。

															@author	CDW
															@date	2015.05.13
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_SHADOWTEXTURE__H__

#define		__SHADEREFFECT_SHADOWTEXTURE__H__

//INCLUDE
#include	"ShaderEffect_3DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	シャドウマップ用深度テクスチャ描画シェーダー。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_ShadowTexture : public CShaderEffect_3DBase {
	public:
		/*******************************//*!
		@brief	シャドウマップ形式列挙

		@author	CDW
		*//********************************/
		enum ShadowType{
			SHADOW_NONE,
			SHADOW_NORMAL,
			SHADOW_VARIANCE,
		};
	protected:
		/*******************//*!
		ライト視点のカメラ
		*//********************/
		CCamera m_LightCam;
		/*******************//*!
		シャドウマップ用深度テクスチャ
		*//********************/
		LPTexture m_pShadowMapTex;
		/*******************//*!
		深度テクスチャ描画用深度バッファ
		*//********************/
		LPDepthTarget m_pDepthTarget;

		LPCamera m_pOrigCamera;				//<!退避
		LPRenderTarget m_pOrigRenderTarget;	//<!退避
		LPDepthTarget m_pOrigDepthTarget;	//<!退避
		
		MofFloat m_LightMapRange;	//<!シャドウマップに描画する範囲
		MofFloat m_LightMapNear;	//<!シャドウマップに描画する最少距離
		MofFloat m_LightMapFar;		//<!シャドウマップに描画する最大距離
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_ShadowTexture();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_ShadowTexture();
		
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param[in]		TexSize シャドウマップ用テクスチャサイズ

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TexSize);
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param[in]		TexSize		シャドウマップ用テクスチャサイズ
				@param[in]		Type		シャドウマップの形式
				@param[in]		TexFormat	シャドウマップ用テクスチャフォーマット
				@param[in]		DepthFormat	シャドウマップ描画用の深度バッファフォーマット

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(MofU32 TexSize,ShadowType Type,PixelFormat TexFormat,PixelFormat DepthFormat);
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
				@brief			開始
				@param[in]		ShadowView	シャドウマップ描画用のビュー行列
				@param[in]		ShadowProj	シャドウマップ描画用の射影行列
		
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Begin(const Matrix44& ShadowView,const Matrix44& ShadowProj);
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
				@brief			シャドウマップの範囲を設定
				@param[in]		Range		シャドウマップに描画する範囲
				@param[in]		Near		シャドウマップに描画する最少距離
				@param[in]		Far			シャドウマップに描画する最大距離
					
				@return			None
		*//**************************************************************************/
		virtual void SetShadowMapParam(MofFloat Range,MofFloat Near,MofFloat Far);
		/*************************************************************************//*!
				@brief			ライトから視点のビュー行列と射影行列の設定
				@param[in]		LightView	ビュー行列
				@param[in]		LightProj	射影行列
					
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetLightViewProjection(const Matrix44& LightView,const Matrix44& LightProj);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			テクスチャの取得
				@param[in]		n			番号
					
				@return			テクスチャ
		*//**************************************************************************/
		virtual LPTexture GetTexture(MofU32 n);
		/*************************************************************************//*!
				@brief			深度テクスチャの取得
				@param			None
				
				@return			深度テクスチャ
		*//**************************************************************************/
		virtual LPTexture GetShadowMapTexture();
		/*************************************************************************//*!
				@brief			ライト視点のカメラ
				@param			None

				@return			ライト視点のカメラ
		*//**************************************************************************/
		virtual LPCamera GetCamera(void);
		/*************************************************************************//*!
				@brief			ライト視点のビュープロジェクション行列取得
				@param			None

				@return			ライト視点のビュープロジェクション行列
		*//**************************************************************************/
		virtual CMatrix44& GetLightViewProjectionMatrix(void);

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_ShadowTexture,MOF_SHADEREFFECTSHADOWTEXTURECLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_ShadowTexture*			LPShaderEffect_ShadowTexture;

#include	"ShaderEffect_ShadowTexture.inl"

}

#endif

//[EOF]