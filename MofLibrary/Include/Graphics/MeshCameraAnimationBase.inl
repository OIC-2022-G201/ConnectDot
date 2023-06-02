/*************************************************************************//*!
					
					@file	MeshCameraAnimationBase.inl
					@brief	���b�V���A�j���[�V�������N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���W�L�[�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pKey			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetPositionKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pPositionKey);
	m_pPositionKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�^�[�Q�b�g�L�[�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pKey			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetTargetKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pTargetKey);
	m_pTargetKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			����L�[�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pKey			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetUpKey(LPVector3KeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pUpKey);
	m_pUpKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			����p�L�[�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pKey			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetFovKey(LPFloatKeyFrameArray pKey) {
	MOF_SAFE_DELETE(m_pFovKey);
	m_pFovKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���[�V�����̃��[�v�t���O�̐ݒ�
		@param[in]		bLoop			���[�v�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMeshCameraAnimation::SetLoop(MofBool bLoop){
	if (m_pPositionKey)
	{
		m_pPositionKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if(m_pTargetKey)
	{
		m_pTargetKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if (m_pUpKey)
	{
		m_pUpKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	if (m_pFovKey)
	{
		m_pFovKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMeshCameraAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			���W�L�[�擾
		@param			None

		@return			���W�L�[
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshCameraAnimation::GetPositionKey(void){
	return m_pPositionKey;
}
/*************************************************************************//*!
		@brief			�^�[�Q�b�g�L�[�擾
		@param			None

		@return			�^�[�Q�b�g�L�[
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshCameraAnimation::GetTargetKey(void){
	return m_pTargetKey;
}
/*************************************************************************//*!
		@brief			����L�[�擾
		@param			None

		@return			����L�[
*//**************************************************************************/
FORCE_INLINE LPVector3KeyFrameArray CMeshCameraAnimation::GetUpKey(void){
	return m_pUpKey;
}
/*************************************************************************//*!
		@brief			����p�L�[�擾
		@param			None

		@return			����p�L�[
*//**************************************************************************/
FORCE_INLINE LPFloatKeyFrameArray CMeshCameraAnimation::GetFovKey(void) {
	return m_pFovKey;
}

//[EOF]