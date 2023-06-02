/*************************************************************************//*!
					
					@file	MeshAnimationBase.inl
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
FORCE_INLINE MofBool CMeshAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���[�V�����̃��[�v�t���O�̐ݒ�
		@param[in]		bLoop			���[�v�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CMeshAnimation::SetLoop(MofBool bLoop){
	if(!m_pBoneAnimation)
	{
		return FALSE;
	}
	for(MofU32 i = 0;i < m_pBoneAnimation->GetArrayCount();i++)
	{
		m_pBoneAnimation->GetData(i)->SetLoop(bLoop);
	}
	for (MofU32 i = 0; i < m_pMorphingAnimation->GetArrayCount(); i++)
	{
		m_pMorphingAnimation->GetData(i)->SetLoop(bLoop);
	}
	return TRUE;
}

/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMeshAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����ł̓���{�[�����擾
		@param			None

		@return			�A�j���[�V�����ł̓���{�[�����z��
*//**************************************************************************/
FORCE_INLINE LPMeshBoneAnimationArray CMeshAnimation::GetBoneAnimation(void){
	return m_pBoneAnimation;
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����ł̓��샂�[�t�B���O���擾
		@param			None

		@return			�A�j���[�V�����ł̓��샂�[�t�B���O���z��
*//**************************************************************************/
FORCE_INLINE LPMeshMorphingAnimationArray CMeshAnimation::GetMorphingAnimation(void) {
	return m_pMorphingAnimation;
}

//[EOF]