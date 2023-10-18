/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowMap.inl
					@brief	シャドウマップシェーダークラス。

															@author	CDW
															@date	2015.05.13
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::Create(){
	return Create(512,PIXELFORMAT_R32_FLOAT);
}
/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param[in]		TexSize シャドウマップ用テクスチャサイズ

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::Create(MofU32 TexSize){
	return Create(TexSize, PIXELFORMAT_R32_FLOAT);
}
/*************************************************************************//*!
		@brief			深度テクスチャ作成開始
		@param			None
		
		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::BeginTexture(){
	return m_pShadowTexture->Begin();
}
/*************************************************************************//*!
		@brief			深度テクスチャ作成終了
		@param			None
		
		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::EndTexture(){
	return m_pShadowTexture->End();
}
/*************************************************************************//*!
		@brief			影を適用した画面描画開始
		@param			None
		
		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::BeginRenderer(){
	m_pShadowRenderer->SetShadowMap(m_pShadowTexture);
	return m_pShadowRenderer->Begin();
}
/*************************************************************************//*!
		@brief			影を適用した画面描画終了
		@param			None
		
		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ShadowMap::EndRenderer(){
	return m_pShadowRenderer->End();
}
/*************************************************************************//*!
		@brief			シャドウマップの範囲を設定
		@param[in]		Range		シャドウマップに描画する範囲
		@param[in]		Near		シャドウマップに描画する最少距離
		@param[in]		Far			シャドウマップに描画する最大距離
			
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_ShadowMap::SetShadowMapParam(MofFloat Range,MofFloat Near,MofFloat Far,MofFloat Epsilon){
	m_pShadowTexture->SetShadowMapParam(Range,Near,Far);
	m_pShadowRenderer->SetEpsilon(Epsilon);
}
/*************************************************************************//*!
		@brief			3Dプリミティブ描画用シェーダーを取得する
		@param			None

		@return			3Dプリミティブ描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_ShadowMap::GetShader(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			3Dプリミティブ描画用シェーダーを取得する
		@param			None

		@return			3Dプリミティブ描画用シェーダー
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_ShadowMap::GetShaderBind(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			深度テクスチャの取得
		@param			None
		
		@return			深度テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_ShadowMap::GetShadowMapTexture(){
	return m_pShadowTexture->GetShadowMapTexture();
}

//[EOF]