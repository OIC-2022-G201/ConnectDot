/*************************************************************************//*!
					
					@file	ShaderEffect_EdgeMaskOutput.h
					@brief	マルチレンダリングによる深度＆法線テクスチャ描画シェーダークラス。

															@author	CDW
															@date	2015.11.02
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_EdgeMaskOutput::Create(){
	return Create(PIXELFORMAT_D24S8_UNORM,FALSE);
}
/*************************************************************************//*!
		@brief			テクスチャの取得
		@param[in]		n			番号
			
		@return			テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeMaskOutput::GetTexture(MofU32 n){
	switch(n)
	{
	case 0:
		return m_pMaskTex;
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			マスクテクスチャの取得
		@param			None
		
		@return			マスクテクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CShaderEffect_EdgeMaskOutput::GetMaskTexture(){
	return m_pMaskTex;
}

//[EOF]