/*************************************************************************//*!
					
					@file	SoundBufferBase.inl
					@brief	�e��T�E���h�o�b�t�@�̏������s�����N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���[�v�t���O��ON������
		@param			None

		@return			TRUE			���[�v�Đ�����<br>
						FALSE			���[�v���Ȃ�
*//**************************************************************************/
FORCE_INLINE MofBool CSoundBufferBase::IsLoop(void){
	return m_bLoop;
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CSoundBufferBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���[�v�t���O�̐ݒ�
		@param[in]		bl			���[�v�t���O�iTRUE:���[�v����AFALSE:���[�v���Ȃ��j
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CSoundBufferBase::SetLoop(MofBool bl){
	m_bLoop = bl;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CSoundBufferBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�Đ����ʎ擾
		@param			None
				
		@return			����(0.0(����)�`1.0(�ʏ�))
*//**************************************************************************/
FORCE_INLINE MofFloat CSoundBufferBase::GetVolume(void){
	return m_Volume;
}
/*************************************************************************//*!
		@brief			�Đ��s�b�`�擾
		@param			None
				
		@return			�s�b�`
*//**************************************************************************/
FORCE_INLINE MofFloat CSoundBufferBase::GetPitch(void){
	return m_Pitch;
}
/*************************************************************************//*!
		@brief			���t�@�C���̎��Ԏ擾
		@param			None
				
		@return			���t�@�C���̎���
*//**************************************************************************/
FORCE_INLINE MofFloat CSoundBufferBase::GetTime(void){
	return m_Time;
}

//[EOF]