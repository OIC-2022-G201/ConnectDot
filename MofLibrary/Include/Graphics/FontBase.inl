/*************************************************************************//*!
					
					@file	FontBase.inl
					@brief	フォント基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			文字描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
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
		@brief			文字描画
		@param[in]		px			描画X座標
		@param[in]		py			描画Y座標
		@param[in]		col			描画色
		@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
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
		@brief			文字描画
		@param[in]		drec		描画矩形
		@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
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
		@brief			文字描画
		@param[in]		drec		描画矩形
		@param[in]		col			描画色
		@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
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
		@brief			名前設定
		@param[in]		pName			設定する名前
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetName(LPCMofChar pName){
	m_Face.SetString(pName);
	return Create();
}
/*************************************************************************//*!
		@brief			サイズ設定
		@param[in]		s				サイズ
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetSize(MofS32 s){
	m_Size = s;
	return Create();
}
/*************************************************************************//*!
		@brief			太さ設定
		@param[in]		s				太さ
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetBold(MofS32 s){
	m_Bold = s;
	return Create();
}
/*************************************************************************//*!
		@brief			斜体設定
		@param[in]		bi				斜体
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetItalic(MofBool bi){
	m_bItalic = bi;
	return Create();
}
/*************************************************************************//*!
		@brief			下線設定
		@param[in]		bi				下線
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetUnderline(MofBool bi){
	m_bUnderline = bi;
	return Create();
}
/*************************************************************************//*!
		@brief			打消し線設定
		@param[in]		bi				打消し線
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetStrikeOut(MofBool bi){
	m_bStrikeOut = bi;
	return Create();
}
/*************************************************************************//*!
		@brief			基本色設定
		@param[in]		c				色
				
		@return			TRUE			正常終了<br>
						それ以外		設定エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::SetDefaultColor(MofU32 c){
	m_DefaultColor = c;
	return TRUE;
}
/*************************************************************************//*!
		@brief			名前取得
		@param			None

		@return			名前の取得
*//**************************************************************************/
FORCE_INLINE LPString CFontBase::GetName(void){
	return &m_Face;
}
/*************************************************************************//*!
		@brief			フォントサイズ取得
		@param			None

		@return			フォントサイズ
*//**************************************************************************/
FORCE_INLINE MofS32 CFontBase::GetSize(void){
	return m_Size;
}
/*************************************************************************//*!
		@brief			フォント太さ取得
		@param			None

		@return			フォント太さ
*//**************************************************************************/
FORCE_INLINE MofS32 CFontBase::GetBold(void){
	return m_Bold;
}
/*************************************************************************//*!
		@brief			フォント斜体取得
		@param			None

		@return			フォント斜体
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::GetItalic(void){
	return m_bItalic;
}
/*************************************************************************//*!
		@brief			フォント下線取得
		@param			None

		@return			フォント下線
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::GetUnderline(void){
	return m_bUnderline;
}
/*************************************************************************//*!
		@brief			フォント打消し線取得
		@param			None

		@return			フォント打消し線
*//**************************************************************************/
FORCE_INLINE MofBool CFontBase::GetStrikeOut(void){
	return m_bStrikeOut;
}
/*************************************************************************//*!
		@brief			フォントタイプ名取得
		@param			None

		@return			フォントタイプ名
*//**************************************************************************/
FORCE_INLINE LPString CFontBase::GetFontFace(void){
	return &m_Face;
}

//[EOF]