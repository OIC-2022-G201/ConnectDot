/*************************************************************************//*!
					
					@file	ShaderBindBase.inl
					@brief	�V�F�[�_�[�o�C���h���C���^�[�t�F�C�X�B<br>
							�e�ݒ�o�b�t�@����̓��C�A�E�g���`���e���p�V�F�[�_�[���Ƀp�C�v���C���ɐݒ肷��B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�ݒ�p�����[�^�[���擾����
		@param			None

		@return			�p�����[�^�[
*//**************************************************************************/
FORCE_INLINE LPShaderBufferArray CShaderBindBase::GetShaderBuffer(void){
	return m_pBufferArray;
}
/*************************************************************************//*!
		@brief			�ݒ�p�����[�^�[���擾����
		@param[in]		n				�ԍ�

		@return			�p�����[�^�[
*//**************************************************************************/
FORCE_INLINE LPShaderBuffer CShaderBindBase::GetShaderBuffer(MofU32 n){
	return m_pBufferArray->GetData(n);
}
/*************************************************************************//*!
		@brief			�ݒ�p�����[�^�[���擾����
		@param[in]		pName			���O

		@return			�p�����[�^�[
*//**************************************************************************/
FORCE_INLINE LPShaderBuffer CShaderBindBase::GetShaderBufferByName(LPCMofChar pName){
	LPShaderBuffer* re = m_pBufferArray->Find(pName);
	if (!re)
	{
		return NULL;
	}
	return *re;
}
/*************************************************************************//*!
		@brief			�ݒ胊�\�[�X���擾����
		@param			None

		@return			���\�[�X
*//**************************************************************************/
FORCE_INLINE LPShaderResourceArray CShaderBindBase::GetShaderResource(void) {
	return m_pResourceArray;
}
/*************************************************************************//*!
		@brief			�ݒ胊�\�[�X���擾����
		@param[in]		n				�ԍ�

		@return			���\�[�X
*//**************************************************************************/
FORCE_INLINE LPShaderResource CShaderBindBase::GetShaderResource(MofU32 n) {
	return m_pResourceArray->GetData(n);
}
/*************************************************************************//*!
		@brief			�ݒ胊�\�[�X���擾����
		@param[in]		pName			���O

		@return			���\�[�X
*//**************************************************************************/
FORCE_INLINE LPShaderResource CShaderBindBase::GetShaderResourceByName(LPCMofChar pName){
	LPShaderResource* re = m_pResourceArray->Find(pName);
	if (!re)
	{
		return NULL;
	}
	return *re;
}

//[EOF]