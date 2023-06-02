/*************************************************************************//*!
					
					@file	IndexBufferBase.inl
					@brief	�C���f�b�N�X�o�b�t�@���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�C���f�b�N�X�擾
		@param			None

		@return			�C���f�b�N�X�̎擾
*//**************************************************************************/
FORCE_INLINE LPMofVoid CIndexBufferBase::GetIndex(void) const{
	return m_pIndex;
}
/*************************************************************************//*!
		@brief			�C���f�b�N�X�擾
		@param			None

		@return			�C���f�b�N�X�̎擾<br>
						�T�C�Y��16bit�C���f�b�N�X�ł͂Ȃ��ꍇNULL
*//**************************************************************************/
FORCE_INLINE LPMofU16 CIndexBufferBase::GetIndexU16(void){
	if(m_Size != sizeof(MofU16))
	{
		return NULL;
	}
	return (LPMofU16)m_pIndex;
}
/*************************************************************************//*!
		@brief			�C���f�b�N�X�擾
		@param			None

		@return			�C���f�b�N�X�̎擾<br>
						�T�C�Y��32bit�C���f�b�N�X�ł͂Ȃ��ꍇNULL
*//**************************************************************************/
FORCE_INLINE LPMofU32 CIndexBufferBase::GetIndexU32(void){
	if(m_Size != sizeof(MofU32))
	{
		return NULL;
	}
	return (LPMofU32)m_pIndex;
}
/*************************************************************************//*!
		@brief			�C���f�b�N�X�T�C�Y�擾
		@param			None

		@return			�C���f�b�N�X�T�C�Y�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CIndexBufferBase::GetIndexSize(void) const{
	return m_Size;
}
/*************************************************************************//*!
		@brief			�C���f�b�N�X���擾
		@param			None

		@return			�C���f�b�N�X���̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CIndexBufferBase::GetIndexCount(void) const{
	return m_Count;
}

//[EOF]