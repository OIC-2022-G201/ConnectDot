/*************************************************************************//*!
					
					@file	MeshBase.inl
					@brief	���b�V�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMeshBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�W�I���g�����X�g�擾
		@param			None

		@return			�W�I���g�����X�g
*//**************************************************************************/
FORCE_INLINE LPGeometryArray CMeshBase::GetGeometry(void){
	return m_pGeometry;
}
/*************************************************************************//*!
		@brief			�u���b�N���X�g�擾
		@param			None

		@return			�u���b�N���X�g
*//**************************************************************************/
FORCE_INLINE LPBlockContainer CMeshBase::GetBlockContainer(void){
	if (!m_pBlockContainer)
	{
		m_pBlockContainer = new CBlockContainer();
	}
	return m_pBlockContainer;
}
/*************************************************************************//*!
		@brief			�W�I���g���o�^���擾
		@param			None

		@return			�W�I���g���o�^��
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshBase::GetGeometryCount(void) const {
	return m_pGeometry->GetArrayCount();
}
/*************************************************************************//*!
		@brief			�W�I���g���擾
		@param[in]		pName			�T���W�I���g����

		@return			�W�I���g��
						������Ȃ������ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE LPGeometry CMeshBase::GetGeometryByName(LPCMofChar pName){
	LPGeometry* re = m_pGeometry->Find(pName);
	if(!re)
	{
		return NULL;
	}
	return *re;
}
/*************************************************************************//*!
		@brief			�W�I���g���擾
		@param[in]		No				�W�I���g���ԍ�

		@return			�W�I���g��
						������Ȃ������ꍇNULL��Ԃ�
*//**************************************************************************/
FORCE_INLINE LPGeometry CMeshBase::GetGeometry(MofU32 No){
	if (No >= m_pGeometry->GetArrayCount())
	{
		return NULL;
	}
	return m_pGeometry->GetData(No);
}

//[EOF]