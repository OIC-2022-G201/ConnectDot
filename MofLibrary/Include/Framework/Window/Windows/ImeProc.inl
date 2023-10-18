/*************************************************************************//*!
					
					@file	ImeProc.inl
					@brief	IME処理プロシージャー。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			入力文字列の設定
		@param[in]		str			設定文字列
			
		@return			TRUE		正常終了<br>
						それ以外	解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CImeProc::SetInputString(LPCMofChar str){
	m_InputString.SetString(str);
	m_InsertPoint = m_InputString.GetLength();
	return TRUE;
}
/*************************************************************************//*!
		@brief			有効フラグの設定
		@param[in]		be			設定フラグ
			
		@return			TRUE		正常終了<br>
						それ以外	解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CImeProc::SetEnable(MofBool be){
	m_bEnable = be;
	return TRUE;
}

/*************************************************************************//*!
		@brief			IME変換リスト文字列の取得
		@param			None

		@return			IME変換リスト文字列
*//**************************************************************************/
FORCE_INLINE LPString CImeProc::GetListString(void){
	return &m_ListString;
}
/*************************************************************************//*!
		@brief			IME操作文字列の取得
		@param			None

		@return			IME操作文字列
*//**************************************************************************/
FORCE_INLINE LPString CImeProc::GetImeString(void){
	return &m_ImeString;
}
/*************************************************************************//*!
		@brief			入力文字列の取得
		@param			None

		@return			入力文字列
*//**************************************************************************/
FORCE_INLINE LPString CImeProc::GetInputString(void){
	return &m_InputString;
}
/*************************************************************************//*!
		@brief			入力文字列とIME操作文字列の取得
		@param[out]		os			出力文字列

		@return			入力文字列とIME操作文字列の結合文字列
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
		@brief			入力確定文字列の取得
		@param			None

		@return			入力確定文字列
*//**************************************************************************/
FORCE_INLINE LPString CImeProc::GetEnterString(void){
	return &m_EnterString;
}
/*************************************************************************//*!
		@brief			挿入位置の取得
		@param			None

		@return			挿入位置
*//**************************************************************************/
FORCE_INLINE MofS32 CImeProc::GetInsertPoint(void) {
	return m_InsertPoint;
}