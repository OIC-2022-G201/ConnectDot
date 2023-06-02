/*************************************************************************//*!
					
					@file	AnalysMesh.inl
					@brief	MOM�t�@�C���̉�͂��s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�ǂݍ��݃u���b�N�̈ړ�
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMesh::MoveBlockOffset(void){
	if(m_Header.BlockSize <= 0)
	{
		return TRUE;
	}
	MofU32 st = m_Header.BlockSize - (m_Offset % m_Header.BlockSize);
	m_Offset += st;
	return TRUE;
}
/*************************************************************************//*!
		@brief			MOM�t�@�C�����𔻒肷��<br>
						�t�@�C���̐擪��MOFMODEL_FILE_HEADER����n�܂��MOM�t�@�C��
		@param			None
				
		@return			TRUE		MOM�t�@�C��<br>
						����ȊO	MOM�t�@�C���ł͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMesh::IsMOMFile(void){
	if(memcmp(m_pBuffer,MOFMODEL_FILE_HEADER,MOFMODEL_FILE_HEADERLEN))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			MOM�t�@�C���t�b�^�[�܂ŉ�͂������𔻒肷��<br>
						���݈ʒu����MOFMODEL_FILE_FOOTER�̃f�[�^�ɂȂ��Ă���΃t�b�^�[
		@param			None
				
		@return			TRUE							�t�b�^�[<br>
						����ȊO						�܂��t�b�^�[�ł͂Ȃ�<br>
						MOFMODEL_RESULTERROR_NOTFOOTER	�t�b�^�[����Ȃ��̂Ƀt�@�C�����I�����Ă���
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMesh::IsMOMFooter(void){
	//�t�@�C���T�C�Y����
	if(m_Offset >= m_Size)
	{
		return MOFMODEL_RESULTERROR_NOTFOOTER;
	}
	if(memcmp(&m_pBuffer[m_Offset],MOFMODEL_FILE_FOOTER,MOFMODEL_FILE_FOOTERLEN))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			�e�N�X�`�������z��ݒ�
		@param[in]		pTex		�e�N�X�`�������z��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMesh::SetTextureArray(LPTextureArray pTex){
	m_pTextureArray = pTex;
	return TRUE;
}

//[EOF]