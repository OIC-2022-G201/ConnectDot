/*************************************************************************//*!
					
					@file	WindowBase.h
					@brief	�E�C���h�E�Y�p�̃E�C���h�E�̏������s�����N���X�B<br>
							�E�C���h�E�Y�p�̃E�C���h�E��_�C�A���O�͂��ׂĂ��̃N���X���p������B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CWindowBase::SetName(LPCMofChar pName){
	return m_Title.SetString(pName);
}
/*************************************************************************//*!
		@brief			�C���X�^���X�n���h���擾
		@param			None

		@return			�C���X�^���X�n���h��
*//**************************************************************************/
FORCE_INLINE MofInstanceHandle CWindowBase::GetInstanceHandle(void){
	return m_hInstance;
}
/*************************************************************************//*!
		@brief			�E�C���h�E�n���h���擾
		@param			None

		@return			�E�C���h�E�n���h��
*//**************************************************************************/
FORCE_INLINE MofWindowHandle CWindowBase::GetWindowHandle(void){
	return m_hWnd;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CWindowBase::GetName(void){
	return &m_Title;
}
/*************************************************************************//*!
		@brief			�E�C���h�E�^�C�g���擾
		@param			None

		@return			�E�C���h�E�^�C�g��
*//**************************************************************************/
FORCE_INLINE LPString CWindowBase::GetTitle(void){
	return &m_Title;
}
/*************************************************************************//*!
		@brief			�E�C���h�E���擾
		@param			None

		@return			�E�C���h�E��
*//**************************************************************************/
FORCE_INLINE MofS32 CWindowBase::GetWidth(void) const{
	return m_Width;
}
/*************************************************************************//*!
		@brief			�E�C���h�E�����擾
		@param			None

		@return			�E�C���h�E����
*//**************************************************************************/
FORCE_INLINE MofS32 CWindowBase::GetHeight(void) const{
	return m_Height;
}

//[EOF]