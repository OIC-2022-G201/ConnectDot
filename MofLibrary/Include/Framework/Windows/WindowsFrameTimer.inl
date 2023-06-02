/*************************************************************************//*!
					
					@file	WindowsFrameTimer.inl
					@brief	Windows�Ńt���[�����Ԃ��v���A�������邽�߂̃N���X�B<br>
							timeGetTime�ɂ�莞�Ԃ̒������s���B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			FPS�̐ݒ�<br>
						FPS�̌Œ������ꍇ�ɐݒ���s���B<br>
						������FPS��0��ݒ肷��ƌŒ�Ȃ��̎��Ԍv���݂̂̏����ɂȂ�B
		@param[in]		s			FPS
			
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CWindowsFrameTimer::SetFPS(MofU32 s){
	m_FPS = s;
	if(s == 0)
	{
		m_FrameTime = 0;
	}
	else
	{
		m_FrameTime = 1000 / s;
	}
	//���݂̎��Ԃ��Z�b�g����
	m_FPSBeforeTime = GetTimeMS();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�t���[�����Ԃ̐ݒ�<br>
						���̃^�C�}�[�Ōo�߂����t���[�����Ԃ������̃~���b�ɍ����ւ���B
		@param[in]		s			�t���[������(msec)
			
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CWindowsFrameTimer::SetFrameMSecond(MofU32 s){
	m_NowFrameTime = s;
	return TRUE;
}
/*************************************************************************//*!
		@brief			����FPS�擾
		@param			None

		@return			FPS�̐����l
*//**************************************************************************/
FORCE_INLINE MofU32 CWindowsFrameTimer::GetRestrictFPS(void) const{
	return m_FPS;
}
/*************************************************************************//*!
		@brief			�����t���[�����Ԏ擾
		@param			None

		@return			�t���[�����Ԃ̐����l
*//**************************************************************************/
FORCE_INLINE MofU32 CWindowsFrameTimer::GetRestrictFrameTime(void) const {
	return m_FrameTime;
}
/*************************************************************************//*!
		@brief			FPS�擾
		@param			None

		@return			�v�����ꂽFPS
*//**************************************************************************/
FORCE_INLINE MofU32 CWindowsFrameTimer::GetFPS(void) const{
	return m_NowFPS;
}
/*************************************************************************//*!
		@brief			�t���[�����Ԏ擾<br>
						�擾����t���[�����Ԃ̒P�ʂ̓~���b
		@param			None

		@return			�t���[������(msec)
*//**************************************************************************/
FORCE_INLINE MofU32 CWindowsFrameTimer::GetUpdateFrameTime(void) const {
	return m_UpdateFrameTime;
}
/*************************************************************************//*!
		@brief			�t���[�����Ԏ擾<br>
						�擾����t���[�����Ԃ̒P�ʂ̓~���b
		@param			None

		@return			�t���[������(msec)
*//**************************************************************************/
FORCE_INLINE MofU32 CWindowsFrameTimer::GetFrameMSecond(void) const{
	return m_NowFrameTime;
}
/*************************************************************************//*!
		@brief			�t���[�����Ԏ擾<br>
						�擾����t���[�����Ԃ̒P�ʂ͕b
		@param			None

		@return			�t���[������(sec)
*//**************************************************************************/
FORCE_INLINE MofFloat CWindowsFrameTimer::GetFrameSecond(void) const{
	return m_NowFrameTime * 0.001f;
}

//[EOF]