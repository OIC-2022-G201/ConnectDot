/*************************************************************************//*!
					
					@file	ShaderEffect_2DBase.h
					@brief	2D用シェーダー効果基底クラス。

															@author	CDW
															@date	2015.04.22
*//**************************************************************************/

/*************************************************************************//*!
@brief			テクスチャの描画
@param[in]		px			描画X座標
@param[in]		py			描画Y座標
@param[in]		pTex		テクスチャ
				
@return			TRUE		成功<br>
				それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_2DBase::Render(MofFloat px,MofFloat py,LPTexture pTex){
	return Render(px,py,MOF_COLOR_WHITE,TEXTUREALIGNMENT_TOPLEFT,pTex);
}

/*************************************************************************//*!
		@brief			シェーダーの取得
		@param			None
				
		@return			シェーダーを返す。
						失敗の場合NULLになる。
*//**************************************************************************/
FORCE_INLINE LPShader CShaderEffect_2DBase::GetShader(void){
	return m_pShader;
}
/*************************************************************************//*!
		@brief			シェーダーバインドの取得
		@param			None
				
		@return			シェーダーバインドを返す。
						失敗の場合NULLになる。
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderEffect_2DBase::GetShaderBind(void){
	return m_pShaderBind;
}

//[EOF]