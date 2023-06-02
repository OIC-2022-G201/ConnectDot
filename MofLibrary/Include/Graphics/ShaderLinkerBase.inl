/*************************************************************************//*!
					
					@file	ShaderLinkerBase.inl
					@brief	�V�F�[�_�[���C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CShaderLinkerBase::SetName(LPCMofChar pName) {
	return FALSE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CShaderLinkerBase::GetName(void) {
	return m_pShader->GetName();
}
/*************************************************************************//*!
		@brief			�ϐ��Ƃ̃����N�̎擾
		@param			None

		@return			�ϐ��Ƃ̃����N
*//**************************************************************************/
FORCE_INLINE IShaderLinker::LPLinkArray CShaderLinkerBase::GetLink(void) {
	return m_pLink;
}
/*************************************************************************//*!
		@brief			�e�N�X�`���Ƃ̃����N�̎擾
		@param			None

		@return			�e�N�X�`���Ƃ̃����N
*//**************************************************************************/
FORCE_INLINE IShaderLinker::LPLinkTextureArray CShaderLinkerBase::GetTextureLink(void) {
	return m_pLinkTexture;
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�̎擾
		@param			None

		@return			�V�F�[�_�[
*//**************************************************************************/
FORCE_INLINE LPShader CShaderLinkerBase::GetShader(void) {
	return m_pShader;
}
/*************************************************************************//*!
		@brief			�V�F�[�_�[�o�C���h�̎擾
		@param			None

		@return			�V�F�[�_�[�o�C���h
*//**************************************************************************/
FORCE_INLINE LPShaderBind CShaderLinkerBase::GetShaderBind(void) {
	return m_pShaderBind;
}

//[EOF]