/*************************************************************************//*!
					
					@file	ShaderEffect_ToonEdge.inl
					@brief	エッジシェーダークラス。

															@author	CDW
															@date	2015.05.22
*//**************************************************************************/

/*************************************************************************//*!
@brief			テクスチャの描画
@param[in]		pTarget		描画ターゲットのテクスチャ
@param[in]		pTex		テクスチャ
@param[in]		pEffect		エッジ描画準備シェーダー
				
@return			TRUE		成功<br>
				それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ToonEdge::Render(LPTexture pTargetTex,LPTexture pTex,LPShaderEffect_EdgeBaseOutput pEffect){
	if(
		!SetDepthNormalTexture(pEffect->GetDepthNormalTexture()) ||
		!SetMaskTexture(pEffect->GetMaskTexture())
	){
		return FALSE;
	}
	return CShaderEffect_2DBase::Render(pTargetTex,pTex);
}
/*************************************************************************//*!
@brief			深度テクスチャの設定
@param[in]		pTex		深度テクスチャ
				
@return			TRUE		成功<br>
				それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ToonEdge::SetDepthNormalTexture(LPTexture pTex){
	return m_pShaderBind->SetTexture(1,pTex);
}
/*************************************************************************//*!
@brief			マスクテクスチャの設定
@param[in]		pTex		マスクテクスチャ
				
@return			TRUE		成功<br>
				それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ToonEdge::SetMaskTexture(LPTexture pTex){
	return m_pShaderBind->SetTexture(2,pTex);
}

//[EOF]