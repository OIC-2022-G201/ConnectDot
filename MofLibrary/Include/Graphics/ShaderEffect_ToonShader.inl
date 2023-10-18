/*************************************************************************//*!
					
					@file	ShaderEffect_ToonShader.h
					@brief	トゥーンレンダリングシェーダークラス。

															@author	CDW
															@date	2015.05.27
*//**************************************************************************/

/*************************************************************************//*!
		@brief			トゥーンマップテクスチャ設定
		@param[in]		pTex			トゥーンマップテクスチャ
		
		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_ToonShader::SetToonMapTexture(LPTexture pTex){
	
	return (
		m_p3DPrimitiveBind->SetTexture(1,pTex) &&
		m_pSkinGeometryBind->SetTexture(1,pTex)
	);
}

//[EOF]