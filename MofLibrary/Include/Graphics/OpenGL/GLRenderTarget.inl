/*************************************************************************//*!
					
					@file	GLRenderTarget.inl
					@brief	OpenGL�`��^�[�Q�b�g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�N���A�J���[�ݒ�
		@param[in]		Color	�N���A�J���[

		@return			None
*//**************************************************************************/
FORCE_INLINE void CGLRenderTarget::SetClearColor(Vector4& Color){
	m_ClearColor = Color;
}
/*************************************************************************//*!
		@brief			�`��^�[�Q�b�g�擾
		@param			None

		@return			�`��^�[�Q�b�g
*//**************************************************************************/
FORCE_INLINE MofRenderTarget CGLRenderTarget::GetTarget(void){
	return m_FBOId;
}
/*************************************************************************//*!
		@brief			�N���A�J���[�擾
		@param			None

		@return			�N���A�J���[
*//**************************************************************************/
FORCE_INLINE const Vector4& CGLRenderTarget::GetClearColor(void)const{
	return m_ClearColor;
}

//[EOF]
