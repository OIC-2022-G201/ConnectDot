/*************************************************************************//*!
					
					@file	ShaderEffect_DepthOutput.h
					@brief	マルチレンダリングによる深度テクスチャ描画シェーダークラス。

															@author	CDW
															@date	2015.05.01
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_DepthOutput::Create(){
	return Create(PIXELFORMAT_R32_FLOAT,PIXELFORMAT_D24S8_UNORM,TRUE);
}
/*************************************************************************//*!
		@brief			テクスチャの取得
		@param[in]		n			番号
			
		@return			テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_DepthOutput::GetTexture(MofU32 n){
	if(n == 0)
	{
		return m_pDepthTex;
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			深度テクスチャの取得
		@param			None
		
		@return			深度テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_DepthOutput::GetDepthTexture(){
	return m_pDepthTex;
}

//[EOF]