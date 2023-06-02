/*************************************************************************//*!
					
					@file	AnalysX.h
					@brief	X�t�@�C���̉�͂��s��CXModel�N���X�ɐݒ���s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			X�t�@�C�����𔻒肷��<br>
						�t�@�C���̐擪��xof����n�܂��X�t�@�C��
		@param			None
				
		@return			TRUE		X�t�@�C��<br>
						����ȊO	X�t�@�C���ł͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysX::IsXFile(void){
	//�ŏ���xof����Ȃ����X�t�@�C������Ȃ�
	if(memcmp(m_pBuffer,MOFSTR("xof "),4 * sizeof(MofChar)))
	{
		return FALSE;
	}
	return TRUE;
}

/*************************************************************************//*!
		@brief			�e�L�X�g�`����X�t�@�C�����𔻒肷��<br>
						�t�@�C���̐擪��xof����n�܂�txt�w�肪����΃e�L�X�g�`����X�t�@�C��
		@param			None
				
		@return			TRUE		�e�L�X�g�`����X�t�@�C��<br>
						����ȊO	�e�L�X�g�`����X�t�@�C���ł͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysX::IsTextXFile(void){
	//X�t�@�C�������f
	if(!IsXFile())
	{
		return FALSE;
	}
	//txt�����f
	if(memcmp(m_pBuffer + 8 * sizeof(MofChar),MOFSTR("txt "),4 * sizeof(MofChar)))
	{
		return FALSE;
	}
	return TRUE;
}

//[EOF]