/*************************************************************************//*!
					
					@file	MeshBoneAnimationBase.inl
					@brief	���b�V���A�j���[�V�������N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���[�v�t���O�����邩�𔻒肷��
		@param			None
				
		@return			TRUE			���[�v����<br>
						FALSE			���[�v���Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::IsLoop(void){
	MofBool re = FALSE;
	if(m_pPositionKey)
	{
		re |= m_pPositionKey->IsLoop();
	}
	if(m_pScalingKey)
	{
		re |= m_pScalingKey->IsLoop();
	}
	if(m_pRotationKey)
	{
		re |= m_pRotationKey->IsLoop();
	}
	return re;
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���[�V�����̃t���O�̐ݒ�
		@param[in]		f				�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetFlag(MofU32 f) {
	m_Flag = f;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���W�L�[�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pKey			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetPositionKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pPositionKey);
	m_pPositionKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�g��L�[�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pKey			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetScalingKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pScalingKey);
	m_pScalingKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			��]�L�[�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pKey			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetRotationKey(LPQuaternionKeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pRotationKey);
	m_pRotationKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���[�V�����̃��[�v�t���O�̐ݒ�
		@param[in]		bLoop			���[�v�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMeshBoneAnimation::SetLoop(MofBool bLoop){
	if(m_pPositionKey)
	{
		m_pPositionKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if(m_pScalingKey)
	{
		m_pScalingKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if(m_pRotationKey)
	{
		m_pRotationKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMeshBoneAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			���W�L�[�擾
		@param			None

		@return			���W�L�[
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshBoneAnimation::GetPositionKey(void){
	return m_pPositionKey;
}
/*************************************************************************//*!
		@brief			�g��L�[�擾
		@param			None

		@return			�g��L�[
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshBoneAnimation::GetScalingKey(void){
	return m_pScalingKey;
}
/*************************************************************************//*!
		@brief			��]�L�[�擾
		@param			None

		@return			��]�L�[
*//**************************************************************************/
FORCE_INLINE LPQuaternionKeyFrameArray CMeshBoneAnimation::GetRotationKey(void){
	return m_pRotationKey;
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����̃t���O�擾
		@param			None

		@return			�A�j���[�V�����̃t���O
*//**************************************************************************/
FORCE_INLINE MofU32 CMeshBoneAnimation::GetFlag(void) {
	return m_Flag;
}

//[EOF]