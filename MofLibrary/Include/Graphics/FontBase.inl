/*************************************************************************//*!
					
					@file	FontBase.inl
					@brief	�t�H���g���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�����`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::RenderFormatString(MofFloat px,MofFloat py,LPCMofChar pText,...){
	va_list arg;
	static MofChar ftext[8192];
	va_start(arg,pText);
	MOF_VPRINT(ftext,pText,arg);
	va_end(arg);
	return RenderString(px, py, m_DefaultColor, ftext);
}
/*************************************************************************//*!
		@brief			�����`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		col			�`��F
		@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::RenderFormatString(MofFloat px,MofFloat py,MofU32 col,LPCMofChar pText,...){
	va_list arg;
	static MofChar ftext[8192];
	va_start(arg,pText);
	MOF_VPRINT(ftext,pText,arg);
	va_end(arg);
	return RenderString(px,py,col,ftext);
}
/*************************************************************************//*!
		@brief			�����`��
		@param[in]		drec		�`���`
		@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::RenderFormatString(Rectangle& drec,LPCMofChar pText,...){
	va_list arg;
	static MofChar ftext[8192];
	va_start(arg,pText);
	MOF_VPRINT(ftext,pText,arg);
	va_end(arg);
	return RenderString(drec, m_DefaultColor, ftext);
}
/*************************************************************************//*!
		@brief			�����`��
		@param[in]		drec		�`���`
		@param[in]		col			�`��F
		@param[in]		pText		�`�敶����A�ψ����ɂ��t�H�[�}�b�g�w��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::RenderFormatString(Rectangle& drec,MofU32 col,LPCMofChar pText,...){
	va_list arg;
	static MofChar ftext[8192];
	va_start(arg,pText);
	MOF_VPRINT(ftext,pText,arg);
	va_end(arg);
	return RenderString(drec,col,ftext);
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetName(LPCMofChar pName){
	m_Face.SetString(pName);
	return Create();
}
/*************************************************************************//*!
		@brief			�T�C�Y�ݒ�
		@param[in]		s				�T�C�Y
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetSize(MofS32 s){
	m_Size = s;
	return Create();
}
/*************************************************************************//*!
		@brief			�����ݒ�
		@param[in]		s				����
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetBold(MofS32 s){
	m_Bold = s;
	return Create();
}
/*************************************************************************//*!
		@brief			�Α̐ݒ�
		@param[in]		bi				�Α�
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetItalic(MofBool bi){
	m_bItalic = bi;
	return Create();
}
/*************************************************************************//*!
		@brief			�����ݒ�
		@param[in]		bi				����
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetUnderline(MofBool bi){
	m_bUnderline = bi;
	return Create();
}
/*************************************************************************//*!
		@brief			�ŏ������ݒ�
		@param[in]		bi				�ŏ�����
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetStrikeOut(MofBool bi){
	m_bStrikeOut = bi;
	return Create();
}
/*************************************************************************//*!
		@brief			��{�F�ݒ�
		@param[in]		c				�F
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetDefaultColor(MofU32 c){
	m_DefaultColor = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CFontBase::GetName(void){
	return &m_Face;
}
/*************************************************************************//*!
		@brief			�t�H���g�T�C�Y�擾
		@param			None

		@return			�t�H���g�T�C�Y
*//**************************************************************************/
FORCE_INLINE MofS32 CFontBase::GetSize(void){
	return m_Size;
}
/*************************************************************************//*!
		@brief			�t�H���g�����擾
		@param			None

		@return			�t�H���g����
*//**************************************************************************/
FORCE_INLINE MofS32 CFontBase::GetBold(void){
	return m_Bold;
}
/*************************************************************************//*!
		@brief			�t�H���g�Α̎擾
		@param			None

		@return			�t�H���g�Α�
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::GetItalic(void){
	return m_bItalic;
}
/*************************************************************************//*!
		@brief			�t�H���g�����擾
		@param			None

		@return			�t�H���g����
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::GetUnderline(void){
	return m_bUnderline;
}
/*************************************************************************//*!
		@brief			�t�H���g�ŏ������擾
		@param			None

		@return			�t�H���g�ŏ�����
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::GetStrikeOut(void){
	return m_bStrikeOut;
}
/*************************************************************************//*!
		@brief			�t�H���g�^�C�v���擾
		@param			None

		@return			�t�H���g�^�C�v��
*//**************************************************************************/
FORCE_INLINE LPString CFontBase::GetFontFace(void){
	return &m_Face;
}

//[EOF]