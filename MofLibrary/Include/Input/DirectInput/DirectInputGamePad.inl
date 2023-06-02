/*************************************************************************//*!
					
					@file	DirectInputGamePad.inl
					@brief	DirectInputでのゲームパッドでの各種入力の処理を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			ゲームパッドキー入力状態判定<br>
						キー番号のキーのPush(このフレームで入力された)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDXGamePad::IsKeyPush(const MofU8 n) const {
	if(n >= MOFINPUT_GAMEPADBUTTONMAX)
	{
		return FALSE;
	}
	return (((m_PadState.rgbButtons[n] & 0x80) && !(m_PrevPadState.rgbButtons[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			ゲームパッドキー入力状態判定<br>
						キー番号のキーのHold(このフレームで入力されている)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDXGamePad::IsKeyHold(const MofU8 n) const {
	if(n >= MOFINPUT_GAMEPADBUTTONMAX)
	{
		return FALSE;
	}
	return ((m_PadState.rgbButtons[n] & 0x80) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			ゲームパッドキー入力状態判定<br>
						キー番号のキーのPull(このフレームで放された)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDXGamePad::IsKeyPull(const MofU8 n) const {
	if(n >= MOFINPUT_GAMEPADBUTTONMAX)
	{
		return FALSE;
	}
	return ((!(m_PadState.rgbButtons[n] & 0x80) && (m_PrevPadState.rgbButtons[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			パッド取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			パッド状態
*//**************************************************************************/
FORCE_INLINE MofGamePad CDXGamePad::GetPad(void){
	return m_pGanePad;
}
/*************************************************************************//*!
		@brief			パッド状態取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			パッド状態
*//**************************************************************************/
FORCE_INLINE MofGamePadState* CDXGamePad::GetPadState(void){
	return &m_PadState;
}
/*************************************************************************//*!
		@brief			パッド状態取得<br>
						スティックの横への傾きを取得する。
		@param			None

		@return			スティック横入力量(-1.0～1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CDXGamePad::GetStickHorizontal(void) const {
	return m_PadState.lX * 0.001f;
}
/*************************************************************************//*!
		@brief			パッド状態取得<br>
						スティックの縦への傾きを取得する。
		@param			None

		@return			スティック縦入力量(-1.0～1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CDXGamePad::GetStickVertical(void) const {
	return m_PadState.lY * 0.001f;
}

//[EOF]