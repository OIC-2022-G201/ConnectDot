/*************************************************************************//*!
					
					@file	AnalysSprite.inl
					@brief	MOS�t�@�C���̉�͂��s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�ǂݍ��݃u���b�N�̈ړ�
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysSprite::MoveBlockOffset(void){
	if(m_Header.BlockSize <= 0)
	{
		return TRUE;
	}
	MofU32 st = m_Header.BlockSize - (m_Offset % m_Header.BlockSize);
	m_Offset += st;
	return TRUE;
}
/*************************************************************************//*!
		@brief			MOS�t�@�C�����𔻒肷��<br>
						�t�@�C���̐擪��MOFSPRITE_FILE_HEADER����n�܂��MOS�t�@�C��
		@param			None
				
		@return			TRUE		MOS�t�@�C��<br>
						����ȊO	MOS�t�@�C���ł͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysSprite::IsMOSFile(void){
	if(memcmp(m_pBuffer,MOFSPRITE_FILE_HEADER,MOFSPRITE_FILE_HEADERLEN))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			MOS�t�@�C���t�b�^�[�܂ŉ�͂������𔻒肷��<br>
						���݈ʒu����MOFSPRITE_FILE_FOOTER�̃f�[�^�ɂȂ��Ă���΃t�b�^�[
		@param			None
				
		@return			TRUE							�t�b�^�[<br>
						����ȊO						�܂��t�b�^�[�ł͂Ȃ�<br>
						MOFSPRITE_RESULTERROR_NOTFOOTER	�t�b�^�[����Ȃ��̂Ƀt�@�C�����I�����Ă���
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysSprite::IsMOSFooter(void){
	//�t�@�C���T�C�Y����
	if(m_Offset >= m_Size)
	{
		return MOFSPRITE_RESULTERROR_NOTFOOTER;
	}
	if(memcmp(&m_pBuffer[m_Offset],MOFSPRITE_FILE_FOOTER,MOFSPRITE_FILE_FOOTERLEN))
	{
		return FALSE;
	}
	return TRUE;
}

//[EOF]