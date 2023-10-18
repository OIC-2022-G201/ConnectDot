/*************************************************************************//*!
					
					@file	MeshMotionController.inl
					@brief	���b�V�����[�V�����Ǘ��N���X�B<br>
							���b�V���A�j���[�V�����̎��ԂƏ�Ԃ��Ǘ�����B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���݂̃��[�V������ύX
		@param[in]		n				���[�V�����ԍ�
		@param[in]		spd				���[�V�����Đ����x
		@param[in]		bLoop			���[�v�t���O
		@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMeshMotionController::ChangeMotion(MofU32 n, MofFloat spd, MofBool bLoop, MofBool bSame){
	return ChangeMotion(n, 0.0f, spd, 0.0f, bLoop, MOTIONLOCK_OFF, bSame);
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�������Ԃ�ݒ�
		@param[in]		t				�ݒ莞��
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMeshMotionController::SetTime(MofFloat t){
	m_MotionTime = t;
	for (MofU32 i = 0; i < m_pBoneState->GetArrayCount(); i++)
	{
		LPBONEMOTIONSTATE pBS = m_pBoneState->GetData(i);
		pBS->AnimationTime = m_MotionTime;
	}
	return Refresh();
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�������Ԏ擾
		@param			None

		@return			���݂̃��[�V��������
*//**************************************************************************/
FORCE_INLINE MofFloat CMeshMotionController::GetTime(void) const{
	return m_MotionTime;
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�����ԍ��擾
		@param			None

		@return			���݂̃��[�V�����ԍ�
*//**************************************************************************/
FORCE_INLINE MofS32 CMeshMotionController::GetMotionNo(void) const {
	return m_MotionNo;
}
/*************************************************************************//*!
		@brief			�o�^����Ă��郂�[�V�������擾
		@param			None

		@return			�o�^����Ă��郂�[�V������
*//**************************************************************************/
FORCE_INLINE MofS32 CMeshMotionController::GetMotionCount(void) const {
	return m_pAnimation->GetArrayCount();
}
/*************************************************************************//*!
		@brief			�o�^����Ă���{�[�����擾
		@param			None

		@return			�o�^����Ă���{�[����
*//**************************************************************************/
FORCE_INLINE MofS32 CMeshMotionController::GetBoneCount(void){
	return m_pBoneState->GetArrayCount();
}
/*************************************************************************//*!
		@brief			�o�^����Ă��郂�[�V�����擾
		@param[in]		n				���[�V�����ԍ�

		@return			�o�^����Ă��郂�[�V����
*//**************************************************************************/
FORCE_INLINE LPMeshAnimation CMeshMotionController::GetMotion(MofU32 n){
	return m_pAnimation->GetData(n);
}
/*************************************************************************//*!
		@brief			�o�^����Ă��郂�[�V�����擾
		@param[in]		pName			���[�V������

		@return			�o�^����Ă��郂�[�V����
*//**************************************************************************/
FORCE_INLINE LPMeshAnimation CMeshMotionController::GetMotionByName(LPCMofChar pName) {
	if(!pName)
	{
		return NULL;
	}
	LPMeshAnimation* pf = m_pAnimation->Find(pName);
	if(!pf)
	{
		return NULL;
	}
	return *pf;
}
/*************************************************************************//*!
		@brief			�o�^����Ă��郂�[�V�����擾
		@param[in]		pName			���[�V������


		@return			�o�^����Ă��郂�[�V�����̔ԍ�
						MOF_U32_MAX		�w�薼�̃��[�V�������o�^����Ă��Ȃ�
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshMotionController::GetMotionNoByName(LPCMofChar pName) const {
	if (!pName)
	{
		return MOF_U32_MAX;
	}
	for (MofU32 i = 0; i < m_pAnimation->GetArrayCount(); i++)
	{
		if (m_pAnimation->GetData(i)->GetName()->CompareCase(pName) == 0)
		{
			return i;
		}
	}
	return MOF_U32_MAX;
}
/*************************************************************************//*!
		@brief			�{�[����Ԏ擾
		@param[in]		n				�{�[���ԍ�

		@return			�{�[�����
*//**************************************************************************/
FORCE_INLINE LPBONEMOTIONSTATE CMeshMotionController::GetBoneState(MofU32 n){
	return m_pBoneState->GetData(n);
}
/*************************************************************************//*!
		@brief			�{�[����Ԏ擾
		@param[in]		Name			��������{�[����

		@return			�{�[�����
*//**************************************************************************/
FORCE_INLINE LPBONEMOTIONSTATE CMeshMotionController::GetBoneState(LPCMofChar Name){
	if(!Name)
	{
		return NULL;
	}
	LPBONEMOTIONSTATE* pf = m_pBoneState->Find(Name);
	if(!pf)
	{
		return NULL;
	}
	return *pf;
}
/*************************************************************************//*!
		@brief			���[���h�}�g���N�X�擾
		@param[in]		None

		@return			���[���h�}�g���N�X
*//**************************************************************************/
FORCE_INLINE CMatrix44& CMeshMotionController::GetWorldMatrix(void){
	return m_WorldMatrix;
}

//[EOF]