/*************************************************************************//*!
					
					@file	Sprite2DContainer.inl
					@brief	�X�v���C�g�R���e�i�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���݂̃��[�V������ύX
		@param[in]		n				���[�V�����ԍ�
		@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSprite2DContainer::ChangeMotion(MofU32 n,MofBool bSame){
	if(m_pMotionController)
	{
		return m_pMotionController->ChangeMotion(n,bSame);
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			���݂̃��[�V������ύX
		@param[in]		str				���[�V������
		@param[in]		bSame			���ꃂ�[�V�����ł̍X�V�t���O
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSprite2DContainer::ChangeMotionByName(LPCMofChar str,MofBool bSame){
	if(m_pMotionController)
	{
		return m_pMotionController->ChangeMotionByName(str,bSame);
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			���Ԃ�ݒ肷��
		@param[in]		t				�����A�j���[�V��������
				
		@return			TRUE			����I��<br>
						����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CSprite2DContainer::SetTime(MofFloat t) {
	if (m_pMotionController)
	{
		return m_pMotionController->SetTime(t);
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			�e�N�X�`���z��擾
		@param			None

		@return			�e�N�X�`���z��
*//**************************************************************************/
FORCE_INLINE LPTextureArray CSprite2DContainer::GetTextureArray(void){
	return m_pTextureArray;
}
/*************************************************************************//*!
		@brief			�X�v���C�g�A�j���[�V�������X�g�擾
		@param			None

		@return			�X�v���C�g�A�j���[�V�������X�g
*//**************************************************************************/
FORCE_INLINE LPSpriteContainerAnimationArray CSprite2DContainer::GetAnimation(void){
	return m_pAnimation;
}
/*************************************************************************//*!
		@brief			�X�v���C�g�A�j���[�V�����R���g���[���[�擾
		@param			None

		@return			�X�v���C�g�A�j���[�V�����R���g���[���[
*//**************************************************************************/
FORCE_INLINE LPSpritePartMotionController CSprite2DContainer::GetMotionController(void){
	return m_pMotionController;
}

//[EOF]