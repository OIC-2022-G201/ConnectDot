/*************************************************************************//*!
					
					@file	PackFile.inl
					@brief	�t�@�C���p�b�L���O�N���X

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CPackFile::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CPackFile::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�p�b�N�t�@�C�����ɕۑ�����Ă���t�@�C����
		@param			None

		@return			�p�b�N�t�@�C�����ɕۑ�����Ă���t�@�C�����̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CPackFile::GetFileCount(void) const{
	return m_FileNum;
}
/*************************************************************************//*!
		@brief			�p�b�N�t�@�C���w�b�_�[
		@param			None

		@return			�p�b�N�t�@�C���w�b�_�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPPackFileHeader CPackFile::GetFileInfo(void){
	return m_pPackHeader;
}
/*************************************************************************//*!
		@brief			�p�b�N�t�@�C���w�b�_�[
		@param[in]		No				�t�@�C���ԍ�

		@return			�p�b�N�t�@�C���w�b�_�[�̎擾
*//**************************************************************************/
FORCE_INLINE LPPackFileHeader CPackFile::GetFileInfo(MofU32 No){
	//�t�@�C���ő吔�ȏ�Ȃ疳��
	if(No >= m_FileNum)
	{
		return NULL;
	}
	return &m_pPackHeader[No];
}

//[EOF]