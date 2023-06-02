/*************************************************************************//*!
					
					@file	DShowMovie.h
					@brief	DirectShow����N���X�B

															@author	CDW
															@date	2015.11.23
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���[�g�ݒ�
		@param[in]		Rate			���[�g
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CDShowMovie::SetRate(MofDouble Rate){
	HRESULT hr = m_pMP->put_Rate(Rate);
	if(FAILED(hr))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���ʐݒ�
		@param[in]		Vol				����(0.0(����)�`1.0(�ʏ�))
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CDShowMovie::SetVolume(MofFloat Vol){
	long lv = MOF_CLIPING(1.0f-Vol,0.0f,1.0f)*-10000;
	HRESULT hr = m_pBA->put_Volume(lv);
	if(FAILED(hr))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			
		@param			None

		@return			TRUE			����I��<br>
						����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CDShowMovie::SetForeground(void){
	//�O�ʂɎ����Ă���
	HRESULT hr = m_pVW->SetWindowForeground(OATRUE);
	if(FAILED(hr))
	{
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���݈ʒu�擾
		@param			None

		@return			���݈ʒu
*//**************************************************************************/
FORCE_INLINE MofDouble CDShowMovie::GetPosition(void){
	if (!m_pMP)
	{
		return 0.0f;
	}
	//���ݍĐ��ʒu
	REFTIME Pos;
	m_pMP->get_CurrentPosition(&Pos);
	return Pos;
}
/*************************************************************************//*!
		@brief			�I�����Ԏ擾
		@param			None

		@return			�I������
*//**************************************************************************/
FORCE_INLINE MofDouble CDShowMovie::GetEndTime(void){
	if (!m_pMP)
	{
		return 0.0f;
	}
	//�I������
	REFTIME Time = 0;
	m_pMP->get_StopTime(&Time);
	return Time;
}
/*************************************************************************//*!
		@brief			���[�g�擾
		@param			None

		@return			���[�g
*//**************************************************************************/
FORCE_INLINE MofDouble CDShowMovie::GetRate(void){
	//���[�g
	REFTIME Rate = 0;
	m_pMP->get_Rate(&Rate);
	return Rate;
}
/*************************************************************************//*!
		@brief			���ʎ擾
		@param			None

		@return			����(0.0(����)�`1.0(�ʏ�))
*//**************************************************************************/
FORCE_INLINE MofFloat CDShowMovie::GetVolume(void){
	//����
	long lv = 0;
	m_pBA->get_Volume(&lv);
	return 1.0f-((float)lv/-10000);
}
/*************************************************************************//*!
		@brief			�q���t���O�擾
		@param			None

		@return			�q���t���O
*//**************************************************************************/
FORCE_INLINE MofBool CDShowMovie::GetChildFlag(void){
	return m_ChildWindow;
}
/*************************************************************************//*!
		@brief			�o�b�t�@�̃T�C�Y���擾
		@param			None

		@return			�o�b�t�@�̃T�C�Y
*//**************************************************************************/
FORCE_INLINE MofU32 CDShowMovie::GetSamplesBufferSize(void){
	return m_BufferSize;
}
/*************************************************************************//*!
		@brief			�e�N�X�`���擾
		@param			None

		@return			�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CDShowMovie::GetTexture(void){
	return m_pTexture;
}
