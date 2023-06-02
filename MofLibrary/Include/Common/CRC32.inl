/*************************************************************************//*!
					
					@file	CRC32.inl
					@brief	CRC32�n�b�V���������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�n�b�V������
		@param[in]		pStr			�n�b�V������������

		@return			���������n�b�V���R�[�h��Ԃ�
*//**************************************************************************/
FORCE_INLINE MofU32 CCRC32::CreateHash(LPCMofChar pStr){
	if(!pStr)
	{
		return MOF_U32_MAX;
	}
	return CreateHash(pStr,MOF_StrLength(pStr));
}
/*************************************************************************//*!
		@brief			�n�b�V������
		@param[in]		pStr			�n�b�V������������

		@return			���������n�b�V���R�[�h��Ԃ�
*//**************************************************************************/
FORCE_INLINE MofU32 CCRC32::CreateHash(const LPString pStr){
	if(!pStr)
	{
		return MOF_U32_MAX;
	}
	return CreateHash(pStr->GetString(),pStr->GetStringSize());
}

//[EOF]