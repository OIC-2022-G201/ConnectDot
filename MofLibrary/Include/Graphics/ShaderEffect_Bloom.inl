/*************************************************************************//*!
					
					@file	ShaderEffect_Bloom.h
					@brief	Bloomシェーダークラス。

															@author	CDW
															@date	2015.11.09
*//**************************************************************************/

/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTex		テクスチャ
		
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_Bloom::Render(LPTexture pTex){
	MofFloat steps[] = { 1,2 };
	return Render(NULL,pTex,2,steps);
}
/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTarget		描画ターゲットのテクスチャ
		@param[in]		pTex		テクスチャ
		
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_Bloom::Render(LPTexture pTargetTex,LPTexture pTex){
	MofFloat steps[] = { 1,2 };
	return Render(pTargetTex,pTex,2,steps);
}
/*************************************************************************//*!
		@brief			高輝度部抽出のパラメータ設定
		@param[in]		Threshold			閾値
			
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_Bloom::SetBrightPassParam(MofFloat Threshold){
	m_pBrightPass->SetThreshold(Threshold);
	return TRUE;
}


//[EOF]