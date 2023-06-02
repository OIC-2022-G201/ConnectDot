/*************************************************************************//*!
					
					@file	SpriteMotionController.inl
					@brief	�X�v���C�g���[�V�����Ǘ��N���X�B<br>
							�X�v���C�g�A�j���[�V�����̎��ԂƏ�Ԃ��Ǘ�����B

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
FORCE_INLINE MofBool CSpriteMotionController::IsEndMotion(void){
	LPSpriteAnimation pAnim = m_pAnimation->GetData(m_MotionNo);
	return ((!pAnim->IsLoop() && m_MotionTime >= pAnim->GetEndTime()) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�������Ԃ�ݒ�
		@param[in]		t				�ݒ莞��
				
		@return			TRUE			����<br>
						����ȊO		���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteMotionController::SetTime(MofFloat t){
	m_MotionTime = t;
	return Refresh();
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�������Ԏ擾
		@param			None

		@return			���݂̃��[�V��������
*//**************************************************************************/
FORCE_INLINE MofFloat CSpriteMotionController::GetTime(void) const {
	return m_MotionTime;
}
/*************************************************************************//*!
		@brief			���݂̃��[�V�����ԍ��擾
		@param			None

		@return			���݂̃��[�V�����ԍ�
*//**************************************************************************/
FORCE_INLINE MofS32 CSpriteMotionController::GetMotionNo(void) const {
	return m_MotionNo;
}
/*************************************************************************//*!
		@brief			�o�^����Ă��郂�[�V�������擾
		@param			None

		@return			�o�^����Ă��郂�[�V������
*//**************************************************************************/
FORCE_INLINE MofS32 CSpriteMotionController::GetMotionCount(void) const {
	return m_pAnimation->GetArrayCount();
}
/*************************************************************************//*!
		@brief			���݂̃t���[���ԍ��擾
		@param			None

		@return			���݂̃t���[���ԍ�
*//**************************************************************************/
FORCE_INLINE MofS32 CSpriteMotionController::GetFrameNo(void) {
	LPSpriteAnimation pAnim = m_pAnimation->GetData(m_MotionNo);
	return pAnim->GetTimeFrameNo(m_MotionTime);
}
/*************************************************************************//*!
		@brief			���݂̃A�j���[�V������`�擾
		@param			None

		@return			���݂̃A�j���[�V������`
*//**************************************************************************/
FORCE_INLINE CRectangle& CSpriteMotionController::GetSrcRect(void){
	return m_SrcRect;
}
/*************************************************************************//*!
		@brief			���݂̃A�j���[�V������`�擾
		@param			None

		@return			���݂̃A�j���[�V������`
*//**************************************************************************/
FORCE_INLINE const CRectangle& CSpriteMotionController::GetSrcRect(void) const {
	return m_SrcRect;
}

//[EOF]