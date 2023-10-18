/*************************************************************************//*!
					
					@file	Sprite2D.inl
					@brief	2D�X�v���C�g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���擾
		@param			None

		@return			�摜�̕�
*//**************************************************************************/
FORCE_INLINE MofFloat CSprite2D::GetWidth(void){
	return (m_ImageRect.Right - m_ImageRect.Left) * m_Scale.x;
}
/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			�摜�̍���
*//**************************************************************************/
FORCE_INLINE MofFloat CSprite2D::GetHeight(void){
	return (m_ImageRect.Bottom - m_ImageRect.Top) * m_Scale.y;
}

//[EOF]