/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowTexture.h
					@brief	シャドウマップ用深度テクスチャ描画シェーダー。

															@author	CDW
															@date	2015.05.13
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowTexture::Create(){
	return Create(512,SHADOW_NORMAL,PIXELFORMAT_R32_FLOAT,PIXELFORMAT_D24S8_UNORM);
}
/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param[in]		TexSize シャドウマップ用テクスチャサイズ

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowTexture::Create(MofU32 TexSize){
	return Create(TexSize,SHADOW_NORMAL,PIXELFORMAT_R32_FLOAT,PIXELFORMAT_D24S8_UNORM);
}
/*************************************************************************//*!
		@brief			テクスチャの取得
		@param[in]		n			番号
			
		@return			テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_ShadowTexture::GetTexture(MofU32 n){
	if(n == 0)
	{
		return m_pShadowMapTex;
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			深度テクスチャの取得
		@param			None
		
		@return			深度テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_ShadowTexture::GetShadowMapTexture(){
	return m_pShadowMapTex;
}
/*************************************************************************//*!
		@brief			ライト視点のカメラ
		@param			None

		@return			ライト視点のカメラ
*//**************************************************************************/
FORCE_INLINE LPCamera CShaderEffect_ShadowTexture::GetCamera(void){
	return &m_LightCam;
}
/*************************************************************************//*!
		@brief			ライト視点のビュープロジェクション行列取得
		@param			None

		@return			ライト視点のビュープロジェクション行列
*//**************************************************************************/
FORCE_INLINE CMatrix44& CShaderEffect_ShadowTexture::GetLightViewProjectionMatrix(void){
	return m_LightCam.GetViewProjectionMatrix();
}
/*************************************************************************//*!
		@brief			シャドウマップの範囲を設定
		@param[in]		Range		シャドウマップに描画する範囲
		@param[in]		Near		シャドウマップに描画する最少距離
		@param[in]		Far			シャドウマップに描画する最大距離
			
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_ShadowTexture::SetShadowMapParam(MofFloat Range,MofFloat Near,MofFloat Far){
	m_LightMapRange = Range;
	m_LightMapNear = Near;
	m_LightMapFar = Far;
}

//[EOF]