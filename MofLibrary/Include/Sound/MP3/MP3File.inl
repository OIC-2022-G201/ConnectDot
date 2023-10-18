/*************************************************************************//*!
					
					@file	MP3File.inl
					@brief	MP3�t�@�C���̓ǂݍ��݂ƃf�R�[�h���s���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CMp3File::SetName(LPCMofChar pName){
	return m_pFile->SetName(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CMp3File::GetName(void){
	return m_pFile->GetName();
}
/*************************************************************************//*!
		@brief			WAVE�t�H�[�}�b�g�擾
		@param			None

		@return			WAVE�t�H�[�}�b�g�̎擾
*//**************************************************************************/
FORCE_INLINE LPWAVEFORMATEX CMp3File::GetWaveFormat(void){
	return &m_WaveFormat;
}
/*************************************************************************//*!
		@brief			�t���[���T�C�Y�擾
		@param			None

		@return			�t���[���T�C�Y�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CMp3File::GetFrameSize(void){
	return m_FrameSize;
}
/*************************************************************************//*!
		@brief			�t���[���T�C�Y�擾
		@param			None

		@return			�t���[���T�C�Y�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CMp3File::GetFrameDecodeSize(void){
	return m_FrameDecodeSize;
}
/*************************************************************************//*!
		@brief			�X�g���[���T�C�Y�擾
		@param			None

		@return			�X�g���[���T�C�Y�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CMp3File::GetStreamSize(void){
	return m_StreamSize;
}
/*************************************************************************//*!
		@brief			�X�g���[���T�C�Y�擾
		@param			None

		@return			�X�g���[���T�C�Y�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CMp3File::GetStreamDecodeSize(void){
	return m_DecodeSize;
}
/*************************************************************************//*!
		@brief			�T�C�Y�擾
		@param			None

		@return			�T�C�Y�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CMp3File::GetSize(void){
	if(!m_pFile)
	{
		return 0;
	}
	return m_pFile->GetBufferSize();
}

//[EOF]