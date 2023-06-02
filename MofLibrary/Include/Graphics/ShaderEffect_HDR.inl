/*************************************************************************//*!
					
					@file	ShaderEffect_HDR.h
					@brief	HDRシェーダークラス。

															@author	CDW
															@date	2015.05.15
*//**************************************************************************/

/*************************************************************************//*!
		@brief			テクスチャの描画
		@param[in]		pTex		テクスチャ
		
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::Render(LPTexture pTex){
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
FORCE_INLINE MofBool CShaderEffect_HDR::Render(LPTexture pTargetTex,LPTexture pTex){
	MofFloat steps[] = { 1,2 };
	return Render(pTargetTex,pTex,2,steps);
}
/*************************************************************************//*!
		@brief			動向シミュレーションの変化速度
		@param[in]		MiddleGray	0.0f～1.0fの変化速度
			
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::SetLumTransitionSpeed(MofFloat Speed){
	m_LumTransitionSpeed = MOF_CLIPING(Speed, 0, 1);
	return TRUE;
}
/*************************************************************************//*!
		@brief			高輝度部抽出のパラメータ設定
		@param[in]		Threshold			閾値
			
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::SetBrightPassParam(MofFloat Threshold){
	return ((m_bToneMap) ? m_pToneBrightPass->SetThreshold(Threshold) : m_pBrightPass->SetThreshold(Threshold));
}

/*************************************************************************//*!
		@brief			高輝度部抽出のパラメータ設定
		@param[in]		Threshold			閾値
		@param[in]		MiddleGray			明るさの基準値
		@param[in]		BrightPassOffset	補正
			
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_HDR::SetBrightPassParam(MofFloat Threshold,MofFloat MiddleGray,MofFloat BrightPassOffset){
	return ((m_bToneMap) ? m_pToneBrightPass->SetHDRBrightPassParam(Threshold,MiddleGray,BrightPassOffset) : m_pBrightPass->SetThreshold(Threshold));
}


//[EOF]