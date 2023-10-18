/*************************************************************************//*!
					
					@file	ShaderEffect_EdgeBaseOutput.h
					@brief	マルチレンダリングによる深度＆法線テクスチャ描画シェーダークラス。

															@author	CDW
															@date	2015.05.29
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_EdgeBaseOutput::Create(){
	return Create(PIXELFORMAT_R32G32B32A32_FLOAT,PIXELFORMAT_D24S8_UNORM,TRUE);
}
/*************************************************************************//*!
		@brief			開始
		@param			None
		
		@return			None
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_EdgeBaseOutput::BeginMask(){
	return m_pEdgeMask->Begin();
}
/*************************************************************************//*!
		@brief			終了
		@param			None
		
		@return			None
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_EdgeBaseOutput::EndMask(){
	return m_pEdgeMask->End();
}
/*************************************************************************//*!
		@brief			テクスチャの取得
		@param[in]		n			番号
			
		@return			テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeBaseOutput::GetTexture(MofU32 n){
	switch(n) {
	case 0:
		return m_pDepthNormalTex;
	case 1:
		return m_pEdgeMask->GetMaskTexture();
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			深度テクスチャの取得
		@param			None
		
		@return			深度テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeBaseOutput::GetDepthNormalTexture(){
	return m_pDepthNormalTex;
}
/*************************************************************************//*!
		@brief			マスクテクスチャの取得
		@param			None
		
		@return			マスクテクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeBaseOutput::GetMaskTexture(){
	return m_pEdgeMask->GetMaskTexture();
}

//[EOF]