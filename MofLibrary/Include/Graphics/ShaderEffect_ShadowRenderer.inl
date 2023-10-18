/*************************************************************************//*!
					
					@file	ShaderEffect_ShadowRenderer.h
					@brief	シャドウマップによる影描画シェーダークラス。

															@author	CDW
															@date	2015.05.04
*//**************************************************************************/

/*************************************************************************//*!
		@brief			イプシロンの設定
		@param[in]		Epsilon			影をずらす量
		
		@return			None
*//**************************************************************************/
FORCE_INLINE void CShaderEffect_ShadowRenderer::SetEpsilon(MofFloat Epsilon){
	m_ShadowEpsilon = Epsilon;
}

//[EOF]