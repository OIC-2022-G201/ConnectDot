/*************************************************************************//*!
					
					@file	PSDReader.inl
					@brief	PSD�ǂݍ��ݗp�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�R�s�[���C�g�ǂݍ���
		@param			None
				
		@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
*//**************************************************************************/
FORCE_INLINE MofS32 CPSDReader::ReadCopyright(void){
	MofS16 Value = GetShort(m_SwapEndian);
	if(Value)
	{
		m_Copyright = TRUE;
	}
	return sizeof(MofS16);
}
/*************************************************************************//*!
		@brief			�O���[�o���A���O���ǂݍ���
		@param			None
				
		@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
*//**************************************************************************/
FORCE_INLINE MofS32 CPSDReader::ReadGlobalAngle(void){
	m_GlobalAngle = GetLong(m_SwapEndian);
	return sizeof(MofS32);
}
/*************************************************************************//*!
		@brief			�F���ǂݍ���
		@param			None
				
		@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
*//**************************************************************************/
FORCE_INLINE MofS32 CPSDReader::ReadColorCount(void){
	m_ColorCount = GetShort(m_SwapEndian);
	return sizeof(MofS16);
}
/*************************************************************************//*!
		@brief			�C���f�b�N�X�ǂݍ���
		@param			None
				
		@return			�ǂݍ��񂾃f�[�^�T�C�Y��Ԃ�
*//**************************************************************************/
FORCE_INLINE MofS32 CPSDReader::ReadTransparentIndex(void){
	m_TransparentIndex = GetShort(m_SwapEndian);
	return sizeof(MofS16);
}
/*************************************************************************//*!
		@brief			�ǂݍ��݃��\�[�X��������������
		@param[in,out]	pResource	�o�̓��\�[�X
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CPSDReader::ResourceReset(PSD_IMAGE_RESOURCE* pResource){
	if(!pResource)
	{
		return FALSE;
	}
	pResource->Length = -1;
	pResource->Type = 0;
	pResource->ID = -1;
	pResource->Size = -1;
	MOF_SAFE_FREE(pResource->pName,"CPSDReader ResourceReset");
	return TRUE;
}
/*************************************************************************//*!
		@brief			PSD�w�b�_�[�擾
		@param			None

		@return			PSD�w�b�_�[
*//**************************************************************************/
FORCE_INLINE LPPSD_HEADER CPSDReader::GetHeader(void){
	return &m_Header;
}
/*************************************************************************//*!
		@brief			PSD���C���[���擾
		@param			None

		@return			PSD���C���[���
*//**************************************************************************/
FORCE_INLINE LPPSDLayerInfoArray CPSDReader::GetPSDLayerInfoList(void){
	return &m_LayerInfo;
}

//[EOF]