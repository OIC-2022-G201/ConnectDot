/*************************************************************************//*!
					
					@file	DX11Shader.inl
					@brief	DirectX11�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�̎擾
		@param			None

		@return			�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE MofShaderEffect CDX11Shader::GetShader(void){
	return m_pShader;
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�̎擾
		@param			None

		@return			�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE MofVertexShader CDX11Shader::GetVertexShader(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�̎擾
		@param			None

		@return			�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE MofPixelShader CDX11Shader::GetPixelShader(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�ݒ�o�b�t�@�̐��擾
		@param			None

		@return			�ݒ�o�b�t�@
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11Shader::GetBufferCount(void) const {
	return m_Desc.ConstantBuffers;
}
/*************************************************************************//*!
		@brief			�ݒ�o�b�t�@�̐��擾
		@param			None

		@return			�ݒ�o�b�t�@
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11Shader::GetGlobalVariableCount(void) const {
	return m_Desc.GlobalVariables;
}
/*************************************************************************//*!
		@brief			�ݒ�o�b�t�@�̐��擾
		@param			None

		@return			�ݒ�o�b�t�@
*//**************************************************************************/
FORCE_INLINE MofU32 CDX11Shader::GetInterfaceCount(void) const {
	return m_Desc.InterfaceVariables;
}

//[EOF]