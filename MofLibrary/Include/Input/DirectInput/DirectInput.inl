/*************************************************************************//*!
					
					@file	DirectInput.inl
					@brief	DirectInputでの各種入力の処理を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			キー状態設定
		@param[in]		n				キー番号
		@param[in]		bState			キー状態
				
		@return			TRUE			設定成功<br>
						FALSE			設定失敗
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::SetKeyState(const MofU8 n,const MofBool bState){
	if(n >= MOFINPUT_KEYBOARDKEYMAX)
	{
		return FALSE;
	}
	if(bState)
	{
		m_bKeyboardState[n] |= 0x80;
	}
	else
	{
		m_bKeyboardState[n] &= ~0x80;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			キー状態設定
		@param[in]		n				キー番号
		@param[in]		bState			キー状態
				
		@return			TRUE			設定成功<br>
						FALSE			設定失敗
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::SetMouseState(const MofU8 n,const MofBool bState) {
	return FALSE;
}
/*************************************************************************//*!
		@brief			ホイール状態設定
		@param[in]		w				ホイール状態
				
		@return			TRUE			設定成功<br>
						FALSE			設定失敗
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::SetMouseWheel(const MofFloat w) {
	return FALSE;
}
/*************************************************************************//*!
		@brief			タッチ情報設定<br>
						タッチ入力が有効な場合のみ処理を実行。
		@param[in]		act				タッチ動作フラグ
		@param[in]		Id				タッチID
		@param[in]		x				タッチX座標
		@param[in]		y				タッチY座標

		@return			インプットデバイス
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::SetTouchState(MofS32 act, MofS32 Id, MofFloat x, MofFloat y){
	LPMOFTOUCHSTATE pTouch = NULL;
	//IDが一致するタッチを検索
	for (MofU32 i = 0; i < MOF_TOUCHMAX; i++)
	{
		if (m_Touch[i].bTouch && m_Touch[i].Id == Id)
		{
			pTouch = &m_Touch[i];
			break;
		}
	}
	//タッチ触れたとき
	if (act == MOF_TOUCHEVENTDOWN)
	{
		//空きを検索
		for (MofU32 i = 0; i < MOF_TOUCHMAX && !pTouch; i++)
		{
			if (!m_Touch[i].bTouch)
			{
				pTouch = &m_Touch[i];
			}
		}
		if (pTouch)
		{
			pTouch->Pos.x = x;
			pTouch->Pos.y = y;
			pTouch->Id = Id;
			pTouch->bTouch = TRUE;
		}
		return TRUE;
	}
	//タッチ移動
	else if (act == MOF_TOUCHEVENTMOVE && pTouch)
	{
		pTouch->Pos.x = x;
		pTouch->Pos.y = y;
		return TRUE;
	}
	//タッチ放したとき
	else if (act == MOF_TOUCHEVENTUP && pTouch)
	{
		pTouch->bTouch = FALSE;
		return TRUE;
	}
	return FALSE;
}
/*************************************************************************//*!
		@brief			インプットデバイス取得<br>
						使用しない環境で呼び出した場合NULLを返す。
		@param			None

		@return			インプットデバイス
*//**************************************************************************/
FORCE_INLINE MofInputDevice CDirectInput::GetDevice(void){
	return m_pInput;
}
/*************************************************************************//*!
		@brief			キーボードキー入力状態判定<br>
						キー番号のキーのPush(このフレームで入力された)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsKeyPush(const MofU8 n){
	return (((m_bKeyboardState[n] & 0x80) && !(m_bPrevKeyboardState[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			キーボードキー入力状態判定<br>
						キー番号のキーのHold(このフレームで入力されている)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsKeyHold(const MofU8 n){
	return ((m_bKeyboardState[n] & 0x80) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			キーボードキー入力状態判定<br>
						キー番号のキーのPull(このフレームで放された)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsKeyPull(const MofU8 n){
	return ((!(m_bKeyboardState[n] & 0x80) && (m_bPrevKeyboardState[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			マウスボタン入力状態判定<br>
						ボタン番号のボタンのPush(このフレームで入力された)判定を行う
		@param[in]		n				ボタン番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsMouseKeyPush(const MofU8 n){
	if(n >= MOFINPUT_MOUSEBUTTONMAX)
	{
		return FALSE;
	}
	return (((m_MouseState.rgbButtons[n] & 0x80) && !(m_PrevMouseState.rgbButtons[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			マウスボタン入力状態判定<br>
						ボタン番号のボタンのHold(このフレームで入力されている)判定を行う
		@param[in]		n				ボタン番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsMouseKeyHold(const MofU8 n){
	if(n >= MOFINPUT_MOUSEBUTTONMAX)
	{
		return FALSE;
	}
	return ((m_MouseState.rgbButtons[n] & 0x80) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			タッチ入力状態判定<br>
						タッチ番号のタッチのPush(このフレームで入力された)判定を行う
		@param[in]		n				タッチ番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchPush(MofU32 n){
	return (GetTouchState(n) && !GetPrevTouchStateById(GetTouchState(n)->Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			タッチ入力状態判定<br>
						タッチIDのタッチのPush(このフレームで入力された)判定を行う
		@param[in]		Id				タッチID

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchPushById(MofS32 Id){
	return (GetTouchStateById(Id) && !GetPrevTouchStateById(Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			タッチ入力状態判定<br>
						タッチ番号のタッチのHold(このフレームで入力されている)判定を行う
		@param[in]		n				タッチ番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchHold(MofU32 n){
	return GetTouchState(n) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			タッチ入力状態判定<br>
						タッチIDのタッチのHold(このフレームで入力されている)判定を行う
		@param[in]		Id				タッチID

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchHoldById(MofS32 Id){
	return GetTouchStateById(Id) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			タッチ入力状態判定<br>
						タッチ番号のタッチのPull(このフレームで放された)判定を行う
		@param[in]		n				タッチ番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchPull(MofU32 n){
	return (!GetTouchState(n) && GetPrevTouchState(n)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			タッチ入力状態判定<br>
						タッチIDのタッチのPull(このフレームで放された)判定を行う
		@param[in]		Id				タッチID

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsTouchPullById(MofS32 Id){
	return (!GetTouchStateById(Id) && GetPrevTouchStateById(Id)) ? TRUE : FALSE;
}
/*************************************************************************//*!
		@brief			マウスボタン入力状態判定<br>
						ボタン番号のボタンのPull(このフレームで放された)判定を行う
		@param[in]		n				ボタン番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::IsMouseKeyPull(const MofU8 n){
	if(n >= MOFINPUT_MOUSEBUTTONMAX)
	{
		return FALSE;
	}
	return ((!(m_MouseState.rgbButtons[n] & 0x80) && (m_PrevMouseState.rgbButtons[n] & 0x80)) ? TRUE : FALSE);
}
/*************************************************************************//*!
		@brief			マウス座標を二つのfloat型のデータとして取得する
		@param[out]		px			マウスＸ座標
		@param[out]		py			マウスＹ座標
				
		@return			TRUE		正常に取得することができた
						FALSE		読み込みエラー
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetMousePos(MofFloat& px,MofFloat& py){
	px = m_MouseState.lX;
	py = m_MouseState.lY;
	return TRUE;
}
/*************************************************************************//*!
		@brief			マウス座標をVector2型のデータとして取得する
		@param[out]		v			Vector2
				
		@return			TRUE		正常に取得することができた
						FALSE		取得エラー
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetMousePos(Vector2& v){
	v.x = m_MouseState.lX;
	v.y = m_MouseState.lY;
	return TRUE;
}
/*************************************************************************//*!
		@brief			マウスのホイール移動を取得する
		@param			None
				
		@return			ホイール移動量
*//**************************************************************************/
FORCE_INLINE MofFloat CDirectInput::GetMouseWheelMove(void){
	return m_MouseState.lZ;
}
/*************************************************************************//*!
		@brief			マウス移動を二つのfloat型のデータとして取得する
		@param[out]		px			マウスＸ移動量
		@param[out]		py			マウスＹ移動量
				
		@return			TRUE		正常に取得することができた
						FALSE		読み込みエラー
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetMouseMove(MofFloat& px,MofFloat& py){
	px = m_MouseState.lX - m_PrevMouseState.lX;
	py = m_MouseState.lY - m_PrevMouseState.lY;
	return TRUE;
}
/*************************************************************************//*!
		@brief			マウス移動をVector3型のデータとして取得する<br>
						x,yにはカーソルの移動量がzにはホイールの移動量が入る
		@param[out]		v			Vector3
				
		@return			TRUE		正常に取得することができた
						FALSE		読み込みエラー
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetMouseMove(Vector3& v){
	v.x = m_MouseState.lX - m_PrevMouseState.lX;
	v.y = m_MouseState.lY - m_PrevMouseState.lY;
	v.z = m_MouseState.lZ;
	return TRUE;
}
/*************************************************************************//*!
		@brief			ゲームパッド接続数取得
		@param			None

		@return			ゲームパッド接続数
*//**************************************************************************/
FORCE_INLINE MofU32 CDirectInput::GetGamePadCount(void){
	return m_pGamePadArray->GetArrayCount();
}
/*************************************************************************//*!
		@brief			ゲームパッド取得
		@param			None

		@return			ゲームパッド
*//**************************************************************************/
FORCE_INLINE LPGamePadArray CDirectInput::GetGamePad(void) {
	return m_pGamePadArray;
}
/*************************************************************************//*!
		@brief			ゲームパッド取得<br>
						番号に接続されているパッドを取得する。<br>
						現在の接続数以上の値を指定した場合NULLを返す
		@param[in]		n			パッド番号

		@return			ゲームパッド
*//**************************************************************************/
FORCE_INLINE LPGamePad CDirectInput::GetGamePad(MofU32 n){
	if(n >= m_pGamePadArray->GetArrayCount())
	{
		return NULL;
	}
	return m_pGamePadArray->GetData(n);
}

/*************************************************************************//*!
		@brief			タッチ認識最大数取得
		@param			None

		@return			タッチ認識最大数
*//**************************************************************************/
FORCE_INLINE MofU32 CDirectInput::GetTouchMax(){
	return MOF_TOUCHMAX;
}
/*************************************************************************//*!
		@brief			タッチ状態取得
						タッチされてなければNULLを返す
		@param[in]		n			タッチインデックス

		@return			タッチ状態
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CDirectInput::GetTouchState(MofU32 n){
	if(n >= MOF_TOUCHMAX || !m_Touch[n].bTouch)
	{
		return NULL;
	}
	return &m_Touch[n];
}
/*************************************************************************//*!
		@brief			IDを使ってタッチ状態取得
						タッチされてなければNULLを返す
		@param[in]		Id			タッチID

		@return			タッチ状態
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CDirectInput::GetTouchStateById(MofS32 Id){
	for(MofU32 i = 0;i < MOF_TOUCHMAX;i++)
	{
		if(m_Touch[i].bTouch && m_Touch[i].Id == Id)
		{
			return &m_Touch[i];
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			直前のタッチ状態取得
						タッチされてなければNULLを返す
		@param[in]		n			タッチ番号

		@return			直前のタッチ状態
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CDirectInput::GetPrevTouchState(MofU32 n){
	if(n >= MOF_TOUCHMAX || !m_PrevTouch[n].bTouch)
	{
		return NULL;
	}
	return &m_PrevTouch[n];
}
/*************************************************************************//*!
		@brief			IDを使って直前のタッチ状態取得
						タッチされてなければNULLを返す
		@param[in]		n			タッチID

		@return			直前のタッチ状態
*//**************************************************************************/
FORCE_INLINE LPCMOFTOUCHSTATE CDirectInput::GetPrevTouchStateById(MofS32 Id){
	for(MofU32 i = 0;i < MOF_TOUCHMAX;i++)
	{
		if(m_PrevTouch[i].bTouch && m_PrevTouch[i].Id == Id)
		{
			return &m_PrevTouch[i];
		}
	}
	return NULL;
}
/*************************************************************************//*!
		@brief			タッチ移動を二つのfloat型のデータとして取得する
		@param[in]		n			タッチ番号
		@param[out]		px			タッチＸ移動量
		@param[out]		py			タッチＹ移動量

		@return			TRUE		正常に取得することができた
						FALSE		読み込みエラー
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetTouchMove(MofU32 n,MofFloat& px,MofFloat& py){
	LPCMOFTOUCHSTATE pTouch = GetTouchState(n);
	LPCMOFTOUCHSTATE pPrev = pTouch ? GetPrevTouchStateById(pTouch->Id) : NULL;
	if(pTouch && pPrev)
	{
		px = pTouch->Pos.x - pPrev->Pos.x;
		py = pTouch->Pos.y - pPrev->Pos.y;
	}
	else
	{
		px = py = 0;
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			タッチ移動を二つのfloat型のデータとして取得する
		@param[in]		Id			タッチID
		@param[out]		px			タッチＸ移動量
		@param[out]		py			タッチＹ移動量

		@return			TRUE		正常に取得することができた
						FALSE		読み込みエラー
*//**************************************************************************/
FORCE_INLINE MofBool CDirectInput::GetTouchMoveById(MofS32 Id,MofFloat& px,MofFloat& py){
	LPCMOFTOUCHSTATE pTouch = GetTouchStateById(Id);
	LPCMOFTOUCHSTATE pPrev = GetPrevTouchStateById(Id);
	if(pTouch && pPrev)
	{
		px = pTouch->Pos.x - pPrev->Pos.x;
		py = pTouch->Pos.y - pPrev->Pos.y;
	}
	else
	{
		px = py = 0;
	}
	return TRUE;
}

//[EOF]