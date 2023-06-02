/*************************************************************************//*!
					
					@file	Sprite3D.inl
					@brief	3D�X�v���C�g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���擾
		@param			None

		@return			�摜�̕�
*//**************************************************************************/
FORCE_INLINE MofFloat CSprite3D::GetWidth(void){
	if(m_bRatio)
	{
		MofFloat w = m_ImageRect.Right - m_ImageRect.Left;
		MofFloat h = m_ImageRect.Bottom - m_ImageRect.Top;
		if(h > w)
		{
			return (w / h) * m_Scale.x;
		}
	}
	return m_Scale.x;
}
/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			�摜�̍���
*//**************************************************************************/
FORCE_INLINE MofFloat CSprite3D::GetHeight(void){
	if(m_bRatio)
	{
		MofFloat w = m_ImageRect.Right - m_ImageRect.Left;
		MofFloat h = m_ImageRect.Bottom - m_ImageRect.Top;
		if(w > h)
		{
			return (h / w) * m_Scale.y;
		}
	}
	return m_Scale.y;
}

//[EOF]