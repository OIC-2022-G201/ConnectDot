/*************************************************************************//*!
					
					@file	GLShader.inl
					@brief	OpenGL�V�F�[�_�[�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�V�F�[�_�[�̎擾
		@param			None

		@return			�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE MofShaderEffect CGLShader::GetShader(void){
	return m_Shader;
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�̎擾
		@param			None

		@return			�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE MofVertexShader CGLShader::GetVertexShader(void){
	return m_VertexShader;
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�̎擾
		@param			None

		@return			�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE MofPixelShader CGLShader::GetPixelShader(void){
	return m_PixelShader;
}

//[EOF]