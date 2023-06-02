/*************************************************************************//*!
					
					@file	SpritePartMotionController.inl
					@brief	�X�v���C�g�p�[�c���[�V�����Ǘ��N���X�B<br>
							�X�v���C�g�p�[�c�A�j���[�V�����̎��ԂƏ�Ԃ��Ǘ�����B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���݂̃��[�V�������I�����Ă��邩�𔻒肷��B<br>
						���[�V���������[�v����ꍇ��TRUE�ɂȂ邱�Ƃ͂Ȃ�
		@param			None
				
		@return			TRUE			�I���ς�<br>
						FALE			�܂��I�����Ă��Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartMotionController::IsEndMotion(void){
	for(MofU32 i = 0;i < m_pPartState->GetArrayCount();i++)
	{
		LPPARTMOTIONSTATE pBS = m_pPartState->GetData(i);
		if (!pBS->pNowAnimation)
		{
			continue;
		}
		if(pBS->pNowAnimation->IsLoop() || pBS->AnimationTime < pBS->pNowAnimation->GetEndTime())
		{
			return FALSE;
		}
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�������Ԃ�ݒ�
		@param[in]		t				�ݒ莞��
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpritePartMotionController::SetTime(MofFloat t){
	m_MotionTime = t;
	for (MofU32 i = 0; i < m_pPartState->GetArrayCount(); i++)
	{
		LPPARTMOTIONSTATE pPS = m_pPartState->GetData(i);
		pPS->AnimationTime = t;
	}
	return Refresh();
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�������Ԏ擾
		@param			None

		@return			���݂̃��[�V��������
*//**************************************************************************/
FORCE_INLINE MofFloat CSpritePartMotionController::GetTime(void) const{
	return m_MotionTime;
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�����ԍ��擾
		@param			None

		@return			���݂̃��[�V�����ԍ�
*//**************************************************************************/
FORCE_INLINE MofS32 CSpritePartMotionController::GetMotionNo(void) const {
	return m_MotionNo;
}
/*************************************************************************//*!
		@brief			�o�^����Ă��郂�[�V�������擾
		@param			None

		@return			�o�^����Ă��郂�[�V������
*//**************************************************************************/
FORCE_INLINE MofS32 CSpritePartMotionController::GetMotionCount(void) const {
	return m_pAnimation->GetArrayCount();
}

//[EOF]