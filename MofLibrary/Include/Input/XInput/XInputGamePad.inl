/*************************************************************************//*!
					
					@file	XInputGamePad.inl
					@brief	XInputでのゲームパッドでの各種入力の処理を行うクラス。

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
FORCE_INLINE MofBool CXGamePad::IsKeyPush(const MofU8 n) const {
	if(n >= XINPUT_MAX)
	{
		return FALSE;
	}
	return ((m_bButtonState[n] && !m_bPrevButtonState[n]) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			ゲームパッドキー入力状態判定<br>
						キー番号のキーのHold(このフレームで入力されている)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CXGamePad::IsKeyHold(const MofU8 n) const {
	if(n >= XINPUT_MAX)
	{
		return FALSE;
	}
	return m_bButtonState[n];
}
/*************************************************************************//*!
		@brief			ゲームパッドキー入力状態判定<br>
						キー番号のキーのPull(このフレームで放された)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CXGamePad::IsKeyPull(const MofU8 n) const {
	if(n >= XINPUT_MAX)
	{
		return FALSE;
	}
	return ((!m_bButtonState[n] && m_bPrevButtonState[n]) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			パッド取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			パッド状態
*//**************************************************************************/
FORCE_INLINE MofGamePad CXGamePad::GetPad(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			パッド状態取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			パッド状態
*//**************************************************************************/
FORCE_INLINE MofGamePadState* CXGamePad::GetPadState(void){
	return NULL;
}
/*************************************************************************//*!
		@brief			パッド状態取得<br>
						スティックの横への傾きを取得する。
		@param			None

		@return			スティック横入力量(-1.0～1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CXGamePad::GetStickHorizontal(void) const {
	return (MofFloat)m_PadState.Gamepad.sThumbLX / (MofFloat)MOFXINPUT_STICKMAX;
}
/*************************************************************************//*!
		@brief			パッド状態取得<br>
						スティックの縦への傾きを取得する。
		@param			None

		@return			スティック縦入力量(-1.0～1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CXGamePad::GetStickVertical(void) const {
	return (MofFloat)m_PadState.Gamepad.sThumbLY / (MofFloat)MOFXINPUT_STICKMAX;
}
/*************************************************************************//*!
		@brief			パッド状態取得<br>
						右スティックの横への傾きを取得する。
		@param			None

		@return			スティック横入力量(-1.0～1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CXGamePad::GetRightStickHorizontal(void) const {
	return (MofFloat)m_PadState.Gamepad.sThumbRX / (MofFloat)MOFXINPUT_STICKMAX;
}
/*************************************************************************//*!
		@brief			パッド状態取得<br>
						右スティックの縦への傾きを取得する。
		@param			None

		@return			スティック縦入力量(-1.0～1.0)
*//**************************************************************************/
FORCE_INLINE MofFloat CXGamePad::GetRightStickVertical(void) const {
	return (MofFloat)m_PadState.Gamepad.sThumbRY / (MofFloat)MOFXINPUT_STICKMAX;
}

//[EOF]