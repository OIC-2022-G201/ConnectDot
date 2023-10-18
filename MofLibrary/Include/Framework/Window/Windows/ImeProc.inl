/*************************************************************************//*!
					
					@file	ImeProc.inl
					@brief	IME�����v���V�[�W���[�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���͕�����̐ݒ�
		@param[in]		str			�ݒ蕶����
			
		@return			TRUE		����I��<br>
						����ȊO	����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CImeProc::SetInputString(LPCMofChar str){
	m_InputString.SetString(str);
	m_InsertPoint = m_InputString.GetLength();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�L���t���O�̐ݒ�
		@param[in]		be			�ݒ�t���O
			
		@return			TRUE		����I��<br>
						����ȊO	����G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CImeProc::SetEnable(MofBool be){
	m_bEnable = be;
	return TRUE;
}

/*************************************************************************//*!
		@brief			IME�ϊ����X�g������̎擾
		@param			None

		@return			IME�ϊ����X�g������
*//**************************************************************************/
FORCE_INLINE LPString CImeProc::GetListString(void){
	return &m_ListString;
}
/*************************************************************************//*!
		@brief			IME���앶����̎擾
		@param			None

		@return			IME���앶����
*//**************************************************************************/
FORCE_INLINE LPString CImeProc::GetImeString(void){
	return &m_ImeString;
}
/*************************************************************************//*!
		@brief			���͕�����̎擾
		@param			None

		@return			���͕�����
*//**************************************************************************/
FORCE_INLINE LPString CImeProc::GetInputString(void){
	return &m_InputString;
}
/*************************************************************************//*!
		@brief			���͕������IME���앶����̎擾
		@param[out]		os			�o�͕�����

		@return			���͕������IME���앶����̌���������
*//**************************************************************************/
FORCE_INLINE MofBool CImeProc::GetInputImeString(CString& os){
	if (!m_bEnable)
	{
		return FALSE;
	}
	os = m_InputString;
	os.Insert(m_ImeString.GetString(), m_InsertPoint);
	return TRUE;
}
/*************************************************************************//*!
		@brief			���͊m�蕶����̎擾
		@param			None

		@return			���͊m�蕶����
*//**************************************************************************/
FORCE_INLINE LPString CImeProc::GetEnterString(void){
	return &m_EnterString;
}
/*************************************************************************//*!
		@brief			�}���ʒu�̎擾
		@param			None

		@return			�}���ʒu
*//**************************************************************************/
FORCE_INLINE MofS32 CImeProc::GetInsertPoint(void) {
	return m_InsertPoint;
}