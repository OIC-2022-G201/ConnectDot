/*************************************************************************//*!
					
					@file	Sprite3D.inl
					@brief	3Dスプライトクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			幅取得
		@param			None

		@return			画像の幅
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
		@brief			高さ取得
		@param			None

		@return			画像の高さ
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