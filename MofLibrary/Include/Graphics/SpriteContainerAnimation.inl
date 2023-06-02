/*************************************************************************//*!
					
					@file	SpriteContainerAnimation.inl
					@brief	�X�v���C�g�R���e�i�A�j���[�V�������N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteContainerAnimation::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���[�V�����̃��[�v�t���O�̐ݒ�
		@param[in]		bLoop			���[�v�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteContainerAnimation::SetLoop(MofBool bLoop){
	if(!m_pPartAnimation)
	{
		return FALSE;
	}
	for(MofU32 i = 0;i < m_pPartAnimation->GetArrayCount();i++)
	{
		m_pPartAnimation->GetData(i)->SetLoop(bLoop);
	}
	return TRUE;
}

/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CSpriteContainerAnimation::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�A�j���[�V�����ł̓���p�[�c���擾
		@param			None

		@return			�A�j���[�V�����ł̓���p�[�c���z��
*//**************************************************************************/
FORCE_INLINE LPSpritePartAnimationArray CSpriteContainerAnimation::GetPartAnimation(void){
	return m_pPartAnimation;
}

//[EOF]