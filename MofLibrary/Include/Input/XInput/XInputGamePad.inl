/*************************************************************************//*!
					
					@file	XInputGamePad.inl
					@brief	XInput�ł̃Q�[���p�b�h�ł̊e����͂̏������s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�Q�[���p�b�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Push(���̃t���[���œ��͂��ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CXGamePad::IsKeyPush(const MofU8 n) const {
	if(n >= XINPUT_MAX)
	{
		return FALSE;
	}
	return ((m_bButtonState[n] && !m_bPrevButtonState[n]) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CXGamePad::IsKeyHold(const MofU8 n) const {
	if(n >= XINPUT_MAX)
	{
		return FALSE;
	}
	return m_bButtonState[n];
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CXGamePad::IsKeyPull(const MofU8 n) const {
	if(n >= XINPUT_MAX)
	{
		return FALSE;
	}
	return ((!m_bButtonState[n] && m_bPrevButtonState[n]) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�p�b�h�擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�p�b�h���
*//**************************************************************************/
FORCE_INLINE MofGamePad CXGamePad::GetPad(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�p�b�h��Ԏ擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�p�b�h���
*//**************************************************************************/
FORCE_INLINE MofGamePadState* CXGamePad::GetPadState(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			�p�b�h��Ԏ擾<br>
						�X�e�B�b�N�̉��ւ̌X�����擾����B
		@param			None

		@return			�X�e�B�b�N�����͗�(-1.0�`1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CXGamePad::GetStickHorizontal(void) const {
	return (MofFloat)m_PadState.Gamepad.sThumbLX / (MofFloat)MOFXINPUT_STICKMAX;
}
/*************************************************************************//*!
		@brief			�p�b�h��Ԏ擾<br>
						�X�e�B�b�N�̏c�ւ̌X�����擾����B
		@param			None

		@return			�X�e�B�b�N�c���͗�(-1.0�`1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CXGamePad::GetStickVertical(void) const {
	return (MofFloat)m_PadState.Gamepad.sThumbLY / (MofFloat)MOFXINPUT_STICKMAX;
}
/*************************************************************************//*!
		@brief			�p�b�h��Ԏ擾<br>
						�E�X�e�B�b�N�̉��ւ̌X�����擾����B
		@param			None

		@return			�X�e�B�b�N�����͗�(-1.0�`1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CXGamePad::GetRightStickHorizontal(void) const {
	return (MofFloat)m_PadState.Gamepad.sThumbRX / (MofFloat)MOFXINPUT_STICKMAX;
}
/*************************************************************************//*!
		@brief			�p�b�h��Ԏ擾<br>
						�E�X�e�B�b�N�̏c�ւ̌X�����擾����B
		@param			None

		@return			�X�e�B�b�N�c���͗�(-1.0�`1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CXGamePad::GetRightStickVertical(void) const {
	return (MofFloat)m_PadState.Gamepad.sThumbRY / (MofFloat)MOFXINPUT_STICKMAX;
}

//[EOF]