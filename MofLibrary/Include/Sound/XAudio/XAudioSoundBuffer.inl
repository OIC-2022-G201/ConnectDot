/*************************************************************************//*!
					
					@file	XAudioSoundBuffer.inl
					@brief	XAudio2�ł̊e��T�E���h�o�b�t�@�̏������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�T�E���h�o�b�t�@�擾
		@param			None

		@return			�T�E���h�o�b�t�@
*//**************************************************************************/
FORCE_INLINE MofSoundBuffer CXAudioSoundBuffer::GetBuffer(void){
	return ((!m_pBuffer) ? NULL : m_pBuffer[0]);
}

//[EOF]