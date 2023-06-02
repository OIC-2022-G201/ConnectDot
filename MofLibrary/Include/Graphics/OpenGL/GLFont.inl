/*************************************************************************//*!
					
					@file	GLFont.h
					@brief	OpenGL�t�H���g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			�����`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		pText		�`�敶����
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGLFont::RenderString(MofFloat px,MofFloat py,LPCMofChar pText){
	return RenderString(px, py, m_DefaultColor, pText);
}
/*************************************************************************//*!
		@brief			�����`��
		@param[in]		drec		�`���`
		@param[in]		pText		�`�敶����
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CGLFont::RenderString(Rectangle& drec,LPCMofChar pText){
	return RenderString(drec, m_DefaultColor, pText);
}

//[EOF]