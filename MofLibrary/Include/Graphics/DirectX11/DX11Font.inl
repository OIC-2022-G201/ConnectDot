/*************************************************************************//*!
					
					@file	DX11Font.cpp
					@brief	DirectX11�t�H���g�N���X�B

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
FORCE_INLINE MofBool CDX11Font::RenderString(MofFloat px,MofFloat py,LPCMofChar pText){
	return RenderString(px, py, m_DefaultColor, pText);
}
/*************************************************************************//*!
		@brief			�����`��
		@param[in]		drec		�`���`
		@param[in]		pText		�`�敶����
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CDX11Font::RenderString(Rectangle& drec,LPCMofChar pText){
	return RenderString(drec, m_DefaultColor, pText);
}
/*************************************************************************//*!
		@brief			�����`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		scl			�`��X�P�[��
		@param[in]		pText		�`�敶����
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
FORCE_INLINE MofBool CDX11Font::RenderStringScale(MofFloat px, MofFloat py, MofFloat scl, LPCMofChar pText) {
	return RenderStringScale(px, py, m_DefaultColor, pText);
}
/*************************************************************************//*!
		@brief			�o�^�e�N�X�`�����擾
		@param			None

		@return			�o�^�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CDX11Font::GetTexture(void) {
	return m_pTexture;
}