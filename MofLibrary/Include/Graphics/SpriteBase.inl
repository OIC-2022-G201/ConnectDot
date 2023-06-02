/*************************************************************************//*!
					
					@file	SpriteBase.inl
					@brief	�X�v���C�g���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			�e�N�X�`���ݒ�
		@param[in]		pTex			�ݒ肷��e�N�X�`��
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetTexture(LPTexture pTex){
	MOF_SAFE_DELETE(m_pTexture);
	if(pTex)
	{
		m_pTexture = pTex->CreateCopyObject();
		if(m_pTexture)
		{
			m_ImageRect.Right = m_pTexture->GetWidth();
			m_ImageRect.Bottom = m_pTexture->GetHeight();
		}
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			�摜��`�ݒ�
		@param[in]		l			��
		@param[in]		t			��
		@param[in]		r			�E
		@param[in]		b			��
				
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetImageRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b){
	m_ImageRect.Left = l;
	m_ImageRect.Right = r;
	m_ImageRect.Top = t;
	m_ImageRect.Bottom = b;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�摜��`�ݒ�
		@param[in]		r			��`
				
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetImageRect(const Rectangle& r){
	m_ImageRect = r;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A���t�@�l�ݒ�
		@param[in]		a			�A���t�@�l
				
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetAlpha(MofFloat a){
	m_Color.a = MOF_CLIPING(a,0.0f,1.0f);
	return TRUE;
}
/*************************************************************************//*!
		@brief			���]�t���O�ݒ�
		@param[in]		bRev		���]�t���O
				
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetReverse(TextureReverse bRev){
	m_Reverse = bRev;
	return TRUE;
}
/*************************************************************************//*!
		@brief			�e�N�X�`���A���C�����g�ݒ�
		@param[in]		bAlignment	�e�N�X�`���A���C�����g
				
		@return			TRUE		����ɐݒ肳�ꂽ<br>
						FALSE		�ݒ�̎��s
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetAlignment(TextureAlignment bAlignment){
	m_Alignment = bAlignment;
	if(bAlignment & TEXTUREALIGNMENT_LEFT)
	{
		m_AlignmentPosition.x = 0.0f;
	}
	else if(bAlignment & TEXTUREALIGNMENT_HCENTER)
	{
		m_AlignmentPosition.x = (m_ImageRect.Right - m_ImageRect.Left) * 0.5f;
	}
	else if(bAlignment & TEXTUREALIGNMENT_RIGHT)
	{
		m_AlignmentPosition.x = (m_ImageRect.Right - m_ImageRect.Left);
	}
	if(bAlignment & TEXTUREALIGNMENT_TOP)
	{
		m_AlignmentPosition.y = 0.0f;
	}
	else if(bAlignment & TEXTUREALIGNMENT_VCENTER)
	{
		m_AlignmentPosition.y = (m_ImageRect.Bottom - m_ImageRect.Top) * 0.5f;
	}
	else if(bAlignment & TEXTUREALIGNMENT_BOTTOM)
	{
		m_AlignmentPosition.y = (m_ImageRect.Bottom - m_ImageRect.Top);
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CSpriteBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�e�N�X�`���擾
		@param			None

		@return			�e�N�X�`��
*//**************************************************************************/
FORCE_INLINE LPTexture CSpriteBase::GetTexture(void){
	return m_pTexture;
}
/*************************************************************************//*!
		@brief			���擾
		@param			None

		@return			�摜�̕�
*//**************************************************************************/
FORCE_INLINE MofFloat CSpriteBase::GetWidth(void){
	return m_ImageRect.Right - m_ImageRect.Left;
}
/*************************************************************************//*!
		@brief			�����擾
		@param			None

		@return			�摜�̍���
*//**************************************************************************/
FORCE_INLINE MofFloat CSpriteBase::GetHeight(void){
	return m_ImageRect.Bottom - m_ImageRect.Top;
}
/*************************************************************************//*!
		@brief			�A���C�����g�擾
		@param			None

		@return			�A���C�����g
*//**************************************************************************/
FORCE_INLINE TextureAlignment CSpriteBase::GetTextureAlignment(void){
	return m_Alignment;
}
/*************************************************************************//*!
		@brief			���]�t���O�擾
		@param			None

		@return			���]�t���O
*//**************************************************************************/
FORCE_INLINE TextureReverse CSpriteBase::GetReverse(void){
	return m_Reverse;
}

//[EOF]