/*************************************************************************//*!
					
					@file	SpriteBase.inl
					@brief	スプライト基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			テクスチャ設定
		@param[in]		pTex			設定するテクスチャ
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
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
		@brief			画像矩形設定
		@param[in]		l			左
		@param[in]		t			上
		@param[in]		r			右
		@param[in]		b			下
				
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetImageRect(MofFloat l,MofFloat t,MofFloat r,MofFloat b){
	m_ImageRect.Left = l;
	m_ImageRect.Right = r;
	m_ImageRect.Top = t;
	m_ImageRect.Bottom = b;
	return TRUE;
}
/*************************************************************************//*!
		@brief			画像矩形設定
		@param[in]		r			矩形
				
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetImageRect(const Rectangle& r){
	m_ImageRect = r;
	return TRUE;
}
/*************************************************************************//*!
		@brief			アルファ値設定
		@param[in]		a			アルファ値
				
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetAlpha(MofFloat a){
	m_Color.a = MOF_CLIPING(a,0.0f,1.0f);
	return TRUE;
}
/*************************************************************************//*!
		@brief			反転フラグ設定
		@param[in]		bRev		反転フラグ
				
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
*//**************************************************************************/
FORCE_INLINE MofBool CSpriteBase::SetReverse(TextureReverse bRev){
	m_Reverse = bRev;
	return TRUE;
}
/*************************************************************************//*!
		@brief			テクスチャアライメント設定
		@param[in]		bAlignment	テクスチャアライメント
				
		@return			TRUE		正常に設定された<br>
						FALSE		設定の失敗
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
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CSpriteBase::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			テクスチャ取得
		@param			None

		@return			テクスチャ
*//**************************************************************************/
FORCE_INLINE LPTexture CSpriteBase::GetTexture(void){
	return m_pTexture;
}
/*************************************************************************//*!
		@brief			幅取得
		@param			None

		@return			画像の幅
*//**************************************************************************/
FORCE_INLINE MofFloat CSpriteBase::GetWidth(void){
	return m_ImageRect.Right - m_ImageRect.Left;
}
/*************************************************************************//*!
		@brief			高さ取得
		@param			None

		@return			画像の高さ
*//**************************************************************************/
FORCE_INLINE MofFloat CSpriteBase::GetHeight(void){
	return m_ImageRect.Bottom - m_ImageRect.Top;
}
/*************************************************************************//*!
		@brief			アライメント取得
		@param			None

		@return			アライメント
*//**************************************************************************/
FORCE_INLINE TextureAlignment CSpriteBase::GetTextureAlignment(void){
	return m_Alignment;
}
/*************************************************************************//*!
		@brief			反転フラグ取得
		@param			None

		@return			反転フラグ
*//**************************************************************************/
FORCE_INLINE TextureReverse CSpriteBase::GetReverse(void){
	return m_Reverse;
}

//[EOF]