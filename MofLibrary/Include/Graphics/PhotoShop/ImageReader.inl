/*************************************************************************//*!
					
					@file	ImageReader.inl
					@brief	PSD�����摜�ۑ��p�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CImageReader::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CImageReader::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�C���[�W�z��擾
		@param			None

		@return			�C���[�W�z��
*//**************************************************************************/
FORCE_INLINE LPImageDataArray CImageReader::GetImage(void){
	return &m_ImageData;
}
/*************************************************************************//*!
		@brief			�C���[�W���擾
		@param[in]		Index			�z����ԍ�

		@return			�C���[�W��
*//**************************************************************************/
FORCE_INLINE LPString CImageReader::GetImageName(MofS32 Index){
	if(Index >= GetImageCount())
	{
		return NULL;
	}
	LPMOFIMAGEDATA pData = m_ImageData.GetData(Index);
	return &pData->Name;
}
/*************************************************************************//*!
		@brief			�C���[�W�f�[�^�擾
		@param[in]		Index			�z����ԍ�

		@return			�C���[�W�f�[�^
*//**************************************************************************/
FORCE_INLINE MofU8* CImageReader::GetImageData(MofS32 Index){
	if(Index >= GetImageCount())
	{
		return NULL;
	}
	LPMOFIMAGEDATA pData = m_ImageData.GetData(Index);
	return pData->pData;
}
/*************************************************************************//*!
		@brief			�C���[�W�f�[�^�T�C�Y�擾
		@param[in]		Index			�z����ԍ�

		@return			�C���[�W�f�[�^�T�C�Y
*//**************************************************************************/
FORCE_INLINE MofU32 CImageReader::GetImageDataSize(MofS32 Index){
	if(Index >= GetImageCount())
	{
		return NULL;
	}
	LPMOFIMAGEDATA pData = m_ImageData.GetData(Index);
	return pData->Size;
}
/*************************************************************************//*!
		@brief			�C���[�W�f�[�^�z�񐔎擾
		@param			None

		@return			�C���[�W�f�[�^�z��
*//**************************************************************************/
FORCE_INLINE MofU32 CImageReader::GetImageCount(void) const {
	return m_ImageData.GetArrayCount();
}

//[EOF]