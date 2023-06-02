/*************************************************************************//*!
					
					@file	ShaderEffect_SimpleBlur.inl
					@brief	単純ぼかしシェーダークラス。

															@author	CDW
															@date	2015.06.17
*//**************************************************************************/

/*************************************************************************//*!
@brief			テクスチャの描画
@param[in]		px			描画X座標
@param[in]		py			描画Y座標
@param[in]		pTex		テクスチャ
				
@return			TRUE		成功<br>
				それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_SimpleBlur::Render(MofFloat px,MofFloat py,LPTexture pTex){
	return Render(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}

/*************************************************************************//*!
		@brief			ぼかしのパラメータの設定
		@param[in]		SampleStepX		サンプリングするピクセルの横間隔
		@param[in]		SampleStepY		サンプリングするピクセルの縦間隔

		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_SimpleBlur::SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY){
	SetBlurParam(SampleStepX,SampleStepY,m_TexWidth,m_TexHeight);
}

//[EOF]