/*************************************************************************//*!
					
					@file	AnalysMDL.inl
					@brief	MDL�t�@�C���̉�͂��s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			MDL�t�@�C�����𔻒肷��
		@param			None
				
		@return			TRUE		MDL�t�@�C��<br>
						����ȊO	MDL�t�@�C���ł͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CAnalysMDL::IsMeshFile(void){
	if(memcmp(m_pBuffer,MBSMODEL_FILE_HEADER,MBSMODEL_FILE_HEADERLEN))
	{
		return FALSE;
	}
	return TRUE;
}

//[EOF]