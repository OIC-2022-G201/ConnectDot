/*************************************************************************//*!
					
					@file	ShaderEffect_DepthOfField.h
					@brief	被写界深度シェーダークラス。

															@author	CDW
															@date	2015.04.29
*//**************************************************************************/

/*************************************************************************//*!
@brief			テクスチャの描画
@param[in]		pTarget		描画ターゲットのテクスチャ
@param[in]		pTex		テクスチャ
@param[in]		pDepthTex	深度テクスチャ
				
@return			TRUE		成功<br>
				それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_DepthOfField::Render(LPTexture pTargetTex,LPTexture pTex,LPTexture pDepthTex){
	if(!SetDepthTexture(pDepthTex))
	{
		return FALSE;
	}
	return Render(pTargetTex,pTex);
}

/*************************************************************************//*!
@brief			深度テクスチャの設定
@param[in]		pTex		深度テクスチャ
				
@return			TRUE		成功<br>
				それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_DepthOfField::SetDepthTexture(LPTexture pTex){
	return m_pShaderBind->SetTexture(2,pTex);
}

//[EOF]