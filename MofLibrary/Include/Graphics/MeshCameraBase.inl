/*************************************************************************//*!
					
					@file	MeshCameraBase.inl
					@brief	���b�V���J�������N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCamera::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMeshCamera::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�J�������擾
		@param			None

		@return			�J�������
*//**************************************************************************/
FORCE_INLINE MOMCAMERAINFO& CMeshCamera::GetInfo(void) {
	return m_Info;
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����ł̓��샂�[�t�B���O���擾
		@param			None

		@return			�A�j���[�V�����ł̓��샂�[�t�B���O���z��
*//**************************************************************************/
FORCE_INLINE LPMeshCameraAnimationArray CMeshCamera::GetAnimation(void) {
	return m_pAnimation;
}
/*************************************************************************//*!
		@brief			�o�^����Ă��A�j���[�V�����擾
		@param[in]		pName			�A�j���[�V������

		@return			�A�j���[�V����
*//**************************************************************************/
FORCE_INLINE LPMeshCameraAnimation CMeshCamera::GetAnimation(LPCMofChar pName) {
	if (!pName)
	{
		return NULL;
	}
	LPMeshCameraAnimation* pf = m_pAnimation->Find(pName);
	if (!pf)
	{
		return NULL;
	}
	return *pf;
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����o�^���擾
		@param			None

		@return			�A�j���[�V�����o�^��
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshCamera::GetAnimationCount(void) {
	return m_pAnimation->GetArrayCount();
}

//[EOF]