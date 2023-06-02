/*************************************************************************//*!
					
					@file	DX11Shader.inl
					@brief	DirectX11シェーダークラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーの取得
		@param			None

		@return			シェーダー
*//**************************************************************************/
FORCE_INLINE MofShaderEffect CDX11Shader::GetShader(void){
	return m_pShader;
}
/*************************************************************************//*!
		@brief			シェーダーの取得
		@param			None

		@return			シェーダー
*//**************************************************************************/
FORCE_INLINE MofVertexShader CDX11Shader::GetVertexShader(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			シェーダーの取得
		@param			None

		@return			シェーダー
*//**************************************************************************/
FORCE_INLINE MofPixelShader CDX11Shader::GetPixelShader(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			設定バッファの数取得
		@param			None

		@return			設定バッファ
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11Shader::GetBufferCount(void) const {
	return m_Desc.ConstantBuffers;
}
/*************************************************************************//*!
		@brief			設定バッファの数取得
		@param			None

		@return			設定バッファ
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11Shader::GetGlobalVariableCount(void) const {
	return m_Desc.GlobalVariables;
}
/*************************************************************************//*!
		@brief			設定バッファの数取得
		@param			None

		@return			設定バッファ
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11Shader::GetInterfaceCount(void) const {
	return m_Desc.InterfaceVariables;
}

//[EOF]