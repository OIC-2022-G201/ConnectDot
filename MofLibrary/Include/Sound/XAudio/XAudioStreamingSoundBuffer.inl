/*************************************************************************//*!
					
					@file	XAudioStreamingSoundBuffer.inl
					@brief	XAudio2�ł̊e��T�E���h�o�b�t�@�̏������s�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�����Đ����̐ݒ�
		@param[in]		cnt			��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CXAudioStreamingSoundBuffer::SetBufferCount(MofU32 cnt) {
	return FALSE;
}
/*************************************************************************//*!
		@brief			�T�E���h�o�b�t�@�擾
		@param			None

		@return			�T�E���h�o�b�t�@
*//**************************************************************************/
FORCE_INLINE MofSoundBuffer CXAudioStreamingSoundBuffer::GetBuffer(void){
	return m_pBuffer;
}

//[EOF]