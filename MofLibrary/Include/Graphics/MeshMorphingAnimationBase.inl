/*************************************************************************//*!
					
					@file	MeshMorphingAnimationBase.inl
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
FORCE_INLINE MofBool CMeshMorphingAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			�p�����[�^�[�L�[�ݒ�<br>
						�Â��f�[�^������ꍇ��������
		@param[in]		pKey			�ݒ肷��L�[
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMeshMorphingAnimation::SetParameterKey(LPFloatKeyFrameArray pKey){
	MOF_SAFE_DELETE(m_pParameterKey);
	m_pParameterKey = pKey;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���[�V�����̃��[�v�t���O�̐ݒ�
		@param[in]		bLoop			���[�v�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMeshMorphingAnimation::SetLoop(MofBool bLoop){
	if(m_pParameterKey)
	{
		m_pParameterKey->SetLoop(((bLoop) ? KEYFRAMEARRAY_LOOPALLFRAME : FALSE));
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMeshMorphingAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�p�����[�^�[�L�[�擾
		@param			None

		@return			�p�����[�^�[�L�[
*//**************************************************************************/
FORCE_INLINE LPFloatKeyFrameArray CMeshMorphingAnimation::GetParameterKey(void){
	return m_pParameterKey;
}

//[EOF]