/*************************************************************************//*!
					
					@file	DirectInputGamePad.inl
					@brief	DirectInput�ł̃Q�[���p�b�h�ł̊e����͂̏������s���N���X�B

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
FORCE_INLINE MofBool CDXGamePad::IsKeyPush(const MofU8 n) const {
	if(n >= MOFINPUT_GAMEPADBUTTONMAX)
	{
		return FALSE;
	}
	return (((m_PadState.rgbButtons[n] & 0x80) && !(m_PrevPadState.rgbButtons[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Hold(���̃t���[���œ��͂���Ă���)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDXGamePad::IsKeyHold(const MofU8 n) const {
	if(n >= MOFINPUT_GAMEPADBUTTONMAX)
	{
		return FALSE;
	}
	return ((m_PadState.rgbButtons[n] & 0x80) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�Q�[���p�b�h�L�[���͏�Ԕ���<br>
						�L�[�ԍ��̃L�[��Pull(���̃t���[���ŕ����ꂽ)������s��
		@param[in]		n				�L�[�ԍ�

		@return			TRUE			���͂���<br>
						FALSE			���͂Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CDXGamePad::IsKeyPull(const MofU8 n) const {
	if(n >= MOFINPUT_GAMEPADBUTTONMAX)
	{
		return FALSE;
	}
	return ((!(m_PadState.rgbButtons[n] & 0x80) && (m_PrevPadState.rgbButtons[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			�p�b�h�擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�p�b�h���
*//**************************************************************************/
FORCE_INLINE MofGamePad CDXGamePad::GetPad(void){
	return m_pGanePad;
}
/*************************************************************************//*!
		@brief			�p�b�h��Ԏ擾<br>
						�g�p���Ȃ����ŌĂяo�����ꍇNULL��Ԃ��B
		@param			None

		@return			�p�b�h���
*//**************************************************************************/
FORCE_INLINE MofGamePadState* CDXGamePad::GetPadState(void){
	return &m_PadState;
}
/*************************************************************************//*!
		@brief			�p�b�h��Ԏ擾<br>
						�X�e�B�b�N�̉��ւ̌X�����擾����B
		@param			None

		@return			�X�e�B�b�N�����͗�(-1.0�`1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CDXGamePad::GetStickHorizontal(void) const {
	return m_PadState.lX * 0.001f;
}
/*************************************************************************//*!
		@brief			�p�b�h��Ԏ擾<br>
						�X�e�B�b�N�̏c�ւ̌X�����擾����B
		@param			None

		@return			�X�e�B�b�N�c���͗�(-1.0�`1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CDXGamePad::GetStickVertical(void) const {
	return m_PadState.lY * 0.001f;
}

//[EOF]