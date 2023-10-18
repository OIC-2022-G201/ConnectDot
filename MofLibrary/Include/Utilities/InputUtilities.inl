/*************************************************************************//*!
					
					@file	InputUtilities.cpp
					@brief	インプット関連の汎用処理をまとめたスタティッククラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			キーボードキー入力状態判定<br>
						キー番号のキーのPush(このフレームで入力された)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsKeyPush(const MofU8 n){
	return m_pInput->IsKeyPush(n);
}
/*************************************************************************//*!
		@brief			キーボードキー入力状態判定<br>
						キー番号のキーのHold(このフレームで入力されている)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsKeyHold(const MofU8 n){
	return m_pInput->IsKeyHold(n);
}
/*************************************************************************//*!
		@brief			キーボードキー入力状態判定<br>
						キー番号のキーのPull(このフレームで放された)判定を行う
		@param[in]		n				キー番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsKeyPull(const MofU8 n){
	return m_pInput->IsKeyPull(n);
}
/*************************************************************************//*!
		@brief			マウスボタン入力状態判定<br>
						ボタン番号のボタンのPush(このフレームで入力された)判定を行う
		@param[in]		n				ボタン番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsMouseKeyPush(const MofU8 n){
	return m_pInput->IsMouseKeyPush(n);
}
/*************************************************************************//*!
		@brief			マウスボタン入力状態判定<br>
						ボタン番号のボタンのHold(このフレームで入力されている)判定を行う
		@param[in]		n				ボタン番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsMouseKeyHold(const MofU8 n){
	return m_pInput->IsMouseKeyHold(n);
}
/*************************************************************************//*!
		@brief			マウスボタン入力状態判定<br>
						ボタン番号のボタンのPull(このフレームで放された)判定を行う
		@param[in]		n				ボタン番号

		@return			TRUE			入力あり<br>
						FALSE			入力なし
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::IsMouseKeyPull(const MofU8 n){
	return m_pInput->IsMouseKeyPull(n);
}
/*************************************************************************//*!
		@brief			インプットインターフェイスを設定する
		@param[in]		pg				インプットインターフェイス

		@return			None
*//**************************************************************************/
FORCE_INLINE void CInputUtilities::SetInput(LPInput pg){
	m_pInput = pg;
	return;
}
/*************************************************************************//*!
		@brief			キー状態設定
		@param[in]		n				キー番号
		@param[in]		bState			キー状態
				
		@return			TRUE			設定成功<br>
						FALSE			設定失敗
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::SetKeyState(const MofU8 n,const MofBool bState){
	return m_pInput->SetKeyState(n,bState);
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
FORCE_INLINE MofBool CInputUtilities::SetTouchState(MofS32 act,MofS32 Id,MofFloat x,MofFloat y){
	return m_pInput->SetTouchState(act,Id,x,y);
}
/*************************************************************************//*!
		@brief			インプットインターフェイスを取得する
		@param			None

		@return			インプットインターフェイス
*//**************************************************************************/
FORCE_INLINE  LPInput CInputUtilities::GetInput(void){
	return m_pInput;
}
/*************************************************************************//*!
		@brief			マウス座標を二つのfloat型のデータとして取得する
		@param[out]		px			マウスＸ座標
		@param[out]		py			マウスＹ座標
				
		@return			TRUE		正常に取得することができた
						FALSE		読み込みエラー
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::GetMousePos(MofFloat& px,MofFloat& py){
	return m_pInput->GetMousePos(px,py);
}
/*************************************************************************//*!
		@brief			マウス座標をVector2型のデータとして取得する
		@param[out]		v			Vector2
				
		@return			TRUE		正常に取得することができた
						FALSE		取得エラー
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::GetMousePos(Vector2& v){
	return m_pInput->GetMousePos(v);
}
/*************************************************************************//*!
		@brief			マウスのホイール移動を取得する
		@param			None
				
		@return			ホイール移動量
*//**************************************************************************/
FORCE_INLINE MofFloat CInputUtilities::GetMouseWheelMove(void){
	return m_pInput->GetMouseWheelMove();
}
/*************************************************************************//*!
		@brief			マウス移動を二つのfloat型のデータとして取得する
		@param[out]		px			マウスＸ移動量
		@param[out]		py			マウスＹ移動量
				
		@return			TRUE		正常に取得することができた
						FALSE		読み込みエラー
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::GetMouseMove(MofFloat& px,MofFloat& py){
	return m_pInput->GetMouseMove(px,py);
}
/*************************************************************************//*!
		@brief			マウス移動をVector3型のデータとして取得する<br>
						x,yにはカーソルの移動量がzにはホイールの移動量が入る
		@param[out]		v			Vector3
				
		@return			TRUE		正常に取得することができた
						FALSE		読み込みエラー
*//**************************************************************************/
FORCE_INLINE MofBool CInputUtilities::GetMouseMove(Vector3& v){
	return m_pInput->GetMouseMove(v);
}

//[EOF]